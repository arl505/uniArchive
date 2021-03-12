package org.arlevin.instakilo.Fragments;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import com.google.android.material.tabs.TabLayout;

import org.arlevin.instakilo.Activities.SignupActivity;
import org.arlevin.instakilo.R;

import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;

public class PhoneFragment extends Fragment {

    FragmentManager fragmentManager;
    TabLayout tabLayout;
    static public String comingFrom;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        View tbreturned = inflater.inflate(R.layout.fragment_phone, container, false);
        tabLayout = tbreturned.findViewById(R.id.tabs);
        fragmentManager = SignupActivity.fragmentManager;
        //fragmentManager.beginTransaction().replace(R.id.flEmailOrPhone, new PhoneSubfragment()).commit();
        if(comingFrom == "nowhere"){
            fragmentManager.beginTransaction().replace(R.id.flEmailOrPhone, new PhoneSubfragment()).commit();
            tabLayout.getTabAt(0).select();
        }
        if(comingFrom == "namePhone"){
            fragmentManager.beginTransaction().replace(R.id.flEmailOrPhone, new PhoneSubfragment()).commit();
            tabLayout.getTabAt(0).select();
        }
        if(comingFrom == "nameEmail"){
            fragmentManager.beginTransaction().replace(R.id.flEmailOrPhone, new EmailSubfragment()).commit();
            tabLayout.getTabAt(1).select();
        }
        tabLayout.addOnTabSelectedListener(new TabLayout.OnTabSelectedListener() {
            @Override
            public void onTabSelected(TabLayout.Tab tab) {
                int i = 0;
                if(tab.getText().toString().contains("EMAIL")){
                    fragmentManager.beginTransaction().replace(R.id.flEmailOrPhone, new EmailSubfragment()).commit();
                    i = 0;
                }
                if(tab.getText().toString().contains("PHONE")){
                    fragmentManager.beginTransaction().replace(R.id.flEmailOrPhone, new PhoneSubfragment()).commit();
                }
            }

            @Override
            public void onTabUnselected(TabLayout.Tab tab) {

            }

            @Override
            public void onTabReselected(TabLayout.Tab tab) {

            }
        });
        return tbreturned;
    }
}