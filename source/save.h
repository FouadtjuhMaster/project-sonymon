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

int SAVEGAME();

int SAVEGAME(int sonymon1ID, int sonymon1LEVEL, int sonymon2ID, int sonymon2LEVEL, int sonymon3ID, int sonymon3LEVEL);

int LOADGAME(int &sonymon1ID, int &sonymon1LEVEL, int &sonymon2ID, int &sonymon2LEVEL, int &sonymon3ID, int &sonymon3LEVEL);

