package org.arlevin.flicks.adapters;

import android.content.Context;
import android.content.Intent;
import android.support.annotation.NonNull;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.RelativeLayout;
import android.widget.TextView;

import com.bumptech.glide.Priority;
import com.bumptech.glide.load.resource.bitmap.RoundedCorners;

import org.arlevin.flicks.DetailActivity;
import org.arlevin.flicks.GlideApp;
import org.arlevin.flicks.R;
import org.arlevin.flicks.models.Movie;
import org.parceler.Parcels;

import java.util.List;

public class MoviesAdapter extends RecyclerView.Adapter<MoviesAdapter.ViewHolder> {

    Context context;
    List<Movie> movies;

    public MoviesAdapter(Context context, List<Movie> movies) {
        this.context = context;
        this.movies = movies;


    }

    @NonNull
    @Override
    public ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(context).inflate(R.layout.item_movie, parent, false);
        return new ViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull ViewHolder holder, int position) {
     Movie movie = movies.get(position);
     holder.bind(movie);
    }

    @Override
    public int getItemCount() {
        return movies.size();
    }

    class ViewHolder extends RecyclerView.ViewHolder {

        TextView tvTitle;
        TextView tvOverview;
        ImageView ivPoster;
        RelativeLayout container;

        public ViewHolder(View itemView) {
            super(itemView);

            tvTitle = itemView.findViewById(R.id.tvTitleD);
            tvOverview = itemView.findViewById(R.id.tvOverview);
            ivPoster = itemView.findViewById(R.id.ivPoster);
            container =itemView.findViewById(R.id.container);
            }

        public void bind(final Movie movie) {
            tvTitle.setText(movie.getTitle());
            tvOverview.setText(movie.getOverview());

           // Glide.with(context).load(movie.getPosterPath(context)).placeholder(R.drawable.placeholder).into(ivPoster);

            GlideApp.with(context)
                    .load(movie.getPosterPath(context))
                    .transform(new RoundedCorners(15))
                    .placeholder(R.drawable.placeholder)
                    .priority(Priority.HIGH)
                    .into(ivPoster);

            container.setOnClickListener(new View.OnClickListener(){
                @Override
                public void onClick(View v) {
                    Intent i = new Intent(context, DetailActivity.class);
                    i.putExtra("movie", Parcels.wrap(movie));
                    context.startActivity(i);

                }
            });
        }
    }

}
