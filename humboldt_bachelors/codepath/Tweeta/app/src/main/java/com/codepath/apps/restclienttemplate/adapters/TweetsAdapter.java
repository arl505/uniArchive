package com.codepath.apps.restclienttemplate.adapters;

import android.content.Context;
import android.content.Intent;
import android.support.annotation.NonNull;
import android.support.v7.widget.RecyclerView;
import android.text.format.DateUtils;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.RelativeLayout;
import android.widget.TextView;

import com.bumptech.glide.Glide;
import com.codepath.apps.restclienttemplate.R;
import com.codepath.apps.restclienttemplate.activities.TweetDetailActivity;
import com.codepath.apps.restclienttemplate.models.Tweet;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.List;
import java.util.Locale;

public class TweetsAdapter extends RecyclerView.Adapter<TweetsAdapter.ViewHolder> {

    private Context context;
    private List<Tweet> tweets;

    public TweetsAdapter(Context context, List<Tweet> tweets) {
        this.context = context;
        this.tweets = tweets;
    }

    public void clear() {
        tweets.clear();
        notifyDataSetChanged();
    }

    public void addAll(List<Tweet> list) {
        tweets.addAll(list);
        notifyDataSetChanged();
    }


    @NonNull
    @Override
    public ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(context).inflate(R.layout.item_tweet, parent, false);
        return new ViewHolder(view);

    }

    @Override
    public void onBindViewHolder(@NonNull ViewHolder holder, int position) {
        final Tweet tweet = tweets.get(position);
        String createdAt = tweet.createdAt;
        String newString;
        newString = toRelativeDateString(createdAt);

        holder.tvBody.setText(tweet.body);
        holder.tvScreenName.setText(tweet.user.screenName);
        Glide.with(context)
                .load(tweet.user.profileImageUrl)
                .into(holder.ivProfileImage);
        holder.tvCreatedWhen.setText(newString);
        holder.tlContainer.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent i = new Intent(context, TweetDetailActivity.class);
                //i.putExtra("tweet",tweet);
                i.putExtra("body",tweet.body);
                context.startActivity(i);
            }
        });

    }

    @Override
    public int getItemCount() {
        return tweets.size();
    }

    public class ViewHolder extends RecyclerView.ViewHolder {

        public ImageView ivProfileImage;
        public TextView tvScreenName;
        public TextView tvBody;
        public TextView tvCreatedWhen;
        public RelativeLayout tlContainer;


        public ViewHolder(View itemView) {
            super(itemView);
            ivProfileImage = itemView.findViewById(R.id.ivProfileImage);
            tvScreenName = itemView.findViewById(R.id.tvScreenName);
            tvBody = itemView.findViewById(R.id.tvBody);
            tvCreatedWhen = itemView.findViewById(R.id.tvCreatedWhen);
            tlContainer = itemView.findViewById(R.id.tlContainer);
        }
    }

    private String toRelativeDateString(String rawJsonDate) {


        String twitterFormat = "EEE MMM dd HH:mm:ss ZZZZZ yyyy";
        SimpleDateFormat sf = new SimpleDateFormat(twitterFormat, Locale.ENGLISH);
        sf.setLenient(true);

        String relativeDate = "";
        try {
            long dateMillis = sf.parse(rawJsonDate).getTime();
            relativeDate = DateUtils.getRelativeTimeSpanString(dateMillis,
                    System.currentTimeMillis(), DateUtils.SECOND_IN_MILLIS, DateUtils.FORMAT_ABBREV_RELATIVE).toString();
        } catch (ParseException e) {
            e.printStackTrace();
        }

        String tbReturned = "";
        if(relativeDate.charAt(2) == ' ')
        {
            // string looks like '23 min. ago'
            tbReturned = (relativeDate.substring(0,2)+ relativeDate.substring(3,4));
        }
        else
        {
            // string looks like '2 min. ago'
            tbReturned = (relativeDate.substring(0,1)+ relativeDate.substring(2,3));
        }

        return tbReturned;
    }


}
