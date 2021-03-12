using Android.App;
using Android.Widget;
using Android.OS;
using Android.Content;
using System;
using System.Collections.Generic;
using Android.Content.PM;
using Android.Provider;

namespace Image_Guesser
{
    [Activity(Label = "Image Guesser", MainLauncher = true, Icon = "@mipmap/icon", Theme = "@style/CustomActionBarTheme", ConfigurationChanges = ConfigChanges.ScreenSize | ConfigChanges.Orientation)]
    public class MainActivity : Activity
    {
        /// <summary>
        /// Used to track the file that we're manipulating between functions
        /// </summary>
        public static Java.IO.File _file;
        Boolean iscamerapic;
        string thing;
        string actuallyis;
        Android.Graphics.Bitmap mymap;

        /// <summary>
        /// Used to track the directory that we'll be writing to between functions
        /// </summary>
        public static Java.IO.File _dir;

        protected override void OnCreate(Bundle savedInstanceState)
        {
            base.OnCreate(savedInstanceState);

            // Set our view from the "main" layout resource
            SetContentView(Resource.Layout.Main);

            if (IsThereAnAppToTakePictures() == true)
            {
                CreateDirectoryForPictures();
                FindViewById<Button>(Resource.Id.launchCameraButton).Click += TakePicture;
            }
        }

        /// <summary>
        /// Apparently, some android devices do not have a camera.  To guard against this,
        /// we need to make sure that we can take pictures before we actually try to take a picture.
        /// </summary>
        /// <returns></returns>
        private bool IsThereAnAppToTakePictures()
        {
            Intent intent = new Intent(MediaStore.ActionImageCapture);
            IList<ResolveInfo> availableActivities =
                PackageManager.QueryIntentActivities
                (intent, PackageInfoFlags.MatchDefaultOnly);
            return availableActivities != null && availableActivities.Count > 0;
        }

        /// <summary>
        /// Creates a directory on the phone that we can place our images
        /// </summary>
        private void CreateDirectoryForPictures()
        {
            _dir = new Java.IO.File(
                Android.OS.Environment.GetExternalStoragePublicDirectory(
                    Android.OS.Environment.DirectoryPictures), "Is Image");
            if (!_dir.Exists())
            {
                _dir.Mkdirs();
            }
        }

        private void TakePicture(object sender, System.EventArgs e)
        {
            iscamerapic = true;
            Intent intent = new Intent(MediaStore.ActionImageCapture);
            _file = new Java.IO.File(_dir, string.Format("myPhoto_{0}.jpg", System.Guid.NewGuid()));
            //android.support.v4.content.FileProvider
            //getUriForFile(getContext(), "com.mydomain.fileprovider", newFile);
            //FileProvider.GetUriForFile

            intent.PutExtra(MediaStore.ExtraOutput, Android.Net.Uri.FromFile(_file));
            iscamerapic = true;
            StartActivityForResult(intent, 0);
        }


        // <summary>
        // Called automatically whenever an activity finishes
        // </summary>
        // <param name = "requestCode" ></ param >
        // < param name="resultCode"></param>
        /// <param name="data"></param>
        /// 

        protected override void OnActivityResult(int requestCode, Result resultCode, Intent data)
        {
            Android.Graphics.Bitmap bitmap = null;
            ImageView imageView = null;

            base.OnActivityResult(requestCode, resultCode, data);
            SetContentView(Resource.Layout.TakenPicture);

            if (iscamerapic == true)
            {
                //Make image available in the gallery

                Intent mediaScanIntent = new Intent(Intent.ActionMediaScannerScanFile);
                var contentUri = Android.Net.Uri.FromFile(_file);
                mediaScanIntent.SetData(contentUri);
                SendBroadcast(mediaScanIntent);


                // Display in ImageView. We will resize the bitmap to fit the display.
                // Loading the full sized image will consume too much memory
                // and cause the application to crash.      
                imageView = FindViewById<ImageView>(Resource.Id.takenPictureImageView);
                int height = Resources.DisplayMetrics.HeightPixels;
                int width = imageView.Height;
                bitmap = _file.Path.LoadAndResizeBitmap(width, height);
            }

            if (bitmap != null)
            {
                imageView.SetImageBitmap(bitmap);
                imageView.Visibility = Android.Views.ViewStates.Visible;
            }

            else
            {
                SetContentView(Resource.Layout.Main);
                if (IsThereAnAppToTakePictures() == true)
                {
                    CreateDirectoryForPictures();
                    FindViewById<Button>(Resource.Id.launchCameraButton).Click += TakePicture;
                }
            }

            if (bitmap != null)
            {
                //convert bitmap into stream to be sent to Google API
                string bitmapString = "";
                using (var stream = new System.IO.MemoryStream())
                {
                    bitmap.Compress(Android.Graphics.Bitmap.CompressFormat.Jpeg, 0, stream);

                    var bytes = stream.ToArray();
                    bitmapString = System.Convert.ToBase64String(bytes);
                }

                //credential is stored in "assets" folder
                string credPath = "google_api.json";
                Google.Apis.Auth.OAuth2.GoogleCredential cred;

                //Load credentials into object form
                using (var stream = Assets.Open(credPath))
                {
                    cred = Google.Apis.Auth.OAuth2.GoogleCredential.FromStream(stream);
                }
                cred = cred.CreateScoped(Google.Apis.Vision.v1.VisionService.Scope.CloudPlatform);

                // By default, the library client will authenticate 
                // using the service account file (created in the Google Developers 
                // Console) specified by the GOOGLE_APPLICATION_CREDENTIALS 
                // environment variable. We are specifying our own credentials via json file.
                var client = new Google.Apis.Vision.v1.VisionService(new Google.Apis.Services.BaseClientService.Initializer()
                {
                    ApplicationName = "isimageapp",
                    HttpClientInitializer = cred
                });

                //set up request
                var request = new Google.Apis.Vision.v1.Data.AnnotateImageRequest();
                request.Image = new Google.Apis.Vision.v1.Data.Image();
                request.Image.Content = bitmapString;

                //tell google that we want to perform label detection
                request.Features = new List<Google.Apis.Vision.v1.Data.Feature>();
                request.Features.Add(new Google.Apis.Vision.v1.Data.Feature() { Type = "LABEL_DETECTION" });
                var batch = new Google.Apis.Vision.v1.Data.BatchAnnotateImagesRequest();
                batch.Requests = new List<Google.Apis.Vision.v1.Data.AnnotateImageRequest>();
                batch.Requests.Add(request);

                //send request.  Note that I'm calling execute() here, but you might want to use
                //ExecuteAsync instead

                var apiResult = client.Images.Annotate(batch).Execute();

                thing = apiResult.Responses[0].LabelAnnotations[0].Description;
                FindViewById<TextView>(Resource.Id.isit).Text += thing;
                mymap = bitmap;
                mainprogramflow(apiResult);
            }
        }

        void mainprogramflow(Google.Apis.Vision.v1.Data.BatchAnnotateImagesResponse results)
        {
            if (mymap != null)
            {
                Button pressedYes = FindViewById<Button>(Resource.Id.YesButton);
                Button pressedNo = FindViewById<Button>(Resource.Id.NoButton);
                Button pressedSO1 = FindViewById<Button>(Resource.Id.newphotobutton);
                float score = 0;
                Boolean exists;

                pressedYes.Click += delegate
                {
                    SetContentView(Resource.Layout.Success);
                    Button pressedSO2 = FindViewById<Button>(Resource.Id.newcamerabutton);
                    pressedSO2.Click += delegate
                    {
                        SetContentView(Resource.Layout.Main);
                        if (IsThereAnAppToTakePictures() == true)
                        {
                            CreateDirectoryForPictures();
                            FindViewById<Button>(Resource.Id.launchCameraButton).Click += TakePicture;
                        }
                    };
                };

                pressedNo.Click += delegate
                {
                    SetContentView(Resource.Layout.Failure1);
                    EditText actuallyisthis = FindViewById<EditText>(Resource.Id.itis);
                    Button pressednext = FindViewById<Button>(Resource.Id.nextbutton);

                    actuallyisthis.TextChanged += delegate
                    {
                        actuallyis = actuallyisthis.Text;
                    };

                    exists = false;

                    for (int i = 0; i < results.Responses[0].LabelAnnotations.Count; i++)
                    {
                        if (actuallyis == results.Responses[0].LabelAnnotations[i].Description)
                        {
                            score = (((float)results.Responses[0].LabelAnnotations[i].Score) * 100);
                            exists = true;
                        }
                    }

                    pressednext.Click += delegate
                    {
                        if (exists == true)
                        {
                            SetContentView(Resource.Layout.Percent);
                            TextView percentis = FindViewById<TextView>(Resource.Id.titleline);
                            percentis.Text += score + "% chance that it was a(n) " + actuallyis;

                            Button gomain = FindViewById<Button>(Resource.Id.gotomain);
                            gomain.Click += delegate
                            {
                                SetContentView(Resource.Layout.Main);
                                if (IsThereAnAppToTakePictures() == true)
                                {
                                    CreateDirectoryForPictures();
                                    FindViewById<Button>(Resource.Id.launchCameraButton).Click += TakePicture;
                                }
                            };
                        }

                        if (exists == false)
                        {
                            SetContentView(Resource.Layout.Noclue);
                            TextView title = FindViewById<TextView>(Resource.Id.titleline);
                            Button pressedSO3 = FindViewById<Button>(Resource.Id.gobacktomain);

                            title.Text += actuallyis;

                            pressedSO3.Click += delegate
                            {
                                SetContentView(Resource.Layout.Main);
                                if (IsThereAnAppToTakePictures() == true)
                                {
                                    CreateDirectoryForPictures();
                                    FindViewById<Button>(Resource.Id.launchCameraButton).Click += TakePicture;
                                }
                            };
                        }
                    };
                };

                pressedSO1.Click += delegate
                {
                    SetContentView(Resource.Layout.Main);
                    if (IsThereAnAppToTakePictures() == true)
                    {
                        CreateDirectoryForPictures();
                        FindViewById<Button>(Resource.Id.launchCameraButton).Click += TakePicture;
                    }
                };
            }
        }

    }
}