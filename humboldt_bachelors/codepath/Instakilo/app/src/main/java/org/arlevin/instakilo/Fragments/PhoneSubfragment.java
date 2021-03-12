package org.arlevin.instakilo.Fragments;

import android.content.Context;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.inputmethod.InputMethodManager;
import android.widget.Button;
import android.widget.EditText;

import com.hbb20.CountryCodePicker;

import org.arlevin.instakilo.Activities.SignupActivity;
import org.arlevin.instakilo.R;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;


public class PhoneSubfragment extends Fragment {

    CountryCodePicker ccp;
    EditText editTextCarrierNumber;
    Button btnNext;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        View view = inflater.inflate(R.layout.fragment_phone_subfragment, container, false);


        ccp = (CountryCodePicker) view.findViewById(R.id.ccp);
        editTextCarrierNumber = (EditText) view.findViewById(R.id.etPhone);
        ccp.registerCarrierNumberEditText(editTextCarrierNumber);
        btnNext = view.findViewById(R.id.btnNext);
        btnNext.setClickable(false);
        btnNext.setBackgroundResource(R.drawable.round_button_nonclickable);

        editTextCarrierNumber.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence charSequence, int i, int i1, int i2) {

            }

            @Override
            public void onTextChanged(CharSequence charSequence, int i, int i1, int i2) {
                SignupActivity.notYetMadePhone = editTextCarrierNumber.getText().toString();
            }

            @Override
            public void afterTextChanged(Editable editable) {

            }
        });

        ccp.setPhoneNumberValidityChangeListener(new CountryCodePicker.PhoneNumberValidityChangeListener() {
            @Override
            public void onValidityChanged(boolean isValidNumber) {
                if(isValidNumber){
                    btnNext.setClickable(true);
                    btnNext.setBackgroundResource(R.drawable.round_button_clickable);
                }
                else{
                    btnNext.setClickable(false);
                    btnNext.setBackgroundResource(R.drawable.round_button_nonclickable);
                }
            }
        });

        editTextCarrierNumber.setText(SignupActivity.notYetMadePhone);

        return view;
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);

        EditText etPhone = view.findViewById(R.id.etPhone);
        etPhone.requestFocus();

        InputMethodManager imgr = (InputMethodManager) getActivity().getSystemService(Context.INPUT_METHOD_SERVICE);
        imgr.toggleSoftInput(InputMethodManager.SHOW_FORCED, InputMethodManager.HIDE_IMPLICIT_ONLY);


    }
}
