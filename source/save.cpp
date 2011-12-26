#include "save.h"

static void SetupGu2()
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

static void DrawStuff2(void)
{

    {
    static int val = 0;

    sceGuStart(GU_DIRECT,list);

    // Clear screen    
    sceGuClearColor(0xFF000000);
    sceGuClearDepth(0);
    sceGuClear(GU_COLOR_BUFFER_BIT|GU_DEPTH_BUFFER_BIT);
    
    // Setup matrices for cube    
    sceGumMatrixMode(GU_PROJECTION);
    sceGumLoadIdentity();
    sceGumPerspective(75.0f,16.0f/9.0f,0.5f,1000.0f);
    
    sceGumMatrixMode(GU_VIEW);
    sceGumLoadIdentity();
    
    sceGumMatrixMode(GU_MODEL);
    
    sceGuFinish();
    sceGuSync(0,0);

    val ++;
}
}

PspUtilitySavedataListSaveNewData newData;
const char * titleShow = "New Sonymon Save File";

char nameMultiple[][20] =	// End list with ""
{
 "0000",
 "0001",
 "0002",
 "0003",
 "0004",
 ""
};

char key[] = "QTAK319JQKJ952HA";	// Key to encrypt or decrypt savedata

int initSavedata(SceUtilitySavedataParam * savedata, int mode)
{
	memset(savedata, 0, sizeof(SceUtilitySavedataParam));
	savedata->base.size = sizeof(SceUtilitySavedataParam);

	savedata->base.language = PSP_SYSTEMPARAM_LANGUAGE_ENGLISH;
	savedata->base.buttonSwap = PSP_UTILITY_ACCEPT_CROSS;
	savedata->base.graphicsThread = 0x11;
	savedata->base.accessThread = 0x13;
	savedata->base.fontThread = 0x12;
	savedata->base.soundThread = 0x10;

	savedata->mode = (PspUtilitySavedataMode)mode;
	savedata->overwrite = 1;
	savedata->focus = PSP_UTILITY_SAVEDATA_FOCUS_LATEST; // Set initial focus to the newest file (for loading)

#if _PSP_FW_VERSION >= 200
	strncpy(savedata->key, key, 16);
#endif

	strcpy(savedata->gameName, "DEMO11111");	// First part of the save name, game identifier name
	strcpy(savedata->saveName, "0000");	// Second part of the save name, save identifier name

	// List of multiple names
	savedata->saveNameList = nameMultiple;

	strcpy(savedata->fileName, "DATA.BIN");	// name of the data file

	// Allocate buffers used to store various parts of the save data
	savedata->dataBuf = malloc(DATABUFFLEN);
	savedata->dataBufSize = DATABUFFLEN;
	savedata->dataSize = DATABUFFLEN;

	// Set some data
	if (mode == PSP_UTILITY_SAVEDATA_LISTSAVE)
	{
	 memset(savedata->dataBuf, 0, DATABUFFLEN);
	 strcpy((char*)savedata->dataBuf,"Sonymon data save file succefully completed");
	 
	 savedata->dataBuf = (void*)DATA1;

	 strcpy(savedata->sfoParam.title,"Sonymon");
	 strcpy(savedata->sfoParam.savedataTitle,"Single Player Save");
	 strcpy(savedata->sfoParam.detail,"Load this file to continue on with your sonymon journey!");
	 savedata->sfoParam.parentalLevel = 1;
	
	 // No icon1
	 savedata->icon1FileData.buf = NULL;
	 savedata->icon1FileData.bufSize = 0;
	 savedata->icon1FileData.size = 0;

	 savedata->pic1FileData.buf = pic1;
	 savedata->pic1FileData.bufSize = size_pic1;
	 savedata->pic1FileData.size = size_pic1;

	 savedata->icon0FileData.buf = icon0;
	 savedata->icon0FileData.bufSize = size_icon0;
	 savedata->icon0FileData.size = size_icon0;
	
	 // No snd0
	 savedata->snd0FileData.buf = NULL;
	 savedata->snd0FileData.bufSize = 0;
	 savedata->snd0FileData.size = 0;

	 // Set title
	 newData.title = (char*)titleShow;

	 // Set new data
	 savedata->newData = &newData;
	
	 leave = 1;
	
	 savedata->focus = PSP_UTILITY_SAVEDATA_FOCUS_FIRSTEMPTY; // If saving, set inital focus to the first empty slot
	 
	 /*FILE * gameSave;
	 
	 if(PSP_UTILITY_SAVEDATA_FOCUS_LATEST == 0) gameSave = fopen("define/%0.save", "w");
	 else if(PSP_UTILITY_SAVEDATA_FOCUS_LATEST == 1) gameSave = fopen("define/%1.save", "w");
	 else if(PSP_UTILITY_SAVEDATA_FOCUS_LATEST == 2) gameSave = fopen("define/%2.save", "w");
	 else if(PSP_UTILITY_SAVEDATA_FOCUS_LATEST == 3) gameSave = fopen("define/%3.save", "w");
	 else if(PSP_UTILITY_SAVEDATA_FOCUS_LATEST == 4) gameSave = fopen("define/%4.save", "w");
	 else if(PSP_UTILITY_SAVEDATA_FOCUS_LATEST == 5) gameSave = fopen("define/%5.save", "w");
	 else if(PSP_UTILITY_SAVEDATA_FOCUS_LATEST == 6) gameSave = fopen("define/%6.save", "w");
	 else {oslWarning("ERROR!!! FAILED TO SAVE GAME!!! EXITING FUNCTION TO AVOID A CRASH!!!"); success = 0;}
	 
     fprintf(gameSave, KEY);
     fprintf(gameSave, "%d", DATA1);
     fprintf(gameSave, KEY);
     fprintf(gameSave, "%d", DATA2);
     fprintf(gameSave, KEY);
     fprintf(gameSave, "%d", DATA3);
     fprintf(gameSave, KEY);
     fprintf(gameSave, "%d", DATA4);
     fprintf(gameSave, KEY);
     fprintf(gameSave, "%d", DATA5);
     fprintf(gameSave, KEY);
     fprintf(gameSave, "%d", DATA6);
     fprintf(gameSave, KEY);
     
     fclose(gameSave);*/
     success = 1;
	 
	}
	
	else if(mode == PSP_UTILITY_SAVEDATA_LISTLOAD)
	{
         FILE * loadSave;
         unsigned long long lSize;
         char * buffer;
	
	     //it has been discovered that the psp can only load 9 buffers at a time
	     //so do not attempt to read more than 9 at a time or expect something
	     //to go wrong!!!!!!!!!!
	     loadSave = fopen("define/0.save", "r");
         
         if(PSP_UTILITY_SAVEDATA_FOCUS_LATEST == 0) loadSave = fopen("define/0.save", "r");
	     else if(PSP_UTILITY_SAVEDATA_FOCUS_LATEST == 1) loadSave = fopen("define/1.save", "r");
	     else if(PSP_UTILITY_SAVEDATA_FOCUS_LATEST == 2) loadSave = fopen("define/2.save", "r");
	     else if(PSP_UTILITY_SAVEDATA_FOCUS_LATEST == 3) loadSave = fopen("define/3.save", "r");
	     else if(PSP_UTILITY_SAVEDATA_FOCUS_LATEST == 4) loadSave = fopen("define/4.save", "r");
	     else if(PSP_UTILITY_SAVEDATA_FOCUS_LATEST == 5) loadSave = fopen("define/5.save", "r");
	     else if(PSP_UTILITY_SAVEDATA_FOCUS_LATEST == 6) loadSave = fopen("define/6.save", "r");
	     else {oslWarning("ERROR!!! FAILED TO SAVE GAME!!! EXITING FUNCTION TO AVOID A CRASH!!!"); success = 0;}
	     
	     if(!loadSave){
                       oslWarning("ERROR!! FAILED TO LOAD GAME!! EXITING FUNCTION TO AVOID A CRASH!!");
                       fclose(loadSave);
                       success = 0;
         }
         
     	fseek(loadSave , 0 , SEEK_END);
        lSize = ftell(loadSave);
	    rewind(loadSave);
	    buffer = (char*) malloc(lSize+1); // Increase buffer size by one byte for NULL terminator.
	    
	    if(!buffer){
                       oslWarning("ERROR!! FAILED TO LOAD GAME!! EXITING FUNCTION TO AVOID A CRASH!!");
                       fclose(loadSave);
                       success = 0;
        }
        
        //read files and apply value to buffer
	    fread(buffer, 1, lSize, loadSave);
	    buffer[lSize] = '\0'; // Add NULL terminator.
	 
	    
	    buffer -= (int)KEY;
	    
        leave = 1;
        
        success = 1;
    }
    
    return success;
}


static void ShowSaveDialog (int mode)
{
	SceUtilitySavedataParam dialog;
	
    initSavedata(&dialog, mode);
	
    sceUtilitySavedataInitStart(&dialog);

    while(running) {

	DrawStuff2();

	switch(sceUtilitySavedataGetStatus()) {

	case PSP_UTILITY_DIALOG_VISIBLE :

	    sceUtilitySavedataUpdate(1);
	    break;

	case PSP_UTILITY_DIALOG_QUIT :

	    sceUtilitySavedataShutdownStart();
	    break;
	    
			
	case PSP_UTILITY_DIALOG_NONE :
	    return;
	}

	sceDisplayWaitVblankStart();
	sceGuSwapBuffers();
    }
}

int LOADGAME(int &sonymon1ID, int &sonymon1LEVEL, int &sonymon2ID, int &sonymon2LEVEL, int &sonymon3ID, int &sonymon3LEVEL)
{
    SetupGu2();
	pspDebugScreenInit();
	
	leave = 0;
	success = 0;
	int mode = 0;
	
	memset(stringSave, 0, sizeof(stringSave));
	
	//set DATA variables to 0; reset DATA
	DATA1 = 1;
	DATA2 = 1;
	DATA3 = 1;
	DATA4 = 1;
	DATA5 = 1;
	DATA6 = 1;
	
	while(running)
	{		
		mode = PSP_UTILITY_SAVEDATA_LISTLOAD;
		
		if(leave)
		    break;
		    
		if(mode)
		{
			ShowSaveDialog(mode);
			pspDebugScreenInit();
			mode = 0;
		}
	}
	
	oslInit(0);
	oslInitGfx(OSL_PF_8888, 1);
	oslSetTransparentColor(RGB(255,0,255));
	
	sonymon1ID = DATA1;
	sonymon1LEVEL = DATA2;
	sonymon2ID = DATA3;
	sonymon2LEVEL = DATA4;
	sonymon3ID = DATA5;
	sonymon3LEVEL = DATA6;
	
    return success;
}

int SAVEGAME(int sonymon1ID, int sonymon1LEVEL, int sonymon2ID, int sonymon2LEVEL, int sonymon3ID, int sonymon3LEVEL)
{
    SetupGu2();
	pspDebugScreenInit();
	
	leave = 0;
	int mode = 0;
	
	memset(stringSave, 0, sizeof(stringSave));
	
	//set DATA variables equal to new variables
	DATA1 = sonymon1ID;
	DATA2 = sonymon1LEVEL;
	DATA3 = sonymon2ID;
	DATA4 = sonymon2LEVEL;
	DATA5 = sonymon3ID;
	DATA6 = sonymon3LEVEL;
	
	while(running)
	{			
		mode = PSP_UTILITY_SAVEDATA_LISTSAVE;
		
		if(leave)
		    break;
		    
		if(mode)
		{
			ShowSaveDialog(mode);
			pspDebugScreenInit();
			mode = 0;
		}
	}
	
	oslInit(0);
	oslInitGfx(OSL_PF_8888, 1);
	oslSetTransparentColor(RGB(255,0,255));
	
    return 0;
}
