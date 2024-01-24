# All the bouncing stuff using C++ and SFML

# 1.) Bouncing Miao Meme
This is my first C++ and SFML game program

For setting up SFML, I am following steps in this YouTube video
https://www.youtube.com/watch?v=lFzpkvrscs4&list=LL&index=1

The source file is Cat_meme_bouncing.cpp

Output of the program

![image](https://github.com/taebearr/bouncing_miao_meme/assets/19384530/872969f3-a162-4745-b71f-5e29c453f53c)

# 2.) Colourful balls boink
This is a program where user can define circle and rectangle shapes in the config file and it will bounces in the window.

Font ttf file is downloaded from https://www.fontspace.com/

User can add and define the shapes(circle/rectangle), size, speed, and color in the config.txt

![image](https://github.com/taebearr/all_the_bouncing_stuff/assets/19384530/599bae27-53a2-4b2f-867f-20aac5986327)

Format

Rectangle N X Y SX SY R G B W H R
- Defines a Rectangle shape with:
  Shape Name  Name  std::string
  Initial Position  (X,Y)   float, float
  Initial Speed  (SX,SY)  float, float
  RGB Color  (R,G,B)  int, int, int
  Size  (W,H)  float, float
  Radius  R  float ---> (define 0 for rectangle)

Circle N X Y SX SY R G B W H R
- Defines a Rectangle shape with:
  Shape Name  Name  std::string
  Initial Position  (X,Y)   float, float
  Initial Speed  (SX,SY)  float, float
  RGB Color  (R,G,B)  int, int, int
  Size  (W,H)  float, float ---> (define 0, 0 for circle shape)
  Radius  R  float


Output of the program

![image](https://github.com/taebearr/all_the_bouncing_stuff/assets/19384530/aee0a0f9-7d61-4fb8-93bf-38bc2beb05aa)




