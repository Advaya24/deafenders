# Deafenders
## What it does
The application accepts Speech through a microphone and then displays videos that contain the translation American Sign Language (ASL) translation of what has been said.

## What we learned
First and foremost, we learned how to string together applications that work in different languages to make one application that seamlessly offers the best features of all of them. We learned about the possibilities that Machine Learning can open us to, and we're very excited to use it in future projects as well. For some of us, this was our first time working with a Web App, and for others, it was our first time working with Flask. As a result we were able to add important tools to our skillset.

An unforeseen benefit was, in our effort to make the world a more equitable and connected place, we also picked up a bit of ASL ourselves!

## Challenges faced
One of our major challenges was to produce a well-organized idea with a clear goal. Even then, once we had an idea, finding the right resources to start our implementation was difficult. For example, working with Computer Vision libraries and several other tools was technically advanced for our skill level set. When we tried to train our own model too recognize ASL characters, none of our machines were powerful enough to train the model in a reasonable time frame. When we tried to find pre-trained models online that would be able to detect ASL and convert it into text, we struggled to find a model that worked as well as we needed it to. 

Another significant challenge that we faced was figuring out how to transfer data between our Javascript app and our Flask server. This ended up taking a significant amount of time, but ended up being one of the backbones of our application, giving it it's portability and functionality.

## Improvements planned
Currently, the app only supports translation one word at a time. We're very close to enabling translation of sentences, but since this would still end up translating it word by word, we do plan on using better Natural Language Processing in the future to get better semantic information about the audio that is input. We also plan on adding multiple language support through Google Cloud's Translation API.

We also plan on training our own models in Python using Tensorflow to convert ASL input into text, that can then use Google Cloud's Text to Speech API to make this application a two-way communication line. With a bit more development, we can make this into a functioning mobile app as well.

## How to use:
Simply run app.py, and open up the localhost link in your favorite browser (We strongly recommend Chrome). Click Record, speak into your mic, and then click submit. Then watch the video get played right before your eyes!
