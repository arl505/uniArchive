package org.arlevin.instakilo.Fragments;

import android.content.Context;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.util.Patterns;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.inputmethod.InputMethodManager;
import android.widget.Button;
import android.widget.EditText;

import org.arlevin.instakilo.Activities.SignupActivity;
import org.arlevin.instakilo.R;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;


public class EmailSubfragment extends Fragment {

    EditText etEmail;
    Button btnNext;
    String email;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        final View view = inflater.inflate(R.layout.fragment_email_subfragment, container, false);

       etEmail =  view.findViewById(R.id.etEmail);
        btnNext = view.findViewById(R.id.btnNext);
        btnNext.setClickable(false);
        btnNext.setBackgroundResource(R.drawable.round_button_nonclickable);
       etEmail.addTextChangedListener(new TextWatcher() {
           @Override
           public void beforeTextChanged(CharSequence charSequence, int i, int i1, int i2) {

           }

           @Override
           public void onTextChanged(CharSequence charSequence, int i, int i1, int i2) {
               if (Patterns.EMAIL_ADDRESS.matcher(etEmail.getText().toString()).matches()){
                    btnNext.setClickable(true);
                    btnNext.setBackgroundResource(R.drawable.round_button_clickable);
               }
               else{
                   btnNext.setClickable(false);
                   btnNext.setBackgroundResource(R.drawable.round_button_nonclickable);
               }
               SignupActivity.notYetMadeEmail = etEmail.getText().toString();
           }

           @Override
           public void afterTextChanged(Editable editable) {

           }
       });

       etEmail.setText(SignupActivity.notYetMadeEmail);


        return view;
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);

        EditText etPhone = view.findViewById(R.id.etEmail);
        etPhone.requestFocus();

        InputMethodManager imgr = (InputMethodManager) getActivity().getSystemService(Context.INPUT_METHOD_SERVICE);
        imgr.toggleSoftInput(InputMethodManager.SHOW_FORCED, InputMethodManager.HIDE_IMPLICIT_ONLY);
    }
}