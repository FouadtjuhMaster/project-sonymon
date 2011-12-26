class MESSAGEBOX
{
      public:
             MESSAGEBOX();
             ~MESSAGEBOX();
             void MessageBoxMap(const char * message, int speed, OSL_IMAGE * image, OSL_MAP * map);
             void DoubleMessageBox(const char * message1, const char * message2, int speed, OSL_IMAGE * image);
             void MessageBox(const char * message, int speed, int location, OSL_IMAGE * image);
             void DisplayBox(const char * message, int speed);
             
      private:
}messagebox;

void MESSAGEBOX::DisplayBox(const char * message, int speed)
{
     int count, posx;
     count = sizeof message;
     posx = 5;
     DialogBox->x = 9;
     DialogBox->y = 200;
     pointer->x = 452;
     pointer->y = 236;
     
     for(pointer->y = 236; pointer->y < 252; pointer->y++)
     {
             if(pointer->y > 250) pointer->y = 236;
             
             oslReadKeys();
             if(osl_keys->pressed.cross)
             { oslPlaySound(beep, 2); break; }
             
             oslStartDrawing();
             oslDrawImage(zero);
             oslDrawImage(DialogBox);
             oslDrawImage(pointer);
             oslSetTextColor(BLACK);
             oslSetBkColor(RGBA(0,0,0,0));
             oslSetFont(verdana);
             oslPrintf_xy(17, 208, "%s", message);
             oslEndDrawing();
             oslSyncFrame();
     }
             
     return;
}


void MESSAGEBOX::MessageBox(const char * message, int speed, int location, OSL_IMAGE * image)
{
     int count, posx;
     count = sizeof message;
     posx = 5;
     DialogBox->x = 9;
     DialogBox->y = 200;
     pointer->x = 452;
     pointer->y = 236;
     
     for(pointer->y = 236; pointer->y < 252; pointer->y++)
     {
             if(pointer->y > 250) pointer->y = 236;
             
             oslReadKeys();
             if(osl_keys->pressed.cross)
             { oslPlaySound(beep, 2); break; }
             
             oslStartDrawing();
             if(location == UPLINK_CENTER && uplink_center != NULL) oslDrawImageSimple(uplink_center);
             
             oslDrawImage(zero);
             oslDrawImage(image);
             oslDrawImage(DialogBox);
             oslDrawImage(pointer);
             oslSetTextColor(BLACK);
             oslSetBkColor(RGBA(0,0,0,0));
             oslSetFont(verdana);
             oslPrintf_xy(17, 208, "%s", message);
             oslEndDrawing();
             oslSyncFrame();
     }
             
     return;
}

void MESSAGEBOX::MessageBoxMap(const char * message, int speed, OSL_IMAGE * image, OSL_MAP * map)
{
     if(map == NULL){oslWarning("Error! Map data sent to messagebox function is equal to NULL!!! Exiting function to avoid crash!!"); return;}
     
     int count, posx;
     count = sizeof message;
     posx = 5;
     DialogBox->x = 9;
     DialogBox->y = 200;
     pointer->x = 452;
     pointer->y = 236;
     
     for(pointer->y = 236; pointer->y < 252; pointer->y++)
     {
             if(pointer->y > 250) pointer->y = 236;
             
             oslReadKeys();
             if(osl_keys->pressed.cross)
             { oslPlaySound(beep, 2); break; }
             
             oslStartDrawing();
             oslDrawMapSimple(map);
             oslDrawImage(zero);
             oslDrawImage(image);
             oslDrawImage(DialogBox);
             oslDrawImage(pointer);
             oslSetTextColor(BLACK);
             oslSetBkColor(RGBA(0,0,0,0));
             oslSetFont(verdana);
             oslPrintf_xy(17, 208, "%s", message);
             oslEndDrawing();
             oslSyncFrame();
     }
             
     return;
}

void MESSAGEBOX::DoubleMessageBox(const char * message1, const char * message2, int speed, OSL_IMAGE * image)
{
     int count1, count2, posx;
     count1 = sizeof message1;
     count2 = sizeof message2;
     posx = 5;
     DialogBox->x = 9;
     DialogBox->y = 200;
     pointer->x = 452;
     pointer->y = 236;
     
     for(pointer->y = 236; pointer->y < 252; pointer->y++)
     {
             if(pointer->y > 250) pointer->y = 236;
             
             oslReadKeys();
             if(osl_keys->pressed.cross)
             { oslPlaySound(beep, 2); break; }
             
             oslStartDrawing();
             oslDrawImage(zero);
             oslDrawImage(image);
             oslDrawImage(DialogBox);
             oslDrawImage(pointer);
             oslSetTextColor(BLACK);
             oslSetBkColor(RGBA(0,0,0,0));
             oslSetFont(verdana);
             
             oslPrintf_xy(17, 208, "%s", message1);
             oslPrintf_xy(17, 218, "%s", message2);
             
             oslEndDrawing();
             oslSyncFrame();
     }
             
     return;
}

MESSAGEBOX::MESSAGEBOX()
{
     return;
}

MESSAGEBOX::~MESSAGEBOX()
{
     return;
}
