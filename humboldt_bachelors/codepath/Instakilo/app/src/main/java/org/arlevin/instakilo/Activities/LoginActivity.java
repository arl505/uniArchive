package org.arlevin.instakilo.Activities;

import android.content.Intent;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.parse.ParseException;
import com.parse.ParseQuery;
import com.parse.ParseUser;

import org.arlevin.instakilo.R;

import java.util.List;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;

public class LoginActivity extends AppCompatActivity {

    EditText etUsername;
    EditText etPassword;
    Button btnLogin;

    boolean usernameFilled;
    boolean passwordFilled;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        if (ParseUser.getCurrentUser() != null) {
            goMainActivity();
        }

        setContentView(R.layout.activity_login);

        Toolbar toolbar = (Toolbar) findViewById(R.id.tb);
        setSupportActionBar(toolbar);


        etUsername = findViewById(R.id.etUsername);
        etPassword = findViewById(R.id.etPassword);
        btnLogin = findViewById(R.id.btnLogin);
        btnLogin.setBackgroundResource(R.drawable.round_button_nonclickable);
        btnLogin.setClickable(false);


        etUsername.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence charSequence, int i, int i1, int i2) {

            }

            @Override
            public void onTextChanged(CharSequence charSequence, int i, int i1, int i2) {
                if (etUsername.getText().length() > 0) {
                    usernameFilled = true;
                } else {
                    usernameFilled = false;
                }

                if (usernameFilled && passwordFilled) {
                    btnLogin.setBackgroundResource(R.drawable.round_button_clickable);
                    btnLogin.setClickable(true);
                } else {
                    btnLogin.setBackgroundResource(R.drawable.round_button_nonclickable);
                    btnLogin.setClickable(false);
                }
            }

            @Override
            public void afterTextChanged(Editable editable) {

            }
        });

        etPassword.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence charSequence, int i, int i1, int i2) {

            }

            @Override
            public void onTextChanged(CharSequence charSequence, int i, int i1, int i2) {
                if (etPassword.getText().length() > 0) {
                    passwordFilled = true;
                } else {
                    passwordFilled = false;
                }

                if (usernameFilled && passwordFilled) {
                    btnLogin.setBackgroundResource(R.drawable.round_button_clickable);
                    btnLogin.setClickable(true);
                } else {
                    btnLogin.setBackgroundResource(R.drawable.round_button_nonclickable);
                    btnLogin.setClickable(false);
                }

            }

            @Override
            public void afterTextChanged(Editable editable) {

            }
        });
    }
    public void swapusername(View view){
        String textEntered = etUsername.getText().toString();
        String password = etPassword.getText().toString();
        if(textEntered.contains("@")){
            List<ParseUser> users = getUsersWithParam("trueEmail", textEntered);

             if(users.size() == 1){
                textEntered = users.get(0).getUsername();
                login(textEntered, password);
            }
            else{
                for(int i = 0; i < users.size(); i++){
                    textEntered = users.get(i).getUsername();
                    login(textEntered, password);
                }
            }
        }

        else if(isNumeric(textEntered)){
            List<ParseUser> users = getUsersWithParam("phone", textEntered);
             if(users.size() == 1){
                textEntered = users.get(0).getUsername();
                login(textEntered, password);
            }
            else{
                for(int i = 0; i < users.size(); i++){
                    textEntered = users.get(i).getUsername();
                    login(textEntered, password);
                }
            }
        }

        else{
            login(textEntered, password);
        }


        if(ParseUser.getCurrentUser() == null){
            Toast.makeText(this, "Invalid Credentials", Toast.LENGTH_SHORT).show();
        }
    }


    public void login(final String username, String password) {
        try {
            ParseUser.logIn(username, password);
            goMainActivity();
        } catch (ParseException e) {
            e.printStackTrace();
        }
    }

    public void goMainActivity() {
        Intent i = new Intent(this, MainActivity.class);
        startActivity(i);
        finish();
    }


    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        if (resultCode == RESULT_OK && requestCode == 20) {
            goMainActivity();
        }
        if(resultCode==RESULT_CANCELED){
            // This is where I arrive after finish()-ing without setting the request code, such
            // as when the user clicks 'already have an account, log in.' This signifies that the secondary
            // activity concluded and that now we wish to continue
            // the original activity without regarding the result, i.e. no user was signed up, simply
            // resume the login activity.
        }
    }

    public void toBeImplemented(View view) {
        Toast.makeText(this, "To Be Implemented", Toast.LENGTH_SHORT).show();
    }

    public void signUp(View view) {
        Intent i = new Intent(this, SignupActivity.class);
        startActivityForResult(i, 20);
    }

    public List<ParseUser> getUsersWithParam(String param1, String param2){
        ParseQuery<ParseUser> usersQuery = new ParseQuery<ParseUser>(ParseUser.class);
        List<ParseUser> users;
        usersQuery.whereEqualTo(param1, param2);
        try {
            users = usersQuery.find();
        } catch (ParseException e) {
            e.printStackTrace();
            users = null;
        }
        return users;
    }

    public boolean isNumeric(String s) {
        return s != null && s.matches("[-+]?\\d*\\.?\\d+");
    }
}
