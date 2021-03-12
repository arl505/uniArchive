## Name: Alec Levin     

# Image Guesser    
This application serves as a simple photo analysis game. The application allows the user to take a photo, performs analysis on the image, and returns what the application thinks the image is of. The application also allows the user to enter what the photo is of and returns the confidence level at which the application actually thought the photo was whatever the user entered. This application serves as an introduction to learning some of the available tools for data processing and implementing those machine learning tools in simple android applications.    
## System Design     

### Requirements:    
* Phone must have working camera  
* Internet for access to Google Vision API     
* Approx Size of complete project on computer without packages: 297 KB     
* Approx Size of complete project on computer with packages: 437 MB
* Approx Size of App to be installed on phone: 13,423 KB    
* Target: Android 7.1       
* Minimum: Android 5.0       

### Flow:
Welcome page, press the button to open the camera:     
![Image of Homescreen](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa3/home.png)      

The camera is launched and the user may now take a photo:     
![Image of Camera Screen](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa3/01.png)

The user may then click the circular button to take a photo, resulting in this check-photo screen:     
![Image of check photo screen](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa3/02.png)   

The user may then click the x to go back to the homescreen, click the refresh button to take another picture, or the checkmark to go to the next screen. Clicking the checkmark will result in the picture being analyzed for label detection and will result in the following screen:    
![Image of screen after approving photo](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa3/03.png)    
NOTE: this is a screenshot of a ScrollView, user can scroll down to see NO button       

The user may now click on the appropriate button. In this example, the appropriate button to click would be yes. Clicking on the yes button results in this screen:     
![Image of success screen](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa3/04.png)   

The user may now restart the process. Clicking start over will return the user to the main screen:     
![Image of homescreen](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa3/home.png)      

The user may now take a new picture. For example, the user may take a blurry image resulting in the following screen:    
![Image of blurry camera screen](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa3/05.png)    

If the user were to accidentally hit the checkmark and submit this photo, the screen would appear as:     
![image of screen after approving blurry photo](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa3/06.png)    
NOTE: this is a screenshot of a ScrollView, user can scroll down to see NO button        

At this point the user would likely select to start over, that would result in being sent back to the homescreen:      
![Image of homescreen](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa3/home.png)      

The user may now select the open camera button and take a new photo, for example:     
![image of check photo screen on laptop](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa3/07.png)    


Hitting the checkmark would result in the user being taken to this screen, where google has guessed that the image is of technology, while this isn't incorrect, it isn't fully correct and we will decide to say no:          
![Image of screen after approving photo; laptop](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa3/08.png)    
NOTE: this is a screenshot of a ScrollView, user can scroll down to see NO button       

Upon clicking no, the user will be taken to the failure screen:    
![image of failure screen](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa3/09.png)   

Here the user may enter what the photo is actually of:     
![image of failure screen with input of laptop](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa3/10.png)    

At this point, if the string entered by the user matches any of google's suspected labels, we tell the user the confidence level at which we thought the string inputted was the correct label. Otherwise we tell them we had no clue. In this instance, upon hitting next with the input of laptop, the user will be shown this screen:     
![image of percentage screen](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa3/11.png)   

The user may now click the start over button and will be brought back to the home screen:     
![image of homescreen](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa3/home.png)    

The user may now select the open camera button and take a new photo, for example:   
![image of chekc photo screen on chair](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa3/12.png)      

If the user were to click on the checkmark, they would then be taken to this screen:  
![image of screen after approving photo; chair](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa3/13.png)   
NOTE: this is a screenshot of a ScrollView, user can scroll down to see NO button      

Obviously this is incorrect and we will click on no, resulting in:   
![image of blank failure screen](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa3/14.png)    

The user may then enter in that it was a chair:     
![image of failure screen with input of chair](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa3/15.png)     

Since Google did not return a label of chair, the user see's the no clue screen:     
![image of no clue screen](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa3/16.png)      

At this point, the user may press start over and will be taken back to the homescreen:      
![image of homescreen](https://raw.githubusercontent.com/arl505/Teaching-MobileApps/master/images/pa3/home.png)     

At this point, all cases and scenarios are covered.     

## Usage Manual
This application allows the user to take a photo, have the photo analzed by google and then provides basic dialogue. To correctly use the application, follow theses steps:   
1) Launch the application    
2) Click the Open Camera Button    
NOTE: Future versions of the app will support picking a picture from the image gallery
3) Take a photo and approve the photo      
4) Answer whether or not the guessed thing is actually what the photo is of, or Start over        
5) If answered yes to 4, SUCCESS! Go to #8    
6) If answered no to 4, FAILURE! Continue to #7    
7) Enter in what the photo actually was of, hit next, and go to #8    
8) Play again    
