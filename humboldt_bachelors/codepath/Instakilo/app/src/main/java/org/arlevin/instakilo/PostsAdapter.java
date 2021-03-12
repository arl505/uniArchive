package org.arlevin.instakilo;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import com.bumptech.glide.Glide;
import com.parse.ParseFile;

import org.arlevin.instakilo.Models.Post;

import java.util.List;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

public class PostsAdapter extends RecyclerView.Adapter<PostsAdapter.Viewholder> {

    private Context context;
    private List<Post> posts;

    public PostsAdapter(Context context, List<Post> posts){
        this.context = context;
        this.posts = posts;
    }

    @NonNull
    @Override
    public Viewholder onCreateViewHolder(@NonNull ViewGroup viewGroup, int i) {
        View view = LayoutInflater.from(context).inflate(R.layout.item_post, viewGroup, false);
        return new Viewholder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull Viewholder viewholder, int i) {
        Post post = posts.get(i);
        viewholder.bind(post);
    }

    public void clear() {
        posts.clear();
        notifyDataSetChanged();
    }


    @Override
    public int getItemCount() {
        return posts.size();
    }

    class Viewholder extends RecyclerView.ViewHolder{

        private TextView tvHandle;
        private ImageView ivImage;
        private TextView tvDescription;

        public Viewholder(@NonNull View itemView) {
            super(itemView);

            tvHandle = itemView.findViewById(R.id.tvHandle);
            ivImage = itemView.findViewById(R.id.ivImage);
            tvDescription = itemView.findViewById(R.id.tvDescription);
        }

        public void bind(Post post){
            tvHandle.setText(post.getUser().getUsername());

            ParseFile image = post.getImage();
            if(image!=null) {
                Glide.with(context).load(image.getUrl()).into(ivImage);
            }
            else {
                ivImage.setVisibility(View.INVISIBLE);
            }
            tvDescription.setText(post.getDescription());

        }
    }
}
