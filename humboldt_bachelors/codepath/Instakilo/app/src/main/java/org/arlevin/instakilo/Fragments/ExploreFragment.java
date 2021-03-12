package org.arlevin.instakilo.Fragments;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageButton;

import org.arlevin.instakilo.Activities.MainActivity;
import org.arlevin.instakilo.R;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;


public class ExploreFragment extends Fragment {

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        MainActivity.current_fragment = "explore";

        return inflater.inflate(R.layout.fragment_explore, container, false);
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);

        ImageButton ibHome = view.findViewById(R.id.ibHome);
        ImageButton ibExplore = view.findViewById(R.id.ibExplore);
        ImageButton ibCompose = view.findViewById(R.id.ibCompose);
        ImageButton ibNotifications = view.findViewById(R.id.ibNotifications);
        ImageButton ibProfile = view.findViewById(R.id.ibProfile);

        ibHome.setImageResource(R.drawable.home_icon);
        ibExplore.setImageResource(R.drawable.magnifying_glass_icon_active);
        ibCompose.setImageResource(R.drawable.compose_icon);
        ibNotifications.setImageResource(R.drawable.heart_icon);
        ibProfile.setImageResource(R.drawable.ic_person_outline_black_24dp);
    }
}
