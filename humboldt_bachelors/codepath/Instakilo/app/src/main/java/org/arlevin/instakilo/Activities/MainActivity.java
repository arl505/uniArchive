package org.arlevin.instakilo.Activities;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;

import com.parse.ParseUser;

import org.arlevin.instakilo.Fragments.ComposeFragment;
import org.arlevin.instakilo.Fragments.ExploreFragment;
import org.arlevin.instakilo.Fragments.NotificationsFragment;
import org.arlevin.instakilo.Fragments.PostsFragment;
import org.arlevin.instakilo.Fragments.ProfileFragment;
import org.arlevin.instakilo.R;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;
import androidx.fragment.app.FragmentManager;

public class MainActivity extends AppCompatActivity {

    public static String current_fragment;
    FragmentManager fragmentManager;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Toolbar toolbar = (Toolbar) findViewById(R.id.tb);
        setSupportActionBar(toolbar);
        fragmentManager = getSupportFragmentManager();
        fragmentManager.beginTransaction().replace(R.id.flContainer, new PostsFragment()).commit();
    }

    public void logout(View view){
        ParseUser.logOut();
        Intent i = new Intent(this, LoginActivity.class);
        startActivity(i);
        finish();
    }

    public void goHome(View view){
        if(current_fragment!="home"){
            fragmentManager.beginTransaction().replace(R.id.flContainer, new PostsFragment()).commit();
        }
        else{
            PostsFragment.scrollToTop();
        }
    }

    public void goExplore(View view){
        if(current_fragment!="explore"){
            fragmentManager.beginTransaction().replace(R.id.flContainer, new ExploreFragment()).commit();
        }
    }

    public void goCompose(View view){
        if(current_fragment!="compose"){
            fragmentManager.beginTransaction().replace(R.id.flContainer, new ComposeFragment()).commit();
        }
    }

    public void goNotifications(View view){
        if(current_fragment!="notifications"){
            fragmentManager.beginTransaction().replace(R.id.flContainer, new NotificationsFragment()).commit();
        }
    }

    public void goProfile(View view){
        if(current_fragment!="profile"){
            fragmentManager.beginTransaction().replace(R.id.flContainer, new ProfileFragment()).commit();
        }
        else{
            ProfileFragment.scrollToTop();
        }
    }

}
