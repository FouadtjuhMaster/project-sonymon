#include <pspkernel.h>
#include <pspdisplay.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <pspmoduleinfo.h>
#include <psputility.h>
#include <pspgu.h>
#include <pspgum.h>
#include <oslib/oslib.h>

/*Wait; will pause the screen for 3 seconds*/
#define Wait sceKernelDelayThread(3000000);

/*briefWait; will pause the screen for 0.5 seconds*/
#define briefWait sceKernelDelayThread(500000);

#define min(x, y) (((x)>(y))?(y):(x))
#define WIDTH 480
#define HEIGHT 272

#define BUF_WIDTH (512)
#define SCR_WIDTH (480)
#define SCR_HEIGHT (272)
#define PIXEL_SIZE (4)
#define FRAME_SIZE (BUF_WIDTH * SCR_HEIGHT * PIXEL_SIZE)
#define ZBUF_SIZE (BUF_WIDTH SCR_HEIGHT * 2)
#define NUM_INPUT_FIELDS	(1)
#define TEXT_LENGTH			(16)
#define MAX_LIGHTS 6

/*declare our pointers toward our sound effects (wav files and bgm files)*/
OSL_SOUND *menu_music, *select, *start_music;

//declare images
OSL_IMAGE *rec_selector, *menu_background, *menu_background2, *menu_background3;

pspUtilityMsgDialogParams dialog;

const char * playerName; 
int quit, selected = 0;
unsigned menuChoice = 1; //by default
unsigned gameSelect = 0;
char string[256];
char button[12];

static int done = 0;
static unsigned int __attribute__((aligned(16))) list[262144];

struct Vertex
{
    float u, v;
    unsigned int color;
    float x,y,z;
};

struct Vertex __attribute__((aligned(16))) vertices[12*3] =
{
    {0, 0, 0xff7f0000,-1,-1, 1}, // 0
    {1, 0, 0xff7f0000,-1, 1, 1}, // 4
    {1, 1, 0xff7f0000, 1, 1, 1}, // 5
    
    {0, 0, 0xff7f0000,-1,-1, 1}, // 0
    {1, 1, 0xff7f0000, 1, 1, 1}, // 5
    {0, 1, 0xff7f0000, 1,-1, 1}, // 1
    
    {0, 0, 0xff7f0000,-1,-1,-1}, // 3
    {1, 0, 0xff7f0000, 1,-1,-1}, // 2
    {1, 1, 0xff7f0000, 1, 1,-1}, // 6
    
    {0, 0, 0xff7f0000,-1,-1,-1}, // 3
    {1, 1, 0xff7f0000, 1, 1,-1}, // 6
    {0, 1, 0xff7f0000,-1, 1,-1}, // 7
    
    {0, 0, 0xff007f00, 1,-1,-1}, // 0
    {1, 0, 0xff007f00, 1,-1, 1}, // 3
    {1, 1, 0xff007f00, 1, 1, 1}, // 7
    
    {0, 0, 0xff007f00, 1,-1,-1}, // 0
    {1, 1, 0xff007f00, 1, 1, 1}, // 7
    {0, 1, 0xff007f00, 1, 1,-1}, // 4
    
    {0, 0, 0xff007f00,-1,-1,-1}, // 0
    {1, 0, 0xff007f00,-1, 1,-1}, // 3
    {1, 1, 0xff007f00,-1, 1, 1}, // 7
    
    {0, 0, 0xff007f00,-1,-1,-1}, // 0
    {1, 1, 0xff007f00,-1, 1, 1}, // 7
    {0, 1, 0xff007f00,-1,-1, 1}, // 4
    
    {0, 0, 0xff00007f,-1, 1,-1}, // 0
    {1, 0, 0xff00007f, 1, 1,-1}, // 1
    {1, 1, 0xff00007f, 1, 1, 1}, // 2
    
    {0, 0, 0xff00007f,-1, 1,-1}, // 0
    {1, 1, 0xff00007f, 1, 1, 1}, // 2
    {0, 1, 0xff00007f,-1, 1, 1}, // 3
    
    {0, 0, 0xff00007f,-1,-1,-1}, // 4
    {1, 0, 0xff00007f,-1,-1, 1}, // 7
    {1, 1, 0xff00007f, 1,-1, 1}, // 6
    
    {0, 0, 0xff00007f,-1,-1,-1}, // 4
    {1, 1, 0xff00007f, 1,-1, 1}, // 6
    {0, 1, 0xff00007f, 1,-1,-1}, // 5
};

//external functions
int SonymonFreeRoam(const char * playerName, const int load);

int Sonymon(const char * playerName, const int load);

//local functions
int MISSING_IMG_FILES(int type);

void intro( void );

void VAUGHN_LOGO( void );

void showGameOptions( void );

void placeSelector(OSL_IMAGE *image, int x, int y);

int collision(OSL_IMAGE *img1,float img1posX, float img1posY, OSL_IMAGE *img2, float img2posX, float img2posY );

void showCredits( void );

void askQuit( void );

void askContinue( void );

void askOptions( void );

void showError( void );

int logoAffiche();

char getInput();

static void SetupGu();

static void DrawStuff(void);

static void ConfigureDialog(pspUtilityMsgDialogParams *dialog, size_t dialog_size);

static void ShowErrorDialog(const unsigned int error);

static void ShowMessageDialog(const char *message, int enableYesno);

int main(int argc, char* argv[]);


