#include <oslib/oslib.h>

/*Wait; will pause the screen for 3 seconds*/
#define Wait sceKernelDelayThread(3000000);

/*Wait; will pause the screen for 0.5 seconds*/
#define hWait sceKernelDelayThread(500000);

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
unsigned menuChoice = 1;
unsigned gameSelect = 0;

int SonymonFreeRoam(const char * playerName, const int load);

void placeSelector(OSL_IMAGE *image, int x, int y) {
	image->x = x;
	image->y = y;
}

void VAUGHN_LOGO( void );

void showCredits( void );

void askContinue( void );

const char * getInput();

int main(int argc, char* argv[]);
