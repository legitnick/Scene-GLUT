## Teleport game in 3D (OpenGL)

This is an old OpenGL project, which is made with GLUT because I have an 12 year old notebook which does not support modern OpenGL, such as 3.3
 This was only tested on Ubuntu, nothing else
 Install dependencies with these commands:
 ```
 sudo apt-get install freeglut3 freeglut3-dev g++ gdb mesa-utils

 ```
The build procedure is also simple:
```shell
> g++ *.cpp -lGL -lGLU -lglut -g -o program
> ./program
```
**Done!**

![Screen1](https://github.com/legitnick/Scene-GLUT/tree/another_b/screenshots/room.png "Picture 1 - Room at the start")
![Screen2](https://github.com/legitnick/Scene-GLUT/tree/another_b/screenshots/room2.png "Picture 2 - Room after movement")
![Screen3](https://github.com/legitnick/Scene-GLUT/tree/another_b/screenshots/win.png "Picture 3 - Scene showed if you've won")
![Screen4](https://github.com/legitnick/Scene-GLUT/tree/another_b/screenshots/lose.png "Picture 4 - Scene showed if you've lost")
![Screen5](https://github.com/legitnick/Scene-GLUT/tree/another_b/screenshots/statistics.png "Picture 5 - Statistics of the game printed to console and saved on the disk")
  
