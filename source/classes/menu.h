class MENU
{
      public:
             MENU();
             ~MENU();
             
             char CHECK_FREQUENCY();
             void OPEN_BAG( void );
             void OPEN_PARTY(bool inBattle, const char * playerName);
             void OPEN_RECORDS( void );
             void OPEN_PLAYER(const char * playerName);
             void SHOWSTATS(const int slot, const char * playerName);
             void pauseGame(const char * playerName);
             
      private:
}menu;

void MENU::pauseGame(const char * playerName)
{
     oslPlaySound(beep, 2);
     int pChoice = 1;
     bool inBattle = false;
     
     while(1)
     {
               oslReadKeys();
               if(osl_keys->pressed.circle || osl_keys->pressed.start) {oslPlaySound(beep, 2); break;}
               
		       else if(osl_keys->pressed.down){pChoice++; oslPlaySound(beep, 2);}
		       else if(osl_keys->pressed.up)  {pChoice--; oslPlaySound(beep, 2);}
		       if(pChoice > 7) pChoice = 1;
               if(pChoice < 1) pChoice = 7;
		
		       if(pChoice == 1)
               {
		         place(mini_rec_selector, 365,10);
		         if(osl_keys->pressed.cross || osl_keys->pressed.start) accessRecords = 1;              
	           }
        
               else if(pChoice == 2)
               {
			     place(mini_rec_selector, 365, 35);
			     if(osl_keys->pressed.cross || osl_keys->pressed.start) accessBag = 1;
		       }	
		
		       else if(pChoice == 3)
               {
			      place(mini_rec_selector, 365, 61);
			      if(osl_keys->pressed.cross || osl_keys->pressed.start) accessParty = 1;
               }
               
               else if(pChoice == 4)
               {
			      place(mini_rec_selector, 365, 87);
			      if(osl_keys->pressed.cross || osl_keys->pressed.start) accessPlayer = 1;
               }
               
               else if(pChoice == 5)
               {
			      place(mini_rec_selector, 365, 116);
			      if(osl_keys->pressed.cross || osl_keys->pressed.start) accessFrequency = 1;
               }
               
               else if(pChoice == 6)
               {
			      place(mini_rec_selector, 365, 139);
			      if(osl_keys->pressed.cross || osl_keys->pressed.start)
			        SAVEGAME(sonymon1_id, sonymon1_level, sonymon2_id, sonymon2_level, sonymon3_id, sonymon3_level);
               }
               
               else if(pChoice == 7)
               {
			      place(mini_rec_selector, 365, 163);
			      if(osl_keys->pressed.cross || osl_keys->pressed.start){quitGame = 1; EXIT_GAME = 1; break;}
               }
      
               oslStartDrawing();
               oslClearScreen(BLACK);    
               oslDrawImageSimple(zero);
		       
		       sb->x = 360;
		       sb->y = 0;
		       
		       oslDrawImageSimple(sb);
		       oslDrawImage(mini_rec_selector);
               oslEndDrawing();
               oslSyncFrame();
               
               if(accessBag)            OPEN_BAG();
               else if(accessParty)     OPEN_PARTY(inBattle, playerName);
               else if(accessFrequency) CHECK_FREQUENCY();
               else if(accessRecords)   OPEN_RECORDS();
               else if(accessPlayer)    OPEN_PLAYER(playerName);
     }       
     return;
}

void MENU::OPEN_PLAYER(const char * playerName)
{
     oslPlaySound(beep, 2);
     accessPlayer = 0;
     
     while(1)
     {
             oslReadKeys();
             if(osl_keys->pressed.circle) break;
             
             oslStartDrawing();
             oslClearScreen(BLACK);
             
             oslSetTextColor(WHITE);
             
             oslPrintf_xy(5, 5, "Player information:");
             oslPrintf_xy(5, 15, "Player name: %s", playerName);
             
             oslSetTextColor(GREEN);
             
             oslPrintf_xy(5, 25, "Money: $%f", money);
             
             oslSetTextColor(RED);
             
             if(sonymon_num == 1) oslPrintf_xy(5, 40, "Current sonymon equipped: %s", sonymon1_name);
             else if(sonymon_num == 2) oslPrintf_xy(5, 40, "Current sonymon equipped: %s", sonymon2_name);
             else if(sonymon_num == 3) oslPrintf_xy(5, 40, "Current sonymon equipped: %s", sonymon3_name);
             
             oslEndDrawing();
             oslSyncFrame();
             
     }
     
     oslPlaySound(beep, 2);
     return;
}

void MENU::OPEN_RECORDS( void )
{
     oslPlaySound(beep, 2);
     accessRecords = 0;
     unsigned i, j, TotalSeen;
     short posy = 0;
     short posx = 5;
     
     //create an object of the stats class
     STATS stats;
     
     //count all the sonymon we have seen
     for(i = 0; i < 99; i++) 
           if(SonymonSeen[i] != 0) TotalSeen++;
           
     while(1)
     {
          oslReadKeys();
          if(osl_keys->pressed.circle) {oslPlaySound(beep, 2); break;}
          
          oslStartDrawing();
          oslClearScreen(RGBA(0,0,0,0));
          oslSetFont(verdana);
          oslSetBkColor(RGBA(0,0,0,0));
          oslSetTextColor(WHITE);
          
          posy = 0;
          posx = 5;
         
          //display sonymon seen
          for(j = 0; j < 69; j++)
          {                
                if(SonymonSeen[j] == 0) {oslSetTextColor(WHITE); oslPrintf_xy(posx, posy, "#%d  -- --", j);}
                else
                { 
                    stats.setRecordName(SonymonSeen[j], RecordName); 
                    if(SonymonSeen[j] == SonymonOwned[j]) oslSetTextColor(YELLOW);
                    oslPrintf_xy(posx, posy, "#%d  %s", j, RecordName);
                }
                
                posy += 15;
                if(posy > 257) {posy = 0; posx += 128; }
          }
          
          //leave a key for the player to see
          oslSetTextColor(WHITE);
          oslPrintf_xy(375, 225, "White = seen");
          oslSetTextColor(YELLOW);
          oslPrintf_xy(350, 240, "Yellow = captured");
          
          oslEndDrawing();
          oslSyncFrame();
      }
     
     oslPlaySound(beep, 2);  
     oslStartDrawing();
     oslClearScreen(RGBA(0,0,0,0));    
     oslEndDrawing();
     oslSyncFrame();  
     
     return;
}

void MENU::SHOWSTATS(const int slot, const char * playerName = "default")
{
    oslSetFont(verdana);
    oslSetBkColor(RGBA(0,0,0,0));
    oslSetTextColor(WHITE);
    
    //create an object of the STATS class
    STATS create;
    
    /**************************************************************/
    //GET MOVES AND SET THEM EQUAL TO NEW VARIABLES
    
    int move1 = empty;
    int move2 = empty;
    int move3 = empty;
    int move4 = empty;
    const char * moveName1 = "-- --";
    const char * moveName2 = "-- --";
    const char * moveName3 = "-- --";
    const char * moveName4 = "-- --";
    bool showStats = true;
    bool showNature = false;
    
    if(slot == 1){
        move1 = sonymon1_move1;
        move2 = sonymon1_move2;
        move3 = sonymon1_move3;
        move4 = sonymon1_move4;
    }
    if(slot == 2){
        move1 = sonymon2_move1;
        move2 = sonymon2_move2;
        move3 = sonymon2_move3;
        move4 = sonymon2_move4;
    }
    if(slot == 3){
        move1 = sonymon3_move1;
        move2 = sonymon3_move2;
        move3 = sonymon3_move3;
        move4 = sonymon3_move4;
    }
    
    if(move1 == tackle)             moveName1 = "tackle";
    else if(move1 == slam)          moveName1 = "slam";
    else if(move1 == pound)         moveName1 = "pound";
    else if(move1 == jumpKick)      moveName1 = "jump kick";
    else if(move1 == waterGun)      moveName1 = "water gun";
    else if(move1 == blaze)         moveName1 = "blaze";
    else if(move1 == steroids)      moveName1 = "steroids";
    else if(move1 == uplink)        moveName1 = "uplink";
    else if(move1 == contaminate)   moveName1 = "contaminate";
    else if(move1 == leech)         moveName1 = "leech";
    else if(move1 == gust)          moveName1 = "gust";
    else if(move1 == clobber)       moveName1 = "clobber";
    
    if(move2 == tackle)             moveName2 = "tackle";
    else if(move2 == slam)          moveName2 = "slam";
    else if(move2 == pound)         moveName2 = "pound";
    else if(move2 == jumpKick)      moveName2 = "jump kick";
    else if(move2 == waterGun)      moveName2 = "water gun";
    else if(move2 == blaze)         moveName2 = "blaze";
    else if(move2 == steroids)      moveName2 = "steroids";
    else if(move2 == uplink)        moveName2 = "uplink";
    else if(move2 == contaminate)   moveName2 = "contaminate";
    else if(move2 == leech)         moveName2 = "leech";
    else if(move2 == gust)          moveName2 = "gust";
    else if(move2 == clobber)       moveName2 = "clobber";
    
    if(move3 == tackle)             moveName3 = "tackle";
    else if(move3 == slam)          moveName3 = "slam";
    else if(move3 == pound)         moveName3 = "pound";
    else if(move3 == jumpKick)      moveName3 = "jump kick";
    else if(move3 == waterGun)      moveName3 = "water gun";
    else if(move3 == blaze)         moveName3 = "blaze";
    else if(move3 == steroids)      moveName3 = "steroids";
    else if(move3 == uplink)        moveName3 = "uplink";
    else if(move3 == contaminate)   moveName3 = "contaminate";
    else if(move3 == leech)         moveName3 = "leech";
    else if(move3 == gust)          moveName3 = "gust";
    else if(move3 == clobber)       moveName3 = "clobber";
    
    if(move4 == tackle)             moveName4 = "tackle";
    else if(move4 == slam)          moveName4 = "slam";
    else if(move4 == pound)         moveName4 = "pound";
    else if(move4 == jumpKick)      moveName4 = "jump kick";
    else if(move4 == waterGun)      moveName4 = "water gun";
    else if(move4 == blaze)         moveName4 = "blaze";
    else if(move4 == steroids)      moveName4 = "steroids";
    else if(move4 == uplink)        moveName4 = "uplink";
    else if(move4 == contaminate)   moveName4= "contaminate";
    else if(move4 == leech)         moveName4 = "leech";
    else if(move4 == gust)          moveName4 = "gust";
    else if(move4 == clobber)       moveName4 = "clobber";
    /**************************************************************/
    
    int id = 1;
    if(slot == 1) id = sonymon1_id;
    else if(slot == 2) id = sonymon2_id;
    else if(slot == 3) id = sonymon3_id;
    else {oslWarning("Incorrect parameter passed to void MENU::SHOWSTATS(const int slot)!! Exiting function to avoid a crash!"); return;}
    
    /* Now lets grab the description of this sonymon from a method in the STATS class */
    char * description = create.Description(id);
    description[200] = '\0';
    int manip = 0;
    
    //create a copy of the sonymon image
    OSL_IMAGE * TempImage;
    TempImage = create.makeImage(id);
    create.playRoar(id);
    if(!TempImage) {oslWarning("ERROR! Failed to assign a value to OSL_IMAGE * TempImage Exiting function to avoid crash!"); return;}
    TempImage->stretchX *= 2;
    TempImage->stretchY *= 2;
    TempImage->x = 10;
    TempImage->y = 90;
    
    for(;;)
    {
        oslReadKeys();
        if(osl_keys->pressed.circle){oslPlaySound(beep, 2); break;}
        else if(osl_keys->pressed.triangle){create.playRoar(id);}
        else if(osl_keys->pressed.right && showStats == true){oslPlaySound(beep, 2); showStats = false; showNature = true;}
        else if(osl_keys->pressed.left && showNature == true){oslPlaySound(beep, 2); showNature = false; showStats = true;}
        
        oslStartDrawing();
        oslClearScreen(BLACK);
        
        //draw sonymon 1 stats
        if(slot == 1)
        {   
            oslSetTextColor(WHITE);
            oslPrintf_xy(5, 5, "sonymon stats: triangle=entrance sound & left/right=toggle info");
            oslSetTextColor(RED);
            oslPrintf_xy(5, 20, "%s Lv:%d", sonymon1_name, sonymon1_level);
            oslSetTextColor(WHITE);
            oslPrintf_xy(5, 35, "original owner: %s", playerName);
            
            if(showStats)
            {
               oslSetTextColor(WHITE);
               oslPrintf_xy(350, 130, "HP: ");
               oslPrintf_xy(380, 130, "%d/%d", sonymon1_health, sonymon1_maxHealth);
               oslPrintf_xy(350, 145, "Exp: ");
               oslPrintf_xy(380, 145, "%d/%d", sonymon1_xp, sonymon1_max_xp);
               oslPrintf_xy(350, 160, "Moves learned:");
               oslPrintf_xy(370, 175, "%s", moveName1);
               oslPrintf_xy(370, 190, "%s", moveName2);
               oslPrintf_xy(370, 205, "%s", moveName3);
               oslPrintf_xy(370, 220, "%s", moveName4);
            }
            if(showNature)
            {
                oslSetTextColor(WHITE);
                
                manip = 0;
                for(int i = 0; i < 35; i++){
                    manip+=8; oslPrintf_xy((manip + 200), 170, "%c", description[i]);
                }
                manip = 0;
                for(int i = 35; i < 71; i++){
                    manip+=8; oslPrintf_xy((manip + 200), 180, "%c", description[i]);
                } 
                manip = 0;
                for(int i = 71; i < 107; i++){
                    manip+=8; oslPrintf_xy((manip + 200), 190, "%c", description[i]);
                }
                manip = 0;
                for(int i = 107; i < 143; i++){
                    manip+=8; oslPrintf_xy((manip + 210), 200, "%c", description[i]);
                }
                manip = 0;
                for(int i = 143; i < 179; i++){
                    manip+=8; oslPrintf_xy((manip + 220), 210, "%c", description[i]);
                }
                manip = 0;
                for(unsigned i = 179; (i < sizeof(description)); i++){
                    manip+=8; oslPrintf_xy((manip + 230), 220, "%c", description[i]);
                }
           }
        }
        //draw sonymon 2 stats
        else if(slot == 2){
            oslPrintf_xy(TempImage->stretchX + 20, TempImage->stretchY - 10, "%s", sonymon2_name);
        }
        
        //draw sonymon 3 stats
        else if(slot == 3){
            oslPrintf_xy(TempImage->stretchX + 20, TempImage->stretchY - 10, "%s", sonymon3_name);
        }
        
        
        oslDrawImage(TempImage);
        oslEndDrawing();
        oslSyncFrame();
    }
    
    //free memory
    if(TempImage != NULL) {oslDeleteImage(TempImage); TempImage = NULL;}
    
    return;
}

void MENU::OPEN_PARTY(bool inBattle, const char * playerName = "default")
{
     oslPlaySound(beep, 2);
     accessParty = 0;
     
     unsigned gab = 0;
     int choice = 1;
     int selecting = 0;
     int sonymon1_selected = 0;
     int sonymon2_selected = 0;
     int sonymon3_selected = 0;
     int sonymon4_selected = 0;
     int sonymon5_selected = 0;
     
     OSL_IMAGE * party, *small_h, *big_h, *qbox, *sbox;
     party = oslLoadImageFile((char*)"img/data/p.png", OSL_IN_RAM, OSL_PF_5551);
     small_h = oslLoadImageFile((char*)"img/data/sp.png", OSL_IN_RAM, OSL_PF_5551);
     big_h = oslLoadImageFile((char*)"img/data/bp.png", OSL_IN_RAM, OSL_PF_5551);
     qbox = oslLoadImageFile((char*)"img/data/qb.png", OSL_IN_RAM, OSL_PF_5551);
     sbox = oslLoadImageFile((char*)"img/data/sbox.png", OSL_IN_RAM, OSL_PF_5551);
     if(!party || !big_h || !small_h || !qbox || !sbox)
         MISSING_IMG_FILES(1);
     
     party->x = 0;      party->y = 0;
     small_h->x = 189;  small_h->y = 13;
     big_h->x = 28;     big_h->y = 14;
     qbox->x = 47;      qbox->y = 160;
     sbox->x = 47;      sbox->y = 160;
     
     //init stats class
     STATS stats;
     
     //get quick snapshots of each of the player's sonymon
     temp1 = NULL; temp2 = NULL; temp3 = NULL; //just in case
     
     if(currentSonymon == 1){
                       stats.setPartyImage(1, sonymon1_id);
     }
     else if(currentSonymon == 2){
                       stats.setPartyImage(1, sonymon1_id);
                       stats.setPartyImage(2, sonymon2_id);
     }
     else if(currentSonymon == 3){
                       stats.setPartyImage(1, sonymon1_id);
                       stats.setPartyImage(2, sonymon2_id);
                       stats.setPartyImage(3, sonymon3_id);
     }
     else oslWarning("Error getting snapshots of player sonymon!!");
     if(temp1 == NULL) {oslWarning("Error! To avoid a crash, exiting party function! Temp1 is NULL!!"); return;}
     
     //now shrink and place each snapshot
     if(temp1 != NULL){temp1->stretchX /= 2; temp1->stretchY /= 2; temp1->x = 38; temp1->y = 20;}
     if(temp2 != NULL){temp2->stretchX /= 2; temp2->stretchY /= 2; temp2->x = 213; temp2->y = 26;}
     if(temp3 != NULL){temp3->stretchX /= 2; temp3->stretchY /= 2; temp3->x = 213; temp3->y = 86;}
     
     while(1)
     {
        //take player input
        oslReadKeys();
        if(osl_keys->pressed.up && selecting != 1)         {if(choice > 2) {oslPlaySound(beep, 2); choice--;}}
        else if(osl_keys->pressed.down && selecting != 1)  {if(choice < 5) {oslPlaySound(beep, 2); choice++;}}
        else if(osl_keys->pressed.left && selecting != 1)  {oslPlaySound(beep, 2); choice = 1;}
        else if(osl_keys->pressed.right && selecting != 1) {if(choice == 1) {oslPlaySound(beep, 2); choice = 2;}}
        
        else if(osl_keys->pressed.circle && selecting != 1){oslPlaySound(beep, 2); break;}
        else if(osl_keys->pressed.circle && selecting) {oslPlaySound(beep, 2); selecting = 0;}
        
        else if(osl_keys->pressed.cross && selecting != 1){
            if(sonymon1_selected)     {if(temp1 != NULL){selecting = 1; oslPlaySound(beep, 2);  }}
            else if(sonymon2_selected){if(temp2 != NULL){selecting = 1; oslPlaySound(beep, 2);  }}
            else if(sonymon3_selected){if(temp3 != NULL){selecting = 1; oslPlaySound(beep, 2);  }}
        }
        
        else if(osl_keys->pressed.cross && selecting && inBattle == false)
        {
            if(sonymon1_selected)      {SHOWSTATS(1,playerName); selecting = 0;}
            else if(sonymon2_selected) {SHOWSTATS(2, playerName); selecting = 0;}
            else if(sonymon3_selected) {SHOWSTATS(3, playerName); selecting = 0;}
        }
        else if(osl_keys->pressed.cross && selecting && inBattle == true)
        {
            //switch sonymon
            oslPlaySound(beep, 2);
            selecting = 0;
        }
        
        if(choice == 1){
                  sonymon1_selected = 1; 
                  sonymon2_selected = 0; 
                  sonymon3_selected = 0; 
                  sonymon4_selected = 0; 
                  sonymon5_selected = 0;
        }
        else if(choice == 2){
                  sonymon1_selected = 0; 
                  sonymon2_selected = 1; 
                  sonymon3_selected = 0; 
                  sonymon4_selected = 0; 
                  sonymon5_selected = 0;
                  small_h->x = 189; small_h->y = 14;
        }
        else if(choice == 3){
                  sonymon1_selected = 0; 
                  sonymon2_selected = 0; 
                  sonymon3_selected = 1; 
                  sonymon4_selected = 0; 
                  sonymon5_selected = 0;
                  small_h->x = 189; small_h->y = 74;
        }
        else if(choice == 4){
                  sonymon1_selected = 0; 
                  sonymon2_selected = 0; 
                  sonymon3_selected = 0; 
                  sonymon4_selected = 1; 
                  sonymon5_selected = 0;
                  small_h->x = 189; small_h->y = 135;
        }
        else if(choice == 5){
                  sonymon1_selected = 0; 
                  sonymon2_selected = 0; 
                  sonymon3_selected = 0; 
                  sonymon4_selected = 0; 
                  sonymon5_selected = 1;
                  small_h->x = 189; small_h->y = 198;
        }
        
        oslStartDrawing();
        oslClearScreen(BLACK);
        oslDrawImage(party);
        if(choice == 1) oslDrawImageSimple(big_h);
        if(choice == 2 || choice == 3 || choice == 4 || choice == 5) oslDrawImageSimple(small_h);
        if(selecting && inBattle == false) oslDrawImageSimple(qbox);
        if(selecting && inBattle == true)  oslDrawImageSimple(sbox);
        
        oslSetFont(verdana);
        oslSetBkColor(RGBA(0,0,0,0));
        oslSetTextColor(WHITE);
        
        if(currentSonymon == 1){
                          oslDrawImage(temp1);
                          oslPrintf_xy(33, 68, "%s Lv %d", sonymon1_name, sonymon1_level);
                          oslPrintf_xy(33, 83, "HP: ");
                          
                          long countHealth = sonymon1_maxHealth;
                          long count2Health = sonymon1_maxHealth / 2;
                          
                          countHealth /= 2; 
                              if(countHealth >= sonymon1_health) oslSetTextColor(GRAY);
                              
                          countHealth = sonymon1_maxHealth;
                          
                          countHealth /= 4;
                              if(countHealth >= sonymon1_health) oslSetTextColor(RED);
                              
                          countHealth = sonymon1_maxHealth;
                              if(sonymon1_health <= countHealth && sonymon1_health > count2Health) oslSetTextColor(GREEN);
                          
                          oslPrintf_xy(63, 83, "%d/%d", sonymon1_health, sonymon1_maxHealth);
                          if(sonymon1_selected && temp1 != NULL) {gab++; if(gab > 1) {temp1->y++; gab = 0;}}
                          if(temp1->y > 30) temp1->y = 20;
        }
        
        oslEndDrawing();
        oslSyncFrame();
     }
     
     //free memory in RAM
     if(party != NULL){oslDeleteImage(party); party = NULL;}
     if(small_h != NULL){oslDeleteImage(small_h); small_h = NULL;}
     if(big_h != NULL){oslDeleteImage(big_h); big_h = NULL;}
     if(sbox != NULL){oslDeleteImage(sbox); sbox = NULL;}
     if(qbox != NULL){oslDeleteImage(qbox); qbox = NULL;}
     if(temp1 != NULL){oslDeleteImage(temp1); temp1 = NULL;}
     if(temp2 != NULL){oslDeleteImage(temp2); temp2 = NULL;}
     if(temp3 != NULL){oslDeleteImage(temp3); temp3 = NULL;}
     
     return;
}

void MENU::OPEN_BAG( void )
{
     oslPlaySound(beep, 2);
     
     //init ITEM class
     ITEM items;
     items.Use(1);
     
     accessBag = 0; //if this is not set back to zero the player will be trapped in an endless pause of death!!!!
     oslPlaySound(beep, 2); 
     oslStartDrawing();
     oslClearScreen(RGBA(0,0,0,0));    
     oslEndDrawing();
     oslSyncFrame();  
     
     return;
}

char MENU::CHECK_FREQUENCY() //THIS FUNCTION NEEDS EXTREME WORK!!!!!
{
     oslPlaySound(beep, 2);
     
     while(1)
     {
          oslReadKeys();
          if(osl_keys->pressed.circle || osl_keys->pressed.select) break;
          oslStartDrawing();
          oslSetFont(verdana);
          oslSetBkColor(RGBA(0,0,0,0));
          oslSetTextColor(WHITE);
          oslPrintf_xy(5,5,"RADIATION PRESENT: %s", radiation);
          oslPrintf_xy(5,15,"DEVICE FREQUENCY %s", Hz);
          oslPrintf_xy(5, 35,"EXPOSURE COUNT: %i", exposure);
          oslPrintf_xy(5, 45,"EXPOSURE FATAL IN %i COUNTS", manipExposure);     
          oslEndDrawing();
          oslSyncFrame();
     }
     
     oslPlaySound(beep, 2);  
     accessFrequency = 0;   
     oslStartDrawing();
     oslClearScreen(RGBA(0,0,0,0));    
     oslEndDrawing();
     oslSyncFrame();    
                                               
     return * Hz;
}

MENU::MENU()
{
     return;
}

MENU::~MENU()
{
     return;
}
