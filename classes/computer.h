#define NormalRotation 1
#define FastRotation 2
#define Still 0

class COMPUTER : public SONYMON {
      public: 
             COMPUTER();
             ~COMPUTER();
             
             //behaviors
             void ComputerAnimate();
             void UpdateAI(const char * playerName);
             void UpdateAIMap(OSL_MAP * map, const char * playerName);
             
             //properites
             const char * name;
             const char * greetMessage;
             const char * winMessage;
             const char * loseMessage;
             const char * normalMessage;
             IMAGE * image;
             int numOfSonymon;
             int posx;
             int posy;
             int AI;
             int reward;
             bool trainer;
             
             //sonymon
             SONYMON trainerSonymon1;
             SONYMON trainerSonymon2;
             SONYMON trainerSonymon3;
             SONYMON trainerSonymon4;
             SONYMON trainerSonymon5;
             
      private:
            int carry;
            int position;
            int march;
            int manip;
            int manipl;
            
            void BattleTrainer(const char * playerName);
            void MessageBoxMap(const char * message, OSL_MAP * map);
            void waitForTrainer(OSL_IMAGE *background, OSL_IMAGE *player, OSL_IMAGE *pointer);
              
};


void COMPUTER::UpdateAIMap(OSL_MAP * map, const char * playerName)
{
     image->x = posx - map->scrollX;
     image->y = posy - map->scrollY;
     
     //basic AI movement
     if(AI == 0) {
          carry++;
          if(carry < 0 ) carry = 0;
          if(carry > 0) position = UP;
          if(carry > 120) position = LEFT;
          if(carry > 240) position = DOWN;
          if(carry > 360) position = RIGHT;
          if(carry > 480) carry = 0;
     }
     
     else if(AI == 1) {
          carry++;
          if(carry < 0 ) carry = 0;
          if(carry > 0) position = UP;
          if(carry > 60) position = LEFT;
          if(carry > 120) position = DOWN;
          if(carry > 180) position = RIGHT;
          if(carry > 240) carry = 0;
     }
     
     else if(AI == 2){
          carry++;
          if(carry < 0 ) carry = 0;
          if(carry > 0) position = UP;
          if(carry > 20) position = LEFT;
          if(carry > 40) position = DOWN;
          if(carry > 60) position = RIGHT;
          if(carry > 80) carry = 0;
     }
     
     int contact = collision(player.image,player.image->x, player.image->y,image,image->x,image->y );
     
     if(contact && player.position == RIGHT)     
     {
                player.image->x = image->x - 23;
                oslSetImageTileSize(image,(1 * 23),LEFT,23,32);
                
                if(trainer){
                  MessageBoxMap(greetMessage, map);
                  BattleTrainer(playerName);
                  MessageBoxMap(loseMessage, map);
                }
                else MessageBoxMap(normalMessage, map);
     }
     else if(contact && player.position == LEFT) 
     {
                player.image->x = image->x + 23;
                oslSetImageTileSize(image,(1 * 23),RIGHT,23,32);
                
                if(trainer){
                  MessageBoxMap(greetMessage, map);
                  BattleTrainer(playerName);
                  MessageBoxMap(loseMessage, map);
                }
                else MessageBoxMap(normalMessage, map);
     }
     
     if(contact && player.position == UP)   
     {
                player.image->y = image->y + 34; 
                oslSetImageTileSize(image,(1 * 23),DOWN,23,32);
         
                if(trainer){
                  MessageBoxMap(greetMessage, map);
                  BattleTrainer(playerName);
                  MessageBoxMap(loseMessage, map);
                }
                else MessageBoxMap(normalMessage, map);
     }
     else if(contact && player.position == DOWN) 
     {
                player.image->y = image->y - 34; 
                oslSetImageTileSize(image,(1 * 23),UP,23,32);

                if(trainer){
                  MessageBoxMap(greetMessage, map);
                  BattleTrainer(playerName);
                  MessageBoxMap(loseMessage, map);
                }
                else MessageBoxMap(normalMessage, map);
     }
     
     if(contact && AI == 42){}
                
     
     return;
}


void COMPUTER::UpdateAI(const char * playerName)
{     
     image->x = posx;
     image->y = posy;
     
     //basic AI movement
     if(AI == 0)
     {
          carry++;
          if(carry < 0 ) carry = 0;
          if(carry > 0) position = UP;
          if(carry > 120) position = LEFT;
          if(carry > 240) position = DOWN;
          if(carry > 360) position = RIGHT;
          if(carry > 480) carry = 0;
     }
     
     else if(AI == 1)
     {
          carry++;
          if(carry < 0 ) carry = 0;
          if(carry > 0) position = UP;
          if(carry > 60) position = LEFT;
          if(carry > 120) position = DOWN;
          if(carry > 180) position = RIGHT;
          if(carry > 240) carry = 0;
     }
     
     else if(AI == 2)
     {
          carry++;
          if(carry < 0 ) carry = 0;
          if(carry > 0) position = UP;
          if(carry > 20) position = LEFT;
          if(carry > 40) position = DOWN;
          if(carry > 60) position = RIGHT;
          if(carry > 80) carry = 0;
     }
     
     int contact = collision(player.image,player.image->x, player.image->y,image,image->x,image->y );
     
     if(contact && player.position == RIGHT)     
     {
                player.image->x = image->x - 23;
                oslSetImageTileSize(image,(1 * 23),LEFT,23,32);
     }
     else if(contact && player.position == LEFT) 
     {
                player.image->x = image->x + 23;
                oslSetImageTileSize(image,(1 * 23),RIGHT,23,32);
     }
     
     if(contact && player.position == UP)   
     {
                player.image->y = image->y + 34; 
                oslSetImageTileSize(image,(1 * 23),DOWN,23,32);
     }
     else if(contact && player.position == DOWN) 
     {
                player.image->y = image->y - 34; 
                oslSetImageTileSize(image,(1 * 23),UP,23,32);
     }
     
     return;
}

void COMPUTER::MessageBoxMap(const char * message, OSL_MAP * map)
{
     if(map == NULL){oslWarning("Error! Map data sent to messagebox function is equal to NULL!!! Exiting function to avoid crash!!"); return;}
     
     int count, posx;
     count = sizeof message;
     posx = 5;
     DialogBox->x = 9;
     DialogBox->y = 200;
     pointer->x = 452;
     pointer->y = 236;
     
     for(pointer->y = 236; pointer->y < 252; pointer->y++)
     {
             if(pointer->y > 250) pointer->y = 236;
             
             oslReadKeys();
             if(osl_keys->pressed.cross)
             { oslPlaySound(beep, 2); break; }
             
             oslStartDrawing();
             oslDrawMapSimple(map);
             oslDrawImage(image);
             oslDrawImage(player.image);
             oslDrawImage(DialogBox);
             oslDrawImage(pointer);
             oslSetTextColor(BLACK);
             oslSetBkColor(RGBA(0,0,0,0));
             oslSetFont(verdana);
             oslPrintf_xy(17, 208, "%s: %s", name, message);
             oslEndDrawing();
             oslSyncFrame();
     }
             
     return;
}

void COMPUTER::ComputerAnimate()
{	
    if(!image) oslFatalError("ERROR! IMAGE IS EQUAL TO NULL! FOUND IN COMPUTER::ComputerAnimate()!!");
    
    if(AI == 0)
          oslSetImageTileSize(image,(0 * 23),position,23,32);
    
    else if(AI == 1)
    {
         manipl++;
         if(manipl > 11) {march++; manipl = 0;}
         oslSetImageTileSize(image,(march * 23),position,23,32);
         if (march == 2) march = 0;
    }
    
    else if(AI == 2)
    {
         manipl++;
         if(manipl > 7) {march++; manipl = 0;}
         oslSetImageTileSize(image,(march * 23),position,23,32);
         if (march == 2) march = 0;
    }
    
    else oslFatalError("Failed to apply AI to computer!!!\nfound in function COMPUTER::ComputerAnimate();!!!");
    
    oslDrawImage(image);
    
    return;
}

//wild-sonymon battle function
void COMPUTER::BattleTrainer(const char * playerName)
{    
     //battle intro
     oslPauseSound(gameMusic, -1); oslPauseSound(center_music, -1);
     oslPlaySound(boss_intro, 3);  oslSetSoundLoop(boss_intro, 1);
     
     //load trainer sonymon image
     trainerSonymon1.image = stats.makeImage(trainerSonymon1.id);
     positionScreenItems(trainerSonymon1.image);
     
     int j = 0;
     for(int i = 0; i < 100; i++)
     {          
           oslStartDrawing();
           j++;
           if(j > 5)oslClearScreen(BLACK);
           if(j > 10)oslClearScreen(WHITE);
           if(j > 15)j = 0;
           
           oslDrawImageSimple(player.image);
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
     
     
     unsigned long squareOne = 0;
     unsigned long squareTwo = 272;
     unsigned long moveSquare = 136;
     unsigned long moveSquare2 = 136;
     int showMaxHealth = 1;
     int enemyShowMaxHealth = 1;
     
     //load health bar variables
     IMAGE *healthBar, *enemyHealthBar;
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
     oslStopSound(boss_intro); oslPlaySound(boss_battle, 3); oslSetSoundLoop(boss_battle, 1);
     
     //initiate STATS class
     STATS stats;
     
     //set enemy stats all based on enemyLevel and enemyType!!! :D
     stats.XPGain(trainerSonymon1.xp, trainerSonymon1.id, trainerSonymon1.level);
     stats.setHealth(trainerSonymon1.health, trainerSonymon1.id, trainerSonymon1.level);
     stats.setAttackPower(trainerSonymon1.attack, trainerSonymon1.id, trainerSonymon1.level);
     stats.setDefense(trainerSonymon1.defense, trainerSonymon1.id, trainerSonymon1.level);
     stats.setType(trainerSonymon1.type, trainerSonymon1.id);
     stats.setEnemyMoves(trainerSonymon1.id, trainerSonymon1.level);
     enemyShowMaxHealth = trainerSonymon1.health;
     
     if(sonymon_num == 1)      showMaxHealth = sonymon1.health;
     else if(sonymon_num == 2) showMaxHealth = sonymon2.health;
     else if(sonymon_num == 3) showMaxHealth = sonymon3.health;
     
     waitForTrainer(background_grass, sonymon1.image, pointer);
     trainerSonymon1.name = stats.setEnemyType(trainerSonymon1.id, trainerSonymon1.image);
     
     while(1)
     {       
             oslStartDrawing();
             oslDrawImage(background_grass);
             
             if(sonymon_num == 1)     healthBar->sizeX = (100 * (sonymon1.health / sonymon1.maxHealth));
             else if(sonymon_num == 2)healthBar->sizeX = (100 * (sonymon2.health / sonymon2.maxHealth));
             else if(sonymon_num == 3)healthBar->sizeX = (100 * (sonymon3.health / sonymon3.maxHealth));
             enemyHealthBar->sizeX = (100 * (trainerSonymon1.health / enemyShowMaxHealth));
             
             /*MAKE SURE TO DRAW SONYMON, BACKGROUND AND ENEMY BEFORE YOU DECLARE AI FUNCTIONS!!*/
             //draw player sonymon based on int sonymon_num
             if(sonymon_num == 1)      oslDrawImage(sonymon1.image);
             else if(sonymon_num == 2) oslDrawImage(sonymon2.image);
             else if(sonymon_num == 3) oslDrawImage(sonymon3.image);
             
             //draw enemy as long as the enemy is still alive
             if(enemyAlive != 0 ) oslDrawImage(trainerSonymon1.image);
             
             //draw util boxes
             oslDrawImage(messageBox);
             oslDrawImage(dialog_box);
             oslDrawImage(xp_bar);
             oslDrawImage(enemy_dialog_box);
             oslDrawImage(healthBar);
             oslDrawImage(enemyHealthBar);
             
             //handle enemy and player health bars
             healthBar = DrawCharacterTextBox(healthBar);
             enemyHealthBar = DrawEnemyTextBox(trainerSonymon1.health, enemyHealthBar);
             
             //handle the first sonymon the trainer has
             controlEnemy.HANDLE_ENEMY(trainerSonymon1.health, trainerSonymon1.attack, trainerSonymon1.xp, trainerSonymon1.id, 
             trainerSonymon1.type, trainerSonymon1.name, trainerSonymon1.image, sonymon1.image, background_grass);
             
             //handle player and player sonymon
             UPDATE(trainerSonymon1.health, trainerSonymon1.defense, trainerSonymon1.type, trainerSonymon1.image, background_grass);
     
             if(selecting && turn && enemyAlive)
             {
                oslDrawImage(fightBox);
                
                oslSetFont(bold);
                oslSetTextColor(BLACK);
                oslSetBkColor(RGBA(0,0,0,0));
                
                oslPrintf_xy(286, 226, "FIGHT");
                oslPrintf_xy(393, 226, "BAG");
                oslPrintf_xy(286, 255, "SNYMN");
                oslPrintf_xy(393, 255, "RUN");
                
                
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
                    oslPrintf_xy(18, 252, "%s", sonymon1.moveName3);
                    oslPrintf_xy(153, 252, "%s", sonymon1.moveName4);
                }
                else if(sonymon_num == 2){
                    oslPrintf_xy(18, 226, "%s" , sonymon2.moveName1);
                    oslPrintf_xy(153, 226, "%s",  sonymon2.moveName2);
                    oslPrintf_xy(18, 252, "%s", sonymon2.moveName3);
                    oslPrintf_xy(153, 252, "%s", sonymon2.moveName4);
                }
                else if(sonymon_num == 3){
                    oslPrintf_xy(18, 226, "%s" , sonymon3.moveName1);
                    oslPrintf_xy(153, 226, "%s",  sonymon3.moveName2);
                    oslPrintf_xy(18, 252, "%s", sonymon3.moveName3);
                    oslPrintf_xy(153, 252, "%s", sonymon3.moveName4);
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
             
             oslPrintf_xy(178, 48, "%i/%i", trainerSonymon1.health, enemyShowMaxHealth);
             oslPrintf_xy(20, 25, "%s  Lv:%i", trainerSonymon1.name, trainerSonymon1.level);
             
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
                     oslDrawImageSimple(trainerSonymon1.image);
                  
                     oslSetFont(normal);
                     oslDrawImage(messageBox);
                     oslDrawImage(pointer);
                     oslSetFont(verdana);
                     oslSetBkColor(RGBA(0,0,0,0));
                     oslSetTextColor(BLACK);
                     oslPrintf_xy(18, 226, "%s cannot run away from %s in a battle!", playerName, name);
                     oslEndDrawing();
                     oslSyncFrame();
                     ran = 0;
                   }
             }
     
             if(enemyAlive == 0) break;
     }
     
     //adjust sound/musc
     hWait;
     oslStopSound(boss_battle);
     oslPauseSound(gameMusic, 0);
     oslPauseSound(center_music, 0);
     
     //delete health bars and set pointers to NULL
     oslDeleteImage(healthBar);
     oslDeleteImage(enemyHealthBar);
     healthBar = NULL;
     enemyHealthBar = NULL;
     
     /******* NOW THE PLAYER HAS "SEEN" THE SONYMON, LET"S ADD IT TO THE RECORDS *********/
     SonymonSeen[trainerSonymon1.id] = trainerSonymon1.id;
     
     //free ram
     oslDeleteImage(trainerSonymon1.image);
     
     return;
}

void COMPUTER::waitForTrainer(OSL_IMAGE *background, OSL_IMAGE *player, OSL_IMAGE *pointer)
{            
     IMAGE * trainer = oslLoadImageFilePNG((char*)"img/sprites/guy1Up.png", OSL_IN_RAM, OSL_PF_5551);
     trainer->stretchX *= 1.6;
     trainer->stretchY *= 1.6;
     trainer->x = 310;
     trainer->y = 8;
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
             oslDrawImageSimple(trainer);
             oslDrawImage(messageBox);
             oslDrawImage(pointer);
             oslSetFont(verdana);
             oslSetBkColor(RGBA(0,0,0,0));
             oslSetTextColor(BLACK);
             oslPrintf_xy(18, 226, "%s wants to battle!", name);
             oslEndDrawing();
             oslSyncFrame();
     }
     
     return;
}

COMPUTER::COMPUTER()
{
     numOfSonymon = 0;
     posx = 0;
     posy = 0;
     carry = 0;
     position = DOWN;
     march = 0;
     manip = 0;
     manipl = 0;
     AI = Still;
     trainer = false;
     reward = 1;
     
     trainerSonymon1.id = 1;
     create.ASSIGN_SONYMON(1, trainerSonymon1.id, 4);
     
     return;
}
COMPUTER::~COMPUTER()
{
     if(image != NULL){oslDeleteImage(image); image = NULL;}
     
     return;
}
