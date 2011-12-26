class COMPUTER
{
      public: 
             COMPUTER();
             ~COMPUTER();
             
             OSL_IMAGE * loadImage(int id, bool &loadedimage);
             void ComputerAnimate(OSL_IMAGE * image, int AI, int &manipl, int &march, int position);
             void UpdateAI(OSL_IMAGE * image, const char * message, int AI, int posx, int posy, int &carry, int &position);
             void UpdateAIMap(OSL_IMAGE * image, OSL_MAP * map, const char * message, int AI, int computerMapX, int computerMapY, int &carry, int &position);
             
             int numOfSonymon;
             int x;
             int y;
             int carry;
             int position;
             int march;
             int manip;
             bool loadedImage;
             OSL_IMAGE * image;
             
             const char * message;
             const char * name;
             
      private:
              
};

OSL_IMAGE * COMPUTER::loadImage(int id, bool &loadedImage)
{
    if(!loadedImage)
    {
       oslSetTransparentColor(RGB(255,0,255));
       
       OSL_IMAGE * image = NULL;

       if(id == 0)image = oslLoadImageFile((char*)"img/sprites/male4.png", OSL_IN_RAM, OSL_PF_5551);
	   if(id == 1)image = oslLoadImageFile((char*)"img/sprites/guy1.png", OSL_IN_RAM, OSL_PF_5551);
	   if(id == 2)image = oslLoadImageFile((char*)"img/sprites/guy2.png", OSL_IN_RAM, OSL_PF_5551);
	   if(id == 3)image = oslLoadImageFile((char*)"img/sprites/guy3.png", OSL_IN_RAM, OSL_PF_5551);
	   if(id == 4)image = oslLoadImageFile((char*)"img/sprites/guy4.png", OSL_IN_RAM, OSL_PF_5551);
	   if(id == 5)image = oslLoadImageFile((char*)"img/sprites/guy5.png", OSL_IN_RAM, OSL_PF_5551);
	   if(id == 6)image = oslLoadImageFile((char*)"img/sprites/guy6.png", OSL_IN_RAM, OSL_PF_5551);
	  
	   if(!image)
	     MISSING_IMG_FILES(1);
	     
	    loadedImage = true;
	    
	    oslDisableTransparentColor();

    } 

    return image;
}

void COMPUTER::UpdateAIMap(OSL_IMAGE * image, OSL_MAP * map, const char * message, int AI, int computerMapX, int computerMapY, int &carry, int &position)
{
     image->x = computerMapX - map->scrollX;
     image->y = computerMapY - map->scrollY;
     
     if(image)oslDrawImage(image);
     else oslFatalError("ERROR! IMAGE IS EQUAL TO NULL!!! Found in function void COMPUTER::UpdateAI()");
     
     //basic AI movement
     if(AI == 0)
     {
          carry++;
          if(carry < 0 ) carry = 0;
          if(carry > 0) position = UP;
          if(carry > 120) position = LEFT;
          if(carry > 240) position = DOWN;
          if(carry > 360) position = RIGHT;
          if(carry > 480) carry = 0;
     }
     
     else if(AI == 1)
     {
          carry++;
          if(carry < 0 ) carry = 0;
          if(carry > 0) position = UP;
          if(carry > 60) position = LEFT;
          if(carry > 120) position = DOWN;
          if(carry > 180) position = RIGHT;
          if(carry > 240) carry = 0;
     }
     
     else if(AI == 2)
     {
          carry++;
          if(carry < 0 ) carry = 0;
          if(carry > 0) position = UP;
          if(carry > 20) position = LEFT;
          if(carry > 40) position = DOWN;
          if(carry > 60) position = RIGHT;
          if(carry > 80) carry = 0;
     }
     
     int contact = collision(zero,zero->x, zero->y,image,image->x,image->y );
     
     if(contact && sprite_position == FACING_RIGHT)     
     {
                zero->x = image->x - 23;
                oslSetImageTileSize(image,(1 * 23),LEFT,23,32);
                
                messagebox.MessageBoxMap(message, 1, image, map);
     }
     else if(contact && sprite_position == FACING_LEFT) 
     {
                zero->x = image->x + 23;
                oslSetImageTileSize(image,(1 * 23),RIGHT,23,32);
                
                messagebox.MessageBoxMap(message, 1, image, map);
     }
     
     if(contact && sprite_position == FACING_UP)   
     {
                zero->y = image->y + 34; 
                oslSetImageTileSize(image,(1 * 23),DOWN,23,32);
         
                messagebox.MessageBoxMap(message, 1, image, map);
     }
     else if(contact && sprite_position == FACING_DOWN) 
     {
                zero->y = image->y - 34; 
                oslSetImageTileSize(image,(1 * 23),UP,23,32);

                messagebox.MessageBoxMap(message, 1, image, map);
     }
     
     if(contact && AI == 42){}
                
     
     return;
}


void COMPUTER::UpdateAI(OSL_IMAGE * image, const char * message, int AI, int posx, int posy, int &carry, int &position)
{     
     image->x = posx;
     image->y = posy;
     
     if(image)oslDrawImage(image);
     else oslFatalError("ERROR! IMAGE IS EQUAL TO NULL!!! Found in function void COMPUTER::UpdateAI()");
     
     //basic AI movement
     if(AI == 0)
     {
          carry++;
          if(carry < 0 ) carry = 0;
          if(carry > 0) position = UP;
          if(carry > 120) position = LEFT;
          if(carry > 240) position = DOWN;
          if(carry > 360) position = RIGHT;
          if(carry > 480) carry = 0;
     }
     
     else if(AI == 1)
     {
          carry++;
          if(carry < 0 ) carry = 0;
          if(carry > 0) position = UP;
          if(carry > 60) position = LEFT;
          if(carry > 120) position = DOWN;
          if(carry > 180) position = RIGHT;
          if(carry > 240) carry = 0;
     }
     
     else if(AI == 2)
     {
          carry++;
          if(carry < 0 ) carry = 0;
          if(carry > 0) position = UP;
          if(carry > 20) position = LEFT;
          if(carry > 40) position = DOWN;
          if(carry > 60) position = RIGHT;
          if(carry > 80) carry = 0;
     }
     
     int contact = collision(zero,zero->x, zero->y,image,image->x,image->y );
     
     if(contact && sprite_position == FACING_RIGHT) 
     {
                zero->x = image->x - 23; 
                oslSetImageTileSize(image,(1 * 23),LEFT,23,32);
                
                messagebox.MessageBox(message, 1, UPLINK_CENTER, image);
     }
     else if(contact && sprite_position == FACING_LEFT) 
     {
                zero->x = image->x + 23; 
                oslSetImageTileSize(image,(1 * 23),RIGHT,23,32);
                
                messagebox.MessageBox(message, 1, UPLINK_CENTER, image);
     }
     
     if(contact && sprite_position == FACING_UP)   
     {
                zero->y = image->y + 34; 
                oslSetImageTileSize(image,(1 * 23),DOWN,23,32);
                
                messagebox.MessageBox(message, 1, UPLINK_CENTER, image);
     }
     else if(contact && sprite_position == FACING_DOWN) 
     {
                zero->y = image->y - 34; 
                oslSetImageTileSize(image,(1 * 23),UP,23,32);
                
                messagebox.MessageBox(message, 1, UPLINK_CENTER, image);
     }
     
     return;
}

void COMPUTER::ComputerAnimate(OSL_IMAGE * image, int AI, int &manipl, int &march, int position)
{	
    if(!image) oslFatalError("ERROR! IMAGE IS EQUAL TO NULL! FOUND IN COMPUTER::ComputerAnimate()!!");
    
    if(AI == 0)
          oslSetImageTileSize(image,(0 * 23),position,23,32);
    
    else if(AI == 1)
    {
         manipl++;
         if(manipl > 11) {march++; manipl = 0;}
         oslSetImageTileSize(image,(march * 23),position,23,32);
         if (march == 2) march = 0;
    }
    
    else if(AI == 2)
    {
         manipl++;
         if(manipl > 7) {march++; manipl = 0;}
         oslSetImageTileSize(image,(march * 23),position,23,32);
         if (march == 2) march = 0;
    }
    
    else oslFatalError("Failed to apply AI to computer!!!\nfound in function COMPUTER::ComputerAnimate();!!!");
    
    return;
}

COMPUTER::COMPUTER()
{
     loadedImage = false;
     numOfSonymon = 0;
     x = 0;
     y = 0;
     carry = 0;
     position = DOWN;
     march = 0;
     manip = 0;
     message = "object created";
     name = "???";
     
     return;
}
COMPUTER::~COMPUTER()
{
     if(image != NULL){oslDeleteImage(image); image = NULL;}
     message = "object destroyed";
     name = "???";
     
     return;
}
