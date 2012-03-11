#include <oslib/oslib.h>

#include <pspkernel.h>
#include <pspdisplay.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <pspmoduleinfo.h>
#include <pspdebug.h>
#include <pspgu.h>
#include <pspgum.h>
#include <psputility.h>
#include <pspctrl.h>
#include<stdlib.h>
#include<stdio.h>

#include "saveIcon.h"
#include "savePic1.h"

int success;

int DATA1;
int DATA2;
int DATA3;
int DATA4;
int DATA5;
int DATA6;

char gameTitle[50] = "Sonymon save";
char gameID[10] = "IED22M2SD";
char saveName[10] = "0001";

char nameList[][20] =	// End list with ""
{
 "0000",
 "0001",
 "0002",
 "0003",
 "0004",
 ""
};

char data[100] = "someData: 50";

int LOADGAME(short &sonymon1ID, short &sonymon1LEVEL, short &sonymon2ID, short &sonymon2LEVEL, short &sonymon3ID, short &sonymon3LEVEL)
{
    struct oslSaveLoad saveLoadData;
    int type = OSL_DIALOG_NONE;
    char message[100] = "";
    char loadedData[100] = "";
    
    type = oslGetSaveLoadType();
        
    oslStartDrawing();
    oslClearScreen(RGBA(0,0,0,0));
    oslDrawSaveLoad();
    oslEndDrawing();
    oslSyncFrame();
        
    if (type == OSL_DIALOG_NONE)
    {
        memset(&saveLoadData, 0, sizeof(saveLoadData));
        strcpy(saveLoadData.gameID, gameID);
        strcpy(saveLoadData.saveName, saveName);
        saveLoadData.nameList = nameList;
        saveLoadData.data = &loadedData;
        saveLoadData.dataSize = 100;
        oslInitLoadDialog(&saveLoadData);
        memset(message, 0, sizeof(message));
    }
    
    sonymon1ID = 12;
    sonymon1LEVEL = 8;
    
    sonymon2ID = 1;
    sonymon2LEVEL = 1;
    
    sonymon3ID = 1;
    sonymon3LEVEL = 1;
    
    return 0;
}

int SAVEGAME(int sonymon1ID, int sonymon1LEVEL, int sonymon2ID, int sonymon2LEVEL, int sonymon3ID, int sonymon3LEVEL)
{
    struct oslSaveLoad saveLoadData;
    int type = OSL_DIALOG_NONE;
    char message[100] = "";
    
    while(1)
    {
        type = oslGetSaveLoadType();
        
        oslStartDrawing();
        oslClearScreen(RGBA(0,0,0,0));
        
        if (type != OSL_DIALOG_NONE)
        {
            oslDrawSaveLoad();
            if (oslGetLoadSaveStatus() == PSP_UTILITY_DIALOG_NONE)
            {
                if (oslSaveLoadGetResult() == OSL_SAVELOAD_CANCEL) break;
                else if (type == OSL_DIALOG_LOAD) break;
                else if (type == OSL_DIALOG_SAVE) break;
                oslEndSaveLoadDialog();
            }
        }
            
        if (type == OSL_DIALOG_NONE)
        {
            memset(&saveLoadData, 0, sizeof(saveLoadData));
            strcpy(saveLoadData.gameTitle, gameTitle);
            strcpy(saveLoadData.gameID, gameID);
            strcpy(saveLoadData.saveName, saveName);
            saveLoadData.nameList = nameList;
            saveLoadData.icon0 = icon0;
            saveLoadData.size_icon0 = size_icon0;
            saveLoadData.pic1 = pic1;
            saveLoadData.size_pic1 = size_pic1;
            saveLoadData.data = data;
            saveLoadData.dataSize = 100;
            oslInitSaveDialog(&saveLoadData);
            memset(message, 0, sizeof(message));
            
            break;
        }
        
        oslEndDrawing();
        oslSyncFrame();
    }
    
    
    return 0;
}

