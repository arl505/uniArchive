package org.arlevin.instakilo.Fragments;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import org.arlevin.instakilo.Activities.SignupActivity;
import org.arlevin.instakilo.R;

import androidx.fragment.app.Fragment;


public class WelcomeFragment extends Fragment {
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        SignupActivity.notYetMadeEmail = null;
        SignupActivity.notYetMadePhone = null;
        return inflater.inflate(R.layout.fragment_welcome, container, false);
    }
}