package com.codepath.apps.restclienttemplate.activities;

import android.content.Intent;
import android.os.Bundle;
import android.support.v4.widget.SwipeRefreshLayout;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.DividerItemDecoration;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.View;
import android.widget.Toast;

import com.codepath.apps.restclienttemplate.R;
import com.codepath.apps.restclienttemplate.TweetaApp;
import com.codepath.apps.restclienttemplate.TweetaClient;
import com.codepath.apps.restclienttemplate.adapters.TweetsAdapter;
import com.codepath.apps.restclienttemplate.models.Tweet;
import com.loopj.android.http.JsonHttpResponseHandler;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;

import cz.msebera.android.httpclient.Header;

public class TimelineActivity extends AppCompatActivity {

    private TweetaClient client;
    RecyclerView rvTweets;
    private TweetsAdapter adapter;
    private List<Tweet> tweets;
    private SwipeRefreshLayout swipeContainer;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.activity_timeline);

        client = TweetaApp.getRestClient(this);

        rvTweets = findViewById(R.id.rvTweets);

        swipeContainer = (SwipeRefreshLayout) findViewById(R.id.swipeContainer);

        swipeContainer.setOnRefreshListener(new SwipeRefreshLayout.OnRefreshListener() {
            @Override
            public void onRefresh() {
                fetchTimelineAsync(0);
            }
        });

        swipeContainer.setColorSchemeResources(android.R.color.holo_blue_bright,
                android.R.color.holo_green_light,
                android.R.color.holo_orange_light,
                android.R.color.holo_red_light);

        tweets = new ArrayList<>();
        adapter = new TweetsAdapter(this, tweets);
        LinearLayoutManager mLayoutManager = new LinearLayoutManager(this);
        rvTweets.setLayoutManager(mLayoutManager);
        rvTweets.setAdapter(adapter);

        Toolbar toolbar = (Toolbar) findViewById(R.id.tb);
        setSupportActionBar(toolbar);

        DividerItemDecoration mDividerItemDecoration = new DividerItemDecoration(rvTweets.getContext(),
                mLayoutManager.getOrientation());
        rvTweets.addItemDecoration(mDividerItemDecoration);

        populateHomeTimeline();
    }

    private void populateHomeTimeline() {
        client.getHomeTimeline(new JsonHttpResponseHandler(){
            @Override
            public void onSuccess(int statusCode, Header[] headers, JSONArray response) {
                for (int i = 0; i < response.length(); i++){
                    try {
                        JSONObject jsonTweetObjet = response.getJSONObject(i);
                        Tweet tweet = Tweet.fromJSON(jsonTweetObjet);
                        tweets.add(tweet);
                        adapter.notifyItemInserted(tweets.size());
                    } catch (JSONException e) {
                        e.printStackTrace();
                    }
                }
            }

            @Override
            public void onFailure(int statusCode, Header[] headers, Throwable throwable, JSONObject errorResponse) {
                Log.e("TweetaClient", errorResponse.toString());
            }

            @Override
            public void onFailure(int statusCode, Header[] headers, String responseString, Throwable throwable) {
                Log.e("TweetaClient", responseString);
            }
        });
    }

    public void fetchTimelineAsync(int page) {
        // Send the network request to fetch the updated data
        // `client` here is an instance of Android Async HTTP
        // getHomeTimeline is an example endpoint.
        adapter.clear();
        populateHomeTimeline();
        swipeContainer.setRefreshing(false);
    }



    public void logout(View view)
    {
        client.clearAccessToken();
        Intent i = new Intent(this, LoginActivity.class);
        startActivity(i);
    }

    public void compose(View view)
    {
        Toast.makeText(this,"To be implemented", Toast.LENGTH_SHORT).show();
    }
}
