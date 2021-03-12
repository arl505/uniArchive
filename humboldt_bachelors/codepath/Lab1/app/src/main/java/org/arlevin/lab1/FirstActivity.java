package org.arlevin.lab1;

import android.content.Intent;
import android.graphics.drawable.Drawable;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.ImageView;
import android.widget.Toast;

public class FirstActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_first);

        ImageView img = (ImageView)findViewById(R.id.ivFirstScreenIcon);
        Drawable icon = getResources().getDrawable(R.drawable.twitter_png);
        img.setImageDrawable(icon);

        findViewById(R.id.firstScreenRegisterButton).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(FirstActivity.this, RegisterActivity.class));
            }
        });

        findViewById(R.id.firstScreenLoginButton).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //startActivity(new Intent(FirstActivity.this, org.arlevin.lab1.LoginActivity.class));
                Toast.makeText(FirstActivity.this, "To be implemented", Toast.LENGTH_SHORT).show();
            }
        });

    }
}
