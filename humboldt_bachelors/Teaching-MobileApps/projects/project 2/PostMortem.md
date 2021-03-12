## Name: Alec Levin   
# Post Mortem

One of the biggest issues I incurred while making my app had to do with loading my bitmap. In my app, the user takes a photograph. Behind the scenes, the photograph is saved to a directory that we create specifically for the images our app generates. Then, we load the image into a bitmap and resize it accordingly to our ImageView. On the screen, the user simply takes the photo and should then be brought to the second page of my app. Here the bitmap is contained in our ImageView and there is a scrollable list of effects implemented as buttons. My application failed to load the bitmap into the image view and thus the user would always be taken to the effects screen with no image. After looking around for hours, I found that I was setting imageView.Visibility to invisible, hiding my image. After this fix, I had proper functionality under correct usage.   

My next issue was when the user did not use the app correctly. If the user opened the app and clicked to open the camera, failed to take a picture, and then attempted to reenter the app, the app would crash because of a null object exception. In order to resolve this, I placed several if-else constructs within my code to check if there was a bitmap, and then return the user to the welcome screen to take a picture if the bitmap was null. This resolved the issue and ensured that the view would only be set to the effects screen when there was a valid bitmap.       

Besides the bitmap, I struggled with the android gallery. I had several points in which I was confused which ultimately led to my app being unable to load images or save images to and from the phone. As an Apple and iOS user, this course is serving as introduction to both how to develop for an android phone and for me, how to even use the android system. With that being said, the android platform perplexes me. Where do the normal photos go when the user opens the standard camera app and takes a standard photo? It seems as though there is both a Photos app and a Gallery app. In order to access the users photos and load them in my app and convert them into a bitmap, where do I look? Where do I save back to? The gallery? The photos app? Some external storage folder on the device?       

Lastly, my app ran incredibly slow. This is because the camera’s on our phones today produce pictures with hundreds of thousands of pixels. Some of my image effects require doing computations on every single pixel and resetting the value on each. In order to quicken this, the image needs to be resized and loaded into a much more handleable bitmap. Lacking this, my application currently takes up to a few minutes to apply some of the image effects. This will definitely be a point that I focus on to improve in the future if I hope to show off my app in real life, not on the emulator.       

The version of my app that I submitted for PA #2 was based on the time that I had. I will continue to develop this application to incorporate gallery saving. I will continue to watch youtube videos and learn more about Android so that I don’t have to ask such naive questions as above. I also would like to research android design features and make my app look more aesthetically pleasing.