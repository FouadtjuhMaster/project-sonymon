class PLAYER : public MAP {
      public:
            PLAYER();
            ~PLAYER();
             
             //properties
             int movedUp;
             int movedDown;
             int movedLeft;
             int movedRight;
             int position;
             unsigned short tile;
             IMAGE * image;
             bool toggled;
             
             //behaviors
	         inline void Update(const char * playerName, OSL_MAP * map);
	         
	  private:
            int maxUp;
            int maxDown;
            int maxLeft;
            int maxRight;
            int march;
            int manip;
            
            inline void SpriteAnimate( void );
             
}player;

inline void PLAYER::Update(const char * playerName, OSL_MAP * map)
{
     if(allowSearch) oslDrawImage(linkOn);
     else            oslDrawImage(linkOff);
   
     if(toggled)
     {
        oslSetFont(verdana);
        oslSetTextColor(WHITE);
        oslPrintf_xy(5,5, "DEBUG MODE");
        oslPrintf_xy(5, 15, "player map x  = %d  player map y = %d", map->scrollX, map->scrollY);
        oslPrintf_xy(5, 25, "player->x = %d  player->y = %d", image->x, image->y);
     }
     
    //set max movement points
    if(area == HOME){
        maxLeft = 50;
        maxRight = 1400;
        maxDown = 1000;
        maxUp = 400;
    }
    else if(area == UPLINK_CENTER){
        maxLeft = 9999;
        maxRight = 9999;
        maxUp = 9999;
        maxDown = 9999;
    }
    
    if (image->x <= 1)   image->x = 1;
    if (image->y <= 1)   image->y = 1;
    if (image->x >= 460) image->x = 460;
    if (image->y >= 239) image->y = 239;
   
    oslReadKeys();
    
    //create an object of class MAP
    MAP check;
    
    if(osl_keys->pressed.R)
         {oslPlaySound(beep, 2);if(allowSearch) allowSearch = 0; else allowSearch = 1;}
   
    if(osl_keys->pressed.start) 
         menu.pauseGame(playerName);
    
    if(osl_keys->pressed.select)
         {if(!toggled) toggled = true; else toggled = false;}
          
    if (osl_keys->held.left && check.CheckTileCollision(map,image,0))
    {
       position = LEFT;        
       if(movedLeft < maxLeft && image->x == 240){map->scrollX-=2; movedLeft += 2; movedRight -= 2;}
       else {image->x-=2;}
       
       SpriteAnimate(); 
    }
     
    else if (osl_keys->held.right && check.CheckTileCollision(map,image,1))
    {
       position = RIGHT; 
       if(movedRight < maxRight && image->x == 240){map->scrollX+= 2; movedRight += 2; movedLeft -= 2;}
       else {image->x += 2;}
       
       SpriteAnimate(); 
    }
             
    else if (osl_keys->held.up && check.CheckTileCollision(map,image,2))
    {
       position = UP; 
       if(movedUp < maxUp && image->y == 121){map->scrollY-=2; movedUp += 2; movedDown -= 2;}
       else {image->y--;}
       
       SpriteAnimate();  
    }
     
    else if (osl_keys->held.down && check.CheckTileCollision(map,image,3))
    {
       position = DOWN;
       if(movedDown < maxDown && image->y == 121){map->scrollY+=2; movedDown +=2; movedUp -= 2;}
       else {image->y++;}
       
       SpriteAnimate(); 
    }
   
    else if (!osl_keys->held.value) 
          {march = 0; oslSetImageTileSize(image,0,position,23,32);}
    
     return;
}

inline void PLAYER::SpriteAnimate( void )
{	
    //Moves the sprite in the row that it is in
    manip++; if(manip > 11) {march++; manip = 0;}
    
    oslSetImageTileSize(image,(march * 23),position,23,32);
    
    if (march == 2) march = 0;
}
	

PLAYER::PLAYER()
{
    manip = 0;
    position = DOWN;
    march = 0;
    money = 0;
    toggled = false;
    
    return;
}

PLAYER::~PLAYER()
{
     return;
}
