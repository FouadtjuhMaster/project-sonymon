#include "sonymon.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
//general functions used by both sonymon free roam and sonymon story modes:////////////////////////////
void LoadFiles(const int mode)
{
    oslSetTransparentColor(RGB(255,0,255));
    
    int FR = 1;
    int SM = 2;
    
    if(mode != FR && mode != SM) oslFatalError("ERROR INVALID PARAMETER PASSED TO void LoadFiles()!!!");
    
    OSL_IMAGE *loading_screen;
	loading_screen = oslLoadImageFile((char*)"img/data/loading1.png", OSL_IN_RAM, OSL_PF_5551);
	if(!loading_screen)
	   MISSING_IMG_FILES(3);
	   
    oslStartDrawing();
    oslDrawImage(loading_screen);
    oslEndDrawing();
    oslSyncFrame();
    
    if(loadedBefore != 1){
        
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
	if(!background_rock || !background_grass || !messageBox || !pointer 
    || !enemy_dialog_box || !dialog_box || !xp_bar || !battle_selector  || !linkOn 
    || !linkOff || !mini_rec_selector || !item1 || !item2 || !item3 || !DialogBox 
    || !battle_pointer || !sb || !hp_bar || !pound_mark)
	   MISSING_IMG_FILES(1);

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
	if(!arsande_front || !arsande_back || !blumkins_front || !blumkins_back
    || !myboross_front || !myboross_back || !argrasse_front || !argrasse_back || !norbonkge_back 
    || !norbonkge_front || !blowhole_back || !blowhole_front || !vandel_front || !vandel_back
    || !waterserore_front || !waterserore_back || !cemes_front || !cemes_back || !lieosaur_front
    || !lieosaur_back || !unknown_back || !unknown_front || !sturk_front || !sturk_back)
	   MISSING_IMG_FILES(5);
	   
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
    enemy12 = oslLoadSoundFile((char*)"music/entrances/enemy12.bgm", OSL_FMT_NONE);
    enemy13 = oslLoadSoundFile((char*)"music/entrances/enemy13.bgm", OSL_FMT_NONE);
    enemy14 = oslLoadSoundFile((char*)"music/entrances/enemy14.bgm", OSL_FMT_NONE);
    enemy15 = oslLoadSoundFile((char*)"music/entrances/enemy15.bgm", OSL_FMT_NONE);
    enemy16 = oslLoadSoundFile((char*)"music/entrances/enemy16.bgm", OSL_FMT_NONE);
    if(!unknown || !blumkins || !arsande || !myboross || !argrasse  || !norbonkge || !blowess
	   || !cemes || !waterserore || !vandel || !lieosaur|| !enemy12 || !enemy13 || !enemy14 || !enemy15
	   || !enemy16)
       MISSING_IMG_FILES(2);
 
    //load move sounds
    tackle_sound = oslLoadSoundFile((char*)"music/moves/tackle.bgm", OSL_FMT_NONE);
    slam_sound = oslLoadSoundFile((char*)"music/moves/slam.bgm", OSL_FMT_NONE);
    uplink_sound = oslLoadSoundFile((char*)"music/moves/uplink.bgm", OSL_FMT_NONE);
    pound_sound = oslLoadSoundFile((char*)"music/moves/pound.bgm", OSL_FMT_NONE);
    jumpKick_sound = oslLoadSoundFile((char*)"music/moves/jumpKick.bgm", OSL_FMT_NONE);
    contaminate_sound = oslLoadSoundFile((char*)"music/moves/contaminate.bgm", OSL_FMT_NONE);
    clobber_sound = oslLoadSoundFile((char*) "music/moves/tackle.bgm", OSL_FMT_NONE);
    steroids_sound = oslLoadSoundFile((char*) "music/moves/steroids.bgm", OSL_FMT_NONE);
    if(!tackle_sound || !slam_sound || !uplink_sound || !pound_sound || !jumpKick_sound
    || !contaminate_sound || !clobber_sound || !steroids_sound) 
        MISSING_IMG_FILES(2);
    
    //load damage taken sounds
    hurt_low = oslLoadSoundFile((char*)"music/moves/hurt(low).bgm", OSL_FMT_NONE);
    hurt_medium = oslLoadSoundFile((char*)"music/moves/hurt(medium).bgm", OSL_FMT_NONE);
    hurt_high = oslLoadSoundFile((char*)"music/moves/hurt(high).bgm", OSL_FMT_NONE);
    
    //load battle music
    wild_battle = oslLoadSoundFile((char*)"music/entrances/wild(loop).bgm", OSL_FMT_NONE);
    leader_battle = oslLoadSoundFile((char*)"music/entrances/leader(loop).bgm", OSL_FMT_NONE);
    boss_battle = oslLoadSoundFile((char*)"music/entrances/boss(loop).bgm", OSL_FMT_NONE);
    wild_intro = oslLoadSoundFile((char*)"music/entrances/wild(intro).bgm", OSL_FMT_NONE);
    leader_intro = oslLoadSoundFile((char*)"music/entrances/leader(intro).bgm", OSL_FMT_NONE);
    boss_intro = oslLoadSoundFile((char*)"music/entrances/boss(intro).bgm", OSL_FMT_NONE);
    if(!wild_battle || !leader_battle || !boss_battle || !wild_intro || !leader_intro
    || !boss_intro) MISSING_IMG_FILES(2);
    
    //load all other sounds
    enter  = oslLoadSoundFile((char*)"music/exit.wav", OSL_FMT_NONE);
    found = oslLoadSoundFile((char*) "music/found.bgm", OSL_FMT_NONE);
    beep = oslLoadSoundFile((char*)"music/beep.bgm", OSL_FMT_NONE);
    Selected = oslLoadSoundFile((char*)"music/selected.bgm", OSL_FMT_NONE);
    gameMusic = oslLoadSoundFile((char*)"music/route/route1.bgm", OSL_FMT_NONE); 
    center_music = oslLoadSoundFile((char*)"music/building1.bgm", OSL_FMT_NONE);
    if(!gameMusic || !beep || !hurt_low || !hurt_medium || !hurt_high || !Selected 
    || !center_music || !found || !enter)
       MISSING_IMG_FILES(2);
       
       
    verdana = oslLoadFontFile((char*)"fonts/verdana.oft");
    if(!verdana)
       MISSING_IMG_FILES(4);
       
    main_font = oslLoadFontFile((char*)"fonts/Agency.oft");
    if(!main_font)
       MISSING_IMG_FILES(4);
       
    bold_battle_font = oslLoadFontFile((char*)"fonts/battle(bold).oft");
    if(!bold_battle_font)
       MISSING_IMG_FILES(4);
       
    battle_font = oslLoadFontFile((char*)"fonts/battle.oft");
    if(!battle_font)
       MISSING_IMG_FILES(4);
       
       
    //load the main character
    zero = oslLoadImageFile((char*)"img/sprites/male4.png", OSL_IN_RAM, OSL_PF_5551);  
    if(!zero)
        MISSING_IMG_FILES(1);
        
    loadedBefore = 1;
	
    }
	
	if(mode == FR)
	{
	    if(uplink_center != NULL){oslDeleteImage(uplink_center); uplink_center = NULL;}
	    if(World_Route_tileset != NULL){oslDeleteImage(World_Route_tileset); World_Route_tileset = NULL;}
	    if(Route01_tileset != NULL){oslDeleteImage(Route01_tileset); Route01_tileset = NULL;}
	    if(Route02_tileset != NULL){oslDeleteImage(Route02_tileset); Route02_tileset = NULL;}
	    if(Route03_tileset != NULL){oslDeleteImage(Route03_tileset); Route03_tileset = NULL;}
	    if(Route04_tileset != NULL){oslDeleteImage(Route04_tileset); Route04_tileset = NULL;}
	    if(FR1_tileset != NULL) {oslDeleteImage(FR1_tileset); FR1_tileset = NULL;}
	
	    //load map data
	    uplink_center = oslLoadImageFile((char*)"img/data/maps/uplink_center.png", OSL_IN_RAM, OSL_PF_5551);
	    World_Route_tileset = oslLoadImageFile((char*)"img/data/maps/world_route_tileset.png", OSL_IN_RAM, OSL_PF_5551);
	    Route01_tileset = oslLoadImageFile((char*)"img/data/maps/route01_tileset.png", OSL_IN_RAM, OSL_PF_5551);
	    Route02_tileset = oslLoadImageFile((char*)"img/data/maps/route02_tileset.png", OSL_IN_RAM, OSL_PF_5551);
	    Route03_tileset = oslLoadImageFile((char*)"img/data/maps/route03_tileset.png", OSL_IN_RAM, OSL_PF_5551);
        Route04_tileset = oslLoadImageFile((char*)"img/data/maps/route04_tileset.png", OSL_IN_RAM, OSL_PF_5551);
	    FR1_tileset = oslLoadImageFile((char*) "img/data/maps/FR1_tileset.png", OSL_IN_RAM, OSL_PF_5551);
        if(!uplink_center || !World_Route_tileset || !Route01_tileset || !Route02_tileset || !Route03_tileset
	    || !Route04_tileset || !FR1_tileset)
	        MISSING_IMG_FILES(5);
	
	    FR1 = oslCreateMap(
		   FR1_tileset,						//Tileset
		   (void *)FR1_map,							//Map
		   32,32,								//Size of the tiles
		   64, 85,							//Size of the Map
		   OSL_MF_U16);
		
	    World_Route = oslCreateMap(
		  World_Route_tileset,						//Tileset
		  (void *)world_route_map,							//Map
		  16,16,								//Size of the tiles
		  70, 50,							//Size of the Map
		  OSL_MF_U16);
	
        Route01 = oslCreateMap(
		  Route01_tileset,						//Tileset
		  (void *)route01_map,							//Map
		  16,16,								//Size of the tiles
		  70, 44,							//Size of the Map
		  OSL_MF_U16);
		
	    Route02 = oslCreateMap(
		  Route02_tileset,						//Tileset
		  (void *)route02_map,							//Map
		  16,16,								//Size of the tiles
		  70, 43,							//Size of the Map
		  OSL_MF_U16);
		
	    Route03 = oslCreateMap(
		  Route03_tileset,						//Tileset
		  (void *)route03_map,							//Map
		  16,16,								//Size of the tiles
		  70, 50,							//Size of the Map
		  OSL_MF_U16);
		
	    Route04 = oslCreateMap(
	 	  Route04_tileset,						//Tileset
		  (void *)route4_map,							//Map
	      16,16,								//Size of the tiles
		  370, 38,							//Size of the Map
		  OSL_MF_U16);
		  
		loadedFRBefore = 1;
    }
	
	if(mode == SM)
	{
        if(uplink_center != NULL){oslDeleteImage(uplink_center); uplink_center = NULL;}
        if(Secruit_Town_tileset != NULL){oslDeleteImage(Secruit_Town_tileset); Secruit_Town_tileset = NULL;}
    
	    //load map data
	    uplink_center = oslLoadImageFile((char*)"img/data/maps/uplink_center.png", OSL_IN_RAM, OSL_PF_5551);
	    Secruit_Town_tileset = oslLoadImageFile((char*)"img/data/maps/Secruit Town tileset.png", OSL_IN_RAM, OSL_PF_5551);
	    if(!uplink_center || !Secruit_Town_tileset)
	        MISSING_IMG_FILES(5);
	
	
	    //create all the maps
	    Secruit_Town = oslCreateMap(
		     Secruit_Town_tileset,						//Tileset
		     (void *)Secruit_Town_map,				//Map
		     16,16,								//Size of the tiles
		     150, 150,							//Size of the Map
		     OSL_MF_U16);
		     
		loadedStoryBefore = 1;
     }
    
    //free RAM
    oslDeleteImage(loading_screen);
    
    oslDisableTransparentColor();
    
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
     if(allowSearch == 0)
        return;
        
     //force the game to pause between each sonymon battle
     swait++;
     if(swait < 40)
         return;
         
     if(area == 0)      map = World_Route;
     else if(area == 1) map = Route01;
     else if(area == 2) map = Route02;
     else if(area == 3) map = Route03;
    
     int random_number;
     srand((unsigned)time(0));
     
     if(strcmp(Hz,"30Hz"))
     {
        random_number = (rand()%30)+1;
        if(random_number == 2 || random_number == 3) {BATTLE(playerName, blumkins_front, 2, 2);}
        else if(random_number == 4 || random_number == 5) {BATTLE(playerName, arsande_front, 3, 2); }
        
        else if(random_number == 6) {BATTLE(playerName, myboross_front, 4, 2); }
        else if(random_number == 7) {BATTLE(playerName, myboross_front, 4, 3); }
        
        else if(random_number == 8) {BATTLE(playerName, lieosaur_front, 11, 2); }
        else if(random_number == 9) {BATTLE(playerName, lieosaur_front, 11, 3); }
        else if(random_number == 10) {BATTLE(playerName, lieosaur_front, 11, 4); }
        else {manipExposure++; if(manipExposure >= 30) {manipExposure = 0; exposure++;}}
     }
     
     else if(strcmp(Hz,"300Hz"))
     {
        random_number = (rand()%30)+1;
        if(random_number == 2 || random_number == 3) { BATTLE(playerName, argrasse_front, 5, 2); }
        else if(random_number == 12 || random_number == 13) {BATTLE(playerName, norbonkge_front, 6, 2); }
        
        else if(random_number == 4) {BATTLE(playerName, blowhole_front, 7, 2);}
        else if(random_number == 5) {BATTLE(playerName, blowhole_front, 7, 3);}
        else if(random_number == 6) {BATTLE(playerName, blowhole_front, 7, 4);}
        
        else if(random_number == 10 || random_number == 11) BATTLE(playerName, cemes_front, 8, 2);
        else if(random_number == 7) {BATTLE(playerName, cemes_front, 8, 3);}
        else if(random_number == 8) {BATTLE(playerName, cemes_front, 8, 4);}
        else if(random_number == 9) {BATTLE(playerName, cemes_front, 8, 5);}
         
        else {manipExposure++; if(manipExposure >= 30) {manipExposure = 0; exposure++;}} 
     }
     
     else if(strcmp(Hz,"3kHz"))
     {
        
        random_number = (rand()%30)+1;
        if(random_number == 2) {BATTLE(playerName, cemes_front, 8, 2); }
        else if(random_number == 3) {BATTLE(playerName, waterserore_front, 9, 2); }
        else if(random_number == 4) {BATTLE(playerName, vandel_front, 10, 2); }
        else if(random_number == 5 || random_number == 6) {BATTLE(playerName, sturk_front, 12, 4); }
        else {manipExposure++; if(manipExposure >= 30) {manipExposure = 0; exposure++;}}
     }
     
     swait = 0;

     return;
}

//assigns a sonymon to the specified slot
void ASSIGN_SONYMON(int slot, int id, int level)
{
     //initiate STATS class
     STATS stats;
     
     if(slot == 1)
     {   
       sonymon1_level = level;
       stats.setAttackPower(sonymon1_attack, id, level);
       stats.setHealth(sonymon1_health, id, level);
       stats.setDefense(sonymon1_defense, id, level);
       stats.setType(sonymon1_type, id);
       sonymon1_move1 = tackle;   
       
       sonymon1_maxHealth = sonymon1_health;        
     }
     
     else if(slot == 2)
     {
       sonymon2_level = level;
       stats.setAttackPower(sonymon2_attack, id, level);
       stats.setHealth(sonymon2_health, id, level);
       stats.setDefense(sonymon2_defense, id, level);
       stats.setType(sonymon2_type, id);
       sonymon2_move1 = tackle;  
       
       sonymon2_maxHealth = sonymon2_health; 
     }
     
     else if(slot == 3)
     {
       sonymon3_level = level;
       stats.setAttackPower(sonymon3_attack, id, level);
       stats.setHealth(sonymon3_health, id, level);
       stats.setDefense(sonymon3_defense, id, level);
       stats.setType(sonymon3_type, id);
       sonymon3_move1 = tackle;  
       
       sonymon3_maxHealth = sonymon3_health; 
     }
     
     stats.setMoves(slot, id, level);
     stats.setName(id, slot);
     stats.setMoveNames(slot);
     stats.setImage(id, slot);
     stats.SetMaxXP(slot, id);
     
     SonymonSeen[id] = id; //now the player has seen this sonymon (probably already did in battle) ...double checking is always good
     SonymonOwned[id] = id; //now the player owns this sonymon
     
     return;
}

int ApplyTypes(const int moveUsed, int &damagePower, const int enemyRealType, int &EFFECT)
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

int ApplyAttackValue(int getValue, int enemyAttackPower)
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

void place(OSL_IMAGE *img, int posx, int posy)
{
     img->x = posx;
     img->y = posy;
     
     return;
}

void ResetStats( void )
{
    //wipe all sonymon memory or stats CLEAN!!!
    
    //const char * object just displays info about where the player is standing
    object = "NULL"; 
    
    //wipe sonymon slot #1
    sonymon1_name = "???";
    sonymon1_moveName1 = "-- --";
    sonymon1_moveName2 = "-- --";
    sonymon1_moveName3 = "-- --";
    sonymon1_moveName4 = "-- --";
    sonymon1_health = 0;
    sonymon1_maxHealth = 0;
    sonymon1_attack = 0;
    sonymon1_defense = 0;
    sonymon1_move1 = 0;
    sonymon1_move2 = 0;
    sonymon1_move3 = 0;
    sonymon1_move4 = 0;
    sonymon1_alive = 0;
    sonymon1_type = UNDEFINED;
    sonymon1_level = 1;
    sonymon1_id = 1;
    sonymon1_xp = 0;
    sonymon1_max_xp = 0;
    if(sonymon_pic1 != NULL) {oslDeleteImage(sonymon_pic1); sonymon_pic1 = NULL;}
    
    //wipe sonymon slot #2
    sonymon2_name = "???";
    sonymon2_moveName1 = "-- --";
    sonymon2_moveName2 = "-- --";
    sonymon2_moveName3 = "-- --";
    sonymon2_moveName4 = "-- --";
    sonymon2_health = 0;
    sonymon2_maxHealth = 0;
    sonymon2_attack = 0;
    sonymon2_defense = 0;
    sonymon2_move1 = 0;
    sonymon2_move2 = 0;
    sonymon2_move3 = 0;
    sonymon2_move4 = 0;
    sonymon2_alive = 0;
    sonymon2_type = UNDEFINED;
    sonymon2_level = 1;
    sonymon2_id = 1;
    sonymon2_xp = 0;
    sonymon2_max_xp = 0;
    if(sonymon_pic2 != NULL) {oslDeleteImage(sonymon_pic2); sonymon_pic2 = NULL;}
    
    //wipe sonymon slot #3
    sonymon3_name = "???";
    sonymon3_moveName1 = "-- --";
    sonymon3_moveName2 = "-- --";
    sonymon3_moveName3 = "-- --";
    sonymon3_moveName4 = "-- --";
    sonymon3_health = 0;
    sonymon3_maxHealth = 0;
    sonymon3_attack = 0;
    sonymon3_defense = 0;
    sonymon3_move1 = 0;
    sonymon3_move2 = 0;
    sonymon3_move3 = 0;
    sonymon3_move4 = 0;
    sonymon3_alive = 0;
    sonymon3_type = UNDEFINED;
    sonymon3_level = 1;
    sonymon3_id = 1;
    sonymon3_xp = 0;
    sonymon3_max_xp = 0;
    if(sonymon_pic3 != NULL) {oslDeleteImage(sonymon_pic3); sonymon_pic3 = NULL;}
    
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
     
     vandel_front->x = 235;
     blowhole_front->x = 235;
     blowhole_front->x = 235;
     waterserore_front->x = 235;
     arsande_front->x = 235;
     lieosaur_front->x = 235;
     cemes_front->x = 235;
     myboross_front->x = 235;
     blumkins_front->x = 235;
     norbonkge_front->x = 235;
     argrasse_front->x = 235;
     sturk_front->x = 235;
     
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
    
    player.collisionLeft = false;
    player.collisionRight = false;
    player.collisionUp = false;
    player.collisionDown = false;
    
    return;
}

void ENTRY_EFFECT(OSL_MAP * map, int area)
{
    oslPlaySound(enter, 2);
    
     //handle OSL_MAP * Level
    if(area == 0)      map = World_Route;
    else if(area == 1) map = Route01;
    else if(area == 2) map = Route02;
    else if(area == 3) map = Route03;
   
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

///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
//sonymon story functions://///////////////////////////////////////////////////////////////////////////

//this function will handle all of the special events in story mode
//based on certain values and variables defineable by the programmer
int EVENT_HANDLER(OSL_MAP * map)
{   
    OSL_IMAGE * garbage = NULL;
    
	if(introPassed != 1)
    {
        //create an object of the COMPUTER class
        COMPUTER scientist;
        scientist.image = scientist.loadImage(6, scientist.loadedImage);
        
        //place our scientist on the map based on the player's position
		scientist.image->x = 800 - zero->x;
        scientist.image->y = 400 - zero->y;
        oslStartDrawing(); oslDrawImageSimple(scientist.image); oslEndDrawing();
        
        messagebox.DisplayBox("Scientist: Excuse me sir!!!!", 1);
        
        while(scientist.image->x != zero->x && scientist.image->y != zero->y - 50)
        {
            oslStartDrawing();
            oslClearScreen(BLACK);
            oslDrawMap(map);
            oslDrawImage(scientist.image);
            oslDrawImage(zero);
        
            if(scientist.image->x >= zero->x) scientist.image->x-=2; //get the same x value as the player
            if(scientist.image->y >= zero->x + 10 && scientist.image->x == zero->x) scientist.image->y--; //then get the player's y value+10
            scientist.ComputerAnimate(scientist.image, 1, scientist.manip, scientist.march, scientist.position);
            
            oslEndDrawing();
            oslSyncFrame();
       }
        
        messagebox.DisplayBox("Scientist: Oh! I'm so glad I caught up with you...phew", 1);
        messagebox.DisplayBox("Scientist: .........", 1);
        messagebox.DisplayBox("Scientist: now what was it, that I was going to ask you...", 1);
        messagebox.DisplayBox("???: CHARLES!! HAVE YOU FOUND SOMEONE YET?!!", 1);
        messagebox.DisplayBox("Scientist: oh that's right! May I ask you to come with me sir?", 1);
        
        TransitionUp(map, garbage);
        
        introPassed = 1;
        
	}
	
	return 1;
}

int Sonymon(const char * playerName, const int load)
{
    oslInit(0);
	oslInitGfx(OSL_PF_8888, 1);
    
    if(playerName == NULL) playerName = "Ken";
     
    //load the game if the user selected "continue game"
    //if(load){
             //int success = 0;
             //success = LOADGAME(sonymon1_id, sonymon1_level, sonymon2_id, sonymon2_level, sonymon3_id, sonymon3_level);
             //if(success != 1) return 0;
    //}
    
    //load files
    LoadFiles(2);
    
    //wipe all sonymon memory or stats CLEAN!!!
    ResetStats();
    
    //reset all variables for normal gameplay
	zero->x = 240; 
    zero->y = 121; 
    sprite_march = 0; 
    oslSetImageTileSize(zero,0,DOWN,23,32);
    Secruit_Town->scrollX = 1181;
    Secruit_Town->scrollY = 252;
    allowSearch = 0;
    InsideCenter = 0;
    introPassed = 0;
    area = SECRUIT_TOWN; 
    introPassed = 0;
    EXIT_GAME = 0;
    
    //welcome the player ;)
    if(gameMusic != NULL){oslStopSound(gameMusic); oslDeleteSound(gameMusic); gameMusic = NULL;}
    gameMusic = oslLoadSoundFile((char*)"music/intro.bgm", OSL_FMT_NONE); {if(!gameMusic) MISSING_IMG_FILES(2);}
    
    //start sound loop
    oslPlaySound(gameMusic, 1); oslSetSoundLoop(gameMusic, 1);
    
    messagebox.DisplayBox("Welcome to Sonymon!", 1);
    messagebox.DisplayBox("In this world you will find strange creatures, secrets, adventures...", 1);
    messagebox.DisplayBox("epic items, and meet lots of other people! ", 1);
    messagebox.DisplayBox("Don't forget to check for updates on this homebrew weekly :D", 1);
    
    oslStopSound(gameMusic); oslDeleteSound(gameMusic); gameMusic = NULL;
    gameMusic = oslLoadSoundFile((char*)"music/route/route3.bgm", OSL_FMT_NONE); {if(!gameMusic) MISSING_IMG_FILES(2);}
    oslPlaySound(gameMusic, 1); oslSetSoundLoop(gameMusic, 1); //start sound loop
    
    for(;;)
    {
       oslStartDrawing();

       if(introPassed != 1)HANDLE_SEARCH(playerName, Secruit_Town);
       HANDLE_STORY(playerName, Secruit_Town); 
       
       oslEndDrawing();
       oslSyncFrame();
       
       //handle all special events and move the story along
	   EVENT_HANDLER(Secruit_Town);
	   
       if(EXIT_GAME)break;     
    }
   
   //fix sig font
   oslSetFont(verdana); oslSetTextColor(BLACK); oslSetBkColor(RGBA(0,0,0,0));
   
   //end any sound
   oslStopSound(center_music); oslStopSound(gameMusic);
    
   return 0;
}

void HANDLE_STORY(const char * playerName, OSL_MAP * level)
{
   if(level == NULL) oslFatalError("ERROR! Map level is equal to NULL CANNOT CONTINUE!!!"); 
   if(Appeared){ENTRY_EFFECT(level, area); Appeared = 0;}
   oslClearScreen(BLACK);
   oslDrawMap(level);
   
   oslDrawImage(zero);
   player.DrawInfo(Toggle1, 2);
   player.ReadKeys(playerName, level);
   if (zero->x <= 1)   zero->x = 1;
   if (zero->y <= 1)   zero->y = 1;
   if (zero->x >= 460) zero->x = 460;
   if (zero->y >= 239) zero->y = 239;
   zeroMapX = level->scrollX;
   zeroMapY = level->scrollY;
   
   items.Populate(level, area); 
   items.Draw(area);
   
   oslDrawImage(zero);
   player.DrawInfo(Toggle1, 1);
   player.ReadKeys(playerName, level);

  return;
 
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
//sonymon free roam functions://///////////////////////////////////////////////////////////////////////
          
int SonymonFreeRoam(const char * playerName, const int load)
{   
	oslInit(0);
	oslInitGfx(OSL_PF_8888, 1);
    
    if(playerName == NULL) playerName = "Ken";
    //load the game if the user selected "continue game"
    //if(load){
             //int success = 0;
             //success = LOADGAME(sonymon1_id, sonymon1_level, sonymon2_id, sonymon2_level, sonymon3_id, sonymon3_level);
             //if(success != 1) return 0;
    //}
    
    //load game files
	LoadFiles(1);
	
	//Place player at the center of the screen
	zero->x = 240; 
    zero->y = 121; 
    sprite_march = 0; 
    oslSetImageTileSize(zero,0,DOWN,23,32);
    
    //reset all map points
    World_Route->scrollX = 0;
    World_Route->scrollY = 0;
    Route01->scrollX = 0;
    Route01->scrollY = 0;
    Route02->scrollX = 0;
    Route02->scrollY = 0;
    Route03->scrollX = 0;
    Route03->scrollY = 0;
    FR1->scrollX = 0;
    FR1->scrollY = 0;
    
    if(gameMusic != NULL){oslStopSound(gameMusic); oslDeleteSound(gameMusic); gameMusic = NULL;}
    gameMusic = oslLoadSoundFile((char*)"music/route/dawn.bgm", OSL_FMT_NONE); {if(!gameMusic) MISSING_IMG_FILES(2);}
    oslPlaySound(gameMusic, 1); oslSetSoundLoop(gameMusic, 1);
    
     //wipe all sonymon memory or stats CLEAN!!!
     ResetStats();
    
    //choose a starting sonymon
     int choice = 1;
     const char * name = "???";
     
     OSL_IMAGE * selection;
     selection = oslLoadImageFile((char*)"img/data/choose.png", OSL_IN_RAM, OSL_PF_5551);
     if(!selection) MISSING_IMG_FILES(1);
     
     while(1)
     { 
        oslStartDrawing();
        oslClearScreen(BLACK);
        oslDrawImage(selection);
        
        if(choice == 1)       {oslDrawImageSimple(waterserore_front); name = "waterserore";  sonymon1_id = 9;}
        else if(choice == 2)  {oslDrawImageSimple(vandel_front);      name = "vandel";       sonymon1_id = 10;}
        else if(choice == 3)  {oslDrawImageSimple(blowhole_front);    name = "blowess";      sonymon1_id = 7;}
        else if(choice == 4)  {oslDrawImageSimple(argrasse_front);    name = "argrasse";     sonymon1_id = 5;}
        else if(choice == 5)  {oslDrawImageSimple(norbonkge_front);   name = "norbonkge";    sonymon1_id = 6;}
        else if(choice == 6)  {oslDrawImageSimple(blumkins_front);    name = "blumkins";     sonymon1_id = 2;}
        else if(choice == 7)  {oslDrawImageSimple(arsande_front);     name = "arsande";      sonymon1_id = 3;}
        else if(choice == 8)  {oslDrawImageSimple(myboross_front);    name = "myboross";     sonymon1_id = 4;}
        else if(choice == 9)  {oslDrawImageSimple(lieosaur_front);    name = "lieosaur";     sonymon1_id = 11;}
        else if(choice == 10) {oslDrawImageSimple(cemes_front);       name = "cemes";        sonymon1_id = 8;}
        else if(choice == 11) {oslDrawImageSimple(sturk_front);       name = "sturk";        sonymon1_id = 12;}
        
        oslSetTextColor(WHITE);
        oslSetBkColor(RGBA(0,0,0,0));
        oslSetFont(main_font);
        oslPrintf_xy(5, 5, "Choose a starting Sonymon");
        oslPrintf_xy(5, 160, "%s Lv5", name); 
        
        oslEndDrawing();
        oslSyncFrame();
        
        oslReadKeys();
        
        //assign that sonymon
        if(osl_keys->pressed.cross || osl_keys->pressed.start){
            sonymon_num = 1; //equip first sonymon
            sonymon1_alive = 1;
            currentSonymon = 1;	
            ASSIGN_SONYMON(1, sonymon1_id, 5);
            break;
        }
        else if(osl_keys->pressed.left && choice > 1){choice--; oslPlaySound(beep, 2);}
        else if(osl_keys->pressed.right && choice < 11){choice++; oslPlaySound(beep, 2);}
        
    }
    
    quitGame = 0;
    
    //testing inventory...temperarily give items to player
    inventory[0] = 1;
    inventory[1] = 2;
    inventory[2] = 3;
    inventory[3] = 4;
    inventory[4] = 99;
    inventory[5] = 98;
    
    if(TOP_DIRT == FR1_map[0][0]) oslWarning("TOLD YOU SO!!");
    
    for(;;)
    { 
        oslStartDrawing();
        
        HANDLE(playerName, FR1);
        HANDLE_SEARCH(playerName, FR1);
        
        oslEndDrawing();
        oslSyncFrame();
        
        if(quitGame){quitGame = 0;  break;}
    }
   
   //fix sig font
   oslSetFont(verdana); oslSetTextColor(BLACK); oslSetBkColor(RGBA(0,0,0,0));
   
   //end any sound
   oslStopSound(center_music); oslStopSound(gameMusic);
   
   return 0;
}

void HANDLE(const char * playerName, OSL_MAP * level)
{
   if(!level) oslFatalError("ERROR! Map level is equal to NULL CANNOT CONTINUE!!!"); 
   if(Appeared){ENTRY_EFFECT(level, area); Appeared = 0;}
   oslClearScreen(BLACK);
   oslDrawMap(level);
   
   if(zero)oslDrawImage(zero);
   else oslFatalError("ERROR! SOMEHOW PLAYER IMAGE IS NOW NULL! CANNOT CONTINUE!!");
   
   player.DrawInfo(Toggle1, 2);
   player.ReadKeys(playerName, level);
   if (zero->x <= 1)   zero->x = 1;
   if (zero->y <= 1)   zero->y = 1;
   if (zero->x >= 460) zero->x = 460;
   if (zero->y >= 239) zero->y = 239;
   zeroMapX = level->scrollX;
   zeroMapY = level->scrollY;
   
   //check for tile collisions....
   player.tile = map.GetTile(level, (level->scrollX / level->tileX), (level->scrollY / level->tileY));
   
   player.collisionDown = player.Check();
   if(player.collisionDown) level->scrollY--;
   
   player.collisionUp = player.Check();
   if(player.collisionUp) level->scrollY++;
   
   player.collisionRight = player.Check();
   if(player.collisionRight) level->scrollX--;
   
   player.collisionLeft = player.Check();
   if(player.collisionLeft) level->scrollX++;
   
   
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
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
//sonymon battle functions:///////////////////////////////////////////////////////////////////////////////////

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
     
     //initiate STATS class
     STATS stats;
     
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
           oslDrawImageSimple(sonymon_pic1);
           oslDrawImageSimple(messageBox);
           
           oslDrawFillRect(-1, squareOne, 481, moveSquare, BLACK);
           oslDrawFillRect(-1, squareTwo, 481, moveSquare2, BLACK);
           oslEndDrawing();
           oslSyncFrame();
     }
     
     //start looping the battle sound
     oslStopSound(wild_intro); oslPlaySound(wild_battle, 3); oslSetSoundLoop(wild_battle, 1);
     
     //set enemy stats all based on enemyLevel and enemyType!!! :D
     
     if(sonymon_num == 1)      showMaxHealth = sonymon1_health;
     else if(sonymon_num == 2) showMaxHealth = sonymon2_health;
     else if(sonymon_num == 3) showMaxHealth = sonymon3_health;
     
     waitForClick("trainer sonymon", background_grass, enemy1, sonymon_pic1, pointer);
     
     while(1)
     {       
             oslStartDrawing();
             oslDrawImage(background_grass);
             
             //handle enemy ai
             
             //handle player and player sonymon
             //UPDATE(enemyHealth, enemyDefense, enemyType, enemy, background_grass);
             
             //draw player sonymon based on int sonymon_num
             if(sonymon_num == 1)      oslDrawImage(sonymon_pic1);
             else if(sonymon_num == 2) oslDrawImage(sonymon_pic2);
             else if(sonymon_num == 3) oslDrawImage(sonymon_pic3);
             
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
                
                oslSetFont(battle_font);
                oslSetTextColor(BLACK);
                oslSetBkColor(RGBA(0,0,0,0));
                
                oslPrintf_xy(286, 216, "FIGHT");
                oslPrintf_xy(393, 216, "BAG");
                oslPrintf_xy(286, 245, "SNYMN");
                oslPrintf_xy(393, 245, "RUN");
                
                
                oslSetFont(verdana);
                oslSetTextColor(BLACK);
                oslSetBkColor(RGBA(0,0,0,0));
                if(sonymon_num == 1)      oslPrintf_xy(18, 216, "What will %s do?", sonymon1_name);
                else if(sonymon_num == 2) oslPrintf_xy(18, 216, "What will %s do?", sonymon2_name);
                else if(sonymon_num == 3) oslPrintf_xy(18, 216, "What will %s do?", sonymon3_name);

                oslDrawImageSimple(battle_pointer);
                
             }
             
             if(selectMoves && turn)
             {
                oslSetFont(battle_font);
                oslSetTextColor(BLACK);
                oslSetBkColor(RGBA(0,0,0,0));
             
                if(sonymon_num == 1){
                    oslPrintf_xy(18, 216, "%s" , sonymon1_moveName1);
                    oslPrintf_xy(153, 216, "%s",  sonymon1_moveName2);
                    oslPrintf_xy(18, 242, "%s", sonymon1_moveName3);
                    oslPrintf_xy(153, 242, "%s", sonymon1_moveName4);
                }
                else if(sonymon_num == 2){
                    oslPrintf_xy(18, 216, "%s" , sonymon2_moveName1);
                    oslPrintf_xy(153, 216, "%s",  sonymon2_moveName2);
                    oslPrintf_xy(18, 242, "%s", sonymon2_moveName3);
                    oslPrintf_xy(153, 242, "%s", sonymon2_moveName4);
                }
                else if(sonymon_num == 3){
                    oslPrintf_xy(18, 216, "%s" , sonymon3_moveName1);
                    oslPrintf_xy(153, 216, "%s",  sonymon3_moveName2);
                    oslPrintf_xy(18, 242, "%s", sonymon3_moveName3);
                    oslPrintf_xy(153, 242, "%s", sonymon3_moveName4);
                }
                oslDrawImageSimple(battle_selector);
             }
             
             oslSetFont(verdana);
             oslSetTextColor(BLACK);
             oslSetBkColor(RGBA(0,0,0,0));
             
             //draw player sonymon health, level, max-health, and name based on int sonymon_num
             if(sonymon_num == 1){
                 oslPrintf_xy(419, 160,"%i/%i", sonymon1_health, sonymon1_maxHealth);
                 oslPrintf_xy(256, 141, "%s  Lv:%i", sonymon1_name, sonymon1_level);
             }
             else if(sonymon_num == 2){
                 oslPrintf_xy(419, 160,"%i/%i", sonymon2_health, sonymon2_maxHealth);
                 oslPrintf_xy(256, 141, "%s  Lv:%i", sonymon2_name, sonymon2_level);
             }
             else if(sonymon_num == 3) {
                 oslPrintf_xy(419, 160,"%i/%i", sonymon3_health, sonymon3_maxHealth);
                 oslPrintf_xy(256, 141, "%s  Lv:%i", sonymon3_name, sonymon3_level);
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
                     if(sonymon_num == 1)      oslDrawImage(sonymon_pic1);
                     else if(sonymon_num == 2) oslDrawImage(sonymon_pic2);
                     else if(sonymon_num == 3) oslDrawImage(sonymon_pic3);
                     
                     //draw enemy
                     //oslDrawImageSimple(enemy);
              
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
     
     for(int i = 0; i < 70; i++)
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
     healthBar = oslLoadImageFile((char*)"img/data/hp_bar.png", OSL_IN_RAM, OSL_PF_5551);
     enemyHealthBar = oslLoadImageFile((char*)"img/data/hp_bar.png", OSL_IN_RAM, OSL_PF_5551);
     if(!healthBar || !enemyHealthBar)
           MISSING_IMG_FILES(1);
           
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
           oslDrawImageSimple(sonymon_pic1);
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
     
     if(sonymon_num == 1)      showMaxHealth = sonymon1_health;
     else if(sonymon_num == 2) showMaxHealth = sonymon2_health;
     else if(sonymon_num == 3) showMaxHealth = sonymon3_health;
     
     waitForClick(enemyName, background_grass, enemy, sonymon_pic1, pointer);
     
     while(1)
     {       
             oslStartDrawing();
             oslDrawImage(background_grass);
             
             if(sonymon_num == 1)     healthBar->sizeX = (100 * (sonymon1_health / sonymon1_maxHealth));
             else if(sonymon_num == 2)healthBar->sizeX = (100 * (sonymon2_health / sonymon2_maxHealth));
             else if(sonymon_num == 3)healthBar->sizeX = (100 * (sonymon3_health / sonymon3_maxHealth));
             enemyHealthBar->sizeX = (100 * (enemyHealth / enemyShowMaxHealth));
             
             /*MAKE SURE TO DRAW SONYMON, BACKGROUND AND ENEMY BEFORE YOU DECLARE AI FUNCTIONS!!*/
             //draw player sonymon based on int sonymon_num
             if(sonymon_num == 1)      oslDrawImage(sonymon_pic1);
             else if(sonymon_num == 2) oslDrawImage(sonymon_pic2);
             else if(sonymon_num == 3) oslDrawImage(sonymon_pic3);
             
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
             controlEnemy.HANDLE_ENEMY(enemyHealth, enemyAttackPower, XP, enemyID, enemyType, enemyName, enemy, sonymon_pic1, background_grass);
             
             //handle player and player sonymon
             UPDATE(enemyHealth, enemyDefense, enemyType, enemy, background_grass);
     
             if(selecting && turn && enemyAlive)
             {
                oslDrawImage(fightBox);
                
                oslSetFont(battle_font);
                oslSetTextColor(BLACK);
                oslSetBkColor(RGBA(0,0,0,0));
                
                oslPrintf_xy(286, 216, "FIGHT");
                oslPrintf_xy(393, 216, "BAG");
                oslPrintf_xy(286, 245, "SNYMN");
                oslPrintf_xy(393, 245, "RUN");
                
                
                oslSetFont(verdana);
                oslSetTextColor(BLACK);
                oslSetBkColor(RGBA(0,0,0,0));
                if(sonymon_num == 1) oslPrintf_xy(18, 216, "What will %s do?", sonymon1_name);
                else if(sonymon_num == 2) oslPrintf_xy(18, 216, "What will %s do?", sonymon2_name);
                else if(sonymon_num == 3) oslPrintf_xy(18, 216, "What will %s do?", sonymon3_name);

                oslDrawImageSimple(battle_pointer);
                
             }
             
             if(selectMoves && turn && enemyAlive)
             {
                oslSetFont(battle_font);
                oslSetTextColor(BLACK);
                oslSetBkColor(RGBA(0,0,0,0));
             
                if(sonymon_num == 1){
                    oslPrintf_xy(18, 216, "%s" , sonymon1_moveName1);
                    oslPrintf_xy(153, 216, "%s",  sonymon1_moveName2);
                    oslPrintf_xy(18, 242, "%s", sonymon1_moveName3);
                    oslPrintf_xy(153, 242, "%s", sonymon1_moveName4);
                }
                else if(sonymon_num == 2){
                    oslPrintf_xy(18, 216, "%s" , sonymon2_moveName1);
                    oslPrintf_xy(153, 216, "%s",  sonymon2_moveName2);
                    oslPrintf_xy(18, 242, "%s", sonymon2_moveName3);
                    oslPrintf_xy(153, 242, "%s", sonymon2_moveName4);
                }
                else if(sonymon_num == 3){
                    oslPrintf_xy(18, 216, "%s" , sonymon3_moveName1);
                    oslPrintf_xy(153, 216, "%s",  sonymon3_moveName2);
                    oslPrintf_xy(18, 242, "%s", sonymon3_moveName3);
                    oslPrintf_xy(153, 242, "%s", sonymon3_moveName4);
                }
                oslDrawImageSimple(battle_selector);
             }
             
             oslSetFont(verdana);
             oslSetTextColor(BLACK);
             oslSetBkColor(RGBA(0,0,0,0));
             
             if(sonymon_num == 1)
             {
                 oslPrintf_xy(419, 160,"%i/%i", sonymon1_health, sonymon1_maxHealth);
                 oslPrintf_xy(256, 141, "%s  Lv:%i", sonymon1_name, sonymon1_level);
             }
             
             else if(sonymon_num == 2)
             {
                 oslPrintf_xy(419, 160,"%i/%i", sonymon2_health, sonymon2_maxHealth);
                 oslPrintf_xy(256, 141, "%s  Lv:%i", sonymon2_name, sonymon2_level);
             }
             
             else if(sonymon_num == 3) 
             {
                 oslPrintf_xy(419, 160,"%i/%i", sonymon3_health, sonymon3_maxHealth);
                 oslPrintf_xy(256, 141, "%s  Lv:%i", sonymon3_name, sonymon3_level);
             }
             
             oslPrintf_xy(178, 48, "%i/%i", enemyHealth, enemyShowMaxHealth);
             oslPrintf_xy(20, 25, "%s  Lv:%i", enemyName, enemyLevel);
             
             //display effectiveness of all the various moves
             if(EFFECT == NOT_EFFECTIVE)
             {
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
                     if(sonymon_num == 1)      oslDrawImage(sonymon_pic1);
                     else if(sonymon_num == 2) oslDrawImage(sonymon_pic2);
                     else if(sonymon_num == 3) oslDrawImage(sonymon_pic3);
                     
                     //draw enemy
                     oslDrawImageSimple(enemy);
              
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
     
     if(sonymon_num == 1) manipulateHealth = sonymon1_health;
     else if(sonymon_num == 2) manipulateHealth = sonymon2_health;
     else if(sonymon_num == 3) manipulateHealth = sonymon3_health;
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
     //postion all the images in the battle scene
     enemy->y = 30; 
     enemy->x = 315;
     sonymon_pic1->y = 95; 
     sonymon_pic1->x = 28; 
     
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
