**Animating sonymon attacks**

This page is for documentation purposes only. It will be used as a reference to current and future developers on our team on how to animate moves in sonymon




_Lets say we have a **move** defined globally like this:_
```
const int TACKLE = 1;
```




_and a **class** defined like this:_
```
class ANIMATE 
{
   public:
            //constructor and destructor
            ANIMATE();
            ~ANIMATE();
                
            //method that animates the player's sonymon attack move
            void animateMovePlayer(int move, const char * name, OSL_IMAGE * sonymon, OSL_IMAGE *enemy, OSL_IMAGE * background);

    private:
             int originalx;
             int originaly; 
             int eoriginalx;
             int eoriginaly;
             float originalAngle;
             float eoriginalAngle;
             
};
```




Now that we have a **class** and a **move** defined let's define that function from **class ANIMATE**
```
ANIMATE::animateMovePlayer(int move, const char * name, OSL_IMAGE * sonymon, OSL_IMAGE * enemy, OSL_IMAGE * background)
{
     
     //save original positions
     originalx = sonymon->x;
     originaly = sonymon->y;
     eoriginalx = enemy->x;
     eoriginaly = enemy->y;
     originalAngle = sonymon->angle;
     eoriginalAngle = enemy->angle;
    
     //if the move our sonymon used is tackle then lets animate it
     if(move == TACKLE)
      {
         //move sonymon forward
         for(sonymon->x = originalx; sonymon->x < 65; sonymon->x+=2)
          {
             oslStartDrawing();
             oslDrawImageSimple(background);
             oslDrawImageSimple(enemy);
             oslDrawImageSimple(sonymon);
             oslDrawImageSimple(messageBox);
             
             oslSetFont(verdana);
             oslSetTextColor(BLACK);
             oslSetBkColor(RGBA(0,0,0,0));
             oslPrintf_xy(18, 216, "%s used tackle", name);
             
             oslEndDrawing();
             oslSyncFrame();
          }
         
          //about now the move is half way from finishing so play whatever sound you have for tackle
          oslPlaySound(tackle_sound, 2);
         
          //move sonymon backward
          for(sonymon->x = sonymon->x; sonymon->x > originalx; sonymon->x--)
           {
              oslStartDrawing();
              oslDrawImageSimple(background);
              oslDrawImageSimple(enemy);
              oslDrawImageSimple(sonymon);
              oslDrawImageSimple(messageBox);
             
              oslSetFont(verdana);
              oslSetTextColor(BLACK);
              oslSetBkColor(RGBA(0,0,0,0));
              oslPrintf_xy(18, 216, "%s used tackle", name);
             
              oslEndDrawing();
              oslSyncFrame();
            }   
     
      }

      //reset points
      sonymon->x = originalx;
      sonymon->y = originaly;
      enemy->x = eoriginalx;
      enemy->y = eoriginaly;
      sonymon->angle = originalAngle;
      enemy->angle = eoriginalAngle;
     
     return;
}
```


Now every time the player's sonymon selects a move we can call this function and it will the animate the move as longs as its **tackle**.