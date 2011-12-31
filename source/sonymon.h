#include <oslib/oslib.h>

/*Wait; will pause the screen for 3 seconds*/
#define Wait sceKernelDelayThread(3000000);

/*Wait; will pause the screen for 0.5 seconds*/
#define hWait sceKernelDelayThread(500000);

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
#define SECRUIT_TOWN -99
#define UPLINK_CENTER -98
#define WORLD_ROUTE -97
#define fromRoute01 1
#define fromRoute02 2
#define fromRoute03 3
#define fromRoute04 4
#define fromWorldRoute 0
#define fromUnknown -1

/* other macros */
#define NO 9032
#define YES 8923
#define OVER_EXPOSURE 150

//story mode maps
#include "levels/Secruit Town.h"

//free roam maps
#include "levels/FR1.h"
#include "levels/world_route.h"
#include "levels/route01.h"
#include "levels/route02.h"
#include "levels/route03.h"
#include "levels/route04.h"

/* pointers to the maps themselves */
OSL_MAP *Current_Map, *Level1, *Level2, *World_Route, *Route01, *Route02, *Route03, *Route04,
*Secruit_Town, *FR1;

/*Level tileset pointers*/
OSL_IMAGE *World_Route_tileset, *Route01_tileset, *Route02_tileset, 
*Route03_tileset, *Route04_tileset, *Secruit_Town_tileset, *FR1_tileset;

//game images
OSL_IMAGE *zero, *background_grass, *background_rock, *messageBox, *pointer, *battle_selector, 
*mini_rec_selector, *DialogBox, *sb, *temp1, *temp2, *temp3, *pound_mark, *dialog_box, 
*enemy_dialog_box, *xp_bar, *linkOff, *linkOn, *item1, *item2, *item3, *uplink_center, 
*fightBox, *battle_pointer, *hp_bar, *enemy1, *enemy2, *enemy3, *sonymon_pic1, *sonymon_pic2,
*sonymon_pic3;

/*declare our pointers toward our sound effects (wav files and bgm files)*/
OSL_SOUND *unknown, *coin, *wild_battle, *leader_battle, *boss_battle, *wild_intro, *leader_intro,
*gameMusic, *hurt_low, *hurt_medium, *hurt_high, *tackle_sound, *slam_sound, *uplink_sound, *beep,
*pound_sound, *boss_intro, *found, *enter, *jumpKick_sound, *contaminate_sound, *clobber_sound, *steroids_sound;

//declare font pointers
OSL_FONT *verdana, *default_font, *main_font, *battle_font, *bold_battle_font;

/*************************** sonymon images and sounds *******************************************/
OSL_IMAGE *blumkins_back, *blumkins_front, *arsande_back, *arsande_front,
*argrasse_front, *argrasse_back, *myboross_back, *myboross_front, *norbonkge_front, *norbonkge_back,
*blowhole_front, *blowhole_back, *lieosaur_front, *lieosaur_back, *cemes_front, *cemes_back, *waterserore_front,
*waterserore_back, *vandel_front, *vandel_back, *unknown_back, *unknown_front, *sturk_front, *sturk_back,
*blip_front, *blip_back, *cecei_front, *cecei_back, *fanz_front, *fanz_back;

OSL_SOUND *blumkins, *arsande, *myboross, *argrasse, *norbonkge, *blowess, *cemes, *waterserore, *vandel, 
*lieosaur, *enemy12, *enemy13, *enemy14, *enemy15, *enemy16, *Selected, *center_music, *sturk, *cecei,
*blip, *fanz;

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

enum types
{
  UNDEFINED = 0,
  STATIC = 1,
  ROCK = 2,
  GRASS = 3,
  FLYING = 4,
  ULTRAVIOLET = 5,
  NORMAL = 6,
  WATER = 7,
  FIRE = 8,
};

enum moves 
{
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

enum items
{
  DEFAULT = 0,
  potion = 1,
  super_potion = 2,
  hyper_potion = 3,
  wonder_drug = 4,
  MP_boost = 99,
  LUJ = 98,
};

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
long inventory[200];  //inventory for the player... holds 200 items
int sonymon_num = 0;  //a counter for which soymon is active
int numofSonymon = 0;
int currentSonymon = 0;
const char * currentSonymonName;
const char * RecordName;

//electromagnetic spectrum variables
const char * Hz = "0Hz";
const char * radiation = "Visible radiation (light)"; 
int exposure = 0;
int manipExposure = 0;

int loadedStoryBefore = 0;
int loadedFRBefore = 0;

/* game variables */
const char * object;
int level = 0;
int turn = 0;
int ran = 0;
int quitGame = 0;
int collide = 0;
int battle = 0;
int manipulate = 0;
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
int Toggle1 = 0;
int EFFECT = 1;
int ENEMY_EFFECT = 1;
int swait = 0;
int EXIT_GAME = 0;
int introPassed = 0;
int area = 0;

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

/* player variables */
float money = 0.00f;
int speed = 2;
int sprite_position;
int sprite_march;
int walked_left = 0;
int walked_right = 0;
int walked_up = 0;
int walked_down = 0;
int playerTime = 0;
float zeroMapX;
float zeroMapY;
int zeroStoppedX = 0;
int zeroStoppedY = 0;

//sonymon slot 1
const char * sonymon1_name;
const char * sonymon1_moveName1;
const char * sonymon1_moveName2;
const char * sonymon1_moveName3;
const char * sonymon1_moveName4;
int sonymon1_health = 0;
int sonymon1_maxHealth = 0;
int sonymon1_attack = 0;
int sonymon1_defense = 0;
int sonymon1_move1 = 0;
int sonymon1_move2 = 0;
int sonymon1_move3 = 0;
int sonymon1_move4 = 0;
int sonymon1_alive = 0;
int sonymon1_type = UNDEFINED;
int sonymon1_level = 1;
int sonymon1_id = 1;
int sonymon1_xp = 0;
int sonymon1_max_xp = 0;

//sonymon slot 2
const char * sonymon2_name;
const char * sonymon2_moveName1;
const char * sonymon2_moveName2;
const char * sonymon2_moveName3;
const char * sonymon2_moveName4;
int sonymon2_health = 0;
int sonymon2_maxHealth = 0;
int sonymon2_attack = 0;
int sonymon2_defense = 0;
int sonymon2_move1 = 0;
int sonymon2_move2 = 0;
int sonymon2_move3 = 0;
int sonymon2_move4 = 0;
int sonymon2_alive = 0;
int sonymon2_type = UNDEFINED;
int sonymon2_level = 1;
int sonymon2_id = 1;
int sonymon2_xp = 0;
int sonymon2_max_xp = 0;

//sonymon slot 3
const char * sonymon3_name;
const char * sonymon3_moveName1;
const char * sonymon3_moveName2;
const char * sonymon3_moveName3;
const char * sonymon3_moveName4;
int sonymon3_health = 0;
int sonymon3_maxHealth = 0;
int sonymon3_attack = 0;
int sonymon3_defense = 0;
int sonymon3_move1 = 0;
int sonymon3_move2 = 0;
int sonymon3_move3 = 0;
int sonymon3_move4 = 0;
int sonymon3_alive = 0;
int sonymon3_type = UNDEFINED;
int sonymon3_level = 1;
int sonymon3_id = 1;
int sonymon3_xp = 0;
int sonymon3_max_xp = 0;

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


//external functions
void MISSING_IMG_FILES(int type);

int collision(OSL_IMAGE *img1,float img1posX, float img1posY, OSL_IMAGE *img2, float img2posX, float img2posY );

int SAVEGAME(int sonymon1ID, int sonymon1LEVEL, int sonymon2ID, int sonymon2LEVEL, int sonymon3ID, int sonymon3LEVEL);

int LOADGAME(int &sonymon1ID, int &sonymon1LEVEL, int &sonymon2ID, int &sonymon2LEVEL, int &sonymon3ID, int &sonymon3LEVEL);

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

void TRAINER_BATTLE(const char * playerName, const char * trainerName, OSL_IMAGE * trainer, 
                    const int enemyID1, const int enemyLevel1, const int enemyID2, const int enemyLevel2,
                    const int enemyID3, const int enemyLevel3);

//general functions
void LoadFiles(const int mode);

void TransitionUp(OSL_MAP * map, OSL_IMAGE * image);

void ClearMessageBox( void );

void place(OSL_IMAGE *img, int posx, int posy);

void HANDLE_SEARCH(const char * playerName, OSL_MAP * map);

void ASSIGN_SONYMON(int slot, int id, int level);

int ApplyAttackValue( int getValue, int enemyAttackPower );

int ApplyTypes(const int moveUsed, int &damagePower, const int enemyRealType, int &EFFECT);

void ENTRY_EFFECT(OSL_MAP * map, int area);

void ResetStats( void );



//sonymon free roam functions
void HANDLE(const char * playerName, OSL_MAP * level);

int SonymonFreeRoam(const char * playerName);



//sonymon story mode functions
int EVENT_HANDLER(OSL_MAP * map);

void HANDLE_STORY(const char * playerName, OSL_MAP * level);

int Sonymon(const char * playerName);



#include "classes/stats.h"

#include "classes/message.h"

#include "classes/item.h"

#include "classes/menu.h"

#include "classes/map.h"

#include "classes/computer.h"

#include "classes/animation.h"

#include "classes/updateTurn.h"

#include "classes/player.h"

#include "classes/enemy.h"

