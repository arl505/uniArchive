package org.arlevin.flicks;

import android.os.Bundle;
import android.widget.RatingBar;
import android.widget.TextView;

import com.google.android.youtube.player.YouTubeBaseActivity;
import com.google.android.youtube.player.YouTubeInitializationResult;
import com.google.android.youtube.player.YouTubePlayer;
import com.google.android.youtube.player.YouTubePlayerView;
import com.loopj.android.http.AsyncHttpClient;
import com.loopj.android.http.JsonHttpResponseHandler;

import org.arlevin.flicks.models.Movie;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;
import org.parceler.Parcels;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

import cz.msebera.android.httpclient.Header;

public class DetailActivity extends YouTubeBaseActivity {

    private static final String YOUTUBE_API_KEY = "AIzaSyCgALVYMtvjcS480dt1r6baD8mAIH15b00";
    private static final String TRAILERS_API = "https://api.themoviedb.org/3/movie/%d/videos?api_key=a07e22bc18f5cb106bfe4cc1f83ad8ed";

     TextView tvTitleD;
     TextView tvOverviewD;
     RatingBar ratingBar;
     Movie movie;
     YouTubePlayerView youTubePlayerView;
     TextView tvReleaseDate;
     TextView tvPopularityRating;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_detail);

        tvTitleD = findViewById(R.id.tvTitleD);
        tvOverviewD = findViewById(R.id.tvOverviewD);
        ratingBar = findViewById(R.id.ratingBar);
        youTubePlayerView  = findViewById(R.id.player);
        tvReleaseDate = findViewById(R.id.tvReleaseDate);
        tvPopularityRating = findViewById(R.id.tvPopularityRating);

        movie = (Movie)Parcels.unwrap(getIntent().getParcelableExtra("movie"));

        String releaseDateString = movie.getReleaseDate();
        SimpleDateFormat myDateFormat = new SimpleDateFormat("yyyy-MM-dd");
        Date releaseDate = null;
        try {
            releaseDate = myDateFormat.parse(releaseDateString);
        } catch (ParseException e) {
            e.printStackTrace();
        }
        SimpleDateFormat outputFormat = new SimpleDateFormat("MMMM dd, yyyy");

        String rating = movie.getPopularityRating().toString();
        tvPopularityRating.setText("Popularity Rating: "+rating);
        ratingBar.setRating(movie.getVoteAverage());
        tvTitleD.setText(movie.getTitle());
        tvOverviewD.setText(movie.getOverview());
        tvReleaseDate.setText(String.format("Released: %s", outputFormat.format(releaseDate)));

        AsyncHttpClient client = new AsyncHttpClient();
        client.get(String.format(TRAILERS_API, movie.getMovieid()), new JsonHttpResponseHandler(){
            @Override
            public void onSuccess(int statusCode, Header[] headers, JSONObject response) {
                try {
                    JSONArray results = response.getJSONArray("results");
                    if (results.length() == 0){
                        return;
                    }
                    JSONObject movieTrailer = results.getJSONObject(0);
                    String thing = movieTrailer.getString("site");
                    int i =0;
                    if(!movieTrailer.getString("site").equals("YouTube"))
                    {
                        return;
                    }
                    String youtubekey = movieTrailer.getString("key");
               initalizeYoutube(youtubekey, movie.getVoteAverage());
                } catch (JSONException e) {
                    e.printStackTrace();
                }
            }

            @Override
            public void onFailure(int statusCode, Header[] headers, Throwable throwable, JSONObject errorResponse) {
                super.onFailure(statusCode, headers, throwable, errorResponse);
            }
        });

    }

    private void initalizeYoutube(final String youtubekey, final Float voteAverage) {
        youTubePlayerView.initialize(YOUTUBE_API_KEY, new YouTubePlayer.OnInitializedListener() {
            @Override
            public void onInitializationSuccess(YouTubePlayer.Provider provider, YouTubePlayer youTubePlayer, boolean b) {
                if(voteAverage < 7) {
                    youTubePlayer.cueVideo(youtubekey);
                }
                else {
                    youTubePlayer.loadVideo(youtubekey);
                }

            }

            @Override
            public void onInitializationFailure(YouTubePlayer.Provider provider, YouTubeInitializationResult youTubeInitializationResult) {

            }
        });
    }
}
