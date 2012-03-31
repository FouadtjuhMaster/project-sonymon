#include <oslib/oslib.h>

/*Wait; will pause the screen for 3 seconds*/
#define Wait sceKernelDelayThread(3000000);

/*Wait; will pause the screen for 0.5 seconds*/
#define hWait sceKernelDelayThread(500000);

#define normal verdana
#define bold verdana

/* battle macros */
#define MAX_SHIFT 130
#define MIN_SHIFT 100
#define HIGHLIGHTED 1
#define IGNORED 0

/* sprite macros */
#define FACING_RIGHT 2
#define FACING_LEFT 1
#define FACING_UP 3
#define FACING_DOWN 4

/* game modes */
#define STORY 1
#define FREE_ROAM 2

/* sprite positions */
#define DOWN 0
#define UP 34
#define LEFT 67
#define RIGHT 99

/* battle macros */
#define SUPER_EFFECTIVE 2
#define NOT_EFFECTIVE 0
#define NOTHING 1

/* map macros */
#define UPLINK_CENTER 55
#define HOME 56

/* other macros */
#define NO 9032
#define YES 8923

//free roam maps
#include "levels/FR1.h"
#include "levels/world_route.h"

typedef OSL_IMAGE IMAGE;
typedef OSL_SOUND SOUND;
typedef OSL_FONT FONT;

class SONYMON {
    public:
           SONYMON();
           ~SONYMON();
           
           //properties
           IMAGE * image;
           const char * name;
           const char * moveName1;
           const char * moveName2;
           const char * moveName3;
           const char * moveName4;
           int health;
           int maxHealth;
           int attack;
           int defense;
           int type;
           int xp;
           int max_xp;
           short move1;
           short move2;
           short move3;
           short move4;
           short alive;
           short id;
           short level;
           
           //behaviors
           void ASSIGN_SONYMON(int slot, int id, int level);
           int ApplyTypes(const int moveUsed, int &damagePower, const int enemyRealType, int &EFFECT);
           int ApplyAttackValue(int getValue, int enemyAttackPower);
           
    private:
        //varaibles
}sonymon1, sonymon2, sonymon3, sonymon4, sonymon5, create;

/* pointers to the maps themselves */
OSL_MAP *Current_Map, *World_Route, *FR1;

/*Level tileset pointers*/
IMAGE *World_Route_tileset, *FR1_tileset;

//game images
IMAGE *background_grass, *background_rock, *messageBox, *pointer, *battle_selector, 
*mini_rec_selector, *DialogBox, *sb, *temp1, *temp2, *temp3, *pound_mark, *dialog_box, 
*enemy_dialog_box, *xp_bar, *linkOff, *linkOn, *item1, *item2, *item3, *uplink_center, 
*fightBox, *battle_pointer, *hp_bar, *enemy1, *enemy2, *enemy3;

/*declare our pointers toward our sound effects (wav files and bgm files)*/
SOUND *unknown, *coin, *wild_battle, *leader_battle, *boss_battle, *wild_intro, *leader_intro,
*gameMusic, *hurt_low, *hurt_medium, *hurt_high, *tackle_sound, *slam_sound, *uplink_sound, *beep,
*pound_sound, *boss_intro, *found, *enter, *jumpKick_sound, *contaminate_sound, *clobber_sound, *steroids_sound,
*healthBoost;

//declare font pointers
FONT *verdana;

/*************************** sonymon images and sounds *******************************************/
IMAGE *blumkins_back, *blumkins_front, *arsande_back, *arsande_front,
*argrasse_front, *argrasse_back, *myboross_back, *myboross_front, *norbonkge_front, *norbonkge_back,
*blowhole_front, *blowhole_back, *lieosaur_front, *lieosaur_back, *cemes_front, *cemes_back, *waterserore_front,
*waterserore_back, *vandel_front, *vandel_back, *unknown_back, *unknown_front, *sturk_front, *sturk_back,
*blip_front, *blip_back, *cecei_front, *cecei_back, *fanz_front, *fanz_back, *darck_front, *darck_back,
*feesh_front, *feesh_back, *abel_front, *abel_back, *chaos_front, *chaos_back;

SOUND *blumkins, *arsande, *myboross, *argrasse, *norbonkge, *blowess, *cemes, *waterserore, *vandel, 
*lieosaur, *Selected, *center_music, *sturk, *cecei,
*blip, *fanz, *darck, *feesh, *abel, *chaos;

enum colors 
{
    RED          = 0xFF0000FF,
	GREEN        = 0xFF00FF00,
	BLUE         = 0xFFFF0000,
	WHITE        = 0xFFFFFFFF,
	LIGHTGRAY    = 0xFFBFBFBF,
	GRAY         = 0xFF7F7F7F,
	DARKGRAY     = 0xFF3F3F3F,		
	BLACK        = 0xFF000000,
	AZURE        = 0xFFFF7F00,
    VIOLET       = 0xFFFF007F,
    ROSE         = 0xFF7F00FF,
    ORANGE       = 0xFF007FFF,
    CHARTREUSE   = 0xFF00FF7F,
    SPRING_GREEN = 0xFF7FFF00,
    CYAN         = 0xFFFFFF00,
    MAGENTA      = 0xFFFF00FF,
    YELLOW       = 0xFF00FFFF,
};

enum types {
  UNDEFINED = 0,
  STATIC = 1,
  ROCK = 2,
  GRASS = 3,
  FLYING = 4,
  ULTRAVIOLET = 5,
  NORMAL = 6,
  WATER = 7,
  FIRE = 8,
  ICE = 9,
};

enum moves {
  erased = 0,
  empty = 0,
  tackle = 1,
  slam = 2,
  pound = 3,
  jumpKick = 4,
  waterGun = 5,
  blaze = 6,
  steroids = 7,
  uplink = 8,
  contaminate = 9,
  leech = 10,
  gust = 11,
  clobber = 12,
};

enum items {
  DEFAULT = 0,
  potion = 1,
  super_potion = 2,
  hyper_potion = 3,
  wonder_drug = 4,
  MP_boost = 99,
  LUJ = 98,
};

const char * des1;
const char * des2;
const char * des3;
const char * des4;
const char * des5;

//battle option variables
typedef int OPTION;
OPTION FIGHT = 0;
OPTION BAG = 0;
OPTION SNYMN = 0;
OPTION FLEE = 0;
OPTION FIRST_MOVE = 0;
OPTION SECOND_MOVE = 0;
OPTION THIRD_MOVE = 0;
OPTION FOURTH_MOVE = 0;

/* types of tiles (based off of FR1.h */
const int TOP_DIRT                = FR1_map[0][0];
const int DIRT                    = FR1_map[0][1];
const int STONE_WALL              = FR1_map[0][5];
const int STONE_WALL_OVERHEAD     = FR1_map[15][4];
const int STONE_WALL_OVERHEAD_TOP = FR1_map[50][0];
const int GRAY_ROAD               = FR1_map[2][6];
const int GRAY_ROAD_TOP           = FR1_map[2][6];

/* sonymon globals */
int SonymonSeen[99];  //counts all the sonymon the player has seen
int SonymonOwned[99]; //counts all the sonymon the player owns

int sonymon_num = 0;  //a counter for which soymon is active
int totalSonymon = 0; //a counter for all of the player's sonymon in party
const char * RecordName;

/* game variables */
long long money;

int level = 0;
int turn = 0;
int ran = 0;
int quitGame = 0;
int collide = 0;
int battle = 0;
int searchBattle = 0;
int accessBag = 0;
int accessParty = 0;
int accessRecords = 0;
int accessPlayer = 0;
int saveGame = 0;
int accessFrequency = 0;
int briefPause = 0;
int allowSearch = 0;
int loadedBefore = 0;
int battleChoice = 1;
int battleManip = 1;
int InsideCenter = 0;
int Appeared = 0;
int EFFECT = 1;
int ENEMY_EFFECT = 1;
int swait = 0;
int EXIT_GAME = 0;
int introPassed = 0;
int area = HOME;

/* enemy variables */
int enemyAlive = 0;
int enemyAlive1;
int enemyAlive2;
int enemyAlive3;
int enemyMove1 = empty;
int enemyMove2 = empty;
int enemyMove3 = empty;
int enemyMove4 = empty;
int enemyUsedMove = empty;
const char * enemyName;
const char * enemyMoveName;

//health bar related variables
int loadedHealthBefore = 0;
int MAX_HP = 0;
int loadedEnemyHealthBefore = 0;
int MAX_ENEMY_HP = 0;
int HEALTH_BAR_COLOR = 0xFF000000;
int ENEMY_HEALTH_BAR_COLOR = 0xFF000000;
int OUTLINE_MAX = 0;
int OUTLINE_ENEMY_MAX = 0;
int selecting = 0;
int selectMoves = 0;

/* item variables */
int itemSwap = 1;
int itemSwapManip = 0;
int itemSpawned = 0;
int seenItem = 0;
int justEntered = 0;

//local variables I have been too lazy to place anywhere else :P
unsigned long GOING_UP, GOING_DOWN;

//very small function...decided to just place it here
void place(OSL_IMAGE *img, int posx, int posy){
     img->x = posx;
     img->y = posy;
     return;
}

//external functions
void MISSING_IMG_FILES(int type);

int collision(OSL_IMAGE *img1,float img1posX, float img1posY, OSL_IMAGE *img2, float img2posX, float img2posY );

int SAVEGAME(int sonymon1ID, int sonymon1LEVEL, int sonymon2ID, int sonymon2LEVEL, int sonymon3ID, int sonymon3LEVEL);

int LOADGAME(short &sonymon1ID, short &sonymon1LEVEL, short &sonymon2ID, short &sonymon2LEVEL, short &sonymon3ID, short &sonymon3LEVEL);

int initOSLib();

//battle functions
int UPDATE(int &enemyHealth, const int enemyDefense, const int enemyRealType, OSL_IMAGE * enemy, OSL_IMAGE * background);

char setEnemyType(int type, int level, OSL_IMAGE *enemy);

void waitForClick(const char * message, OSL_IMAGE *background, OSL_IMAGE *enemy, OSL_IMAGE *player, OSL_IMAGE *pointer);

void playDeathSound(int type);

int getPlayerSonymon();

void positionScreenItems(OSL_IMAGE *enemy);

OSL_IMAGE * DrawCharacterTextBox(OSL_IMAGE * image);

OSL_IMAGE * DrawEnemyTextBox(int enemyHealth, OSL_IMAGE * image);

void BATTLE(const char * playerName, OSL_IMAGE * enemy, const int enemyID, const int enemyLevel);

//general functions
void LoadFiles();

void TransitionUp(OSL_MAP * map, OSL_IMAGE * image);

void ClearMessageBox( void );

void place(OSL_IMAGE *img, int posx, int posy);

void HANDLE_SEARCH(const char * playerName, OSL_MAP * map);

void ENTRY_EFFECT(OSL_MAP * map, int area);

void ResetStats( void );


//sonymon free roam functions
void HANDLE(const char * playerName, OSL_MAP * level);

int SonymonFreeRoam(const char * playerName);


#include "engine/stats.h"

#include "engine/message.h"

#include "engine/item.h"

#include "engine/map.h"

#include "engine/animation.h"

#include "engine/menu.h"

#include "engine/updateTurn.h"

#include "engine/player.h"

#include "engine/enemy.h"

#include "engine/computer.h"

#include "save.h"
