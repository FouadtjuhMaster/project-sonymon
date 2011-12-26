class ANIMATE
{
      public:
             ANIMATE();
             ~ANIMATE();
             
             //animation methods
             void animateMovePlayer(int move, const char * name, OSL_IMAGE * sonymon, OSL_IMAGE * enemy, OSL_IMAGE * background);
             void animateMoveEnemy(int move, const char * name, OSL_IMAGE * sonymon, OSL_IMAGE * enemy, OSL_IMAGE * background);
             /* moves aminated:
                      tackle
                      slam
                      uplink
                      pound
                      jumpKick
                      contaminate
                      clobber
                      steroids
                      
                      NEEDS ANIMATION:
                            -leech
                            -blaze
                            -watergun
                            -gust
             */
             
             void frontDie(OSL_IMAGE *image, int XP, const char * writeDeath, OSL_IMAGE *playerSonymon, OSL_IMAGE *background);
             void flashHurtEnemy(OSL_IMAGE * sonymon, OSL_IMAGE * enemy, OSL_IMAGE * background);
             void flashHurtPlayer(OSL_IMAGE * sonymon, OSL_IMAGE * enemy, OSL_IMAGE * background);
      
      private:
            int originalx;
            int originaly; 
            int eoriginalx;
            int eoriginaly;
            float originalAngle;
            float eoriginalAngle;
             
}animate;

ANIMATE::ANIMATE()
{
    originalx = 0;
    originaly = 0;
    eoriginalx = 0;
    eoriginaly = 0;
    originalAngle = 0.0;
    eoriginalAngle = 0.0;
    
    return;
}

ANIMATE::~ANIMATE()
{
     return;
}

void ANIMATE::animateMovePlayer(int move, const char * name, OSL_IMAGE * sonymon, OSL_IMAGE * enemy, OSL_IMAGE * background)
{
     originalx = sonymon->x;
     originaly = sonymon->y;
     eoriginalx = enemy->x;
     eoriginaly = enemy->y;
     originalAngle = sonymon->angle;
     eoriginalAngle = enemy->angle;
     
     //if side is 1, player sonymon will be the one attacking
     if(move == tackle)
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
     
     else if(move == steroids)
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
             oslPrintf_xy(18, 216, "%s used steroids", name);
             
             oslEndDrawing();
             oslSyncFrame();
         }
         
         oslPlaySound(steroids_sound, 2);
         
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
             oslPrintf_xy(18, 216, "%s used steroids", name);
             
             oslEndDrawing();
             oslSyncFrame();
         }   
     
     }
     
     else if(move == slam)
     {
         //move sonymon forward
         for(sonymon->x = originalx; sonymon->x < 85; sonymon->x+=4)
         {
             oslStartDrawing();
             oslDrawImageSimple(background);
             oslDrawImageSimple(enemy);
             oslDrawImageSimple(sonymon);
             oslDrawImageSimple(messageBox);
             
             oslSetFont(verdana);
             oslSetTextColor(BLACK);
             oslSetBkColor(RGBA(0,0,0,0));
             oslPrintf_xy(18, 216, "%s used slam", name);
             
             oslEndDrawing();
             oslSyncFrame();
         }
         
         oslPlaySound(slam_sound, 2);
         
         //move sonymon backward and enemy forward
         for(sonymon->x = sonymon->x; sonymon->x > originalx; sonymon->x--)
         {
             if(enemy->x <= 345) enemy->x += 3;
             oslStartDrawing();
             oslDrawImageSimple(background);
             oslDrawImageSimple(enemy);
             oslDrawImageSimple(sonymon);
             oslDrawImageSimple(messageBox);
             
             oslSetFont(verdana);
             oslSetTextColor(BLACK);
             oslSetBkColor(RGBA(0,0,0,0));
             oslPrintf_xy(18, 216, "%s used slam", name);
             
             oslEndDrawing();
             oslSyncFrame();
         }  
          
     }
     
     else if(move == pound)
     {
          int i, j;
          j = 0;
          oslPlaySound(pound_sound, 2);
          pound_mark->x = enemy->x + 20;
          pound_mark->y = enemy->y;
          
         for(i = 0; i < 70; i++)
         {
             oslStartDrawing();
             oslDrawImageSimple(background);
             oslDrawImageSimple(enemy);
             oslDrawImageSimple(sonymon);
             oslDrawImageSimple(messageBox);
             
             //little animation used for pound
             j++;
             if(j > 0) oslDrawImageSimple(pound_mark);
             if(j > 40) j = -6000;
             
             oslSetFont(verdana);
             oslSetTextColor(BLACK);
             oslSetBkColor(RGBA(0,0,0,0));
             oslPrintf_xy(18, 216, "%s used pound", name);
             
             oslEndDrawing();
             oslSyncFrame();
         }
          
     }
     
     else if(move == uplink)
     {
          int garb = 0;
          int moreGarb = 0;
          int bleh = 0;
          oslPlaySound(uplink_sound, 2);
          
         //move sonymon forward
         for(garb = 0; garb < 120; garb++)
         {
             //shake characters
             moreGarb++;
             if(moreGarb < 20) {sonymon->x+=4; enemy->x-=2;}
             if(moreGarb > 40) {sonymon->x-=4; enemy->x+=2;}
             if(moreGarb > 60) moreGarb = 0;
             
             //randomly flash
             bleh++;
             if(bleh > 20) oslClearScreen(BLACK);
             if(bleh > 30) bleh = -6000;
             
             oslStartDrawing();
             oslDrawImageSimple(background);
             oslDrawImageSimple(enemy);
             oslDrawImageSimple(sonymon);
             oslDrawImageSimple(messageBox);
             
             oslSetFont(verdana);
             oslSetTextColor(BLACK);
             oslSetBkColor(RGBA(0,0,0,0));
             oslPrintf_xy(18, 216, "%s used uplink", name);
             
             oslEndDrawing();
             oslSyncFrame();
         }
          
     }
     
     else if(move == jumpKick)
     {
          //move sonymon forward and upward
         for(sonymon->x = originalx; sonymon->x < 85; sonymon->x+=4)
         {
             sonymon->y--;
             
             oslStartDrawing();
             oslDrawImageSimple(background);
             oslDrawImageSimple(enemy);
             oslDrawImageSimple(sonymon);
             oslDrawImageSimple(messageBox);
             
             oslSetFont(verdana);
             oslSetTextColor(BLACK);
             oslSetBkColor(RGBA(0,0,0,0));
             oslPrintf_xy(18, 216, "%s used jumpKick", name);
             
             oslEndDrawing();
             oslSyncFrame();
         }
         
         oslPlaySound(jumpKick_sound, 2);
         
         //move sonymon backward and enemy forward
         for(sonymon->x = sonymon->x; sonymon->x > originalx; sonymon->x--)
         {
             if(sonymon->y <= originaly) sonymon->y++;
             if(enemy->x <= 345) enemy->x += 3;
             oslStartDrawing();
             oslDrawImageSimple(background);
             oslDrawImageSimple(enemy);
             oslDrawImageSimple(sonymon);
             oslDrawImageSimple(messageBox);
             
             oslSetFont(verdana);
             oslSetTextColor(BLACK);
             oslSetBkColor(RGBA(0,0,0,0));
             oslPrintf_xy(18, 216, "%s used jumpKick", name);
             
             oslEndDrawing();
             oslSyncFrame();
         } 
     }
     
     else if(move == contaminate)
     {
          int i;
          int MAXHIGH = originaly - 20;
          int MAXLOW = originaly + 20;
          int CHANGEDH = 0;
          int CHANGEDL = 1; //begin shifting
          OSL_IMAGE * manipulateEnemy = NULL;
          oslCopyImage(manipulateEnemy, enemy);
          if(!manipulateEnemy)
             oslWarning("ERROR! Failed to copy image in animation method!!");
          
          oslClearImage(manipulateEnemy, SPRING_GREEN);
          oslPlaySound(contaminate_sound, 2);
          
          for(i = 0; i < 200; i++)
          {
                oslStartDrawing();
                
                //if the sonymon image has reached MAXLOW shift upwards
                if(CHANGEDL) sonymon->x--;
                
                //if the sonymon image has reached MAXHIGH shift downwards
                if(CHANGEDH) sonymon->x++;
                
                //handle and manipulate CHANGEDH and CHANGEDL based on sonymon->x
                if(sonymon->x == MAXHIGH){CHANGEDL = 0; CHANGEDH = 1;}
                if(sonymon->x == MAXLOW){CHANGEDH = 0; CHANGEDL = 1;}
                
                oslDrawImageSimple(background);
                oslDrawImageSimple(manipulateEnemy);
                oslDrawImageSimple(sonymon);
                oslDrawImageSimple(messageBox);
             
                oslSetFont(verdana);
                oslSetTextColor(BLACK);
                oslSetBkColor(RGBA(0,0,0,0));
                oslPrintf_xy(18, 216, "%s used contaminate", name);
          }
     }
     
     else if(move == clobber)
     {
          int i;
          
          oslPlaySound(clobber_sound, 2);
          
          for(i = 0; i < 100; i++)
          {
                oslStartDrawing();
                
                enemy->angle +=2;
                
                oslDrawImage(background);
                oslDrawImage(enemy);
                oslDrawImage(sonymon);
                oslDrawImage(messageBox);
                
                oslSetFont(verdana);
                oslSetTextColor(BLACK);
                oslSetBkColor(RGBA(0,0,0,0));
                oslPrintf_xy(18, 216, "%s used clobber", name);
          }
     }
     
     else oslWarning("ERROR! Animation has not been coded for this move yet!!!");

     //reset points
     sonymon->x = originalx;
     sonymon->y = originaly;
     enemy->x = eoriginalx;
     enemy->y = eoriginaly;
     sonymon->angle = originalAngle;
     enemy->angle = eoriginalAngle;
     
     return;
}

void ANIMATE::animateMoveEnemy(int move, const char * name, OSL_IMAGE * sonymon, OSL_IMAGE * enemy, OSL_IMAGE * background)
{   
     originalx = sonymon->x;
     originaly = sonymon->y;
     eoriginalx = enemy->x;
     eoriginaly = enemy->y;
     originalAngle = sonymon->angle;
     eoriginalAngle = enemy->angle;
     
     //if side is 1, player sonymon will be the one attacking
     if(move == tackle)
     {   
         //move sonymon forward
         for(enemy->x = eoriginalx; enemy->x > 275; enemy->x-=2)
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
         
         oslPlaySound(tackle_sound, 2);
         
         //move enemy back
         for(enemy->x = enemy->x; enemy->x < eoriginalx; enemy->x++)
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
     
     else if(move == steroids)
     {   
         //move sonymon forward
         for(enemy->x = eoriginalx; enemy->x > 275; enemy->x-=2)
         {
             oslStartDrawing();
             oslDrawImageSimple(background);
             oslDrawImageSimple(enemy);
             oslDrawImageSimple(sonymon);
             oslDrawImageSimple(messageBox);
             
             oslSetFont(verdana);
             oslSetTextColor(BLACK);
             oslSetBkColor(RGBA(0,0,0,0));
             oslPrintf_xy(18, 216, "%s used steroids", name);
             
             oslEndDrawing();
             oslSyncFrame();
         }
         
         oslPlaySound(steroids_sound, 2);
         
         //move enemy back
         for(enemy->x = enemy->x; enemy->x < eoriginalx; enemy->x++)
         {
             oslStartDrawing();
             oslDrawImageSimple(background);
             oslDrawImageSimple(enemy);
             oslDrawImageSimple(sonymon);
             oslDrawImageSimple(messageBox);
             
             oslSetFont(verdana);
             oslSetTextColor(BLACK);
             oslSetBkColor(RGBA(0,0,0,0));
             oslPrintf_xy(18, 216, "%s used steroids", name);
             
             oslEndDrawing();
             oslSyncFrame();
         }   
     
     }
     
     else if(move == pound)
     {
          int i, j;
          j = 0;
          oslPlaySound(pound_sound, 2);
          pound_mark->x = sonymon->x + 40;
          pound_mark->y = sonymon->y;
          
         for(i = 0; i < 70; i++)
         {
             oslStartDrawing();
             oslDrawImageSimple(background);
             oslDrawImageSimple(enemy);
             oslDrawImageSimple(sonymon);
             oslDrawImageSimple(messageBox);
             
             //little animation used for pound
             j++;
             if(j > 0) oslDrawImageSimple(pound_mark);
             if(j > 40) j = -6000;
             
             oslSetFont(verdana);
             oslSetTextColor(BLACK);
             oslSetBkColor(RGBA(0,0,0,0));
             oslPrintf_xy(18, 216, "%s used pound", name);
             
             oslEndDrawing();
             oslSyncFrame();
         }
          
     }
     
     else if(move == slam)
     {   
         //move sonymon forward
         for(enemy->x = eoriginalx; enemy->x < 275; sonymon->x-=4)
         {
             oslStartDrawing();
             oslDrawImageSimple(background);
             oslDrawImageSimple(enemy);
             oslDrawImageSimple(sonymon);
             oslDrawImageSimple(messageBox);
             
             oslSetFont(verdana);
             oslSetTextColor(BLACK);
             oslSetBkColor(RGBA(0,0,0,0));
             oslPrintf_xy(18, 216, "%s used slam", name);
             
             oslEndDrawing();
             oslSyncFrame();
         }
         
         oslPlaySound(slam_sound, 2);
         
         //move sonymon backward and enemy forward
         for(enemy->x = enemy->x; enemy->x < eoriginalx; enemy->x++)
         {
             if(enemy->x <= 15) sonymon->x -= 3;
             oslStartDrawing();
             oslDrawImageSimple(background);
             oslDrawImageSimple(enemy);
             oslDrawImageSimple(sonymon);
             oslDrawImageSimple(messageBox);
             
             oslSetFont(verdana);
             oslSetTextColor(BLACK);
             oslSetBkColor(RGBA(0,0,0,0));
             oslPrintf_xy(18, 216, "%s used slam", name);
             
             oslEndDrawing();
             oslSyncFrame();
         }  
          
     }
     
     else if(move == uplink)
     {
          int garb = 0;
          int moreGarb = 0;
          int bleh = 0;
          oslPlaySound(uplink_sound, 2);
          
         //move sonymon forward
         for(garb = 0; garb < 120; garb++)
         {
             //shake characters
             moreGarb++;
             if(moreGarb < 20) {enemy->x-=4; sonymon->x+=2;}
             if(moreGarb > 40) {enemy->x+=4; sonymon->x-=2;}
             if(moreGarb > 60) moreGarb = 0;
             
             //randomly flash
             bleh++;
             if(bleh > 20) oslClearScreen(BLACK);
             if(bleh > 30) bleh = -6000;
             
             oslStartDrawing();
             oslDrawImageSimple(background);
             oslDrawImageSimple(enemy);
             oslDrawImageSimple(sonymon);
             oslDrawImageSimple(messageBox);
             
             oslSetFont(verdana);
             oslSetTextColor(BLACK);
             oslSetBkColor(RGBA(0,0,0,0));
             oslPrintf_xy(18, 216, "%s used uplink", name);
             
             oslEndDrawing();
             oslSyncFrame();
         }
          
     }
     
     else if(move == jumpKick)
     {
         //move enemy forward and downward
         for(enemy->x = eoriginalx; enemy->x < 275; sonymon->x-=4)
         {
             enemy->y++;
             
             oslStartDrawing();
             oslDrawImageSimple(background);
             oslDrawImageSimple(enemy);
             oslDrawImageSimple(sonymon);
             oslDrawImageSimple(messageBox);
             
             oslSetFont(verdana);
             oslSetTextColor(BLACK);
             oslSetBkColor(RGBA(0,0,0,0));
             oslPrintf_xy(18, 216, "%s used jumpKick", name);
             
             oslEndDrawing();
             oslSyncFrame();
         }
         
         oslPlaySound(jumpKick_sound, 2);
         
         //move sonymon backward and enemy forward and upward
         for(enemy->x = enemy->x; enemy->x < eoriginalx; enemy->x++)
         {
             if(enemy->y >= eoriginaly) enemy->y--;
             if(enemy->x <= 15) sonymon->x -= 3;
             oslStartDrawing();
             oslDrawImageSimple(background);
             oslDrawImageSimple(enemy);
             oslDrawImageSimple(sonymon);
             oslDrawImageSimple(messageBox);
             
             oslSetFont(verdana);
             oslSetTextColor(BLACK);
             oslSetBkColor(RGBA(0,0,0,0));
             oslPrintf_xy(18, 216, "%s used jumpKick", name);
             
             oslEndDrawing();
             oslSyncFrame();
         } 
     }
     
     else if(move == contaminate)
     {
          int i;
          int MAXHIGH = eoriginaly - 20;
          int MAXLOW = eoriginaly + 20;
          int CHANGEDH = 0;
          int CHANGEDL = 1; //begin shifting
          OSL_IMAGE * manipulateSonymon = NULL;
          oslCopyImage(manipulateSonymon, sonymon);
          if(!manipulateSonymon)
             oslWarning("ERROR! Failed to copy image in animation method!!");
          
          oslClearImage(manipulateSonymon, SPRING_GREEN);
          oslPlaySound(contaminate_sound, 2);
          
          for(i = 0; i < 200; i++)
          {
                oslStartDrawing();
                
                //if the sonymon enemy has reached MAXLOW shift upwards
                if(CHANGEDL) enemy->x--;
                
                //if the sonymon enemy has reached MAXHIGH shift downwards
                if(CHANGEDH) enemy->x++;
                
                //handle and manipulate CHANGEDH and CHANGEDL based on sonymon->x
                if(sonymon->x == MAXHIGH){CHANGEDL = 0; CHANGEDH = 1;}
                if(sonymon->x == MAXLOW){CHANGEDH = 0; CHANGEDL = 1;}
                
                oslDrawImageSimple(background);
                oslDrawImageSimple(manipulateSonymon);
                oslDrawImageSimple(enemy);
                oslDrawImageSimple(messageBox);
             
                oslSetFont(verdana);
                oslSetTextColor(BLACK);
                oslSetBkColor(RGBA(0,0,0,0));
                oslPrintf_xy(18, 216, "%s used contaminate", name);
          }
     }
     
     else if(move == clobber)
     {
          int i;
          oslPlaySound(clobber_sound, 2);
          
          for(i = 0; i < 200; i++)
          {
                oslStartDrawing();
                
                sonymon->angle +=2;
                
                oslDrawImage(background);
                oslDrawImage(enemy);
                oslDrawImage(sonymon);
                oslDrawImage(messageBox);
                
                oslSetFont(verdana);
                oslSetTextColor(BLACK);
                oslSetBkColor(RGBA(0,0,0,0));
                oslPrintf_xy(18, 216, "%s used clobber", name);
          }
     }
     
     else oslWarning("ERROR! Animation has not been coded for this move yet!!!");

     //reset points
     sonymon->x = originalx;
     sonymon->y = originaly;
     enemy->x = eoriginalx;
     enemy->y = eoriginaly;
     sonymon->angle = originalAngle;
     enemy->angle = eoriginalAngle;
     
     return;
}

void ANIMATE::frontDie(OSL_IMAGE *image, int XP, const char * writeDeath, OSL_IMAGE *playerSonymon, OSL_IMAGE *background)
{
     unsigned i;
     int sonymon_xp, sonymon_max_xp, sonymon_level, sonymon_id;
     float originalx, originaly;
     const char * sonymonName = "???";
     sonymon_id = 1;
     
     //set stats
     if(sonymon_num == 1)     {sonymon_id = sonymon1_id; sonymon_level = sonymon1_level; sonymon_xp = sonymon1_xp; sonymon_max_xp = sonymon1_max_xp; sonymonName = sonymon1_name;}
     else if(sonymon_num == 2){sonymon_id = sonymon2_id; sonymon_level = sonymon2_level; sonymon_xp = sonymon2_xp; sonymon_max_xp = sonymon2_max_xp; sonymonName = sonymon2_name;}
     else if(sonymon_num == 3){sonymon_id = sonymon3_id; sonymon_level = sonymon3_level; sonymon_xp = sonymon3_xp; sonymon_max_xp = sonymon3_max_xp; sonymonName = sonymon3_name;}
     
     originalx = image->x;
     originaly = image->y;
     
     ClearMessageBox();
     
     oslStartDrawing();
     oslClearScreen(RGBA(0,0,0,0));
     oslEndDrawing();
     oslSyncFrame();
     
     for(i = 0; i < 50; i++)
     {
           oslStartDrawing();
           image->y++;
           oslDrawImageSimple(background);
           oslDrawImageSimple(playerSonymon);
           oslDrawImage(image);
           oslDrawImageSimple(messageBox);
           oslSyncFrame();
           oslEndDrawing();
     }
     
     image->x = originalx;
     image->y = originaly;
     
     for(pointer->y = 240; pointer->y < 252; pointer->y++)
     {
             if(pointer->y > 250) pointer->y = 240;
             
             oslReadKeys();
             if(osl_keys->pressed.cross)
             { oslPlaySound(beep, 2); break; }
             
             oslStartDrawing();
             oslDrawImage(background);
             oslDrawImageSimple(playerSonymon);
             oslDrawImage(messageBox);
             oslDrawImage(pointer);
             oslSetFont(verdana);
             oslSetBkColor(RGBA(0,0,0,0));
             oslSetTextColor(BLACK);
             oslPrintf_xy(18, 216, "%s fainted...", enemyName);
             oslEndDrawing();
             oslSyncFrame();
     }
     
     for(pointer->y = 240; pointer->y < 252; pointer->y++)
     {
             if(pointer->y > 250) pointer->y = 240;
             
             oslReadKeys();
             if(osl_keys->pressed.cross)
             { oslPlaySound(beep, 2); break; }
             
             oslStartDrawing();
             oslDrawImageSimple(playerSonymon);
             oslDrawImage(messageBox);
             oslDrawImage(pointer);
             oslSetFont(verdana);
             oslSetBkColor(RGBA(0,0,0,0));
             oslSetTextColor(BLACK);
             oslPrintf_xy(18, 216, "%s gained %i exp points", sonymonName, XP);
             oslEndDrawing();
             oslSyncFrame();
     }
     
     //add the xp
     if(sonymon_num == 1) sonymon1_xp += XP;
     else if(sonymon_num == 2) sonymon2_xp += XP;
     else if(sonymon_num == 3) sonymon3_xp += XP;
       
     //if the sonymon leveled up show it
     if(sonymon1_xp > sonymon1_max_xp || sonymon2_xp > sonymon2_max_xp || sonymon3_xp > sonymon3_max_xp)
     {
         STATS stats;
         stats.LEVEL_UP(sonymon_num,  sonymon_id);
         oslPlaySound(found, 2);
         
         int sonymonLevel = 2;
         if(sonymon_num == 1)      sonymonLevel = sonymon1_level;
         else if(sonymon_num == 2) sonymonLevel = sonymon2_level;
         else if(sonymon_num == 3) sonymonLevel = sonymon3_level;
         
         for(pointer->y = 240; pointer->y < 252; pointer->y++)
         {
             if(pointer->y > 250) pointer->y = 240;
             
             oslReadKeys();
             if(osl_keys->pressed.cross)
             { oslPlaySound(beep, 2); break; }
             
             oslStartDrawing();
             oslDrawImage(playerSonymon);
             oslDrawImage(messageBox);
             oslDrawImage(pointer);
             oslSetFont(verdana);
             oslSetBkColor(RGBA(0,0,0,0));
             oslSetTextColor(BLACK);
             oslPrintf_xy(18, 216, "%s reached level %i", sonymonName, sonymonLevel);
             oslEndDrawing();
             oslSyncFrame();
          }
     }
                    

     
     
     return;
}

void ANIMATE::flashHurtEnemy(OSL_IMAGE * sonymon, OSL_IMAGE * enemy, OSL_IMAGE * background)
{
     int j = 0;
     int originalx = enemy->x;
     int originaly = enemy->y;
     
     for(int i = 0; i < 86; i++)
     {
           j++;
           oslStartDrawing();
           oslDrawImage(background);
           oslDrawImage(sonymon);
           if(j > 10) {oslDrawImage(enemy); j = 0;}
           oslDrawImage(messageBox);
           oslSyncFrame();
           oslEndDrawing();
     }
     
     enemy->x = originalx;
     enemy->y = originaly;
     
     oslStartDrawing();
     oslDrawImageSimple(enemy);
     oslDrawImageSimple(sonymon);
     oslDrawImage(messageBox);
     oslEndDrawing();
     oslSyncFrame();
     
     return;
}

void ANIMATE::flashHurtPlayer(OSL_IMAGE * sonymon, OSL_IMAGE * enemy, OSL_IMAGE * background)
{
     unsigned i, j;
     float originalx, originaly;
     
     j = 0;
     originalx = sonymon->x;
     originaly = sonymon->y;
     
     for(i = 0; i < 86; i++)
     {
           j++;
           oslStartDrawing();
           oslDrawImage(background);
           oslDrawImage(enemy);
           if(j > 10) {oslDrawImage(sonymon); j = 0;}
           oslDrawImage(messageBox);
           oslSyncFrame();
           oslEndDrawing();
     }
     
     sonymon->x = originalx;
     sonymon->y = originaly;
     
     oslStartDrawing();
     oslDrawImageSimple(enemy);
     oslDrawImageSimple(sonymon);
     oslDrawImage(messageBox);
     oslEndDrawing();
     oslSyncFrame();
     
     return;
}

