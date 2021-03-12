package org.arlevin.instakilo.Fragments;

import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageButton;

import com.parse.FindCallback;
import com.parse.ParseException;
import com.parse.ParseQuery;

import org.arlevin.instakilo.Activities.MainActivity;
import org.arlevin.instakilo.Models.Post;
import org.arlevin.instakilo.PostsAdapter;
import org.arlevin.instakilo.R;

import java.util.ArrayList;
import java.util.List;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;
import androidx.swiperefreshlayout.widget.SwipeRefreshLayout;

public class PostsFragment extends Fragment {

    static protected RecyclerView rvPosts;
    protected PostsAdapter adapter;
    protected List<Post> mPosts;
    protected SwipeRefreshLayout swipeContainer;

    public static void scrollToTop() {
        rvPosts.smoothScrollToPosition(0);
    }


    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        return inflater.inflate(R.layout.fragment_posts, container, false);
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
         rvPosts = view.findViewById(R.id.rvPosts);

         mPosts = new ArrayList<>();
         adapter = new PostsAdapter(getContext(), mPosts);
         rvPosts.setAdapter(adapter);
         rvPosts.setLayoutManager(new LinearLayoutManager(getContext()));
         swipeContainer = (SwipeRefreshLayout) view.findViewById(R.id.swipeContainer);
         swipeContainer.setOnRefreshListener(new SwipeRefreshLayout.OnRefreshListener() {
            @Override
            public void onRefresh() {
                // Your code to refresh the list here.
                // Make sure you call swipeContainer.setRefreshing(false)
                // once the network request has completed successfully.
                queryPosts();
            }
        });
        swipeContainer.setColorSchemeResources(android.R.color.holo_blue_bright,
                android.R.color.holo_green_light,
                android.R.color.holo_orange_light,
                android.R.color.holo_red_light);


        ImageButton ibHome = view.findViewById(R.id.ibHome);
        ImageButton ibExplore = view.findViewById(R.id.ibExplore);
        ImageButton ibCompose = view.findViewById(R.id.ibCompose);
        ImageButton ibNotifications = view.findViewById(R.id.ibNotifications);
        ImageButton ibProfile = view.findViewById(R.id.ibProfile);

        ibHome.setImageResource(R.drawable.home_icon_active);
        ibExplore.setImageResource(R.drawable.magnifying_glass_icon);
        ibCompose.setImageResource(R.drawable.compose_icon);
        ibNotifications.setImageResource(R.drawable.heart_icon);
        ibProfile.setImageResource(R.drawable.ic_person_outline_black_24dp);

        MainActivity.current_fragment = "home";

        queryPosts();
    }

    protected void queryPosts(){
        ParseQuery<Post> postQuery = new ParseQuery<Post>(Post.class);
        postQuery.include(Post.KEY_USER);
        postQuery.setLimit(20);
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
                for(int i=0; i<posts.size();i++){
                    Post post = posts.get(i);
                    Log.d("PostsFragment", "Post: " + post.getDescription()+ ", username: " + post.getUser().getUsername());
                }
            }
        });
    }
}
