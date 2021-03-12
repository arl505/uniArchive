package org.arlevin.flicks.models;

import android.content.Context;
import android.content.res.Configuration;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;
import org.parceler.Parcel;

import java.util.ArrayList;
import java.util.List;

@Parcel
public class Movie {

    String posterPath;
    String title;
    String overview;
    String backdropPath;
    Float voteAverage;
    int movieid;
    String releaseDate;
    Double popularityRating;

    public Movie() {
    }

    public Movie(JSONObject jsonObject) throws JSONException {


        posterPath = jsonObject.getString("poster_path");
        title = jsonObject.getString("title");
        overview = jsonObject.getString("overview");
        backdropPath = jsonObject.getString("backdrop_path");
        voteAverage =  Float.parseFloat((jsonObject.getString("vote_average")));
        movieid = jsonObject.getInt("id");
        releaseDate = jsonObject.getString("release_date");
        popularityRating = jsonObject.getDouble("popularity");
    }

    public static List<Movie> fromJsonArray(JSONArray movieJsonArray) throws JSONException {
        List<Movie> movies = new ArrayList<>();
        for(int i = 0; i < movieJsonArray.length(); i++)
        {
            movies.add(new Movie(movieJsonArray.getJSONObject(i)));
        }

        return movies;
    }

    public String getPosterPath(Context context) {
       if (context.getResources().getConfiguration().orientation == Configuration.ORIENTATION_PORTRAIT){
           return String.format("https://image.tmdb.org/t/p/w342/%s", posterPath);
       }
            return String.format("https://image.tmdb.org/t/p/w342/%s", backdropPath);
    }

    public String getTitle() {
        return title;
    }

    public String getOverview() {
        return overview;
    }

    public Float getVoteAverage() {
        return voteAverage;
    }

    public int getMovieid() {
        return movieid;
    }

    public String getReleaseDate() {
        return releaseDate;
    }

    public Double getPopularityRating() {
        return popularityRating;
    }
}
