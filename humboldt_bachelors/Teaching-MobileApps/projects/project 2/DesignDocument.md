## Name: Alec Levin  

# Image Manipulator 
This application serves as a simple picture manipulator. The application allows the user to take a picture with their camera and add various effects. I created this application both to meet the PA requirements and to expand my scope of understanding in Android programming. 

## System Design 

### Requirements:
Phone must have working camera      
Target: Android 7.1       
Minimum: Android 5.0     
Approx Size: 121 MB

### Flow:
Welcome page, press the button to open the camera:     
![Image of Greeting](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa2/greeting.png)     

Upon opening Camera, take a picture using the Camera:  
![Image of initial camera](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa2/Take.png)    

Upon taking a picture, comfirm or retake the photo using the Camera:      
![Image of confirmation screen in camera](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa2/Select.png)       

Upon confirming the picture, you are brought to the image effect selection page. Here your initial, undedited image is at the top of the page. Following the image are 'Clear Effects' and 'Take New Photo' buttons, followed by the scrollable list of image effects:      
![Image of editing screen in app](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa2/initial.png)     

Upon selecting Woodgrain, the effect will be applied to the initial image resulting in:  
![Image of remove red effect](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa2/Woodgrain-(1).png)       

Upon pressing Clear Effects, the original image will return to the screen resulting in:       
![Image of editing screen in app](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa2/initial.png)           

Upon selecting Remove Red, the effect will be applied to the initial image resulting in:       
![Image of remove red effect](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa2/rmred.png)         

Upon pressing Clear Effects and then Remove Green, the effect will be applied to the initial image resulting in:    
![Image of remove green effect](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa2/rmgreen.png)           

Upon pressing Clear effects and then Remove Blue, the effect will be applied to the initial image resulting in:     
![Image of remove blue effect](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa2/rmblue.png)           

Upon pressing Clear effects and then Negate Red, the effect will be applied to the initial image resulting in:      
![Image of negate red effect](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa2/nred.png)          

Upon pressing Clear effects and then Negate Green, the effect will be applied to the initial image resulting in:   
![Image of negate green effect](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa2/ngreen.png)      

Upon pressing Clear effects and then Negate Green, the effect will be applied to the initial image resulting in:   
![Image of negate blue effect](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa2/nblue.png)          

Upon pressing Clear effects and then Add Random Noise, the effect will be applied to the initial image resulting in:      
![Image of random noise effect](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa2/arn.png)          

Upon pressing Clear effects and then High Contrast, the effect will be applied to the initial image resulting in:     
![Image of High Contrast effect](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa2/HC.png)    

Upon pressing Clear effects and then Grayscale, the effect will be applied to the initial image resulting in:     
![Image of Grayscale effect](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa2/G.png)      

Upon pressing New Photo, you will be returned to the welcome screen:     
![Image of Greeting](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa2/greeting.png)    

## Usage Manual
This is an application to both take photos and manipulate images. To correctly use the application, follow theses steps:   
1) Launch the application    
2) Click the Open Camera Button and take a photo    
NOTE: Future versions of the app will support picking a picture from the image gallery
3) Apply image effects using the scrolling list of effects
4) Get your original image back using the Clear Effects button or
5) Click New Photo button to return to the welcome screen
