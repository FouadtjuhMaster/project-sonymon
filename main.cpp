#include "main.h"

int main(int argc, char* argv[])
{  
	oslInit(0);
    oslInitGfx(OSL_PF_8888, 1);
    oslInitAudio();
    oslSetQuitOnLoadFailure(1);
    oslSetKeyAutorepeatInit(20);
    oslSetKeyAutorepeatInterval(5);
    
	oslSetTransparentColor(RGB(255,0,255));
    menu_music = oslLoadSoundFileBGM((char*)"music/winterbliss.bgm", OSL_FMT_NONE);
    select = oslLoadSoundFileBGM((char*)"music/selected.bgm", OSL_FMT_NONE);
    menu_background = oslLoadImageFilePNG((char*)"img/data/menu_bk.png", OSL_IN_RAM, OSL_PF_5551);	
    rec_selector = oslLoadImageFilePNG((char*)"img/data/rec-selector.png", OSL_IN_RAM, OSL_PF_5551);
    
    //Show my logo
	VAUGHN_LOGO();	
    
    //start menu music
    oslPlaySound(menu_music, 1); 
    oslSetSoundLoop(menu_music, 1);
	
    for(;;)
	{  
	   while (1)
	   {	
		  oslReadKeys();
		  
		  if(osl_keys->pressed.circle) askQuit();
		  else if(osl_keys->pressed.down){menuChoice++; oslPlaySound(select, 2);}
		  else if(osl_keys->pressed.up)  {menuChoice--; oslPlaySound(select, 2);}
		  
		  if(menuChoice > 4) menuChoice = 1;
          if(menuChoice < 1) menuChoice = 4;
		
		  if(menuChoice == 1){
		    placeSelector(rec_selector, 3,7);
		    if(osl_keys->pressed.cross || osl_keys->pressed.start) {
                oslPlaySound(select, 2); 
                oslStopSound(menu_music);
                playerName = getInput(); 
                SonymonFreeRoam(playerName, 0);
                oslPlaySound(menu_music, 1); 
                oslSetSoundLoop(menu_music, 1);
            }                      
		  }
        
          else if(menuChoice == 2){
			placeSelector(rec_selector, 3, 58);
			if(osl_keys->pressed.cross || osl_keys->pressed.start){
                oslPlaySound(select, 2); 
                oslStopSound(menu_music);
                SonymonFreeRoam(playerName, 0);
                oslPlaySound(menu_music, 1); 
                oslSetSoundLoop(menu_music, 1);
            }     
		  }	
		
		  else if(menuChoice == 3){
			placeSelector(rec_selector, 3, 110);
			if(osl_keys->pressed.cross || osl_keys->pressed.start){oslPlaySound(select, 2); showCredits(); }
		  }
		  
		  else if(menuChoice == 4){
			placeSelector(rec_selector, 3, 160);
			if(osl_keys->pressed.cross || osl_keys->pressed.start){oslPlaySound(select, 2); sceKernelExitGame(); }
		  }
		
		  oslStartDrawing();
		  oslDrawImage(menu_background);
          oslDrawImage(rec_selector);
          oslSetBkColor(RGBA(0,0,0,0));
          oslSetTextColor(0xFF000000);
          oslPrintf_xy(3, 212, "Sonymon v0.2");
		  oslEndDrawing();
		  oslSyncFrame();		
       } 

  }

  //kill oslib
  oslEndGfx();
  oslDeinitAudio();
  
  sceKernelExitGame();
  
  return 0;
}

void showCredits( void )
{
     OSL_IMAGE * credits_bk;
     credits_bk = oslLoadImageFile((char*)"img/data/x71.png", OSL_IN_RAM, OSL_PF_5551);
     if(!credits_bk)
         MISSING_IMG_FILES(1);
     
     while(1)
     {
    	  oslReadKeys();
    	  if(osl_keys->pressed.circle) {oslPlaySound(select, 2); break;}
    	  
          oslStartDrawing();
          oslDrawImage(credits_bk);
          
          oslSetTextColor(0xFF0000FF);
          oslPrintf_xy(5, 15, "Credits: Sonymon v0.2 ~'the pokemon homebrew'");
          oslSetTextColor(0xFF000000);
          
          oslPrintf_xy(5, 35, "Programming: V@ughn");
          oslPrintf_xy(5, 45, "Programming support: Hardhat, Pspjoke, and HadesMinion");
          oslPrintf_xy(5, 55, "Sound Effects: V@ughn");
          oslPrintf_xy(5, 65, "Music: www.entropoy.com");
          oslPrintf_xy(5, 75, "Art/Maps: V@ughn and fouadtjuhmaster");
          oslPrintf_xy(5, 85, "Art Advisor: JerretB");
          
          oslSetTextColor(0xFF0000FF);
          oslPrintf_xy(5, 105, "Beta Testers:");
          oslSetTextColor(0xFF000000);
          
          oslPrintf_xy(5, 115, "-Casavault");
          oslPrintf_xy(5, 125, "-HadesMinion");
          oslPrintf_xy(5, 135, "-JimWest");
          
          oslSetTextColor(0xFF0000FF);
          oslPrintf_xy(5, 155, "Tools used:");
          oslSetTextColor(0xFF000000);
          
          oslPrintf_xy(5, 165, "-Dev-C++ 4.9.9.2");
          oslPrintf_xy(5, 175, "-sfxr generator");
          oslPrintf_xy(5, 185, "-photoshop cs5");
          oslPrintf_xy(5, 195, "-oslib + gu of pspsdk");
          
          oslEndDrawing();
          oslSyncFrame();
     }
     
     if(credits_bk != NULL) {oslDeleteImage(credits_bk); credits_bk = NULL;}
     
     return;
}

//this function will ask the player if he or she wants to exit the game
void askQuit( void )
{
   oslStartDrawing();
   oslClearScreen(RGBA(0,0,0,0));
   oslEndDrawing();
   oslSyncFrame();
   oslEndGfx();
   SetupGu();
   
   ShowMessageDialog("Quit Sonymon and return to XMB?", 1);
			  
   if(dialog.buttonPressed == PSP_UTILITY_MSGDIALOG_RESULT_YES)
   {sceGuTerm(); sceKernelExitGame();}
   
   else if(dialog.buttonPressed == PSP_UTILITY_MSGDIALOG_RESULT_NO) 
       sprintf(button, "No");
       
   else sprintf(button, "Back");
   
   sceGuTerm();	
   oslInitGfx(OSL_PF_8888, 1);
   oslSetTransparentColor(RGB(255,0,255));
     return;
}

//this will be the options function
void askOptions( void )
{
     oslStartDrawing();
     oslClearScreen(RGBA(0,0,0,0));
     oslEndDrawing();
     oslSyncFrame();
     oslEndGfx();
     SetupGu();
	
	 sprintf(string, "sorry the options selection has not been coded yet");
     ShowMessageDialog(string, 0);
     
     sceGuTerm();	
     oslInitGfx(OSL_PF_8888, 1);
     oslSetTransparentColor(RGB(255,0,255));
   
     return;
}

//shows a simple error
void showError( void )
{
     oslStartDrawing();
     oslClearScreen(RGBA(0,0,0,0));
     oslEndDrawing();
     oslSyncFrame();
     oslEndGfx();
     SetupGu();
	
	 ShowErrorDialog(0x80020001);
     
     sceGuTerm();	
     oslInitGfx(OSL_PF_8888, 1);
     oslSetTransparentColor(RGB(255,0,255));
   
     return;
}

//my custom logo ;)
void VAUGHN_LOGO( void )
{
     OSL_IMAGE *logo;
     OSL_SOUND *logo_sound;
     logo = oslLoadImageFilePNG((char*)"img/data/logo.png", OSL_IN_RAM, OSL_PF_5551);
     logo_sound = oslLoadSoundFileWAV((char*)"music/powerup2.wav", OSL_FMT_NONE);  
     
     if(!logo || !logo_sound)
         MISSING_IMG_FILES(4);
         
     oslPlaySound(logo_sound, 1);
     
     oslStartDrawing();
     oslDrawImage(logo);
     oslEndDrawing();
     oslSyncFrame();
     
     Wait;
     oslStopSound(logo_sound);
     oslDeleteSound(logo_sound);
     oslDeleteImage(logo);
     
}

//intro function!!!!
void intro( void )
{
     oslStopSound(menu_music); 
     oslPlaySound(start_music, 1); 
     oslSetSoundLoop(start_music, 1);
          
     OSL_IMAGE *light1, *light2, *light3, *light4, *light5, *light6;
     light1 = oslLoadImageFile((char*)"img/data/l1.png", OSL_IN_RAM, OSL_PF_5551);	
     light2 = oslLoadImageFile((char*)"img/data/l2.png", OSL_IN_RAM, OSL_PF_5551);	
     light3 = oslLoadImageFile((char*)"img/data/l3.png", OSL_IN_RAM, OSL_PF_5551);	
     light4 = oslLoadImageFile((char*)"img/data/l4.png", OSL_IN_RAM, OSL_PF_5551);	
     light5 = oslLoadImageFile((char*)"img/data/l5.png", OSL_IN_RAM, OSL_PF_5551);	
     light6 = oslLoadImageFile((char*)"img/data/l6.png", OSL_IN_RAM, OSL_PF_5551);	
     if(!light1 || !light2 || !light3 || !light4 || !light5 || !light6)
        MISSING_IMG_FILES(1);
        
     int i = 0;
     int NUM_OF_LIGHTS = 1;
     
     for(i = 0; i < 162; i++)
     {
           i++;
           oslStartDrawing();
           if(NUM_OF_LIGHTS == 1) oslDrawImage(light1);
           if(NUM_OF_LIGHTS == 2) oslDrawImage(light2);
           if(NUM_OF_LIGHTS == 3) oslDrawImage(light3);
           if(NUM_OF_LIGHTS == 4) oslDrawImage(light4);
           if(NUM_OF_LIGHTS == 5) oslDrawImage(light5);
           if(NUM_OF_LIGHTS == 6) oslDrawImage(light6);
           oslEndDrawing();
           oslSyncFrame();
           
           if(i >= 160) {NUM_OF_LIGHTS += 1; i = 0;}
           if(NUM_OF_LIGHTS > 6) break;
     }
     
     oslStopSound(start_music);
     return;
}

void showGameOptions( void )
{
     unsigned menuChoice2 = 1;
     
     while (1)
	   {	
		  oslReadKeys();
		  
		  if(osl_keys->pressed.circle) {oslPlaySound(select, 2); break; gameSelect = 0;}
		  else if(osl_keys->pressed.down){menuChoice2++; oslPlaySound(select, 2);}
		  else if(osl_keys->pressed.up){menuChoice2--; oslPlaySound(select, 2);}
		  
		  if(menuChoice2 > 2) menuChoice2 = 1;
          if(menuChoice2 < 1) menuChoice2 = 2;
		
		  if(menuChoice2 == 1)
          {
		    placeSelector(rec_selector, 3,7);
		    if(osl_keys->pressed.cross || osl_keys->pressed.start)
              {gameSelect = 1; oslPlaySound(select, 2); break;}                      
		  }
        
          else if(menuChoice2 == 2)
          {
			placeSelector(rec_selector, 3, 58);
			if(osl_keys->pressed.cross || osl_keys->pressed.start)
			     {gameSelect = 2; oslPlaySound(select, 2); break;}
		  }	
		
		  oslStartDrawing();
		  oslDrawImage(menu_background2);
          oslDrawImage(rec_selector);
		  oslEndDrawing();
		  oslSyncFrame();		
      }
     
     return;
}

void placeSelector(OSL_IMAGE *image, int x, int y)
{
	image->x = x;
	image->y = y;
}

int MISSING_IMG_FILES(int type)
{
     if(type == 1) oslFatalError("At least one file is missing. \nPlease check the img folder that came with this EBOOT!");
     else if(type == 2) oslFatalError("At least one file is missing. \nPlease check the music folder that came with this EBOOT!");
     else if(type == 3) oslFatalError("YOU ARE MISSING TOO MANY FILES!!! RE-DOWNLOAD IMMEDIATELY!!!");
     else if(type == 4) oslFatalError("At least one file is missing.\nPlease check the fonts folder that came with this EBOOT!");
     else if(type == 5) oslFatalError("ERROR: Sonymon image library corrupt\neither redownload or consult with V@ughn!!");
     return type;
}


int collision(OSL_IMAGE *img1,float img1posX, float img1posY, OSL_IMAGE *img2, float img2posX, float img2posY ) 
{
   int collisio;
   collisio = 0;
   float img1width  = img1->stretchX;
   float img1height = img1->stretchY;
   float img2width  = img2->stretchX;
   float img2height = img2->stretchY;
   
   if ((img1posX + img1width > img2posX) &&
       (img1posX < img2posX + img2width) &&
       (img1posY + img1height > img2posY) &&
       (img1posY < img2posY + img2height) ) 
{
         collisio = 1;               
   }     
   return collisio;
}

const char * getInput()
{   
    const char * name = "Ken";
    oslInitOsk((char*)"Enter your name", (char*)"Ken", 128, 1, -1);
	
    for(;;)
    {
       oslStartDrawing();
       oslClearScreen(RGBA(0,0,0,0));
       oslDrawOsk();
       
	   if (oslGetOskStatus() == PSP_UTILITY_DIALOG_NONE)
       {
			if (oslOskGetResult() == OSL_OSK_CANCEL) break;
			
            else
            {
				char userText[20] = "";
				oslOskGetText(userText);
				if(userText !=NULL)name = userText;
				else oslWarning("ERROR player entered an incorrect value! Setting 'Ken' as player name!");
				
				break;
			}
			oslEndOsk();	
        }
        
        oslEndDrawing();
        oslSyncFrame();
        
   }
				
    return name; 
}

static void SetupGu()
{
    sceGuInit();

    sceGuStart(GU_DIRECT,list);
    sceGuDrawBuffer(GU_PSM_8888,(void*)0,BUF_WIDTH);
    sceGuDispBuffer(SCR_WIDTH,SCR_HEIGHT,(void*)0x88000,BUF_WIDTH);
    sceGuDepthBuffer((void*)0x110000,BUF_WIDTH);
    sceGuOffset(2048 - (SCR_WIDTH/2),2048 - (SCR_HEIGHT/2));
    sceGuViewport(2048,2048,SCR_WIDTH,SCR_HEIGHT);
    sceGuDepthRange(0xc350,0x2710);
    sceGuScissor(0,0,SCR_WIDTH,SCR_HEIGHT);
    sceGuEnable(GU_SCISSOR_TEST);
    sceGuDepthFunc(GU_GEQUAL);
    sceGuEnable(GU_DEPTH_TEST);
    sceGuFrontFace(GU_CW);
    sceGuShadeModel(GU_SMOOTH);
    sceGuEnable(GU_CULL_FACE);
    sceGuEnable(GU_CLIP_PLANES);
    sceGuFinish();
    sceGuSync(0,0);
    
    sceDisplayWaitVblankStart();
    sceGuDisplay(GU_TRUE);
}

static void DrawStuff(void)
{
    static int val = 0;

    sceGuStart(GU_DIRECT,list);

    // clear screen
    
    sceGuClearColor(0xff554433);
    sceGuClearDepth(0);
    sceGuClear(GU_COLOR_BUFFER_BIT|GU_DEPTH_BUFFER_BIT);
    
    sceGuFinish();
    sceGuSync(0,0);

    val ++;
}


/* Utility dialog functions */

static void ConfigureDialog(pspUtilityMsgDialogParams *dialog, size_t dialog_size)
{
    memset(dialog, 0, dialog_size);

    dialog->base.size = dialog_size;
    sceUtilityGetSystemParamInt(PSP_SYSTEMPARAM_ID_INT_LANGUAGE,
				&dialog->base.language); // Prompt language
    sceUtilityGetSystemParamInt(PSP_SYSTEMPARAM_ID_INT_UNKNOWN,
				&dialog->base.buttonSwap); // X/O button swap

    dialog->base.graphicsThread = 0x11;
    dialog->base.accessThread = 0x13;
    dialog->base.fontThread = 0x12;
    dialog->base.soundThread = 0x10;
}

static void ShowErrorDialog(const unsigned int error)
{
    ConfigureDialog(&dialog, sizeof(dialog));
    dialog.mode = PSP_UTILITY_MSGDIALOG_MODE_ERROR;
	dialog.options = PSP_UTILITY_MSGDIALOG_OPTION_ERROR;
    dialog.errorValue = error;

    sceUtilityMsgDialogInitStart(&dialog);

    for(;;) {

	DrawStuff();
	
	switch(sceUtilityMsgDialogGetStatus()) {
	    
	case PSP_UTILITY_DIALOG_VISIBLE:
	    sceUtilityMsgDialogUpdate(1);
	    break;
	    
	case PSP_UTILITY_DIALOG_QUIT:
	    sceUtilityMsgDialogShutdownStart();
	    break;
	    
	case PSP_UTILITY_DIALOG_NONE:
	    return;
	    
	}

	//sceDisplayWaitVblankStart();
	sceGuSwapBuffers();
    }
}

static void ShowMessageDialog(const char *message, int enableYesno)
{
    ConfigureDialog(&dialog, sizeof(dialog));
    dialog.mode = PSP_UTILITY_MSGDIALOG_MODE_TEXT;
	dialog.options = PSP_UTILITY_MSGDIALOG_OPTION_TEXT;
	
	if(enableYesno)
		dialog.options |= PSP_UTILITY_MSGDIALOG_OPTION_YESNO_BUTTONS|PSP_UTILITY_MSGDIALOG_OPTION_DEFAULT_NO;		
	
    strcpy(dialog.message, message);

    sceUtilityMsgDialogInitStart(&dialog);

    for(;;) {

	DrawStuff();

	switch(sceUtilityMsgDialogGetStatus()) {

	case 2:
	    sceUtilityMsgDialogUpdate(1);
	    break;
	    
	case 3:
	    sceUtilityMsgDialogShutdownStart();
	    break;
	    
	case 0:
	    return;
	    
	}

	//sceDisplayWaitVblankStart();
	sceGuSwapBuffers();
    }
}

