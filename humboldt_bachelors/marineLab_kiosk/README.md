# HSU Marine Lab Kiosk
## Instructions for non-developers on how to run kiosk
1) Log on to the useradmin account
2) Click on the Windows start button in bottom left
3) Click on the settings wheel
4) Scroll down and select `Ease of Access`
5) On the left navigation menu, scroll down and select `Keyboard`
6) Turn the first option on (`Use the On-Screen Keyboard`) 
7) Open Zamok2.0 application
8) If screen says, "Loading..." for more than 5 seconds, close the application and re-open it

   * It tends to work every other time, you may need to close and reopen the application. To close the application, use the on screen keyboard to select `ctrl`, `shift`, and `esacpe` to open the task manager. Select the Zamok app and press end task. Now reopen the Zamok app and it should run. 
9) Close the on screen keyboard
10) The kiosk is now up and running!
11) To close the kiosk application, if the keyboard is available press `alt` and `F4` simultaneously. If the keyeboard is not  available turn off and back on the whole system

## Instructions for maintaining kiosk
* Advanced Kiosks provides a [website](http://zamok2.com) where one can
    * View the current status of the kiosk
    * Change the homepage
    * Turn on/off kiosk features
    * View usage reports and intersting statistics (similar to Google Analytics)
    * Turn off or restart the Zamok2 application
        * I highly advise against using these features due to the reasons listed above on insturction #3. The Kiosk restarts/turns on and off very unreliably. Do not attempt to do this remotely because chances are you will need to close and reopen the application which you cannot do from the website.
    

## Instructions for modifying kiosk content
* The kiosk simply loads HTML/CSS content stored on the desktop 
* The files are located at `C:\Users\useradmin\Desktop\OneDrive\`. 
    * This directory is a OneDrive directory meaning that one may update the kiosk content remotely. Please email `alec@arlevin.org` to obtain shared access to this directory. 
* The Zamok2 Kiosk app caches files and makes it extremely aggravating to update already existing CSS, thus in order to trick the Zamok2 app to load in the changes I simply altered the CSS filenames each time I needed to update an already existing CSS file.
