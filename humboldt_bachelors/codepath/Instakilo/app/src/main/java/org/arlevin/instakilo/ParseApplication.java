package org.arlevin.instakilo;

import android.app.Application;

import com.parse.Parse;
import com.parse.ParseObject;

import org.arlevin.instakilo.Models.Post;
import org.arlevin.instakilo.Models.User;

public class ParseApplication extends Application {
    @Override
    public void onCreate() {
        super.onCreate();

        ParseObject.registerSubclass(Post.class);
        ParseObject.registerSubclass(User.class);

        Parse.initialize(new Parse.Configuration.Builder(this)
                .applicationId("instakilo-codepath") // should correspond to APP_ID env variable
                .clientKey("instakiloMasterKey")  // set explicitly unless clientKey is explicitly configured on Parse server
                .server("https://instakilo-codepath.herokuapp.com/parse").build());
    }
}
