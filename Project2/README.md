# Project2: Weather Visualization
![](/img/p2.gif)

This is a visualization of current weather in New York. Using primitive 3D shapes, 2D polyline and type, I created this poster-like animated scene to demonstrate the weather. I was trying to make the visualization not too literal, but still left some subtle connection of how each property would be represented in the real world.

![](/img/p2day.jpeg)

Current time, temperature, wind speed and humidity data are called from Dark Sky API as variables to control the visual elements:
1. Temperature is controling the color of the object as well as the Outter color of background gradient. The color temperature gets warmer or colder following the actual temperture data.
2. Wind speed is controling the rotating speed of the object.
3. Time switches the background between day/night mode. When it's after sunrise and before sunset, day mode is on; when it's after sunset and before sunrise, night mode is on. The inner color of background gradient is white in day mode and black in night mode. The Chinese text shows "Good day" in day and "Hazy moon" at night.
4. Humidity increases/decreases the density of the white curves.

![](/img/p2night.jpeg)

To me, this project is not only practicing using external data in OpenFrameworks, but also to try some new functions I haven't used yet in OF. For example, I learned how to set up a 3D scene with camera, lights and materials. It opens a whole new world of visual possibilities in OF for me. The combination of 3D and 2D also sparked some unexpected effects. Of course there were problems in the learning progress too. You'll see one of them in my demo video: gui is not working well in 3D, which is an unfixed bug of OF. It functions without showing any texts or bars. It's kind of hilarious to see me blind-dragging the gui. Also, I was trying to find a solution to play with Chinese characters. Luckily I got that solved by ofTrueTypeFont.

There are still a lot of potentials in this visual translation. Now the main animation it's just simply rotating the object. It could go further by getting the vertices and changing them in more diverse ways. 

Click the link below to watch the demo video:
https://youtu.be/3HYQoc9zSzk
