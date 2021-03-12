package com.codepath.debuggingchallenges.activities;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.widget.ListView;

import com.codepath.debuggingchallenges.R;
import com.codepath.debuggingchallenges.adapters.MoviesAdapter;
import com.codepath.debuggingchallenges.models.Movie;
import com.loopj.android.http.AsyncHttpClient;
import com.loopj.android.http.JsonHttpResponseHandler;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;

import cz.msebera.android.httpclient.Header;

public class MoviesActivity extends AppCompatActivity {

    private static final String API_KEY = "a07e22bc18f5cb106bfe4cc1f83ad8ed";

    ListView lvMovies;
    MoviesAdapter adapter;
    ArrayList<Movie> movies;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_movies);
        lvMovies = (ListView) findViewById(R.id.lvMovies);

        // Create the adapter to convert the array to views
        movies = new ArrayList<>();
        MoviesAdapter adapter = new MoviesAdapter(this, movies);

        // Attach the adapter to a ListView
        lvMovies.setAdapter(adapter);

        fetchMovies(adapter);
    }


    private void fetchMovies(final MoviesAdapter adapter) {
        String url = "https://api.themoviedb.org/3/movie/now_playing?api_key=" + API_KEY;
        AsyncHttpClient client = new AsyncHttpClient();
        client.get(url, new JsonHttpResponseHandler() {
            @Override
            public void onFailure(int statusCode, Header[] headers, Throwable throwable, JSONObject errorResponse) {
                super.onFailure(statusCode, headers, throwable, errorResponse);
            }
            @Override
            public void onSuccess(int statusCode, Header[] headers, JSONObject response) {
                try {
                    JSONArray moviesJson = response.getJSONArray("results");
                    movies.addAll(Movie.fromJSONArray(moviesJson));
                    adapter.notifyDataSetChanged();
                } catch (JSONException e) {
                    e.printStackTrace();
                }
            }
        });
    }
}
