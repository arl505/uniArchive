package org.arlevin.instakilo.Models;
import com.parse.ParseClassName;
import com.parse.ParseObject;

@ParseClassName("User")
public class User extends ParseObject  {
    public static String KEY_USERNAME = "username";
    public static String KEY_EMAIL = "trueEmail";
    public static String KEY_NAME = "name";
    public static String KEY_PASSWORD = "password";
    public static String KEY_PHONE = "phone";


    public String getUsername(){
        return getString(KEY_USERNAME);
    }

    public void putUsername(String Username){
        put(KEY_USERNAME, Username);
    }

    public String getEmail(){
        return getString(KEY_EMAIL);
    }

    public void putEmail(String email){
        put(KEY_EMAIL, email);
    }

    public String getName(){
        return getString(KEY_NAME);
    }

    public void putName(String name){
        put(KEY_NAME, name);
    }

    public String getPassword(){
        return getString(KEY_PASSWORD);
    }

    public void putPassword(String password){
        put(KEY_PASSWORD, password);
    }

    public String getPhone(){
        return getString(KEY_PHONE);
    }

    public void putPhone(String phone){
        put(KEY_PHONE, phone);
    }

}
