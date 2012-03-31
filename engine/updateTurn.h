class UPDATE_TURN
{
      public:       
             UPDATE_TURN();
             ~UPDATE_TURN();
             
             void Stats();
             void Bounce();
             void Options();
             void Select();
             void UsedMove(int &enemyHealth, const int enemyDefense, const int enemyRealType, OSL_IMAGE * enemy, OSL_IMAGE * background);
             
      private:
              OSL_IMAGE * sonymon;
              const char * name;
              const char * moveName1;
              const char * moveName2;
              const char * moveName3;
              const char * moveName4;
     
              int move1;
              int move2;
              int move3;
              int move4;
              int usedFirstMove;
              int usedSecondMove;
              int usedThirdMove;
              int usedFourthMove;
              int power;
              int attack;
};

void UPDATE_TURN::UsedMove(int &enemyHealth, const int enemyDefense, const int enemyRealType, OSL_IMAGE * enemy, OSL_IMAGE * background)
{
     //if the player attacked the enemy then adjust basic variables
     if(usedFirstMove || usedSecondMove || usedThirdMove || usedFourthMove){
         selectMoves = 0;
         selecting = 1;
         turn = 2;
         ClearMessageBox();
     }
     
     //now apply move values and attack the enemy!!!! >:)                
     if(usedFirstMove)
     {
         animate.animateMovePlayer(move1, name, sonymon, enemy, background);

         attack = create.ApplyAttackValue(move1, power);
         create.ApplyTypes(move1, attack, enemyRealType, EFFECT);
         animate.flashHurtEnemy(sonymon, enemy, background);
         attack -= enemyDefense;
         if(attack <= 0) attack = 1; 
             
         enemyHealth -= attack;
     }
     if(usedSecondMove)
     {
         animate.animateMovePlayer(move2, name, sonymon, enemy, background);
         
         attack = create.ApplyAttackValue(move2, power);
         create.ApplyTypes(move2, attack, enemyRealType, EFFECT);
         animate.flashHurtEnemy(sonymon, enemy, background);
         attack -= enemyDefense;
         if(attack <= 0) attack = 1; 
             
         enemyHealth -= attack;
     }
     if(usedThirdMove)
     {
         animate.animateMovePlayer(move3, name, sonymon, enemy, background);
         
         attack = create.ApplyAttackValue(move3, power);
         create.ApplyTypes(move3, attack, enemyRealType, EFFECT);
         animate.flashHurtEnemy(sonymon, enemy, background);
         attack -= enemyDefense;
         if(attack <= 0) attack = 1; 
             
         enemyHealth -= attack;
     }
     if(usedFourthMove)
     { 
         animate.animateMovePlayer(move4, name, sonymon, enemy, background);
         
         attack = create.ApplyAttackValue(move4, power);
         create.ApplyTypes(move4, attack, enemyRealType, EFFECT);
         animate.flashHurtEnemy(sonymon, enemy, background);
         attack -= enemyDefense;
         if(attack <= 0) attack = 1; 
             
         enemyHealth -= attack;
     }
     
     return;
}

void UPDATE_TURN::Select()
{
     //selecting options
     if(selecting && turn)
     {
     //handle options/moves menu selector
     if(osl_keys->pressed.left){
        oslPlaySound(beep, 2); 
        battleChoice++;
     }
     
     else if(osl_keys->pressed.right){
           oslPlaySound(beep, 2); 
           battleChoice--; 
     }
     
     else if(osl_keys->pressed.up) 
     {
       if(battleManip != 1)
       {oslPlaySound(beep, 2); battleManip = 1;}
     }
     
     else if(osl_keys->pressed.down) 
     {
       if(battleManip != 2)
       {oslPlaySound(beep, 2); battleManip = 2;}
     }
     
     if(battleChoice > 2) battleChoice = 1;
     if(battleChoice < 1) battleChoice = 2;
     
     if(battleChoice == 1 && battleManip == 1)
     {FIGHT = HIGHLIGHTED; BAG = IGNORED; FLEE = IGNORED; SNYMN = IGNORED; place(battle_pointer, 275, 225); }
          
     else if(battleChoice == 2 && battleManip == 1)
     {BAG = HIGHLIGHTED; FIGHT = IGNORED; SNYMN = IGNORED; FLEE = IGNORED; place(battle_pointer, 382, 225);}
     
     else if(battleChoice == 1 && battleManip == 2)
     {SNYMN = HIGHLIGHTED; FIGHT = IGNORED; FLEE = IGNORED; BAG = IGNORED; place(battle_pointer, 275, 252);}
     
     else if(battleChoice == 2 && battleManip == 2)
     {FLEE = HIGHLIGHTED; FIGHT = IGNORED; SNYMN = IGNORED; BAG = IGNORED; place(battle_pointer, 382, 252);}
     
     }
     
     //selecting moves
     if(selectMoves && turn)
     {
     //handle options/moves menu selector
     if(osl_keys->pressed.left){
        oslPlaySound(beep, 2); 
        battleChoice++;
     }
     
     else if(osl_keys->pressed.right){
           oslPlaySound(beep, 2); 
           battleChoice--; 
     }
     
     else if(osl_keys->pressed.up) 
     {
       if(battleManip != 1)
       {oslPlaySound(beep, 2); battleManip = 1;}
     }
     
     else if(osl_keys->pressed.down) 
     {
       if(battleManip != 2)
       {oslPlaySound(beep, 2); battleManip = 2;}
     }
     
     if(battleChoice > 2) battleChoice = 1;
     if(battleChoice < 1) battleChoice = 2;
     
     if(battleChoice == 1 && battleManip == 1)
     {FIRST_MOVE = HIGHLIGHTED; SECOND_MOVE = IGNORED; FOURTH_MOVE = IGNORED; THIRD_MOVE = IGNORED; place(battle_selector, 15, 220); }
          
     else if(battleChoice == 2 && battleManip == 1)
     {SECOND_MOVE = HIGHLIGHTED; FIRST_MOVE = IGNORED; THIRD_MOVE = IGNORED; FOURTH_MOVE = IGNORED; place(battle_selector, 150, 220);}
     
     else if(battleChoice == 1 && battleManip == 2)
     {THIRD_MOVE = HIGHLIGHTED; FIRST_MOVE = IGNORED; FOURTH_MOVE = IGNORED; SECOND_MOVE = IGNORED; place(battle_selector, 15, 247);}
     
     else if(battleChoice == 2 && battleManip == 2)
     {FOURTH_MOVE = HIGHLIGHTED; FIRST_MOVE = IGNORED; THIRD_MOVE = IGNORED; SECOND_MOVE = IGNORED; place(battle_selector, 150, 247);}
     
     }
     
     return;
}

void UPDATE_TURN::Options()
{
    bool inBattle = true;
     
     //check if the player selected an option       
     if(selecting)
     {
        if(osl_keys->pressed.cross && FIGHT == HIGHLIGHTED)      {oslPlaySound(beep, 2);  selecting = 0; selectMoves = 1;}
        else if(osl_keys->pressed.cross && FLEE == HIGHLIGHTED)  ran = 1;
        else if(osl_keys->pressed.cross && BAG == HIGHLIGHTED)   menu.OPEN_BAG();
        else if(osl_keys->pressed.cross && SNYMN == HIGHLIGHTED) menu.OPEN_PARTY(inBattle);
     }
     
     //check if the player selected a move
     else if(selectMoves)
     {
        if(osl_keys->pressed.cross && FIRST_MOVE == HIGHLIGHTED && move1 != empty)       {usedFirstMove = 1;}
        else if(osl_keys->pressed.cross && SECOND_MOVE == HIGHLIGHTED && move2 != empty) {usedSecondMove = 1;}
        else if(osl_keys->pressed.cross && THIRD_MOVE == HIGHLIGHTED && move3 != empty)  {usedThirdMove = 1;}
        else if(osl_keys->pressed.cross && FOURTH_MOVE == HIGHLIGHTED && move4 != empty) {usedFourthMove = 1;} 
        else if(osl_keys->pressed.circle) {oslPlaySound(beep, 2); selectMoves = 0; selecting = 1;} 
     }
     
     return;
}

void UPDATE_TURN::Bounce()
{
     if(sonymon->y > MAX_SHIFT) {GOING_DOWN = 1; GOING_UP = 0;}
     if(sonymon->y < MIN_SHIFT) {GOING_DOWN = 0; GOING_UP = 1;}
                
     if(GOING_UP) sonymon->y++;
     else if(GOING_DOWN) sonymon->y--;
     
     return;
}

void UPDATE_TURN::Stats()
{        
     //get the current sonymon's moves and apply them to move1, move2, move3, and move4 also apply int power
     if(sonymon_num == 1){
           power = sonymon1.attack;
           sonymon = sonymon1.image;
           name = sonymon1.name;
           move1 = sonymon1.move1;
           move2 = sonymon1.move2;
           move3 = sonymon1.move3;
           move4 = sonymon1.move4;
           moveName1 = sonymon1.moveName1;
           moveName2 = sonymon1.moveName1;
           moveName3 = sonymon1.moveName1;
           moveName4 = sonymon1.moveName1;
     }
     else if(sonymon_num == 2){
           power = sonymon2.attack;
           sonymon = sonymon2.image;
           name = sonymon2.name;
           move1 = sonymon2.move1;
           move2 = sonymon2.move2;
           move3 = sonymon2.move3;
           move4 = sonymon2.move4;
           moveName1 = sonymon2.moveName1;
           moveName2 = sonymon2.moveName1;
           moveName3 = sonymon2.moveName1;
           moveName4 = sonymon2.moveName1;
     }
     else if(sonymon_num == 3){
           power = sonymon3.attack;
           sonymon = sonymon3.image;
           name = sonymon3.name;
           move1 = sonymon3.move1;
           move2 = sonymon3.move2;
           move3 = sonymon3.move3;
           move4 = sonymon3.move4;
           moveName1 = sonymon3.moveName1;
           moveName2 = sonymon3.moveName1;
           moveName3 = sonymon3.moveName1;
           moveName4 = sonymon3.moveName1;  
     }
     
     return;
}

UPDATE_TURN::UPDATE_TURN()
{
    sonymon = unknown_back;
    name = "???";
    moveName1 = "???";
    moveName2 = "???";
    moveName3 = "???";
    moveName4 = "???";
    move1 = empty;
    move2 = empty;
    move3 = empty;
    move4 = empty;
    usedFirstMove = 0;
    usedSecondMove = 0;
    usedThirdMove = 0;
    usedFourthMove = 0;
    power = 0;
    attack = 0;
    
    return;
}

UPDATE_TURN::~UPDATE_TURN()
{
    return;
}
