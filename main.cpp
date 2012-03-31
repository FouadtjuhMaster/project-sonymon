#include "main.h"

PSP_MODULE_INFO("Sonymon", 0, 1, 1);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER | THREAD_ATTR_VFPU);
PSP_HEAP_SIZE_KB(-1024);

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
		  if(osl_keys->pressed.down){menuChoice++; oslPlaySound(select, 2);}
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
          //oslPrintf_xy(3, 212, "Sonymon v0.3");
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
     
     while(1)
     {
    	  oslReadKeys();
    	  if(osl_keys->pressed.circle) {oslPlaySound(select, 2); break;}
    	  
          oslStartDrawing();
          oslDrawImage(credits_bk);
          
          oslSetTextColor(0xFF0000FF);
          oslPrintf_xy(5, 15, "Credits: Sonymon v0.35 the pokemon homebrew");
          oslSetTextColor(0xFF000000);
          
          oslPrintf_xy(5, 25, "Programming: V@ughn");
          oslPrintf_xy(5, 35, "Programming support: Hardhat, Pspjoke, and HadesMinion");
          oslPrintf_xy(5, 45, "Sound Effects: V@ughn");
          oslPrintf_xy(5, 55, "Music: www.entropoy.com");
          oslPrintf_xy(5, 65, "Maps: V@ughn");
          oslPrintf_xy(5, 75, "Art: fouadtjuhmaster, pspgabe550 and V@ughn");
          
          oslSetTextColor(0xFF0000FF);
          oslPrintf_xy(5, 95, "Beta Testers:");
          oslSetTextColor(0xFF000000);
          
          oslPrintf_xy(5, 105, "-Casavault");
          oslPrintf_xy(5, 115, "-HadesMinion");
          oslPrintf_xy(5, 125, "-JimWest");
          
          oslSetTextColor(0xFF0000FF);
          oslPrintf_xy(5, 145, "Tools used:");
          oslSetTextColor(0xFF000000);
          
          oslPrintf_xy(5, 155, "-Dev-C++ 4.9.9.2");
          oslPrintf_xy(5, 165, "-sfxr generator");
          oslPrintf_xy(5, 175, "-photoshop cs5");
          oslPrintf_xy(5, 185, "-MS paint");
          oslPrintf_xy(5, 195, "-oslib + gu of pspsdk");
          
          oslEndDrawing();
          oslSyncFrame();
     }
     
     if(credits_bk != NULL) {oslDeleteImage(credits_bk); credits_bk = NULL;}
     
     return;
}

//my custom logo ;)
void VAUGHN_LOGO( void )
{
     OSL_IMAGE *logo;
     OSL_SOUND *logo_sound;
     logo = oslLoadImageFilePNG((char*)"img/data/logo.png", OSL_IN_RAM, OSL_PF_5551);
     logo_sound = oslLoadSoundFileWAV((char*)"music/powerup2.wav", OSL_FMT_NONE);  
         
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

