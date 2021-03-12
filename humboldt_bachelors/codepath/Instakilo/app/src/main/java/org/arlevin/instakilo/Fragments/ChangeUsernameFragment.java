package org.arlevin.instakilo.Fragments;

import android.content.Context;
import android.graphics.Color;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
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


public class ChangeUsernameFragment extends Fragment {

    EditText etUsername;
    Button btnNext;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        View view = inflater.inflate(R.layout.fragment_change_username, container, false);

        etUsername = view.findViewById(R.id.etUsername);
        btnNext = view.findViewById(R.id.btnNext);
        etUsername.setText(SignupActivity.newUserUsername);

        btnNext.setBackgroundResource(R.drawable.round_button_clickable);
        btnNext.setTextColor(Color.parseColor("#FFFFFF"));
        btnNext.setClickable(true);


        return view;
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);

        etUsername = view.findViewById(R.id.etUsername);
        etUsername.requestFocus();
        InputMethodManager imgr = (InputMethodManager) getActivity().getSystemService(Context.INPUT_METHOD_SERVICE);
        imgr.toggleSoftInput(InputMethodManager.SHOW_FORCED, InputMethodManager.HIDE_IMPLICIT_ONLY);
        etUsername.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence charSequence, int i, int i1, int i2) {

            }

            @Override
            public void onTextChanged(CharSequence charSequence, int i, int i1, int i2) {
                if(etUsername.getText().toString().length() == 0){
                    btnNext.setBackgroundResource(R.drawable.round_button_nonclickable_unfilled);
                    btnNext.setTextColor(Color.parseColor("#99CCFF"));
                    btnNext.setClickable(false);
                }
                else{
                    btnNext.setBackgroundResource(R.drawable.round_button_clickable);
                    btnNext.setTextColor(Color.parseColor("#FFFFFF"));
                    btnNext.setClickable(true);
                }
            }

            @Override
            public void afterTextChanged(Editable editable) {

            }
        });
    }
}
