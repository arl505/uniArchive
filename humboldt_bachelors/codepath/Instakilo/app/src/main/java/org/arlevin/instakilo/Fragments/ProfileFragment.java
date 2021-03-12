package org.arlevin.instakilo.Fragments;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.ImageButton;

import com.parse.FindCallback;
import com.parse.ParseException;
import com.parse.ParseQuery;
import com.parse.ParseUser;

import org.arlevin.instakilo.Activities.MainActivity;
import org.arlevin.instakilo.Models.Post;
import org.arlevin.instakilo.R;

import java.util.List;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

public class ProfileFragment extends PostsFragment {

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);

        ImageButton ibHome = view.findViewById(R.id.ibHome);
        ImageButton ibExplore = view.findViewById(R.id.ibExplore);
        ImageButton ibCompose = view.findViewById(R.id.ibCompose);
        ImageButton ibNotifications = view.findViewById(R.id.ibNotifications);
        ImageButton ibProfile = view.findViewById(R.id.ibProfile);

        ibHome.setImageResource(R.drawable.home_icon);
        ibExplore.setImageResource(R.drawable.magnifying_glass_icon);
        ibCompose.setImageResource(R.drawable.compose_icon);
        ibNotifications.setImageResource(R.drawable.heart_icon);
        ibProfile.setImageResource(R.drawable.ic_person_black_24dp);

        MainActivity.current_fragment = "profile";

    }

    @Override
    protected void queryPosts() {
        ParseQuery<Post> postQuery = new ParseQuery<Post>(Post.class);
        postQuery.include(Post.KEY_USER);
        postQuery.setLimit(20);
        postQuery.whereEqualTo(Post.KEY_USER, ParseUser.getCurrentUser());
        postQuery.addDescendingOrder("createdAt");
        postQuery.findInBackground(new FindCallback<Post>() {
            @Override
            public void done(List<Post> posts, ParseException e) {
                if (e != null) {
                    Log.e("PostsFragment", "Error with query");
                    return;
                }
                adapter.clear();
                mPosts.addAll(posts);
                adapter.notifyDataSetChanged();
                swipeContainer.setRefreshing(false);
                for (int i = 0; i < posts.size(); i++) {
                    Post post = posts.get(i);
                    Log.d("PostsFragment", "Post: " + post.getDescription() + ", username: " + post.getUser().getUsername());
                }
            }
        });
    }
}
