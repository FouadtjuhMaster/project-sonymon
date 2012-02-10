class PLAYER : public MAP
{
      public:
            PLAYER();
            ~PLAYER();
            
             unsigned short tile;
             
             void DrawInfo(int &WordsToggled, const int gameMode);
             inline void SpriteAnimate( void );
	         inline void ReadKeys(const char * playerName, OSL_MAP * map);
	         
	         
	         
	  private:
            
}player;
  
/*
void PLAYER::DetectCenterEnds()
{
     if(zero->x >= 184 && zero->x <= 256 && zero->y > 216) {seenEntrance = 1;}
     else seenEntrance = 0;

     if(seenEntrance)
        object = "entrance";
     
     if(seenEntrance == 0)
        object = "NULL";
        
     if(zero->x >= 184 && zero->x <= 256 && zero->y > 238) {
                InsideCenter = 0; area = 0;
                oslStopSound(center_music); 
                oslPlaySound(gameMusic, 1); 
                oslSetSoundLoop(gameMusic, 1);
     }
     
     return;
}*/


inline void PLAYER::ReadKeys(const char * playerName, OSL_MAP * map)
{
    zeroMapX = map->scrollX;
    zeroMapY = map->scrollY;
    if (zero->x <= 1)   zero->x = 1;
    if (zero->y <= 1)   zero->y = 1;
    if (zero->x >= 460) zero->x = 460;
    if (zero->y >= 239) zero->y = 239;
   
    oslReadKeys();
    
    //create an object of class MAP
    MAP check;
    
    if(osl_keys->pressed.R)
         {oslPlaySound(beep, 2);if(allowSearch) allowSearch = 0; else allowSearch = 1;}
   
    if(osl_keys->pressed.L && osl_keys->pressed.R) 
          oslQuit();
          
    if (osl_keys->held.left && check.CheckTileCollision(map,zero,0))
    {
       sprite_position = LEFT;        
       map->scrollX-=2;
       SpriteAnimate(); 
    }
     
    else if (osl_keys->held.right && check.CheckTileCollision(map,zero,1))
    {
       sprite_position = RIGHT; 
       map->scrollX+= 2;
       SpriteAnimate(); 
    }
             
    else if (osl_keys->held.up && check.CheckTileCollision(map,zero,2))
    {
       sprite_position = UP; 
       map->scrollY-=2;
       SpriteAnimate();  
    }
     
    else if (osl_keys->held.down && check.CheckTileCollision(map,zero,3))
    {
       sprite_position = DOWN;
       map->scrollY+=2;
       SpriteAnimate(); 
    }
    
    else if(osl_keys->pressed.start) 
         menu.pauseGame(playerName);
    
    else if(osl_keys->pressed.select)
         {if(Toggle1 != 1)Toggle1 = 1; else Toggle1 = 0;}
   
    else if (!osl_keys->held.value) 
          {sprite_march = 0; oslSetImageTileSize(zero,0,sprite_position,23,32);}
    
     return;
}


void PLAYER::DrawInfo(int &WordsToggled, const int gameMode)
{
     //handle device stats
     if(gameMode == FREE_ROAM){
         if(allowSearch) oslDrawImage(linkOn);
         else            oslDrawImage(linkOff);
     }
     else if(gameMode == STORY){  
         if(allowSearch && introPassed) oslDrawImageSimple(linkOn);
         else           {if(introPassed){oslDrawImageSimple(linkOff);}}
     }
   
     if(WordsToggled)
     {
        oslSetBkColor(RGBA(0,0,0,0));
        oslSetTextColor(WHITE);
        oslSetFont(verdana);
        oslPrintf_xy(5,5,"RADIATION PRESENT: %s", radiation);
        oslPrintf_xy(5,17,"DEVICE FREQUENCY: %s", Hz);
     
        oslSetBkColor(RGBA(0,0,0,0));
        oslSetTextColor(RED);
        oslSetFont(verdana);
        oslPrintf_xy(5,29,"EXPOSURE COUNT: %i", exposure);
   
        //draw object const char* info
        oslSetFont(verdana);
        oslPrintf_xy(406, 30, "%s", object);
        oslSetTextColor(WHITE);
        oslPrintf_xy(190, 210, "zeroMapX = %f  zeroMapY = %f", zeroMapX, zeroMapY);
        oslPrintf_xy(295, 225, "zero->x = %i  zero->y = %i", zero->x, zero->y);
     }
   
     return;
}

inline void PLAYER::SpriteAnimate( void )
{	
    //Moves the sprite in the row that it is in
    manipulate++; if(manipulate > 11) {sprite_march++; manipulate = 0;}
    
    oslSetImageTileSize(zero,(sprite_march * 23),sprite_position,23,32);
    
    if (sprite_march == 2) sprite_march = 0;
}
	

PLAYER::PLAYER()
{
     return;
}

PLAYER::~PLAYER()
{
     return;
}
