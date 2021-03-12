package org.arlevin.instakilo.Fragments;

import android.os.Bundle;
import android.text.Spannable;
import android.text.SpannableString;
import android.text.TextPaint;
import android.text.method.LinkMovementMethod;
import android.text.style.URLSpan;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.TextView;

import com.parse.ParseException;
import com.parse.ParseQuery;
import com.parse.ParseUser;

import org.arlevin.instakilo.Activities.SignupActivity;
import org.arlevin.instakilo.R;

import java.util.List;

import androidx.fragment.app.Fragment;

public class UsernameFragment extends Fragment {

    TextView tvTerms;
    TextView tvUsername;
    Button btnNext;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        View view =  inflater.inflate(R.layout.fragment_username, container, false);

        tvUsername = view.findViewById(R.id.tvUsername);
        tvTerms = view.findViewById(R.id.tvTerms);
        tvTerms.setMovementMethod(LinkMovementMethod.getInstance());
        stripUnderlines(tvTerms);

        String username = craftUsername();
        tvUsername.setText(username);
        SignupActivity.newUserUsername = username;

        return view;
    }

    private void stripUnderlines(TextView textView) {
        Spannable s = new SpannableString(textView.getText());
        URLSpan[] spans = s.getSpans(0, s.length(), URLSpan.class);
        for (URLSpan span: spans) {
            int start = s.getSpanStart(span);
            int end = s.getSpanEnd(span);
            s.removeSpan(span);
            span = new UsernameFragment.URLSpanNoUnderline(span.getURL());
            s.setSpan(span, start, end, 0);
        }
        textView.setText(s);
    }
    private class URLSpanNoUnderline extends URLSpan {
        public URLSpanNoUnderline(String url) {
            super(url);
        }
        @Override public void updateDrawState(TextPaint ds) {
            super.updateDrawState(ds);
            ds.setUnderlineText(false);
        }
    }

    protected String craftUsername(){
        String name;
        if(SignupActivity.newUserEmail == null){
            name = SignupActivity.newUserName.replaceAll("\\s+","_");;
        }
        else{
            name = SignupActivity.newUserEmail.replaceAll("\\s+","");;
            int endAt = name.indexOf('@');
            name = name.substring(0, endAt);
        }
        Integer counter = 1;
        name = name.toLowerCase();
        while(!isUsernameAvailable(name)){
            if(SignupActivity.newUserEmail == null){
                name = SignupActivity.newUserName + counter;
                name = name.toLowerCase();
            }
            else{
                name = SignupActivity.newUserEmail;
                int endAt = name.indexOf('@');
                name = name.substring(0, endAt) + counter;
                name = name.toLowerCase();
            }
            counter++;
        }
        name = name.toLowerCase();
        return name;
    }


    static public Boolean isUsernameAvailable(String thing){
        ParseQuery<ParseUser> userQuery = new ParseQuery<ParseUser>(ParseUser.class);
        Boolean result = true;
        userQuery.whereEqualTo("username", thing);
        try {
            List<ParseUser> users = userQuery.find();
            if(users.size() > 0){
                result = false;
            }
            else {
                result = true;
            }
        } catch (ParseException e) {
            e.printStackTrace();
        }
        return result;
    }
}