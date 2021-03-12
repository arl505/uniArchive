package org.arlevin.instakilo.Fragments;

import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.net.Uri;
import android.os.Bundle;
import android.os.Environment;
import android.provider.MediaStore;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.Toast;

import com.parse.ParseException;
import com.parse.ParseFile;
import com.parse.ParseUser;
import com.parse.SaveCallback;

import org.arlevin.instakilo.Activities.MainActivity;
import org.arlevin.instakilo.Models.Post;
import org.arlevin.instakilo.R;

import java.io.File;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.core.content.FileProvider;
import androidx.fragment.app.Fragment;

import static android.app.Activity.RESULT_OK;


public class ComposeFragment extends Fragment {

    EditText etDescription;
    Button btnTakePhoto;
    Button btnPost;
    ImageView ivPostImage;
    public String photoFileName = "photo.jpg";
    private File photoFile;

    public final static int CAPTURE_IMAGE_ACTIVITY_REQUEST_CODE = 1034;

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        return inflater.inflate(R.layout.fragment_compose, container, false);
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);

        etDescription = view.findViewById(R.id.etDescription);
        btnPost = view.findViewById(R.id.btnPost);
        btnTakePhoto = view.findViewById(R.id.btnTakePhoto);
        ivPostImage = view.findViewById(R.id.ivPostImage);
        btnPost.setClickable(false);

        btnTakePhoto.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                launchCamera(view);
            }
        });

        btnPost.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                savePost(view);
            }
        });

        ImageButton ibHome = view.findViewById(R.id.ibHome);
        ImageButton ibExplore = view.findViewById(R.id.ibExplore);
        ImageButton ibCompose = view.findViewById(R.id.ibCompose);
        ImageButton ibNotifications = view.findViewById(R.id.ibNotifications);
        ImageButton ibProfile = view.findViewById(R.id.ibProfile);

        ibHome.setImageResource(R.drawable.home_icon);
        ibExplore.setImageResource(R.drawable.magnifying_glass_icon);
        ibCompose.setImageResource(R.drawable.compose_icon_active);
        ibNotifications.setImageResource(R.drawable.heart_icon);
        ibProfile.setImageResource(R.drawable.ic_person_outline_black_24dp);

        MainActivity.current_fragment = "compose";


    }

    public void savePost(View view){
        if(photoFile != null && ivPostImage.getImageAlpha() != 0) {
            String description = etDescription.getText().toString();
            ParseUser user = ParseUser.getCurrentUser();

            Post post = new Post();
            post.setDescription(description);
            post.setUser(user);
            post.setImage(new ParseFile(photoFile));
            post.saveInBackground(new SaveCallback() {
                @Override
                public void done(ParseException e) {
                    if (e != null) {
                        return;
                    }
                    etDescription.setText("");
                    ivPostImage.setImageResource(0);
                    btnPost.setClickable(false);
                }
            });
        }
    }

    public void launchCamera(View view){
        Intent intent = new Intent(MediaStore.ACTION_IMAGE_CAPTURE);
        // Create a File reference to access to future access
        photoFile = getPhotoFileUri(photoFileName);

        // wrap File object into a content provider
        // required for API >= 24
        // See https://guides.codepath.com/android/Sharing-Content-with-Intents#sharing-files-with-api-24-or-higher
        Uri fileProvider = FileProvider.getUriForFile(getContext(), "com.codepath.fileprovider", photoFile);
        intent.putExtra(MediaStore.EXTRA_OUTPUT, fileProvider);

        // If you call startActivityForResult() using an intent that no app can handle, your app will crash.
        // So as long as the result is not null, it's safe to use the intent.
        if (intent.resolveActivity(getContext().getPackageManager()) != null) {
            // Start the image capture intent to take photo
            startActivityForResult(intent, CAPTURE_IMAGE_ACTIVITY_REQUEST_CODE);
        }
    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent data){
        if (requestCode == CAPTURE_IMAGE_ACTIVITY_REQUEST_CODE) {
            if (resultCode == RESULT_OK) {
                // by this point we have the camera photo on disk
                Bitmap takenImage = BitmapFactory.decodeFile(photoFile.getAbsolutePath());
                // RESIZE BITMAP, see section below
                // Load the taken image into a preview
                ivPostImage.setImageBitmap(takenImage);
                btnPost.setClickable(true);
            } else { // Result was a failure
                Toast.makeText(getContext(), "Picture wasn't taken!", Toast.LENGTH_SHORT).show();
            }
        }
    }

    // Returns the File for a photo stored on disk given the fileName
    public File getPhotoFileUri(String fileName) {
        // Get safe storage directory for photos
        // Use `getExternalFilesDir` on Context to access package-specific directories.
        // This way, we don't need to request external read/write runtime permissions.
        File mediaStorageDir = new File(getContext().getExternalFilesDir(Environment.DIRECTORY_PICTURES), "MainActivity");

        // Create the storage directory if it does not exist
        if (!mediaStorageDir.exists() && !mediaStorageDir.mkdirs()){
            Log.d("MainActivity", "failed to create directory");
        }

        // Return the file target for the photo based on filename
        File file = new File(mediaStorageDir.getPath() + File.separator + fileName);

        return file;
    }




}