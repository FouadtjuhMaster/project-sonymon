#include "save.h"

int LOADGAME(int &sonymon1ID, int &sonymon1LEVEL, int &sonymon2ID, int &sonymon2LEVEL, int &sonymon3ID, int &sonymon3LEVEL)
{
    struct oslSaveLoad saveLoadData;
    int type = OSL_DIALOG_NONE;
    char message[100] = "";
    char loadedData[100] = "";
    
    while(1)
    {
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
    }
    
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


