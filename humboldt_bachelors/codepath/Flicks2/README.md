Codepath Submitting Assignments Page, "If the assignment is a continuation of the same project from a preview week, add the new template to the end of the previous README instead of creating a new file."

**As required, the new README has been added below, at the end of the previous README.** 

# Project 1 - *Flicks*

**Flicks** shows the latest movies currently playing in theaters. The app utilizes the Movie Database API to display images and basic information about these movies to the user.

Time spent: **5** hours spent in total

**You can put this application on your Android device by downloading [this APK file](https://github.com/arl505/Flicks/blob/master/app-release-unsigned.apk) to your device.**

## User Stories

The following **required** functionality is completed:

* [x] User can view a list of movies (title, poster image, and overview) currently playing in theaters from the Movie Database API.

* [x] Views should be responsive for both landscape/portrait mode.
     * [x] In portrait mode, the poster image, title, and movie overview is shown.
     * [x] In landscape mode, the rotated alternate layout should use the backdrop image instead and show the title and movie overview to the right of it.

The following **optional** features are implemented:

* [x] Improved the user interface by experimenting with styling and coloring.

## Video Walkthrough

Here's a walkthrough of implemented user stories:

<img src='https://github.com/arl505/Flicks/blob/master/walkthrough1.gif' title='Video Walkthrough' width='' alt='Video Walkthrough' />

## Open-source libraries used

- [Android Async HTTP](https://github.com/loopj/android-async-http) - Simple asynchronous HTTP requests with JSON parsing
- [Glide](https://github.com/bumptech/glide) - Image loading and caching library for Android

## License

    Copyright [2018] [Alec Levin]

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.

# Project 1, part 2 - *Flicks2*

**Flicks2** shows the latest movies currently playing in theaters. The app utilizes the Movie Database API to display images and basic information about these movies to the user.

Time spent: **10** hours spent in total

## User Stories

The following **required** functionality is completed:

* [x] Expose details of movie (ratings using RatingBar, popularity, and synopsis) in a separate activity.

* [x] Allow video posts to be played in full-screen using the YouTubePlayerView (2 points)

    * [x] When clicking on a popular movie (i.e. a movie voted for more than 5 stars) the video should be played immediately.
    * [x] Less popular videos rely on the detailed page should show an image preview that can initiate playing a YouTube video.

The following **optional** features are implemented:

* [x] Add a play icon overlay to popular movies to indicate that the movie can be played (1 point).
* [ ] Apply the popular ButterKnife annotation library to reduce view boilerplate. (1 point)
* [x] Add a rounded corners for the images using the Glide transformations. (1 point)

The following **stretch** features from week 1 are also implemented:
* [x] Display a nice default [placeholder graphic](https://guides.codepath.com/android/Displaying-Images-with-the-Glide-Library#advanced-usage) for each image during loading
* [x] Improved the user interface by experimenting with styling and coloring.

## Video Walkthrough

Here's a walkthrough of implemented user stories:

<img src='walkthrough1.gif' title='Video Walkthrough' width='' alt='Video Walkthrough' />

## Open-source libraries used

- [Android Async HTTP](https://github.com/loopj/android-async-http) - Simple asynchronous HTTP requests with JSON parsing
- [Glide](https://github.com/bumptech/glide) - Image loading and caching library for Android

## License

    Copyright [2018] [Alec Levin]

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
