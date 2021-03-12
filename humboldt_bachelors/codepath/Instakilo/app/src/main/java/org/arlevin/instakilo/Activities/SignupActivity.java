package org.arlevin.instakilo.Activities;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.inputmethod.InputMethodManager;
import android.widget.EditText;
import android.widget.Toast;

import com.hbb20.CountryCodePicker;
import com.parse.ParseException;
import com.parse.ParseUser;
import com.parse.SignUpCallback;

import org.arlevin.instakilo.Fragments.ChangeUsernameFragment;
import org.arlevin.instakilo.Fragments.EmailSubfragment;
import org.arlevin.instakilo.Fragments.NameFragment;
import org.arlevin.instakilo.Fragments.PhoneFragment;
import org.arlevin.instakilo.Fragments.PhoneSubfragment;
import org.arlevin.instakilo.Fragments.UsernameFragment;
import org.arlevin.instakilo.Fragments.WelcomeFragment;
import org.arlevin.instakilo.R;

import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.FragmentManager;

public class SignupActivity extends AppCompatActivity {

    static public FragmentManager fragmentManager;
    static public String newUserPhone;
    static public String newUserEmail;
    static public String newUserUsername;
    static public String newUserName;
    static public String newUserPassword;

    static public String notYetMadePhone;
    static public String notYetMadeEmail;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_signup);

        fragmentManager = getSupportFragmentManager();
        fragmentManager.beginTransaction().replace(R.id.flContent, new WelcomeFragment()).commit();
        newUserEmail = null;
        newUserPhone = null;
        newUserUsername = null;

    }

    public void signupWithPhone(View view){
        PhoneFragment.comingFrom = "nowhere";
        fragmentManager.beginTransaction().replace(R.id.flContent, new PhoneFragment()).addToBackStack("back to welcome").commit();
    }

    public void processPhoneInput(View view){
        InputMethodManager imm = (InputMethodManager) this.getSystemService(Activity.INPUT_METHOD_SERVICE);
        imm.hideSoftInputFromWindow(view.getWindowToken(), 0);
        PhoneFragment.comingFrom = "namePhone";
        CountryCodePicker ccp = findViewById(R.id.ccp);
        newUserPhone = ccp.getFullNumber();
        newUserEmail = null;
        fragmentManager.beginTransaction().replace(R.id.flContent, new NameFragment()).addToBackStack("back to phone").commit();
    }

    public void processEmailInput(View view){
        InputMethodManager imm = (InputMethodManager) this.getSystemService(Activity.INPUT_METHOD_SERVICE);
        imm.hideSoftInputFromWindow(view.getWindowToken(), 0);
        PhoneFragment.comingFrom = "nameEmail";
        newUserPhone =null;
        EditText etEmail = findViewById(R.id.etEmail);
        newUserEmail = etEmail.getText().toString();
        fragmentManager.beginTransaction().replace(R.id.flContent, new NameFragment()).addToBackStack("back to phone").commit();
    }

    public void processNameInput(View view){
        EditText etFullName = findViewById(R.id.etFullName);
        EditText etPassword = findViewById(R.id.etPassword);
        newUserName = etFullName.getText().toString();
        newUserPassword = etPassword.getText().toString();
        InputMethodManager imm = (InputMethodManager) this.getSystemService(Activity.INPUT_METHOD_SERVICE);
        imm.hideSoftInputFromWindow(view.getWindowToken(), 0);
        fragmentManager.beginTransaction().replace(R.id.flContent, new UsernameFragment()).addToBackStack("back to name").commit();
    }


    public void toBeImplemented(View view) {
        Toast.makeText(SignupActivity.this, "To Be Implemented", Toast.LENGTH_SHORT).show();
    }

    public void backToLogin(View view){
        finish();
    }

    public void openPhoneTab(View view){
        fragmentManager.beginTransaction().replace(R.id.flEmailOrPhone, new PhoneSubfragment()).commit();
    }

    public void openEmailTab(View view){
        fragmentManager.beginTransaction().replace(R.id.flEmailOrPhone, new EmailSubfragment()).commit();
    }

    public void logout(View view){
        ParseUser.logOut();
        Intent i = new Intent(this, LoginActivity.class);
        startActivity(i);
        finish();
    }

    public void processUsernameInput(View view){
        ParseUser user = new ParseUser();
        user.setUsername(newUserUsername);
        user.setPassword(newUserPassword);
        user.put("name", newUserName);
        if(newUserPhone != null){
            user.put("phone", newUserPhone);
        }
        else{
            user.put("trueEmail",newUserEmail);
        }
        user.signUpInBackground(new SignUpCallback() {
            @Override
            public void done(ParseException e) {
                if(e==null) {
                    setResult(RESULT_OK);
                    finish();
                }
            }
        });
    }

    public void makeUsernameChange(View view){
        fragmentManager.beginTransaction().replace(R.id.flContent, new ChangeUsernameFragment()).addToBackStack("back to usernam").commit();
    }

    public void processUsernameChange(View view){
        EditText etUsername = findViewById(R.id.etUsername);
        String username = etUsername.getText().toString().toLowerCase();
        if(UsernameFragment.isUsernameAvailable(username)){
            SignupActivity.newUserUsername = username;
            processUsernameInput(view);
        }
        else{
            Toast.makeText(getApplicationContext(), "Username is taken", Toast.LENGTH_SHORT).show();
        }
    }
}
