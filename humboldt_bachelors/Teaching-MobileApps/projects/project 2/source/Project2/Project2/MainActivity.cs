using Android.App;
using Android.Widget;
using Android.OS;
using Android.Content;
using System;
using System.Collections.Generic;
using Android.Content.PM;
using Android.Provider;

namespace Project2
{
    [Activity(Label = "Image Manipulator", MainLauncher = true, Icon = "@mipmap/icon")]
    public class MainActivity : Activity
    {
        /// <summary>
        /// Used to track the file that we're manipulating between functions
        /// </summary>
        public static Java.IO.File _file;
        Boolean iscamerapic;

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
                    Android.OS.Environment.DirectoryPictures), "CameraExample");
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
        Android.Graphics.Bitmap RemoveRed(Android.Graphics.Bitmap mymap)
        {
            for (int i = 0; i < mymap.Width; i++)
            {
                for (int j = 0; j < mymap.Height; j++)
                {
                    int p = mymap.GetPixel(i, j);
                    Android.Graphics.Color c = new Android.Graphics.Color(p);
                    c.R = 0;
                    mymap.SetPixel(i, j, c);
                }
            }
            return mymap;
        }

        Android.Graphics.Bitmap RemoveGreen(Android.Graphics.Bitmap mymap)
        {
            for (int i = 0; i < mymap.Width; i++)
            {
                for (int j = 0; j < mymap.Height; j++)
                {
                    int p = mymap.GetPixel(i, j);
                    Android.Graphics.Color c = new Android.Graphics.Color(p);
                    c.G = 0;
                    mymap.SetPixel(i, j, c);
                }
            }
            return mymap;
        }

        Android.Graphics.Bitmap RemoveBlue(Android.Graphics.Bitmap mymap)
        {
            for (int i = 0; i < mymap.Width; i++)
            {
                for (int j = 0; j < mymap.Height; j++)
                {
                    int p = mymap.GetPixel(i, j);
                    Android.Graphics.Color c = new Android.Graphics.Color(p);
                    c.B = 0;
                    mymap.SetPixel(i, j, c);
                }
            }
            return mymap;
        }

        Android.Graphics.Bitmap NegateRed(Android.Graphics.Bitmap mymap)
        {
            for (int i = 0; i < mymap.Width; i++)
            {
                for (int j = 0; j < mymap.Height; j++)
                {
                    int p = mymap.GetPixel(i, j);
                    Android.Graphics.Color c = new Android.Graphics.Color(p);
                    c.R = (byte)(255 - c.R);
                    mymap.SetPixel(i, j, c);
                }
            }
            return mymap;
        }

        Android.Graphics.Bitmap NegateGreen(Android.Graphics.Bitmap mymap)
        {
            for (int i = 0; i < mymap.Width; i++)
            {
                for (int j = 0; j < mymap.Height; j++)
                {
                    int p = mymap.GetPixel(i, j);
                    Android.Graphics.Color c = new Android.Graphics.Color(p);
                    c.G = (byte)(255 - c.G);
                    mymap.SetPixel(i, j, c);
                }
            }
            return mymap;
        }

        Android.Graphics.Bitmap NegateBlue(Android.Graphics.Bitmap mymap)
        {
            for (int i = 0; i < mymap.Width; i++)
            {
                for (int j = 0; j < mymap.Height; j++)
                {
                    int p = mymap.GetPixel(i, j);
                    Android.Graphics.Color c = new Android.Graphics.Color(p);
                    c.B = (byte)(255 - c.B);
                    mymap.SetPixel(i, j, c);
                }
            }
            return mymap;
        }

        Android.Graphics.Bitmap AddRandomNoise(Android.Graphics.Bitmap mymap)
        {
            Random r = new Random();
            for (int i = 0; i < mymap.Width; i++)
            {
                for (int j = 0; j < mymap.Height; j++)
                {
                    int p = mymap.GetPixel(i, j);
                    Android.Graphics.Color c = new Android.Graphics.Color(p);
                    //Random r = new Random();
                    int randnum = r.Next(-10, 11);
                    int r_temp = c.R;
                    int g_temp = c.G;
                    int b_temp = c.B;

                    r_temp = r_temp + randnum;
                    g_temp = g_temp + randnum;
                    b_temp = b_temp + randnum;

                    if(r_temp > 255)
                    {
                        c.R = 255;
                    }

                    else if(r_temp < 0)
                    {
                        c.R = 0;
                    }

                    else
                    {
                        c.R = Convert.ToByte(r_temp);
                    }

                    if (g_temp > 255)
                    {
                        c.G = 255;
                    }

                    else if (g_temp < 0)
                    {
                        c.G = 0;
                    }

                    else
                    {
                        c.G = Convert.ToByte(g_temp);
                    }

                    if (b_temp > 255)
                    {
                        c.B = 255;
                    }

                    else if (b_temp < 0)
                    {
                        c.B = 0;
                    }

                    else
                    {
                        c.B = Convert.ToByte(b_temp);
                    }

                    mymap.SetPixel(i, j, c);
                }
            }
            return mymap;
        }

        Android.Graphics.Bitmap HighContrast(Android.Graphics.Bitmap mymap)
        {
            for (int i = 0; i < mymap.Width; i++)
            {
                for (int j = 0; j < mymap.Height; j++)
                {
                    int p = mymap.GetPixel(i, j);
                    Android.Graphics.Color c = new Android.Graphics.Color(p);

                    if (c.R > (255 / 2))
                    {
                        c.R = 255;
                    }
                    else
                    {
                        c.R = 0;
                    }

                    if (c.G > (255 / 2))
                    {
                        c.G = 255;
                    }
                    else
                    {
                        c.G = 0;
                    }

                    if (c.B > (255 / 2))
                    {
                        c.B = 255;
                    }
                    else
                    {
                        c.B = 0;
                    }

                    mymap.SetPixel(i, j, c);
                }
            }
            return mymap;
        }

        Android.Graphics.Bitmap Grayscale(Android.Graphics.Bitmap mymap)
        {
            for (int i = 0; i < mymap.Width; i++)
            {
                for (int j = 0; j < mymap.Height; j++)
                {
                    int p = mymap.GetPixel(i, j);
                    Android.Graphics.Color c = new Android.Graphics.Color(p);
                    int sum;
                    sum = (byte)(c.R + c.G + c.B);
                    sum = sum / 3;
                    c.R = (byte)(sum);
                    c.G = (byte)(sum);
                    c.B = (byte)(sum);
                    mymap.SetPixel(i, j, c);
                }
            }
            return mymap;
        }

        Android.Graphics.Bitmap Woodgrain(Android.Graphics.Bitmap mymap)
        { 
            for (int i = 0; i < mymap.Width; i++)
            {
                for (int j = 0; j < mymap.Height; j++)
                {
                    int p = mymap.GetPixel(i, j);
                    Android.Graphics.Color c = new Android.Graphics.Color(p);
                    Random r = new Random();
                    int randnum = r.Next(-20, 21);
                    int r_temp = c.R;
                    int g_temp = c.G;
                    int b_temp = c.B;

                    r_temp = r_temp + randnum;
                    g_temp = g_temp + randnum;
                    b_temp = b_temp + randnum;

                    if (r_temp > 255)
                    {
                        c.R = 255;
                    }

                    else if (r_temp < 0)
                    {
                        c.R = 0;
                    }

                    else
                    {
                        c.R = Convert.ToByte(r_temp);
                    }

                    if (g_temp > 255)
                    {
                        c.G = 255;
                    }

                    else if (g_temp < 0)
                    {
                        c.G = 0;
                    }

                    else
                    {
                        c.G = Convert.ToByte(g_temp);
                    }

                    if (b_temp > 255)
                    {
                        c.B = 255;
                    }

                    else if (b_temp < 0)
                    {
                        c.B = 0;
                    }

                    else
                    {
                        c.B = Convert.ToByte(b_temp);
                    }

                    mymap.SetPixel(i, j, c);
                }
            }
            return mymap;
        }

        protected override void OnActivityResult(int requestCode, Result resultCode, Intent data)
        {
            Android.Graphics.Bitmap bitmap = null;
            Android.Graphics.Bitmap copyBitmap = null ;
            bool original = true;
            ImageView imageView = null;

            base.OnActivityResult(requestCode, resultCode, data);
            SetContentView(Resource.Layout.Effect);

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
            else
            {
                if (resultCode == Result.Ok)
                {
                    SetContentView(Resource.Layout.Effect);
                    imageView = FindViewById<ImageView>(Resource.Id.takenPictureImageView);
                    imageView.SetImageURI(data.Data);

                    int height = Resources.DisplayMetrics.HeightPixels;
                    int width = imageView.Height;
                }
            }
            if (bitmap != null)
            {
                copyBitmap = bitmap.Copy(Android.Graphics.Bitmap.Config.Argb8888, true);
                imageView.SetImageBitmap(copyBitmap);
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
                Button pressedRR = FindViewById<Button>(Resource.Id.RemoveRedButton);
                Button pressedRG = FindViewById<Button>(Resource.Id.RemoveGreenButton);
                Button pressedRB = FindViewById<Button>(Resource.Id.RemoveBlueButton);
                Button pressedNR = FindViewById<Button>(Resource.Id.NegateRedButton);
                Button pressedNG = FindViewById<Button>(Resource.Id.NegateGreenButton);
                Button pressedNB = FindViewById<Button>(Resource.Id.NegateBlueButton);
                Button pressedARN = FindViewById<Button>(Resource.Id.AddRandomNoiseButton);
                Button pressedHC = FindViewById<Button>(Resource.Id.HighContrastButton);
                Button pressedG = FindViewById<Button>(Resource.Id.GrayscaleButton);
                Button pressedW = FindViewById<Button>(Resource.Id.WoodgrainButton);
                Button pressedCE = FindViewById<Button>(Resource.Id.ClearEffectsButton);
                Button pressedTNP = FindViewById<Button>(Resource.Id.NewPhoto);

                
            if (copyBitmap != null)
            {


                pressedRR.Click += delegate
                {
                    copyBitmap = RemoveRed(copyBitmap);
                    imageView.SetImageBitmap(copyBitmap);
                    original = false;
                };

                pressedRG.Click += delegate
                    {
                        copyBitmap = RemoveGreen(copyBitmap);
                        imageView.SetImageBitmap(copyBitmap);
                        original = false;
                    };

                pressedRB.Click += delegate
                {
                    copyBitmap = RemoveBlue(copyBitmap);
                    imageView.SetImageBitmap(copyBitmap);
                    original = false;
                };

                pressedNR.Click += delegate
                {
                    copyBitmap = NegateRed(copyBitmap);
                    imageView.SetImageBitmap(copyBitmap);
                    original = false;
                };

                pressedNG.Click += delegate
                {
                    copyBitmap = NegateGreen(copyBitmap);
                    imageView.SetImageBitmap(copyBitmap);
                    original = false;
                };

                pressedNB.Click += delegate
                {
                    copyBitmap = NegateBlue(copyBitmap);
                    imageView.SetImageBitmap(copyBitmap);
                    original = false;
                };

                pressedARN.Click += delegate
                {
                    copyBitmap = AddRandomNoise(copyBitmap);
                    imageView.SetImageBitmap(copyBitmap);
                    original = false;
                };

                pressedHC.Click += delegate
                {
                    copyBitmap = HighContrast(copyBitmap);
                    imageView.SetImageBitmap(copyBitmap);
                    original = false;
                };

                pressedG.Click += delegate
                {
                    copyBitmap = Grayscale(copyBitmap);
                    imageView.SetImageBitmap(copyBitmap);
                    original = false;
                };

                pressedW.Click += delegate
                {
                    copyBitmap = Woodgrain(copyBitmap);
                    imageView.SetImageBitmap(copyBitmap);
                    original = false;
                };

                pressedCE.Click += delegate
                {
                    if (original == false)
                    {
                        copyBitmap = bitmap.Copy(Android.Graphics.Bitmap.Config.Argb8888, true);
                        imageView.SetImageBitmap(copyBitmap);
                        original = true;
                    }
                    else if(original)
                    {
                        Toast.MakeText(this, "No effects", ToastLength.Short).Show();
                    }

                };

                pressedTNP.Click += delegate
                {
                    SetContentView(Resource.Layout.Main);
                    if (IsThereAnAppToTakePictures() == true)
                    {
                        CreateDirectoryForPictures();
                        FindViewById<Button>(Resource.Id.launchCameraButton).Click += TakePicture;
                    }
                };
            }
            // Dispose of the Java side bitmap.
            System.GC.Collect();
        }
    }
}


