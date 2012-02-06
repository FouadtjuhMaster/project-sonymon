#include "sonymon.h"

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
//sonymon class method definitions:////////////////////

/* create a sonymon and assign them to a certain slot */
void SONYMON::ASSIGN_SONYMON(int slot, int id, int level)
{     
     if(slot == 1){   
       sonymon1.level = level;
       stats.setAttackPower(sonymon1.attack, id, level);
       stats.setHealth(sonymon1.health, id, level);
       stats.setDefense(sonymon1.defense, id, level);
       stats.setType(sonymon1.type, id); 
       
       sonymon1.maxHealth = sonymon1.health;    
       sonymon1.image = stats.setImage(id);    
     }
     
     else if(slot == 2){
       sonymon2.level = level;
       stats.setAttackPower(sonymon2.attack, id, level);
       stats.setHealth(sonymon2.health, id, level);
       stats.setDefense(sonymon2.defense, id, level);
       stats.setType(sonymon2.type, id);
       
       sonymon2.maxHealth = sonymon2.health; 
       sonymon2.image = stats.setImage(id);
     }
     
     else if(slot == 3){
       sonymon3.level = level;
       stats.setAttackPower(sonymon3.attack, id, level);
       stats.setHealth(sonymon3.health, id, level);
       stats.setDefense(sonymon3.defense, id, level);
       stats.setType(sonymon3.type, id);
       
       sonymon3.maxHealth = sonymon3.health; 
       sonymon3.image = stats.setImage(id);
     }
     
     stats.setMoves(slot, id, level);
     stats.setName(id, slot);
     stats.setMoveNames(slot);
     stats.SetMaxXP(slot, id);
     
     SonymonSeen[id] = id; //now the player has seen this sonymon (probably already did in battle) ...double checking is always good
     SonymonOwned[id] = id; //now the player owns this sonymon
     
     return;
}

int SONYMON::ApplyAttackValue(int getValue, int enemyAttackPower)
{
     /*
        DECIDED VALUES FOR EACH MOVE(DONT FORGET VALUES ARE APPLIED BY ATTACK POWER AFTER!!!)
        -empty: 0
        -tackle:      20
        -slam:        30
        -pound:       10
        -jumpkick:    50
        -waterGun:    35
        -blaze:       20
        -steroids:    60
        -uplink:      75
        -contaminate: 90
        -leech:       30
        -gust:        25
        -clobber:     60
     */
     
     int changedValue = 0;
    
     if(getValue == tackle)            changedValue = 20;   //tackle
     else if(getValue == slam)         changedValue = 30;   //slam
     else if(getValue == pound)        changedValue = 10;   //pound
     else if(getValue == jumpKick)     changedValue = 50;   //jumpkick
     else if(getValue == waterGun)     changedValue = 35;   //water gun
     else if(getValue == blaze)        changedValue = 20;   //blaze
     else if(getValue == steroids)     changedValue = 60;   //steroids
     else if(getValue == uplink)       changedValue = 75;   //uplink
     else if(getValue == contaminate)  changedValue = 90;   //contaminate
     else if(getValue == leech)        changedValue = 25;   //leech
     else if(getValue == gust)         changedValue = 30;   //gust
     else if(getValue == clobber)      changedValue = 65;   //clobber
     
     else oslFatalError("Failed to apply attack value to int &changedVaule\nin function void ApplyAttackValue();!!!");
     
     //now add changed value with attack power
     changedValue = changedValue + enemyAttackPower;
     
     //now divide the attack by two... to make the sonymon weaker
     if(changedValue > 1)
         changedValue = changedValue / 2;
         
     return changedValue;
}

int SONYMON::ApplyTypes(const int moveUsed, int &damagePower, const int enemyRealType, int &EFFECT)
{
    int manipType = UNDEFINED;
    int manipEnemyType = UNDEFINED;
    EFFECT = 1;
    
    if(moveUsed == tackle)           manipType = NORMAL;
    else if(moveUsed == slam)        manipType = NORMAL;
    else if(moveUsed == pound)       manipType = NORMAL;
    else if(moveUsed == jumpKick)    manipType = NORMAL;
    else if(moveUsed == waterGun)    manipType = WATER;
    else if(moveUsed == blaze)       manipType = FIRE;
    else if(moveUsed == steroids)    manipType = UNDEFINED;
    else if(moveUsed == uplink)      manipType = STATIC;
    else if(moveUsed == contaminate) manipType = ULTRAVIOLET;
    else if(moveUsed == leech)       manipType = GRASS;
    else if(moveUsed == gust)        manipType = FLYING;
    else if(moveUsed == clobber)     manipType = ROCK;
    else oslFatalError("Could not detect what the move or type of move was used!!\nfound in function ApplyTypes();!!!");
    
    manipEnemyType = enemyRealType;
    
    //see TypesTable.txt!!!!!!!!!!
    
    //manipEnemyType is the enemy's type, and manipType is the move type
    if(manipEnemyType == UNDEFINED && manipType == UNDEFINED)         {EFFECT = NOTHING; }
    else if(manipEnemyType == UNDEFINED && manipType == NORMAL)       {EFFECT = NOTHING; }
    else if(manipEnemyType == UNDEFINED && manipType == STATIC)       {EFFECT = NOTHING; }
    else if(manipEnemyType == UNDEFINED && manipType == GRASS)        {EFFECT = NOTHING; }
    else if(manipEnemyType == UNDEFINED && manipType == WATER)        {EFFECT = NOTHING; }
    else if(manipEnemyType == UNDEFINED && manipType == FLYING)       {EFFECT = NOTHING; }
    else if(manipEnemyType == UNDEFINED && manipType == ULTRAVIOLET)  {EFFECT = NOTHING; }
    else if(manipEnemyType == UNDEFINED && manipType == ROCK)         {EFFECT = NOTHING; }
    else if(manipEnemyType == UNDEFINED && manipType == FIRE)         {EFFECT = NOTHING; }
    
    else if(manipEnemyType == NORMAL && manipType == UNDEFINED)    {EFFECT = NOTHING;          }
    else if(manipEnemyType == NORMAL && manipType == NORMAL)       {EFFECT = NOTHING;          }
    else if(manipEnemyType == NORMAL && manipType == STATIC)       {EFFECT = SUPER_EFFECTIVE;  }
    else if(manipEnemyType == NORMAL && manipType == GRASS)        {EFFECT = NOTHING;          }
    else if(manipEnemyType == NORMAL && manipType == WATER)        {EFFECT = NOTHING;          }
    else if(manipEnemyType == NORMAL && manipType == FLYING)       {EFFECT = NOTHING;          }
    else if(manipEnemyType == NORMAL && manipType == ULTRAVIOLET)  {EFFECT = SUPER_EFFECTIVE;  }
    else if(manipEnemyType == NORMAL && manipType == ROCK)         {EFFECT = NOTHING;          }
    else if(manipEnemyType == NORMAL && manipType == FIRE)         {EFFECT = NOTHING;          }
    
    else if(manipEnemyType == STATIC && manipType == UNDEFINED)    {EFFECT = NOTHING;         }
    else if(manipEnemyType == STATIC && manipType == NORMAL)       {EFFECT = NOTHING;         }
    else if(manipEnemyType == STATIC && manipType == STATIC)       {EFFECT = NOT_EFFECTIVE;   }
    else if(manipEnemyType == STATIC && manipType == GRASS)        {EFFECT = NOTHING;         }
    else if(manipEnemyType == STATIC && manipType == WATER)        {EFFECT = NOTHING;         }
    else if(manipEnemyType == STATIC && manipType == FLYING)       {EFFECT = NOT_EFFECTIVE;   }
    else if(manipEnemyType == STATIC && manipType == ULTRAVIOLET)  {EFFECT = NOT_EFFECTIVE;   }
    else if(manipEnemyType == STATIC && manipType == ROCK)         {EFFECT = SUPER_EFFECTIVE; }
    else if(manipEnemyType == STATIC && manipType == FIRE)         {EFFECT = NOTHING;         }
    
    else if(manipEnemyType == GRASS && manipType == UNDEFINED)    {EFFECT = NOTHING;          }
    else if(manipEnemyType == GRASS && manipType == NORMAL)       {EFFECT = NOTHING;          }
    else if(manipEnemyType == GRASS && manipType == STATIC)       {EFFECT = NOTHING;          }
    else if(manipEnemyType == GRASS && manipType == GRASS)        {EFFECT = NOT_EFFECTIVE;    }
    else if(manipEnemyType == GRASS && manipType == WATER)        {EFFECT = NOT_EFFECTIVE;    }
    else if(manipEnemyType == GRASS && manipType == FLYING)       {EFFECT = NOTHING;          }
    else if(manipEnemyType == GRASS && manipType == ULTRAVIOLET)  {EFFECT = SUPER_EFFECTIVE;  }
    else if(manipEnemyType == GRASS && manipType == ROCK)         {EFFECT = NOTHING;          }
    else if(manipEnemyType == GRASS && manipType == FIRE)         {EFFECT = SUPER_EFFECTIVE;  }
    
    else if(manipEnemyType == WATER && manipType == UNDEFINED)    {EFFECT = NOTHING;          }
    else if(manipEnemyType == WATER && manipType == NORMAL)       {EFFECT = NOTHING;          }
    else if(manipEnemyType == WATER && manipType == STATIC)       {EFFECT = NOTHING;          }
    else if(manipEnemyType == WATER && manipType == GRASS)        {EFFECT = SUPER_EFFECTIVE;  }
    else if(manipEnemyType == WATER && manipType == WATER)        {EFFECT = NOTHING;          }
    else if(manipEnemyType == WATER && manipType == FLYING)       {EFFECT = NOTHING;          }
    else if(manipEnemyType == WATER && manipType == ULTRAVIOLET)  {EFFECT = SUPER_EFFECTIVE;  }
    else if(manipEnemyType == WATER && manipType == ROCK)         {EFFECT = NOTHING;          }
    else if(manipEnemyType == WATER && manipType == FIRE)         {EFFECT = NOT_EFFECTIVE;    }
    
    else if(manipEnemyType == FLYING && manipType == UNDEFINED)   {EFFECT = NOTHING;          }
    else if(manipEnemyType == FLYING && manipType == NORMAL)      {EFFECT = NOTHING;          }
    else if(manipEnemyType == FLYING && manipType == STATIC)      {EFFECT = SUPER_EFFECTIVE;  }
    else if(manipEnemyType == FLYING && manipType == GRASS)       {EFFECT = NOTHING;          }
    else if(manipEnemyType == FLYING && manipType == WATER)       {EFFECT = NOTHING;          }
    else if(manipEnemyType == FLYING && manipType == FLYING)      {EFFECT = NOTHING;          }
    else if(manipEnemyType == FLYING && manipType == ULTRAVIOLET) {EFFECT = SUPER_EFFECTIVE;  }
    else if(manipEnemyType == FLYING && manipType == ROCK)        {EFFECT = NOTHING;          }
    else if(manipEnemyType == FLYING && manipType == FIRE)        {EFFECT = NOTHING;          }
    
    else if(manipEnemyType == ROCK && manipType == UNDEFINED)     {EFFECT = NOTHING;         }
    else if(manipEnemyType == ROCK && manipType == NORMAL)        {EFFECT = NOT_EFFECTIVE;   }
    else if(manipEnemyType == ROCK && manipType == STATIC)        {EFFECT = SUPER_EFFECTIVE; }
    else if(manipEnemyType == ROCK && manipType == GRASS)         {EFFECT = SUPER_EFFECTIVE; }
    else if(manipEnemyType == ROCK && manipType == WATER)         {EFFECT = SUPER_EFFECTIVE; }
    else if(manipEnemyType == ROCK && manipType == FLYING)        {EFFECT = NOT_EFFECTIVE;   }
    else if(manipEnemyType == ROCK && manipType == ULTRAVIOLET)   {EFFECT = SUPER_EFFECTIVE; }
    else if(manipEnemyType == ROCK && manipType == ROCK)          {EFFECT = NOT_EFFECTIVE;   }
    else if(manipEnemyType == ROCK && manipType == FIRE)          {EFFECT = NOT_EFFECTIVE;   }
    
    else if(manipEnemyType == ULTRAVIOLET && manipType == UNDEFINED)   {EFFECT = NOTHING;         }
    else if(manipEnemyType == ULTRAVIOLET && manipType == NORMAL)      {EFFECT = NOT_EFFECTIVE;   }
    else if(manipEnemyType == ULTRAVIOLET && manipType == STATIC)      {EFFECT = SUPER_EFFECTIVE; }
    else if(manipEnemyType == ULTRAVIOLET && manipType == GRASS)       {EFFECT = NOT_EFFECTIVE;   }
    else if(manipEnemyType == ULTRAVIOLET && manipType == WATER)       {EFFECT = NOT_EFFECTIVE;   }
    else if(manipEnemyType == ULTRAVIOLET && manipType == FLYING)      {EFFECT = NOT_EFFECTIVE;   }
    else if(manipEnemyType == ULTRAVIOLET && manipType == ULTRAVIOLET) {EFFECT = SUPER_EFFECTIVE; }
    else if(manipEnemyType == ULTRAVIOLET && manipType == ROCK)        {EFFECT = NOT_EFFECTIVE;   }
    else if(manipEnemyType == ULTRAVIOLET && manipType == FIRE)        {EFFECT = NOTHING;         }
    
    else if(manipEnemyType == FIRE && manipType == UNDEFINED)   {EFFECT = NOTHING;        }
    else if(manipEnemyType == FIRE && manipType == NORMAL)      {EFFECT = NOTHING;        }
    else if(manipEnemyType == FIRE && manipType == STATIC)      {EFFECT = NOTHING;        }
    else if(manipEnemyType == FIRE && manipType == GRASS)       {EFFECT = NOT_EFFECTIVE;  }
    else if(manipEnemyType == FIRE && manipType == WATER)       {EFFECT = NOT_EFFECTIVE;  }
    else if(manipEnemyType == FIRE && manipType == FLYING)      {EFFECT = NOTHING;        }
    else if(manipEnemyType == FIRE && manipType == ULTRAVIOLET) {EFFECT = NOTHING;        }
    else if(manipEnemyType == FIRE && manipType == ROCK)        {EFFECT = NOT_EFFECTIVE;  }
    else if(manipEnemyType == FIRE && manipType == FIRE)        {EFFECT = NOT_EFFECTIVE;  }

    else oslWarning("Failed to apply scales to move and type!!! Found in function ApplyTypes();!!!");
    
    
    //now handle the type table data!
    if(EFFECT == NOTHING)              {damagePower = damagePower; oslPlaySound(hurt_medium, 7);}
    else if(EFFECT == SUPER_EFFECTIVE) {damagePower*=2;            oslPlaySound(hurt_high, 7);  }
    else if(EFFECT == NOT_EFFECTIVE)   {damagePower/=2;            oslPlaySound(hurt_low, 7);   }
    else oslWarning("Error using Type table!!!");
    
    return damagePower;
}

SONYMON::SONYMON()
{
    name = "not given yet";
    moveName1 = NULL;
    moveName2 = NULL;
    moveName3 = NULL;
    moveName4 = NULL;
    health = 0;
    maxHealth = 0;
    attack = 0;
    defense = 0;
    move1 = 0;
    move2 = 0;
    move3 = 0;
    move4 = 0;
    alive = 0;
    type = UNDEFINED;
    level = 1;
    id = 1;
    xp = 0;
    max_xp = 1;

    return;
}

SONYMON::~SONYMON()
{
    return;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
//general functions used by both sonymon free roam and sonymon story modes:////////////////////
void LoadFiles(const int mode)
{     
    OSL_IMAGE * loading_screen = oslLoadImageFile((char*)"img/data/loading1.png", OSL_IN_RAM, OSL_PF_5551);

    oslStartDrawing();
    oslClearScreen(BLACK);
    oslDrawImage(loading_screen);
    oslEndDrawing();
    oslSyncFrame();
    
    if(loadedBefore != 1)
    {
      
    //load images to memory
    item1 = oslLoadImageFile((char*)"img/data/item1.png", OSL_IN_RAM, OSL_PF_5551);
	item2 = oslLoadImageFile((char*)"img/data/item2.png", OSL_IN_RAM, OSL_PF_5551);
	item3 = oslLoadImageFile((char*)"img/data/item3.png", OSL_IN_RAM, OSL_PF_5551);
	mini_rec_selector = oslLoadImageFile((char*)"img/data/mini-rec-selector.png", OSL_IN_RAM, OSL_PF_5551);
	pointer = oslLoadImageFile((char*)"img/data/p0.png", OSL_IN_RAM, OSL_PF_5551);
	battle_pointer = oslLoadImageFile((char*)"img/data/p1.png", OSL_IN_RAM, OSL_PF_5551);
	linkOn = oslLoadImageFile((char*)"img/data/On.png", OSL_IN_RAM, OSL_PF_5551);
	linkOff = oslLoadImageFile((char*)"img/data/Off.png", OSL_IN_RAM, OSL_PF_5551);
	battle_selector = oslLoadImageFile((char*)"img/data/bs2.png", OSL_IN_RAM, OSL_PF_5551);
	pound_mark = oslLoadImageFile((char*)"img/data/pmark.png", OSL_IN_RAM, OSL_PF_5551);
    
	//load all the boxes
	xp_bar = oslLoadImageFile((char*)"img/data/xp_bar.png", OSL_IN_RAM, OSL_PF_5551);
	hp_bar = oslLoadImageFile((char*)"img/data/hp_bar.png", OSL_IN_RAM, OSL_PF_5551);
	sb = oslLoadImageFile((char*)"img/data/sb.png", OSL_IN_RAM, OSL_PF_5551);
	dialog_box = oslLoadImageFile((char*)"img/data/dialog.png", OSL_IN_RAM, OSL_PF_5551);
	enemy_dialog_box = oslLoadImageFile((char*)"img/data/dialog.png", OSL_IN_RAM, OSL_PF_5551);
	messageBox = oslLoadImageFile((char*)"img/data/messageBox.png", OSL_IN_RAM, OSL_PF_5551);
	fightBox = oslLoadImageFile((char*)"img/data/fightBox.png", OSL_IN_RAM, OSL_PF_5551);
	DialogBox = oslLoadImageFile((char*)"img/data/DialogBox.png", OSL_IN_RAM, OSL_PF_5551);
	background_grass = oslLoadImageFile((char*)"img/data/background_grass.png", OSL_IN_RAM, OSL_PF_5551);
	background_rock = oslLoadImageFile((char*)"img/data/background_rock.png", OSL_IN_RAM, OSL_PF_5551);
     
    //set up the link and linkoff boxes
	linkOn->x =  405;
    linkOn->y = 6;
    linkOff->x = linkOn->x;
    linkOff->y = linkOn->y;
       
    //load all sonymon images
    unknown_back = oslLoadImageFile((char*)"img/sonymon/unknownb.png", OSL_IN_RAM, OSL_PF_5551);
    unknown_front = oslLoadImageFile((char*)"img/sonymon/unknownf.png", OSL_IN_RAM, OSL_PF_5551);
	arsande_front = oslLoadImageFile((char*)"img/sonymon/arsande_front.png", OSL_IN_RAM, OSL_PF_5551);
	arsande_back = oslLoadImageFile((char*)"img/sonymon/arsande_back.png", OSL_IN_RAM, OSL_PF_5551);
	blumkins_front = oslLoadImageFile((char*)"img/sonymon/blumkins_front.png", OSL_IN_RAM, OSL_PF_5551);
	blumkins_back = oslLoadImageFile((char*)"img/sonymon/blumkins_back.png", OSL_IN_RAM, OSL_PF_5551);
	argrasse_front = oslLoadImageFile((char*)"img/sonymon/argrasse_front.png", OSL_IN_RAM, OSL_PF_5551);
	argrasse_back = oslLoadImageFile((char*)"img/sonymon/argrasse_back.png", OSL_IN_RAM, OSL_PF_5551);
	myboross_front = oslLoadImageFile((char*)"img/sonymon/myboross_front.png", OSL_IN_RAM, OSL_PF_5551);
	myboross_back = oslLoadImageFile((char*)"img/sonymon/myboross_back.png", OSL_IN_RAM, OSL_PF_5551);
	norbonkge_front = oslLoadImageFile((char*)"img/sonymon/norbonkge_front.png", OSL_IN_RAM, OSL_PF_5551);
	norbonkge_back = oslLoadImageFile((char*)"img/sonymon/norbonkge_back.png", OSL_IN_RAM, OSL_PF_5551);
	blowhole_front = oslLoadImageFile((char*)"img/sonymon/blowhole_front.png", OSL_IN_RAM, OSL_PF_5551);
	blowhole_back = oslLoadImageFile((char*)"img/sonymon/blowhole_back.png", OSL_IN_RAM, OSL_PF_5551);
	vandel_front = oslLoadImageFile((char*)"img/sonymon/vandel_front.png", OSL_IN_RAM, OSL_PF_5551);
	vandel_back = oslLoadImageFile((char*)"img/sonymon/vandel_back.png", OSL_IN_RAM, OSL_PF_5551);
	waterserore_front = oslLoadImageFile((char*)"img/sonymon/waterserore_front.png", OSL_IN_RAM, OSL_PF_5551);
	waterserore_back = oslLoadImageFile((char*)"img/sonymon/waterserore_back.png", OSL_IN_RAM, OSL_PF_5551);
	cemes_front = oslLoadImageFile((char*)"img/sonymon/cemes_front.png", OSL_IN_RAM, OSL_PF_5551);
	cemes_back = oslLoadImageFile((char*)"img/sonymon/cemes_back.png", OSL_IN_RAM, OSL_PF_5551);
	lieosaur_front = oslLoadImageFile((char*)"img/sonymon/lieosaur_front.png", OSL_IN_RAM, OSL_PF_5551);
	lieosaur_back = oslLoadImageFile((char*)"img/sonymon/lieosaur_back.png", OSL_IN_RAM, OSL_PF_5551);
	sturk_front = oslLoadImageFile((char*)"img/sonymon/sturk_front.png", OSL_IN_RAM, OSL_PF_5551);
	sturk_back = oslLoadImageFile((char*)"img/sonymon/sturk_back.png", OSL_IN_RAM, OSL_PF_5551);
	blip_front = oslLoadImageFile((char*)"img/sonymon/blip_front.png", OSL_IN_RAM, OSL_PF_5551);
	blip_back = oslLoadImageFile((char*)"img/sonymon/blip_back.png", OSL_IN_RAM, OSL_PF_5551);
	cecei_front = oslLoadImageFile((char*)"img/sonymon/cecei_front.png", OSL_IN_RAM, OSL_PF_5551);
	cecei_back = oslLoadImageFile((char*)"img/sonymon/cecei_back.png", OSL_IN_RAM, OSL_PF_5551);
	fanz_front = oslLoadImageFile((char*)"img/sonymon/fanz_front.png", OSL_IN_RAM, OSL_PF_5551);
	fanz_back = oslLoadImageFile((char*)"img/sonymon/fanz_back.png", OSL_IN_RAM, OSL_PF_5551);
       
    //load all sonymon sounds
    unknown = oslLoadSoundFile((char*)"music/entrances/unknown.bgm", OSL_FMT_NONE); 
    blumkins = oslLoadSoundFile((char*)"music/entrances/blumkins.bgm", OSL_FMT_NONE);
    arsande = oslLoadSoundFile((char*)"music/entrances/arsande.bgm", OSL_FMT_NONE);
    myboross = oslLoadSoundFile((char*)"music/entrances/myboross.bgm", OSL_FMT_NONE);
    argrasse = oslLoadSoundFile((char*)"music/entrances/argrasse.bgm", OSL_FMT_NONE);
    norbonkge = oslLoadSoundFile((char*)"music/entrances/norbonkge.bgm", OSL_FMT_NONE);
    blowess = oslLoadSoundFile((char*)"music/entrances/blowess.bgm", OSL_FMT_NONE);
    cemes = oslLoadSoundFile((char*)"music/entrances/cemes.bgm", OSL_FMT_NONE);
    waterserore = oslLoadSoundFile((char*)"music/entrances/waterserore.bgm", OSL_FMT_NONE);
    vandel = oslLoadSoundFile((char*)"music/entrances/vandel.bgm", OSL_FMT_NONE);
    lieosaur = oslLoadSoundFile((char*)"music/entrances/lieosaur.bgm", OSL_FMT_NONE);
    blip = oslLoadSoundFile((char*)"music/entrances/blip.bgm", OSL_FMT_NONE);
    cecei = oslLoadSoundFile((char*)"music/entrances/cecei.bgm", OSL_FMT_NONE);
    fanz = oslLoadSoundFile((char*)"music/entrances/fanz.bgm", OSL_FMT_NONE);
    enemy12 = oslLoadSoundFile((char*)"music/entrances/enemy12.bgm", OSL_FMT_NONE);
    enemy13 = oslLoadSoundFile((char*)"music/entrances/enemy13.bgm", OSL_FMT_NONE);
    enemy14 = oslLoadSoundFile((char*)"music/entrances/enemy14.bgm", OSL_FMT_NONE);
    enemy15 = oslLoadSoundFile((char*)"music/entrances/enemy15.bgm", OSL_FMT_NONE);
    enemy16 = oslLoadSoundFile((char*)"music/entrances/enemy16.bgm", OSL_FMT_NONE);
 
    //load move sounds
    tackle_sound = oslLoadSoundFileBGM((char*)"music/moves/tackle.bgm", OSL_FMT_NONE);
    slam_sound = oslLoadSoundFileBGM((char*)"music/moves/slam.bgm", OSL_FMT_NONE);
    uplink_sound = oslLoadSoundFileBGM((char*)"music/moves/uplink.bgm", OSL_FMT_NONE);
    pound_sound = oslLoadSoundFileBGM((char*)"music/moves/pound.bgm", OSL_FMT_NONE);
    jumpKick_sound = oslLoadSoundFileBGM((char*)"music/moves/jumpKick.bgm", OSL_FMT_NONE);
    contaminate_sound = oslLoadSoundFileBGM((char*)"music/moves/contaminate.bgm", OSL_FMT_NONE);
    clobber_sound = oslLoadSoundFileBGM((char*) "music/moves/tackle.bgm", OSL_FMT_NONE);
    steroids_sound = oslLoadSoundFileBGM((char*) "music/moves/steroids.bgm", OSL_FMT_NONE);
    
    //load damage taken sounds
    hurt_low = oslLoadSoundFileBGM((char*)"music/moves/hurt(low).bgm", OSL_FMT_NONE);
    hurt_medium = oslLoadSoundFileBGM((char*)"music/moves/hurt(medium).bgm", OSL_FMT_NONE);
    hurt_high = oslLoadSoundFileBGM((char*)"music/moves/hurt(high).bgm", OSL_FMT_NONE);
    
    //load battle music
    wild_battle = oslLoadSoundFileBGM((char*)"music/entrances/wild(loop).bgm", OSL_FMT_NONE);
    leader_battle = oslLoadSoundFileBGM((char*)"music/entrances/leader(loop).bgm", OSL_FMT_NONE);
    boss_battle = oslLoadSoundFileBGM((char*)"music/entrances/boss(loop).bgm", OSL_FMT_NONE);
    wild_intro = oslLoadSoundFileBGM((char*)"music/entrances/wild(intro).bgm", OSL_FMT_NONE);
    leader_intro = oslLoadSoundFileBGM((char*)"music/entrances/leader(intro).bgm", OSL_FMT_NONE);
    boss_intro = oslLoadSoundFileBGM((char*)"music/entrances/boss(intro).bgm", OSL_FMT_NONE);
    
    //load all other sounds
    enter  = oslLoadSoundFileWAV((char*)"music/exit.wav", OSL_FMT_NONE);
    found = oslLoadSoundFileBGM((char*) "music/found.bgm", OSL_FMT_NONE);
    beep = oslLoadSoundFileBGM((char*)"music/beep.bgm", OSL_FMT_NONE);
    Selected = oslLoadSoundFileBGM((char*)"music/selected.bgm", OSL_FMT_NONE);
    gameMusic = oslLoadSoundFileBGM((char*)"music/route/route1.bgm", OSL_FMT_NONE); 
    center_music = oslLoadSoundFileBGM((char*)"music/building1.bgm", OSL_FMT_NONE);
    
    //load fonts 
    verdana = oslLoadFontFile((char*)"fonts/verdana.oft");  
       
    //load the main character
    zero = oslLoadImageFilePNG((char*)"img/sprites/male4.png", OSL_IN_RAM, OSL_PF_5551);  
	
	//load and init fonts
    oslIntraFontInit(INTRAFONT_CACHE_ALL | INTRAFONT_STRING_UTF8);
    normal = oslLoadFontFile("flash0:/font/ltn0.pgf");
    bold = oslLoadFontFile("flash0:/font/ltn4.pgf");
    italic = oslLoadFontFile("flash0:/font/ltn2.pgf");
    oslIntraFontSetStyle(normal, 1.0f,WHITE,BLACK,INTRAFONT_ALIGN_LEFT);
    
	loadedBefore = 1;
	
    }
    
	if(uplink_center != NULL){oslDeleteImage(uplink_center); uplink_center = NULL;}
	if(World_Route_tileset != NULL){oslDeleteImage(World_Route_tileset); World_Route_tileset = NULL;}
	if(FR1_tileset != NULL) {oslDeleteImage(FR1_tileset); FR1_tileset = NULL;}
	
	//load map data
	uplink_center = oslLoadImageFilePNG((char*)"img/data/maps/uplink_center.png", OSL_IN_RAM, OSL_PF_5551);
	World_Route_tileset = oslLoadImageFilePNG((char*)"img/data/maps/world_route_tileset.png", OSL_IN_RAM, OSL_PF_5551);
	FR1_tileset = oslLoadImageFilePNG((char*) "img/data/maps/FR1_tileset.png", OSL_IN_RAM, OSL_PF_5551);
	
    FR1 = oslCreateMap(
	FR1_tileset,				
	(void *)FR1_map,							
	32,32,							
	64, 85,						
	OSL_MF_U16);
		
    World_Route = oslCreateMap(
	World_Route_tileset,				
	(void *)world_route_map,					
	16,16,							
	70, 50,							
	OSL_MF_U16);
	
    //free RAM
    oslDeleteImage(loading_screen);
    
    return;
}

void TransitionUp(OSL_MAP * map, OSL_IMAGE * image)
{
    bool drawMap = true;
    if(map == NULL) drawMap = false;
    if(image == NULL) drawMap = true;
    if(image == NULL && map == NULL) {oslWarning("ERROR! Invalid parameters passed to TransitionUp()!!. Exiting function to avoid a crash!"); return;}
    
    oslPlaySound(enter, 2);
    
     if(drawMap == false)
     {
         unsigned long i;
         unsigned long squareOne = 0;
         unsigned long squareTwo = 0;
     
         for(i = 0; i < 80; i++)
         {
             squareOne+=4;
             squareTwo+=4;
           
             oslStartDrawing();
             oslDrawImageSimple(image);
           
             oslDrawFillRect(-2, squareOne, 482, squareTwo, BLACK);
             oslEndDrawing();
             oslSyncFrame();
         }
    }
    if(drawMap == true)
     {
         unsigned long i;
         unsigned long squareOne = 0;
         unsigned long squareTwo = 0;
     
         for(i = 0; i < 80; i++)
         {
             squareOne+=4;
             squareTwo+=4;
           
             oslStartDrawing();
             oslDrawMapSimple(map);
           
             oslDrawFillRect(-2, squareOne, 482, squareTwo, BLACK);
             oslEndDrawing();
             oslSyncFrame();
         }
    }
     
      return;
}

//clear message box by drawing it to the screen
void ClearMessageBox( void )
{
     oslStartDrawing();
     oslDrawImage(messageBox);
     oslEndDrawing();
     oslSyncFrame();
     
     return;
}

//handles how we search for new sonymon
void HANDLE_SEARCH(const char * playerName, OSL_MAP * map)
{
    //if search is not enabled...exit
    if(allowSearch == 0)
        return;
        
    //force the game to pause between each sonymon battle
    swait++;
    if(swait < 40)
         return;
    
    int random_number;
    srand((unsigned)time(0));
    random_number = (rand()%30)+1;
    
    /* battle blumdins */
    if(random_number == 2 || random_number == 3) {BATTLE(playerName, blumkins_front, 2, 2);}
    
    /* battle arsande */
    else if(random_number == 4 || random_number == 5) {BATTLE(playerName, arsande_front, 3, 2); }
    
    /* battle myboross */
    else if(random_number == 6) {BATTLE(playerName, myboross_front, 4, 2); }
    else if(random_number == 7) {BATTLE(playerName, myboross_front, 4, 3); }
    
    /* battle lieosaur */
    else if(random_number == 8) {BATTLE(playerName, lieosaur_front, 11, 2); }
    else if(random_number == 9) {BATTLE(playerName, lieosaur_front, 11, 3); }
    else if(random_number == 10){BATTLE(playerName, lieosaur_front, 11, 4); }
    
    /* battle argrasse */
    else if(random_number == 11 || random_number == 12)  { BATTLE(playerName, argrasse_front, 5, 2); }
    
    /* battle norbonkge */
    else if(random_number == 13 || random_number == 14) {BATTLE(playerName, norbonkge_front, 6, 2); }
    
    /* battle blowess */
    else if(random_number == 15) {BATTLE(playerName, blowhole_front, 7, 2);}
    else if(random_number == 16) {BATTLE(playerName, blowhole_front, 7, 3);}
    else if(random_number == 17) {BATTLE(playerName, blowhole_front, 7, 4);}
    
    /* battle cemes */
    else if(random_number == 18 || random_number == 19) BATTLE(playerName, cemes_front, 8, 2);
    else if(random_number == 20) {BATTLE(playerName, cemes_front, 8, 3);}
    else if(random_number == 21) {BATTLE(playerName, cemes_front, 8, 4);}
    else if(random_number == 22) {BATTLE(playerName, cemes_front, 8, 5);}
    
    /* battle sturk */
    else if(random_number == 23 || random_number == 24) {BATTLE(playerName, sturk_front, 12, 4); }
    
    /* battle cecei */
    else if(random_number == 25 || random_number == 26) {BATTLE(playerName, cecei_front, 14, 2); }
    
    /* battle fanz */
    else if(random_number == 27 || random_number == 28) {BATTLE(playerName, fanz_front, 15, 8); }
    
    /* battle blip */
    else if(random_number == 29 || random_number == 30) {BATTLE(playerName, blip_front, 13, 3); }
     
    swait = 0;

    return;
}

void ResetStats( void )
{
    //wipe all sonymon memory or stats CLEAN!!!
    
    //const char * object just displays info about where the player is standing
    object = "NULL"; 
    
    //wipe sonymon slot #1
    sonymon1.name = "???";
    sonymon1.moveName1 = "-- --";
    sonymon1.moveName2 = "-- --";
    sonymon1.moveName3 = "-- --";
    sonymon1.moveName4 = "-- --";
    sonymon1.health = 0;
    sonymon1.maxHealth = 0;
    sonymon1.attack = 0;
    sonymon1.defense = 0;
    sonymon1.move1 = 0;
    sonymon1.move2 = 0;
    sonymon1.move3 = 0;
    sonymon1.move4 = 0;
    sonymon1.alive = 0;
    sonymon1.type = UNDEFINED;
    sonymon1.level = 1;
    sonymon1.id = 1;
    sonymon1.xp = 0;
    sonymon1.max_xp = 0;
    if(sonymon1.image != NULL) {oslDeleteImage(sonymon1.image); sonymon1.image = NULL;}
    
    //wipe sonymon slot #2
    sonymon2.name = "???";
    sonymon2.moveName1 = "-- --";
    sonymon2.moveName2 = "-- --";
    sonymon2.moveName3 = "-- --";
    sonymon2.moveName4 = "-- --";
    sonymon2.health = 0;
    sonymon2.maxHealth = 0;
    sonymon2.attack = 0;
    sonymon2.defense = 0;
    sonymon2.move1 = 0;
    sonymon2.move2 = 0;
    sonymon2.move3 = 0;
    sonymon2.move4 = 0;
    sonymon2.alive = 0;
    sonymon2.type = UNDEFINED;
    sonymon2.level = 1;
    sonymon2.id = 1;
    sonymon2.xp = 0;
    sonymon2.max_xp = 0;
    if(sonymon2.image != NULL) {oslDeleteImage(sonymon2.image); sonymon2.image = NULL;}
    
    //wipe sonymon slot #3
    sonymon3.name = "???";
    sonymon3.moveName1 = "-- --";
    sonymon3.moveName2 = "-- --";
    sonymon3.moveName3 = "-- --";
    sonymon3.moveName4 = "-- --";
    sonymon3.health = 0;
    sonymon3.maxHealth = 0;
    sonymon3.attack = 0;
    sonymon3.defense = 0;
    sonymon3.move1 = 0;
    sonymon3.move2 = 0;
    sonymon3.move3 = 0;
    sonymon3.move4 = 0;
    sonymon3.alive = 0;
    sonymon3.type = UNDEFINED;
    sonymon3.level = 1;
    sonymon3.id = 1;
    sonymon3.xp = 0;
    sonymon3.max_xp = 0;
    if(sonymon3.image != NULL) {oslDeleteImage(sonymon3.image); sonymon3.image = NULL;}
    
    vandel_front->y = 120;
    blowhole_front->y = 120;
    blowhole_front->y = 120;
    waterserore_front->y = 120;
    arsande_front->y = 120;
    lieosaur_front->y = 120;
    cemes_front->y = 120;
    myboross_front->y = 120;
    blumkins_front->y = 120;
    norbonkge_front->y = 120;
    argrasse_front->y = 120;
    sturk_front->y = 120;
    blip_front->y = 120;
    cecei_front->y = 120;
    fanz_front->y = 120;
    
    vandel_front->x = 230;
    blowhole_front->x = 230;
    blowhole_front->x = 230;
    waterserore_front->x = 230;
    arsande_front->x = 230;
    lieosaur_front->x = 230;
    cemes_front->x = 230;
    myboross_front->x = 230;
    blumkins_front->x = 230;
    norbonkge_front->x = 230;
    argrasse_front->x = 230;
    sturk_front->x = 230;
    blip_front->x = 230;
    cecei_front->x = 230;
    fanz_front->x = 230;
    
    //I am pretty sure you can guess what this does ;)
    totalSonymon = 0;
    
    //fix SonymonSeen[] array
    unsigned i;
    for(i = 0; i < 100; i++)
        SonymonSeen[i] = 0;
        
    //fix SonymonOwned[] array
    unsigned j;
    for(j = 0; j < 100; j++)
        SonymonSeen[j] = 0;
        
    //fix inventory[] array
    unsigned m;
    for(m = 0; m < 200; m++)
        inventory[m] = 0;
    
    /***** THE CODE BELOW CAUSES SonymonSeen[1] to become equal to 1.. which puts it in records******/
    //since this is a new game set first sonymon slot to default (no sonymon)...kinda
    //sonymon_num = 0; //unequip any sonymon
    //currentSonymon = 0;	
    //ASSIGN_SONYMON(1, 1, 2);
    
    return;
}

void ENTRY_EFFECT(OSL_MAP * map, int area)
{
    oslPlaySound(enter, 2);
    
     //handle OSL_MAP * Level
    if(area == 0)      map = World_Route;
   
     unsigned long i;
     unsigned long squareOne = 250;
     unsigned long squareTwo = 267;
     unsigned long moveSquare = 0;
     unsigned long moveSquare2 = 480;
     
     for(i = 0; i < 80; i++)
     {
           squareOne-=4;
           squareTwo+=4;
           
           oslStartDrawing();
           if(InsideCenter) oslDrawImageSimple(uplink_center);
           else oslDrawMapSimple(map);
           oslDrawImageSimple(zero);
           
           oslDrawFillRect(squareOne, 0, moveSquare, 272, BLACK);
           oslDrawFillRect(squareTwo, 0, moveSquare2, 272, BLACK);
           oslEndDrawing();
           oslSyncFrame();
     }
     
     return;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
//sonymon free roam functions://///////////////////////////////////////////////////////////////
          
int SonymonFreeRoam(const char * playerName, const int load)
{   
    if(playerName == NULL)playerName = "Ken";
    //load the game if the user selected "continue game"
    //if(load){
             //int success = 0;
             //success = LOADGAME(sonymon1_id, sonymon1_level, sonymon2_id, sonymon2_level, sonymon3_id, sonymon3_level);
             //if(success != 1) return 0;
    //}
    
    //load game files
	LoadFiles(1);
	
	//reset all map points
    World_Route->scrollX = 0;
    World_Route->scrollY = 0;
    FR1->scrollX = 0;
    FR1->scrollY = 0;
    
	//Place player at the center of the screen
	zero->x = 240; 
    zero->y = 121; 
    FR1->scrollX = -2005;
    FR1->scrollY = 1181;  
    oslSetImageTileSize(zero,0,DOWN,23,32);
    
    if(gameMusic != NULL){oslStopSound(gameMusic); oslDeleteSound(gameMusic); gameMusic = NULL;}
    gameMusic = oslLoadSoundFileBGM((char*)"music/route/dawn.bgm", OSL_FMT_NONE);
    oslPlaySound(gameMusic, 1); oslSetSoundLoop(gameMusic, 1);
    
     //wipe all sonymon memory or stats CLEAN!!!
     ResetStats();
    
     //choose a starting sonymon
     int choice = 2;
     const char * name = "???";
     
     OSL_IMAGE * selection;
     selection = oslLoadImageFilePNG((char*)"img/data/choose.png", OSL_IN_RAM, OSL_PF_5551);
     if(!selection) MISSING_IMG_FILES(1);
     
     oslSetFont(bold);
     
     while(1)
     { 
        oslStartDrawing();
        oslClearScreen(BLACK);
        oslDrawImage(selection);
        
        //I skip 1 because that is the id of "unknown" and it makes more sense :)
        
             if(choice == 2)  {oslDrawImageSimple(blumkins_front);    name = "blumdins";     sonymon1.id = choice;}
        else if(choice == 3)  {oslDrawImageSimple(arsande_front);     name = "arsande";      sonymon1.id = choice;}
        else if(choice == 4)  {oslDrawImageSimple(myboross_front);    name = "myboross";     sonymon1.id = choice;}
        else if(choice == 5)  {oslDrawImageSimple(argrasse_front);    name = "argrasse";     sonymon1.id = choice;}
        else if(choice == 6)  {oslDrawImageSimple(norbonkge_front);   name = "norbonkge";    sonymon1.id = choice;}
        else if(choice == 7)  {oslDrawImageSimple(blowhole_front);    name = "blowess";      sonymon1.id = choice;}
        else if(choice == 8)  {oslDrawImageSimple(cemes_front);       name = "cemes";        sonymon1.id = choice;}
        else if(choice == 9)  {oslDrawImageSimple(waterserore_front); name = "waterserore";  sonymon1.id = choice;}
        else if(choice == 10) {oslDrawImageSimple(vandel_front);      name = "vandel";       sonymon1.id = choice;}
        else if(choice == 11) {oslDrawImageSimple(lieosaur_front);    name = "lieosaur";     sonymon1.id = choice;}
        else if(choice == 12) {oslDrawImageSimple(sturk_front);       name = "sturk";        sonymon1.id = choice;}
        else if(choice == 13) {oslDrawImageSimple(blip_front);        name = "blip";         sonymon1.id = choice;}
        else if(choice == 14) {oslDrawImageSimple(cecei_front);       name = "cecei";        sonymon1.id = choice;}
        else if(choice == 15) {oslDrawImageSimple(fanz_front);        name = "fanz";         sonymon1.id = choice;}
        
        oslSetTextColor(WHITE);
        oslSetBkColor(BLACK);
        oslDrawString(5, 15, "Choose a starting Sonymon");
        oslPrintf_xy(5, 160, "%s Lv5", name); 
        
        oslEndDrawing();
        oslSyncFrame();
        
        oslReadKeys();
        
        //assign that sonymon
        if(osl_keys->pressed.cross || osl_keys->pressed.start){
            sonymon_num = 1; //equip first sonymon
            sonymon1.alive = 1;
            totalSonymon++;	
            create.ASSIGN_SONYMON(1, sonymon1.id, 5);
            break;
        }
        else if(osl_keys->pressed.left && choice > 2){choice--; oslPlaySound(beep, 2);}
        else if(osl_keys->pressed.right && choice < 15){choice++; oslPlaySound(beep, 2);}
        
	 }
    
    quitGame = 0;
    
    //testing inventory...temperarily give items to player
    inventory[0] = 1;
    inventory[1] = 2;
    inventory[2] = 3;
    inventory[3] = 4;
    inventory[4] = 99;
    inventory[5] = 98;
    
    while(quitGame == 0)
    { 
        oslStartDrawing();
        
        HANDLE(playerName, FR1);
        HANDLE_SEARCH(playerName, FR1);
        
        oslEndDrawing();
        oslSyncFrame();
    }

   //fix sig font
   oslSetFont(verdana); oslSetTextColor(BLACK); oslSetBkColor(BLACK);
   
   //end any sound
   oslStopSound(center_music); oslStopSound(gameMusic);
   
   return 0;
}

void HANDLE(const char * playerName, OSL_MAP * level)
{
   if(!level) oslFatalError("ERROR! Map is equal to NULL CANNOT CONTINUE!!!"); 
   if(Appeared){ENTRY_EFFECT(level, area); Appeared = 0;}
   oslClearScreen(BLACK);
   oslDrawMap(level);
   
   oslDrawImage(zero);
   player.DrawInfo(Toggle1, 2);
   player.ReadKeys(playerName, level);
   
   if(InsideCenter)
   {
        oslDrawImageSimple(uplink_center);
        
        COMPUTER Cguy1;
        Cguy1.image = Cguy1.loadImage(1, Cguy1.loadedImage);
        Cguy1.UpdateAI(Cguy1.image, "Trainer Paul: I keep getting beat by arsandes!", 0, 400, 60, Cguy1.carry, Cguy1.position);
        Cguy1.ComputerAnimate(Cguy1.image, 0, Cguy1.manip, Cguy1.march, Cguy1.position);
        
        COMPUTER Cguy2;
        Cguy2.image = Cguy2.loadImage(2, Cguy2.loadedImage);
        Cguy2.UpdateAI(Cguy2.image, "Trainer Rick: I can't wait! Can't Wait! Can't Wait!", 0, 100, 110, Cguy2.carry, Cguy2.position);
        Cguy2.ComputerAnimate(Cguy2.image, 1, Cguy2.manip, Cguy2.march, Cguy2.position);
        
        COMPUTER Cguy3;
        Cguy3.image = Cguy3.loadImage(3, Cguy3.loadedImage);
        Cguy3.UpdateAI(Cguy3.image, "Old Trainer Jackson: I forgot to save my progress ohhh!", 2, 305, 127, Cguy3.carry, Cguy3.position);
        Cguy3.ComputerAnimate(Cguy3.image, 2, Cguy3.manip, Cguy3.march, Cguy3.position);
        
        if(justEntered){
           oslStopSound(gameMusic);
           oslPlaySound(center_music, 1);
           oslSetSoundLoop(center_music, 1);
           zero->x = 225;
           zero->y = 227;
           justEntered = 0;
           ENTRY_EFFECT(level, area);
        }
   }
   
   //COMPUTER introGuy;
   //introGuy.image = introGuy.loadImage(1, introGuy.loadedImage);
   //introGuy.UpdateAIMap(introGuy.image, level, "V@ughn: Welcome to Sonymon build betav9, made by me!!", 0, 600, 280, introGuy.carry, introGuy.position);
   //introGuy.ComputerAnimate(introGuy.image, 1, introGuy.manip, introGuy.march, introGuy.position);
   
   //COMPUTER trainer1;
   //trainer1.image = trainer1.loadImage(4, trainer1.loadedImage);
   //trainer1.UpdateAIMap(trainer1.image, level, "Trainer Joe: I'm not ready to battle just yet...maybe later ;)", 1, 400, 340, trainer1.carry, trainer1.position);
   //trainer1.ComputerAnimate(trainer1.image, 2, trainer1.manip, trainer1.march, trainer1.position);
   
   items.Populate(level, area); 
   items.Draw(area);

  return;
 
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
//sonymon battle functions:////////////////////////////////////////////////////////////////////

//trainer battle fuction
void TRAINER_BATTLE(const char * playerName, const char * trainerName, OSL_IMAGE * trainer, 
                    const int enemyID1, const int enemyLevel1, const int enemyID2, const int enemyLevel2,
                    const int enemyID3, const int enemyLevel3)
{
     int totalTrainerSonymon = 1;
     if(enemyID1 != 0 && enemyID2 != 0 && enemyID3 != 0) totalTrainerSonymon= 3;
     else if(enemyID1 != 0 && enemyID2 != 0) totalTrainerSonymon = 2;
     else if(enemyID1 != 0) totalTrainerSonymon = 1;
     else {oslWarning("FAILED TO COUNT TOTAL TRAINER SONYMON!!! EXITING FUNCTION TO AVOID A CRASH!!!"); return;}
     
     //load images based on const int enemyID...
     if(enemy1 != NULL) {oslDeleteImage(enemy1); enemy1 = NULL;}
     if(enemy2 != NULL) {oslDeleteImage(enemy2); enemy2 = NULL;}
     if(enemy3 != NULL) {oslDeleteImage(enemy3); enemy3 = NULL;}
     
     if(totalTrainerSonymon == 3){
           stats.setImageUnspecified(enemyID1, enemy1);
           stats.setImageUnspecified(enemyID2, enemy2);
           stats.setImageUnspecified(enemyID3, enemy3);
     }
     else if(totalTrainerSonymon == 2){
           stats.setImageUnspecified(enemyID1, enemy1);
           stats.setImageUnspecified(enemyID2, enemy2);
     }
     else if(totalTrainerSonymon == 1){
           stats.setImageUnspecified(enemyID1, enemy1);
     }
     
     //battle intro
     oslPauseSound(gameMusic, -1); oslPauseSound(center_music, -1);
     oslPlaySound(wild_intro, 3);  oslSetSoundLoop(wild_intro, 1);
   
     unsigned i = 0;
     unsigned j = 0;
     
     for(i = 0; i < 70; i++)
     {          
           oslStartDrawing();
           j++;
           if(j > 2)oslClearScreen(BLACK);
           if(j > 4)oslClearScreen(RED);
           if(j > 6)oslClearScreen(BLUE);
           if(j > 8) j = 0;
           
           oslDrawImageSimple(zero);
           oslEndDrawing();
           oslSyncFrame();
     }
     
     //reset all the battle variables so next time we have normal gameplay
     turn = 0; loadedHealthBefore = 0; briefPause = 0;
     MAX_HP = 0; MAX_ENEMY_HP = 0;
     loadedEnemyHealthBefore = 0;
     OUTLINE_MAX = 0; OUTLINE_ENEMY_MAX = 0;
     GOING_UP = 1; GOING_DOWN = 0;//begin shifting
     turn = 1; selecting = 1; ran = 0; //player's turn
     
     positionScreenItems(enemy1);
     
     unsigned long squareOne = 0;
     unsigned long squareTwo = 272;
     unsigned long moveSquare = 136;
     unsigned long moveSquare2 = 136;
     int showMaxHealth;
     
     //init ENEMY class
     ENEMY controlEnemy;
     
     int showMaxHealth1, enemyHealth1, enemyAttackPower1, enemyDefense1, enemyType1, XP1;
     int showMaxHealth2, enemyHealth2, enemyAttackPower2, enemyDefense2, enemyType2, XP2;
     int showMaxHealth3, enemyHealth3, enemyAttackPower3, enemyDefense3, enemyType3, XP3;
     const char * enemyName1 = "???";
     const char * enemyName2 = "???";
     const char * enemyName3 = "???";
     
     int trainer_num = 1;
     
     //set enemy stats all based on enemyLevel and enemyType!!! :D
     
     //trainer slot #1
     stats.setEnemyType(enemyID1, enemyLevel1, enemy1);
     stats.XPGain(XP1, enemyID1, enemyLevel1);
     stats.setHealth(enemyHealth1, enemyID1, enemyLevel1);
     stats.setAttackPower(enemyAttackPower1, enemyID1, enemyLevel1);
     stats.setDefense(enemyDefense1, enemyID1, enemyLevel1);
     stats.setType(enemyType1, enemyID1);
     stats.setEnemyMoves(enemyID1, enemyLevel1);
     showMaxHealth1 = enemyHealth1;
     
     //trainer slot #2
     stats.setEnemyType(enemyID2, enemyLevel2, enemy2);
     stats.XPGain(XP2, enemyID2, enemyLevel2);
     stats.setHealth(enemyHealth2, enemyID2, enemyLevel2);
     stats.setAttackPower(enemyAttackPower2, enemyID2, enemyLevel2);
     stats.setDefense(enemyDefense2, enemyID2, enemyLevel2);
     stats.setType(enemyType2, enemyID2);
     stats.setEnemyMoves(enemyID2, enemyLevel2);
     showMaxHealth2 = enemyHealth2;
     
     //trainer slot #3
     stats.setEnemyType(enemyID3, enemyLevel3, enemy3);
     stats.XPGain(XP3, enemyID3, enemyLevel3);
     stats.setHealth(enemyHealth3, enemyID3, enemyLevel3);
     stats.setAttackPower(enemyAttackPower3, enemyID3, enemyLevel3);
     stats.setDefense(enemyDefense3, enemyID3, enemyLevel3);
     stats.setType(enemyType3, enemyID3);
     stats.setEnemyMoves(enemyID3, enemyLevel3);
     showMaxHealth3 = enemyHealth3;
     
     //load health bar variables
     OSL_IMAGE *healthBar, *enemyHealthBar;
     healthBar = oslLoadImageFile((char*)"img/data/Hbar.png", OSL_IN_RAM, OSL_PF_5551);
     enemyHealthBar = oslLoadImageFile((char*)"img/data/Hbar.png", OSL_IN_RAM, OSL_PF_5551);
     if(!healthBar || !enemyHealthBar)
           MISSING_IMG_FILES(1);
     
     //intro animation
     for(i = 0; i < 142; i++)
     {
           squareOne--;
           moveSquare--;
           squareTwo++;
           moveSquare2++;
           
           oslStartDrawing();
           oslClearScreen(RGBA(0,0,0,0));
           oslDrawImageSimple(background_grass);
           oslDrawImageSimple(sonymon1.image);
           oslDrawImageSimple(messageBox);
           
           oslDrawFillRect(-1, squareOne, 481, moveSquare, BLACK);
           oslDrawFillRect(-1, squareTwo, 481, moveSquare2, BLACK);
           oslEndDrawing();
           oslSyncFrame();
     }
     
     //start looping the battle sound
     oslStopSound(wild_intro); oslPlaySound(wild_battle, 3); oslSetSoundLoop(wild_battle, 1);
     
     //set enemy stats all based on enemyLevel and enemyType!!! :D
     
     if(sonymon_num == 1)      showMaxHealth = sonymon1.health;
     else if(sonymon_num == 2) showMaxHealth = sonymon2.health;
     else if(sonymon_num == 3) showMaxHealth = sonymon3.health;
     
     waitForClick("trainer sonymon", background_grass, enemy1, sonymon1.image, pointer);
     
     while(1)
     {       
             oslStartDrawing();
             oslDrawImage(background_grass);
             
             //handle enemy ai
             
             //handle player and player sonymon
             //UPDATE(enemyHealth, enemyDefense, enemyType, enemy, background_grass);
             
             //draw player sonymon based on int sonymon_num
             if(sonymon_num == 1)      oslDrawImage(sonymon1.image);
             else if(sonymon_num == 2) oslDrawImage(sonymon2.image);
             else if(sonymon_num == 3) oslDrawImage(sonymon3.image);
             
             //draw trainer sonymon based on int trainer_num
             if(trainer_num == 1)      oslDrawImage(enemy1);
             else if(trainer_num == 2) oslDrawImage(enemy2);
             else if(trainer_num == 3) oslDrawImage(enemy3);
             
             //draw util boxes
             oslDrawImage(messageBox);
             oslDrawImage(dialog_box);
             oslDrawImage(xp_bar);
             oslDrawImage(enemy_dialog_box);
             oslDrawImage(healthBar);
             oslDrawImage(enemyHealthBar);
             
             //handle enemy and player health bars
             DrawCharacterTextBox(healthBar);
             if(trainer_num == 1)DrawEnemyTextBox(enemyHealth1, enemyHealthBar);
             else if(trainer_num == 2)DrawEnemyTextBox(enemyHealth2, enemyHealthBar);
             else if(trainer_num == 3)DrawEnemyTextBox(enemyHealth3, enemyHealthBar);
             
             if(selecting && turn)
             {
                oslDrawImage(fightBox);
                
                oslSetFont(bold);
                oslSetTextColor(BLACK);
                oslSetBkColor(RGBA(0,0,0,0));
                
                oslPrintf_xy(286, 216, "FIGHT");
                oslPrintf_xy(393, 216, "BAG");
                oslPrintf_xy(286, 245, "SNYMN");
                oslPrintf_xy(393, 245, "RUN");
                
                
                oslSetFont(normal);
                oslSetTextColor(BLACK);
                oslSetBkColor(RGBA(0,0,0,0));
                if(sonymon_num == 1)      oslPrintf_xy(18, 216, "What will %s do?", sonymon1.name);
                else if(sonymon_num == 2) oslPrintf_xy(18, 216, "What will %s do?", sonymon2.name);
                else if(sonymon_num == 3) oslPrintf_xy(18, 216, "What will %s do?", sonymon3.name);

                oslDrawImageSimple(battle_pointer);
                
             }
             
             if(selectMoves && turn)
             {
                oslSetFont(italic);
                oslSetTextColor(BLACK);
                oslSetBkColor(RGBA(0,0,0,0));
             
                if(sonymon_num == 1){
                    oslPrintf_xy(18, 216, "%s" , sonymon1.moveName1);
                    oslPrintf_xy(153, 216, "%s",  sonymon1.moveName2);
                    oslPrintf_xy(18, 242, "%s", sonymon1.moveName3);
                    oslPrintf_xy(153, 242, "%s", sonymon1.moveName4);
                }
                else if(sonymon_num == 2){
                    oslPrintf_xy(18, 216, "%s" , sonymon2.moveName1);
                    oslPrintf_xy(153, 216, "%s",  sonymon2.moveName2);
                    oslPrintf_xy(18, 242, "%s", sonymon2.moveName3);
                    oslPrintf_xy(153, 242, "%s", sonymon2.moveName4);
                }
                else if(sonymon_num == 3){
                    oslPrintf_xy(18, 216, "%s" , sonymon3.moveName1);
                    oslPrintf_xy(153, 216, "%s",  sonymon3.moveName2);
                    oslPrintf_xy(18, 242, "%s", sonymon3.moveName3);
                    oslPrintf_xy(153, 242, "%s", sonymon3.moveName4);
                }
                oslDrawImageSimple(battle_selector);
             }
             
             oslSetFont(verdana);
             oslSetTextColor(BLACK);
             oslSetBkColor(RGBA(0,0,0,0));
             
             //draw player sonymon health, level, max-health, and name based on int sonymon_num
             if(sonymon_num == 1){
                 oslPrintf_xy(419, 160,"%i/%i", sonymon1.health, sonymon1.maxHealth);
                 oslPrintf_xy(256, 141, "%s  Lv:%i", sonymon1.name, sonymon1.level);
             }
             else if(sonymon_num == 2){
                 oslPrintf_xy(419, 160,"%i/%i", sonymon2.health, sonymon2.maxHealth);
                 oslPrintf_xy(256, 141, "%s  Lv:%i", sonymon2.name, sonymon2.level);
             }
             else if(sonymon_num == 3) {
                 oslPrintf_xy(419, 160,"%i/%i", sonymon3.health, sonymon3.maxHealth);
                 oslPrintf_xy(256, 141, "%s  Lv:%i", sonymon3.name, sonymon3.level);
             }
             
             //draw trainer sonymon level, health, max-health, and name based on int trainer_num
             if(trainer_num == 1){
                 oslPrintf_xy(178, 48,"%i", enemyHealth1);
                 oslPrintf_xy(20, 25, "%s  Lv:%i", enemyName1, enemyLevel1);
             }
             else if(trainer_num == 2){
                 oslPrintf_xy(178, 48,"%i", enemyHealth2);
                 oslPrintf_xy(20, 25, "%s  Lv:%i", enemyName2, enemyLevel2);
             }
             else if(trainer_num == 3) {
                 oslPrintf_xy(178, 48,"%i", enemyHealth3);
                 oslPrintf_xy(20, 25, "%s  Lv:%i", enemyName3, enemyLevel3);
             }
             
             //display effectiveness of all the various moves
             if(EFFECT == NOT_EFFECTIVE)
             {
                       oslSetFont(normal);
                       ClearMessageBox();
                       oslStartDrawing();
                       oslPrintf_xy(18, 216, "It's not very effective...");
                       oslEndDrawing();
                       oslSyncFrame();
                       EFFECT = NOTHING;
                       hWait; hWait;
             }
             else if(ENEMY_EFFECT == NOT_EFFECTIVE)
             {
                       oslSetFont(normal);
                       ClearMessageBox();
                       oslStartDrawing();
                       oslPrintf_xy(18, 216, "It's not very effective...");
                       oslEndDrawing();
                       oslSyncFrame();
                       ENEMY_EFFECT = NOTHING;
                       hWait; hWait;
             }
             else if(EFFECT == SUPER_EFFECTIVE)
             {
                       oslSetFont(normal);
                       ClearMessageBox();
                       oslStartDrawing();
                       oslPrintf_xy(18, 216, "It's SUPER effective!");
                       oslEndDrawing();
                       oslSyncFrame();
                       EFFECT = NOTHING;
                       hWait; hWait;
             }
             else if(ENEMY_EFFECT == SUPER_EFFECTIVE)
             {
                       oslSetFont(normal);
                       ClearMessageBox();
                       oslStartDrawing();
                       oslPrintf_xy(18, 216, "It's SUPER effective!");
                       oslEndDrawing();
                       oslSyncFrame();
                       ENEMY_EFFECT = NOTHING;
                       hWait; hWait;
             }
             
             oslEndDrawing();
             oslSyncFrame();
                 
             if(ran) 
             {
     
                  for(pointer->y = 250; pointer->y < 262; pointer->y++)
                  {
                     if(pointer->y > 258) pointer->y = 250;
             
                     oslReadKeys();
                     if(osl_keys->pressed.cross) { oslPlaySound(beep, 2); break; }
             
                     oslStartDrawing();
                     oslDrawImage(background_grass);
                     
                     //draw player sonymon
                     if(sonymon_num == 1)      oslDrawImage(sonymon1.image);
                     else if(sonymon_num == 2) oslDrawImage(sonymon2.image);
                     else if(sonymon_num == 3) oslDrawImage(sonymon3.image);
                     
                     //draw enemy
                     //oslDrawImageSimple(enemy);
                     oslSetFont(normal);
                     oslDrawImage(messageBox);
                     oslDrawImage(pointer);
                     oslSetFont(verdana);
                     oslSetBkColor(RGBA(0,0,0,0));
                     oslSetTextColor(BLACK);
                     oslPrintf_xy(18, 216, "%s got away safely", playerName);
                     oslEndDrawing();
                     oslSyncFrame();
                   }
                   
                   break;
             }
     
             if(enemyAlive1 == 0 && enemyAlive2 == 0 && enemyAlive3 == 0) break;
     }
     
     //adjust sound/musc
     hWait;
     oslStopSound(wild_battle);
     oslPauseSound(gameMusic, 0);
     oslPauseSound(center_music, 0);
     
     //delete health bars and set pointers to NULL
     oslDeleteImage(healthBar);
     oslDeleteImage(enemyHealthBar);
     healthBar = NULL;
     enemyHealthBar = NULL;
     
     /******* NOW THE PLAYER HAS "SEEN" THE SONYMON, LET"S ADD IT TO THE RECORDS *********/
     if(enemyID1 != 0) SonymonSeen[enemyID1] = enemyID1;
     if(enemyID2 != 0) SonymonSeen[enemyID2] = enemyID2;
     if(enemyID3 != 0) SonymonSeen[enemyID3] = enemyID3;
     
     return;
}

//wild-sonymon battle function
void BATTLE(const char * playerName, OSL_IMAGE * enemy, const int enemyID, const int enemyLevel)
{
     //first check and make sure the enemy image is not NULL
     if(!enemy) oslFatalError("ERROR!! enemy *image is equal to NULL!!!\nCannot continue!!!");
     
     //battle intro
     oslPauseSound(gameMusic, -1); oslPauseSound(center_music, -1);
     oslPlaySound(wild_intro, 3);  oslSetSoundLoop(wild_intro, 1);
   
     int j = 0;
     
     for(int i = 0; i < 100; i++)
     {          
           oslStartDrawing();
           j++;
           if(j > 5)oslClearScreen(BLACK);
           if(j > 10)oslClearScreen(WHITE);
           if(j > 15)j = 0;
           
           oslDrawImageSimple(zero);
           oslEndDrawing();
           oslSyncFrame();
     }
     
     //reset all the battle variables so next time we have normal gameplay
     briefPause = 0;
     MAX_HP = 0;
     loadedHealthBefore = 0;
     MAX_ENEMY_HP = 0;
     loadedEnemyHealthBefore = 0;
     OUTLINE_MAX = 0;
     OUTLINE_ENEMY_MAX = 0;
     turn = 0;
     GOING_UP = 1; GOING_DOWN = 0;//begin shifting
     turn = 1; selecting = 1; ran = 0; //player's turn
     positionScreenItems(enemy);
     
     unsigned long squareOne = 0;
     unsigned long squareTwo = 272;
     unsigned long moveSquare = 136;
     unsigned long moveSquare2 = 136;
     int showMaxHealth = 1;
     int enemyShowMaxHealth = 1;
     int enemyHealth, enemyAttackPower, enemyDefense, enemyType, XP;
     
     //init ENEMY class
     ENEMY controlEnemy;
     
     //load health bar variables
     OSL_IMAGE *healthBar, *enemyHealthBar;
     healthBar = oslLoadImageFilePNG((char*)"img/data/hp_bar.png", OSL_IN_RAM, OSL_PF_5551);
     enemyHealthBar = oslLoadImageFilePNG((char*)"img/data/hp_bar.png", OSL_IN_RAM, OSL_PF_5551);
           
     healthBar->x = 284;
     healthBar->y = 164;
     oslClearImage(healthBar, GREEN);
     enemyHealthBar->x = 43;
     enemyHealthBar->y = 52;
     oslClearImage(enemyHealthBar, GREEN);
     
     //intro animation
     for(int i = 0; i < 142; i++)
     {
           squareOne--;
           moveSquare--;
           squareTwo++;
           moveSquare2++;
           
           oslStartDrawing();
           oslClearScreen(RGBA(0,0,0,0));
           oslDrawImageSimple(background_grass);
           oslDrawImageSimple(sonymon1.image);
           oslDrawImageSimple(messageBox);
           
           oslDrawFillRect(-1, squareOne, 481, moveSquare, BLACK);
           oslDrawFillRect(-1, squareTwo, 481, moveSquare2, BLACK);
           oslEndDrawing();
           oslSyncFrame();
     }
     
     //start looping the battle sound
     oslStopSound(wild_intro); oslPlaySound(wild_battle, 3); oslSetSoundLoop(wild_battle, 1);
     
     //initiate STATS class
     STATS stats;
     
     //set enemy stats all based on enemyLevel and enemyType!!! :D
     stats.setEnemyType(enemyID, level, enemy);
     stats.XPGain(XP, enemyID, enemyLevel);
     stats.setHealth(enemyHealth, enemyID, enemyLevel);
     stats.setAttackPower(enemyAttackPower, enemyID, enemyLevel);
     stats.setDefense(enemyDefense, enemyID, enemyLevel);
     stats.setType(enemyType, enemyID);
     stats.setEnemyMoves(enemyID, enemyLevel);
     enemyShowMaxHealth = enemyHealth;
     
     if(sonymon_num == 1)      showMaxHealth = sonymon1.health;
     else if(sonymon_num == 2) showMaxHealth = sonymon2.health;
     else if(sonymon_num == 3) showMaxHealth = sonymon3.health;
     
     waitForClick(enemyName, background_grass, enemy, sonymon1.image, pointer);
     
     while(1)
     {       
             oslStartDrawing();
             oslDrawImage(background_grass);
             
             if(sonymon_num == 1)     healthBar->sizeX = (100 * (sonymon1.health / sonymon1.maxHealth));
             else if(sonymon_num == 2)healthBar->sizeX = (100 * (sonymon2.health / sonymon2.maxHealth));
             else if(sonymon_num == 3)healthBar->sizeX = (100 * (sonymon3.health / sonymon3.maxHealth));
             enemyHealthBar->sizeX = (100 * (enemyHealth / enemyShowMaxHealth));
             
             /*MAKE SURE TO DRAW SONYMON, BACKGROUND AND ENEMY BEFORE YOU DECLARE AI FUNCTIONS!!*/
             //draw player sonymon based on int sonymon_num
             if(sonymon_num == 1)      oslDrawImage(sonymon1.image);
             else if(sonymon_num == 2) oslDrawImage(sonymon2.image);
             else if(sonymon_num == 3) oslDrawImage(sonymon3.image);
             
             //draw enemy as long as the enemy is still alive
             if(enemyAlive != 0 ) oslDrawImage(enemy);
             
             //draw util boxes
             oslDrawImage(messageBox);
             oslDrawImage(dialog_box);
             oslDrawImage(xp_bar);
             oslDrawImage(enemy_dialog_box);
             oslDrawImage(healthBar);
             oslDrawImage(enemyHealthBar);
             
             //handle enemy and player health bars
             healthBar = DrawCharacterTextBox(healthBar);
             enemyHealthBar = DrawEnemyTextBox(enemyHealth, enemyHealthBar);
             
             //handle enemy ai
             controlEnemy.HANDLE_ENEMY(enemyHealth, enemyAttackPower, XP, enemyID, enemyType, enemyName, enemy, sonymon1.image, background_grass);
             
             //handle player and player sonymon
             UPDATE(enemyHealth, enemyDefense, enemyType, enemy, background_grass);
     
             if(selecting && turn && enemyAlive)
             {
                oslDrawImage(fightBox);
                
                oslSetFont(bold);
                oslSetTextColor(BLACK);
                oslSetBkColor(RGBA(0,0,0,0));
                
                oslDrawString(286, 226, "FIGHT");
                oslDrawString(393, 226, "BAG");
                oslDrawString(286, 255, "SNYMN");
                oslDrawString(393, 255, "RUN");
                
                
                oslSetFont(normal);
                oslSetTextColor(BLACK);
                oslSetBkColor(RGBA(0,0,0,0));
                if(sonymon_num == 1)      oslPrintf_xy(18, 226, "What will %s do?", sonymon1.name);
                else if(sonymon_num == 2) oslPrintf_xy(18, 226, "What will %s do?", sonymon2.name);
                else if(sonymon_num == 3) oslPrintf_xy(18, 226, "What will %s do?", sonymon3.name);

                oslDrawImageSimple(battle_pointer);
                
             }
             
             if(selectMoves && turn && enemyAlive)
             {
                oslSetFont(bold);
                oslSetTextColor(BLACK);
                oslSetBkColor(RGBA(0,0,0,0));
             
                if(sonymon_num == 1){
                    oslPrintf_xy(18, 226, "%s" , sonymon1.moveName1);
                    oslPrintf_xy(153, 226, "%s",  sonymon1.moveName2);
                    oslPrintf_xy(18, 242, "%s", sonymon1.moveName3);
                    oslPrintf_xy(153, 242, "%s", sonymon1.moveName4);
                }
                else if(sonymon_num == 2){
                    oslPrintf_xy(18, 226, "%s" , sonymon2.moveName1);
                    oslPrintf_xy(153, 226, "%s",  sonymon2.moveName2);
                    oslPrintf_xy(18, 242, "%s", sonymon2.moveName3);
                    oslPrintf_xy(153, 242, "%s", sonymon2.moveName4);
                }
                else if(sonymon_num == 3){
                    oslPrintf_xy(18, 226, "%s" , sonymon3.moveName1);
                    oslPrintf_xy(153, 226, "%s",  sonymon3.moveName2);
                    oslPrintf_xy(18, 242, "%s", sonymon3.moveName3);
                    oslPrintf_xy(153, 242, "%s", sonymon3.moveName4);
                }
                oslDrawImageSimple(battle_selector);
             }
             
             oslSetFont(verdana);
             oslSetTextColor(BLACK);
             oslSetBkColor(RGBA(0,0,0,0));
             
             if(sonymon_num == 1)
             {
                 oslPrintf_xy(419, 160,"%i/%i", sonymon1.health, sonymon1.maxHealth);
                 oslPrintf_xy(256, 141, "%s  Lv:%i", sonymon1.name, sonymon1.level);
             }
             
             else if(sonymon_num == 2)
             {
                 oslPrintf_xy(419, 160,"%i/%i", sonymon2.health, sonymon2.maxHealth);
                 oslPrintf_xy(256, 141, "%s  Lv:%i", sonymon2.name, sonymon2.level);
             }
             
             else if(sonymon_num == 3) 
             {
                 oslPrintf_xy(419, 160,"%i/%i", sonymon3.health, sonymon3.maxHealth);
                 oslPrintf_xy(256, 141, "%s  Lv:%i", sonymon3.name, sonymon3.level);
             }
             
             oslPrintf_xy(178, 48, "%i/%i", enemyHealth, enemyShowMaxHealth);
             oslPrintf_xy(20, 25, "%s  Lv:%i", enemyName, enemyLevel);
             
             //display effectiveness of all the various moves
             if(EFFECT == NOT_EFFECTIVE)
             {
                       oslSetFont(normal);
                       ClearMessageBox();
                       oslStartDrawing();
                       oslDrawString(18, 226, "It's not very effective...");
                       oslEndDrawing();
                       oslSyncFrame();
                       EFFECT = NOTHING;
                       hWait; hWait;
             }
             else if(ENEMY_EFFECT == NOT_EFFECTIVE)
             {
                       oslSetFont(normal);
                       ClearMessageBox();
                       oslStartDrawing();
                       oslDrawString(18, 226, "It's not very effective...");
                       oslEndDrawing();
                       oslSyncFrame();
                       ENEMY_EFFECT = NOTHING;
                       hWait; hWait;
             }
             else if(EFFECT == SUPER_EFFECTIVE)
             {
                       oslSetFont(normal);
                       ClearMessageBox();
                       oslStartDrawing();
                       oslDrawString(18, 226, "It's SUPER effective!");
                       oslEndDrawing();
                       oslSyncFrame();
                       EFFECT = NOTHING;
                       hWait; hWait;
             }
             else if(ENEMY_EFFECT == SUPER_EFFECTIVE)
             {
                       oslSetFont(normal);
                       ClearMessageBox();
                       oslStartDrawing();
                       oslDrawString(18, 226, "It's SUPER effective!");
                       oslEndDrawing();
                       oslSyncFrame();
                       ENEMY_EFFECT = NOTHING;
                       hWait; hWait;
             }
             
             oslEndDrawing();
             oslSyncFrame();
                 
             if(ran) 
             {
     
                  for(pointer->y = 250; pointer->y < 262; pointer->y++)
                  {
                     if(pointer->y > 258) pointer->y = 250;
             
                     oslReadKeys();
                     if(osl_keys->pressed.cross) { oslPlaySound(beep, 2); break; }
             
                     oslStartDrawing();
                     oslDrawImage(background_grass);
                     
                     //draw player sonymon
                     if(sonymon_num == 1)      oslDrawImage(sonymon1.image);
                     else if(sonymon_num == 2) oslDrawImage(sonymon2.image);
                     else if(sonymon_num == 3) oslDrawImage(sonymon3.image);
                     
                     //draw enemy
                     oslDrawImageSimple(enemy);
                  
                     oslSetFont(normal);
                     oslDrawImage(messageBox);
                     oslDrawImage(pointer);
                     oslSetFont(verdana);
                     oslSetBkColor(RGBA(0,0,0,0));
                     oslSetTextColor(BLACK);
                     oslPrintf_xy(18, 226, "%s got away safely", playerName);
                     oslEndDrawing();
                     oslSyncFrame();
                   }
                   
                   break;
             }
     
             if(enemyAlive == 0) break;
     }
     
     //adjust sound/musc
     hWait;
     oslStopSound(wild_battle);
     oslPauseSound(gameMusic, 0);
     oslPauseSound(center_music, 0);
     
     //delete health bars and set pointers to NULL
     oslDeleteImage(healthBar);
     oslDeleteImage(enemyHealthBar);
     healthBar = NULL;
     enemyHealthBar = NULL;
     
     /******* NOW THE PLAYER HAS "SEEN" THE SONYMON, LET"S ADD IT TO THE RECORDS *********/
     SonymonSeen[enemyID] = enemyID;
     
     return;
}


OSL_IMAGE * DrawCharacterTextBox(OSL_IMAGE * image)
{
     //draw player health bar
     int manipulateHealth;
     
     if(sonymon_num == 1) manipulateHealth = sonymon1.health;
     else if(sonymon_num == 2) manipulateHealth = sonymon2.health;
     else if(sonymon_num == 3) manipulateHealth = sonymon3.health;
     else manipulateHealth = 0;
     
     //now manipulate!!!
     if(loadedHealthBefore == 0){
        MAX_HP = manipulateHealth; //we do not want MAX_HP to be changed anymore NO MATTER WHAT
        OUTLINE_MAX = MAX_HP + 2;
        loadedHealthBefore = 1;
     }
     //set color of health bar!!!
     int findChange = MAX_HP;
     findChange /= 2;
     
     if(manipulateHealth > findChange) {
          HEALTH_BAR_COLOR = GREEN; oslClearImage(image, GREEN);
          //image->sizeX = 
     }
     else if(manipulateHealth <= findChange) {
          HEALTH_BAR_COLOR = ORANGE; oslClearImage(image, ORANGE);
     }
     
     findChange = MAX_HP;
     findChange /= 4;
     if(manipulateHealth <= findChange) {HEALTH_BAR_COLOR = RED; oslClearImage(image, RED);}
     
     
     //manipulateHealth = manipulateHealth * -1; //this will flip the direction
     //oslDrawFillRect(284, 166, 415, 171, HEALTH_BAR_COLOR); //used manipulateHealth
     //oslDrawRect(282, 164, 417, 173, BLACK); //used OUTLINE_MAX
     
     return image;
}

OSL_IMAGE * DrawEnemyTextBox(int enemyHealth, OSL_IMAGE * image)
{
     //draw player health bar
     int manipulateEnemyHealth;
     manipulateEnemyHealth = enemyHealth;
     
     //now manipulate!!!
     if(loadedEnemyHealthBefore == 0){
        MAX_ENEMY_HP = manipulateEnemyHealth; //we do not want MAX_HP to be changed anymore NO MATTER WHAT
        OUTLINE_ENEMY_MAX = MAX_ENEMY_HP + 2;
        loadedEnemyHealthBefore = 1;
     }
     
     //set color of health bar!!!
     int findChange = MAX_ENEMY_HP;
     findChange /= 2;
     
     if(manipulateEnemyHealth > findChange) {ENEMY_HEALTH_BAR_COLOR = GREEN; oslClearImage(image, GREEN);}
     else if(manipulateEnemyHealth <= findChange) {ENEMY_HEALTH_BAR_COLOR = ORANGE; oslClearImage(image, ORANGE);}
     
     findChange = MAX_ENEMY_HP;
     findChange /= 4;
     
     if(manipulateEnemyHealth <= findChange) {ENEMY_HEALTH_BAR_COLOR = RED; oslClearImage(image, RED);}
     
     //oslDrawFillRect(42, 53, 167, 58, ENEMY_HEALTH_BAR_COLOR);
     //oslDrawRect(40, 51, 169, 60, BLACK);
     
     return image;
}

//lol before I made a class this function was like 2000 lines of code
int UPDATE(int &enemyHealth, const int enemyDefense, const int enemyRealType, OSL_IMAGE * enemy, OSL_IMAGE * background)
{    
     //if its not the player's turn then exit this function!!
     if(turn != 1)
        return 0;
     
     oslReadKeys();
     
     //initiate UPDATE_TURN class
     UPDATE_TURN update;
     update.Stats();
     update.Bounce();
     update.Options();
     update.Select();
     update.UsedMove(enemyHealth, enemyDefense, enemyRealType, enemy, background);
     
     return enemyHealth;
}

void positionScreenItems(OSL_IMAGE *enemy)
{
     /* postion all the images in the battle scene */
     
     enemy->y = 30; 
     enemy->x = 315;
     
     if(sonymon1.image != NULL){
     sonymon1.image->y = 95; 
     sonymon1.image->x = 28;
     }
     
     if(sonymon2.image != NULL){
       sonymon2.image->y = 95; 
       sonymon2.image->x = 28; 
     }
     
     if(sonymon3.image != NULL){
       sonymon3.image->y = 95; 
       sonymon3.image->x = 28; 
     }
     
     if(sonymon4.image != NULL){
       sonymon4.image->y = 95; 
       sonymon4.image->x = 28; 
     }
     
     if(sonymon5.image != NULL){
       sonymon5.image->y = 95; 
       sonymon5.image->x = 28; 
     }
     
     messageBox->y = 212;
     enemy_dialog_box->x = 10;
     
     fightBox->y = 212;
     fightBox->x = 270;
     
     enemy_dialog_box->y =20;
     
     dialog_box->x = 250;
     dialog_box->y = 132;
     
     xp_bar->x = 254;
     xp_bar->y = 182;
     
     pointer->x = 445;
     pointer->y = 250;
     
     return;
}

void playDeathSound(int type)
{
	//simply play a death sound
	if(type == 1)      oslPlaySound(unknown, 4);
	else if(type == 2) oslPlaySound(blumkins, 4);
	else if(type == 3) oslPlaySound(arsande, 4);
	else if(type == 4) oslPlaySound(myboross, 4);
	else if(type == 5) oslPlaySound(argrasse, 4);
	else if(type == 6) oslPlaySound(norbonkge, 4);
	else if(type == 7) oslPlaySound(blowess, 4);
	else if(type == 8) oslPlaySound(cemes, 4);
	else if(type == 9) oslPlaySound(waterserore, 4);
	else if(type == 10) oslPlaySound(vandel, 4);
	else if(type == 11) oslPlaySound(lieosaur, 4);
	else if(type == 12) oslPlaySound(enemy12, 4);
	else if(type == 13) oslPlaySound(enemy13, 4);
	else oslFatalError("DID NOT APPLY A DEATH SOUND TO SONYMON!!!\nfound in function playDeathSound(int type);!!!");
     
     return;
}

void waitForClick(const char * message, OSL_IMAGE *background, OSL_IMAGE *enemy, OSL_IMAGE *player, OSL_IMAGE *pointer)
{            

     pointer->x = 445;
     pointer->y = 250;
     
     for(pointer->y = 250; pointer->y < 262; pointer->y++)
     {
             if(pointer->y > 258) pointer->y = 250;
             
             oslReadKeys();
             if(osl_keys->pressed.cross)
             { oslPlaySound(beep, 2); break; }
             
             oslStartDrawing();
             oslClearScreen(RGBA(0,0,0,0));
             oslDrawImageSimple(background);
             oslDrawImageSimple(player);
             oslDrawImageSimple(enemy);
             
             oslDrawImage(messageBox);
             oslDrawImage(pointer);
             oslSetFont(verdana);
             oslSetBkColor(RGBA(0,0,0,0));
             oslSetTextColor(BLACK);
             oslPrintf_xy(18, 216, "Wild %s appeared...", message);
             oslEndDrawing();
             oslSyncFrame();
     }
     
     return;
}
