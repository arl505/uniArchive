package org.arlevin.instakilo.Fragments;

import android.content.Context;
import android.graphics.Color;
import android.os.Bundle;
import android.text.Editable;
import android.text.Spannable;
import android.text.SpannableString;
import android.text.SpannableStringBuilder;
import android.text.TextPaint;
import android.text.TextWatcher;
import android.text.method.LinkMovementMethod;
import android.text.style.ForegroundColorSpan;
import android.text.style.URLSpan;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.inputmethod.InputMethodManager;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import org.arlevin.instakilo.R;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;


public class NameFragment extends Fragment {

    EditText etFullName;
    EditText etPassword;
    TextView tvContactsLearn;
    Button btnNext;
    TextView tvContacts2;
    Boolean nameFilled;
    Boolean passwordFilled;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        View view = inflater.inflate(R.layout.fragment_name, container, false);

        TextView tvContactsLearn = view.findViewById(R.id.tvContactsLearn);
        SpannableStringBuilder str = new SpannableStringBuilder(tvContactsLearn.getText().toString());
        str.setSpan(new android.text.style.StyleSpan(android.graphics.Typeface.BOLD), 116, 127, Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);

        Button temp_button = view.findViewById(R.id.btnNext);
        temp_button.setBackgroundResource(R.drawable.round_button_nonclickable);
        temp_button.setClickable(false);


        TextView tvContacts = view.findViewById(R.id.tvContacts2);
        SpannableStringBuilder str2 = new SpannableStringBuilder(tvContacts.getText().toString());
        str2.setSpan(new android.text.style.StyleSpan(android.graphics.Typeface.BOLD), 37, 63, Spannable.SPAN_INCLUSIVE_INCLUSIVE);
        str2.setSpan(new ForegroundColorSpan(Color.BLACK), 37, 63, Spannable.SPAN_INCLUSIVE_INCLUSIVE);

        tvContacts.setText(str2);

        nameFilled = false;
        passwordFilled = false;
        tvContacts.setClickable(false);
        return view;
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);

        etFullName = view.findViewById(R.id.etFullName);
        etPassword = view.findViewById(R.id.etPassword);
        tvContactsLearn = view.findViewById(R.id.tvContactsLearn);
        btnNext = view.findViewById(R.id.btnNext);
        tvContacts2 = view.findViewById(R.id.tvContacts2);

        tvContactsLearn.setMovementMethod(LinkMovementMethod.getInstance());
        stripUnderlines(tvContactsLearn);

        etFullName.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence charSequence, int i, int i1, int i2) {

            }

            @Override
            public void onTextChanged(CharSequence charSequence, int i, int i1, int i2) {
                String text = etFullName.getText().toString();
                if(text.length() > 0){
                    nameFilled = true;
                }
                else{
                    nameFilled = false;
                }

                if(nameFilled && passwordFilled){
                    btnNext.setBackgroundResource(R.drawable.round_button_clickable);
                    btnNext.setClickable(true);
                    tvContacts2.setClickable(true);
                }
                else{
                    btnNext.setBackgroundResource(R.drawable.round_button_nonclickable);
                    btnNext.setClickable(false);
                    tvContacts2.setClickable(false);
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
                String text = etPassword.getText().toString();
                if(text.length()>0){
                    passwordFilled = true;
                }
                else{
                    passwordFilled = false;
                }

                if(nameFilled && passwordFilled){
                    btnNext.setBackgroundResource(R.drawable.round_button_clickable);
                    btnNext.setClickable(true);
                    tvContacts2.setClickable(true);

                }
                else{
                    btnNext.setBackgroundResource(R.drawable.round_button_nonclickable);
                    btnNext.setClickable(false);
                    tvContacts2.setClickable(false);
                }
            }

            @Override
            public void afterTextChanged(Editable editable) {

            }
        });

        etFullName.requestFocus();
        InputMethodManager imgr = (InputMethodManager) getActivity().getSystemService(Context.INPUT_METHOD_SERVICE);
        imgr.toggleSoftInput(InputMethodManager.SHOW_FORCED, InputMethodManager.HIDE_IMPLICIT_ONLY);
    }

    private void stripUnderlines(TextView textView) {
        Spannable s = new SpannableString(textView.getText());
        URLSpan[] spans = s.getSpans(0, s.length(), URLSpan.class);
        for (URLSpan span: spans) {
            int start = s.getSpanStart(span);
            int end = s.getSpanEnd(span);
            s.removeSpan(span);
            span = new URLSpanNoUnderline(span.getURL());
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
}


