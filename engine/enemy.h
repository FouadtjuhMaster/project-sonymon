class ENEMY
{
      public:         
             ENEMY();
             ~ENEMY();             
        
             void SelectMove();
             void CheckDeath(int &enemyHealth, int XP, const char * name, const int enemy_type, OSL_IMAGE * image, OSL_IMAGE * playerSonymon, OSL_IMAGE * background);
             void UseMove(int &enemyHealth, int &enemyAttackPower, int enemy_type, int enemyRealType, const char * name, OSL_IMAGE *image, OSL_IMAGE *playerSonymon, OSL_IMAGE *background);   
             void HANDLE_ENEMY(int &enemyHealth, int &enemyAttackPower, int XP, int enemy_type, int enemyRealType, const char * name, OSL_IMAGE *image, OSL_IMAGE *playerSonymon, OSL_IMAGE *background);             
             void SetEnemyMoveName(int moveUsed);
             
             int exit;
             
      private:
              int enemyAttack;
              int sonymonType;
              int random_number;
}controlEnemy;

void ENEMY::SetEnemyMoveName(int moveUsed)
{
     const char * enemyMoveName = NULL;
     
     //based on the integers give values
     if(moveUsed == tackle)           enemyMoveName = "Tackle";
     else if(moveUsed == slam)        enemyMoveName = "Slam";
     else if(moveUsed == pound)       enemyMoveName = "Pound";
     else if(moveUsed == jumpKick)    enemyMoveName = "Jump Kick";
     else if(moveUsed == leech)       enemyMoveName = "leech";
     else if(moveUsed == clobber)     enemyMoveName = "clober";
     else if(moveUsed == contaminate) enemyMoveName = "contaminate";
     else if(moveUsed == steroids)    enemyMoveName = "steroids";
     else if(moveUsed == uplink)      enemyMoveName = "uplink";
     else if(moveUsed == blaze)       enemyMoveName = "blaze";
     else if(moveUsed == gust)        enemyMoveName = "gust";
     
     else oslWarning("ERROR!!! Failed to assign string to enemy move name!!");
     
     
     if(enemyMoveName == NULL) oslFatalError("ERROR!!! Failed to give const char * enemyMoveName a value!!\nfound in function void setEnemyMoveName();!!");
     
     return;
}


void ENEMY::HANDLE_ENEMY(int &enemyHealth, int &enemyAttackPower, int XP, int enemy_type, int enemyRealType, const char * name, OSL_IMAGE *image, OSL_IMAGE *playerSonymon, OSL_IMAGE *background)
{
      //if its not the enemies turn then quit the function
     if(turn != 2)
        return;
     
     CheckDeath(enemyHealth, XP, name, enemy_type, image, playerSonymon, background);
     
     if(exit)
         return;
         
     SelectMove(); 
     
     /*DESCRIPTION OF ENEMY ATTACK:
       
       -like in pokemon the attack variable is based off both the value of the move used,
       the attack/special attack of the pokemon using it, AND the defense of the pokemon
       getting attacked...
       
       -all these variables must be handled for an accurate attack value to be created...
       
       -the attack variable gets redefined every time the enemy attacks...(there is no global
       enemy attack int!!!! so dont look for one!!!)
     */
     
     UseMove(enemyHealth, enemyAttackPower, enemy_type, enemyRealType, name, image, playerSonymon, background);
     
     //reset turn
     turn = 1;
     
     return;
}

void ENEMY::UseMove(int &enemyHealth, int &enemyAttackPower, int enemy_type, int enemyRealType, const char * name, OSL_IMAGE *image, OSL_IMAGE *playerSonymon, OSL_IMAGE *background)
{
     //get the sonymon's type
     if(sonymon_num == 1)      sonymonType = sonymon1.type;
     else if(sonymon_num == 2) sonymonType = sonymon2.type;
     else if(sonymon_num == 3) sonymonType = sonymon3.type;
     
     if(enemyUsedMove == 1)
     {
        animate.animateMoveEnemy(enemyMove1, name, playerSonymon, image, background);
        SetEnemyMoveName(enemyMove1);
        
        enemyAttack = enemyMove1;
        enemyAttack = create.ApplyAttackValue(enemyMove1, enemyAttackPower);
        create.ApplyTypes(enemyMove1, enemyAttack, sonymonType, ENEMY_EFFECT);
        animate.flashHurtPlayer(playerSonymon, image, background);
        
        if(sonymon_num == 1) enemyAttack -= sonymon1.defense;
        else if(sonymon_num == 2) enemyAttack -= sonymon2.defense;
        else if(sonymon_num == 3) enemyAttack -= sonymon3.defense;
     }
     
     else if(enemyUsedMove == 2)
     {
        animate.animateMoveEnemy(enemyMove2, name, playerSonymon, image, background);
        SetEnemyMoveName(enemyMove2);
        
        enemyAttack = enemyMove2;
        enemyAttack = create.ApplyAttackValue(enemyMove2, enemyAttackPower);
        create.ApplyTypes(enemyMove2, enemyAttack, sonymonType, ENEMY_EFFECT);
        animate.flashHurtPlayer(playerSonymon, image, background);
        
        if(sonymon_num == 1) enemyAttack -= sonymon1.defense;
        else if(sonymon_num == 2) enemyAttack -= sonymon2.defense;
        else if(sonymon_num == 3) enemyAttack -= sonymon3.defense;
     }
     
     else if(enemyUsedMove == 3)
     {
        animate.animateMoveEnemy(enemyMove3, name, playerSonymon, image, background);
        SetEnemyMoveName(enemyMove3);
        
        enemyAttack = enemyMove3;
        enemyAttack = create.ApplyAttackValue(enemyMove3, enemyAttackPower);
        create.ApplyTypes(enemyMove3, enemyAttack, sonymonType, ENEMY_EFFECT);
        animate.flashHurtPlayer(playerSonymon, image, background);
        
        if(sonymon_num == 1) enemyAttack -= sonymon1.defense;
        else if(sonymon_num == 2) enemyAttack -= sonymon2.defense;
        else if(sonymon_num == 3) enemyAttack -= sonymon3.defense;
     }
     
     else if(enemyUsedMove == 4)
     {
        animate.animateMoveEnemy(enemyMove4, name, playerSonymon, image, background);
        SetEnemyMoveName(enemyMove4);
        
        enemyAttack = enemyMove4;
        enemyAttack = create.ApplyAttackValue(enemyMove4, enemyAttackPower);
        create.ApplyTypes(enemyMove4, enemyAttack, sonymonType, ENEMY_EFFECT);
        animate.flashHurtPlayer(playerSonymon, image, background);
        
        if(sonymon_num == 1) enemyAttack -= sonymon1.defense;
        else if(sonymon_num == 2) enemyAttack -= sonymon2.defense;
        else if(sonymon_num == 3) enemyAttack -= sonymon3.defense; 
     }
     
     //always deal at least 1 damage point
     if(enemyAttack <= 0) enemyAttack = 1;
     
     if(sonymon_num == 1)      sonymon1.health -= enemyAttack;
     else if(sonymon_num == 2) sonymon2.health -= enemyAttack;
     else if(sonymon_num == 3) sonymon3.health -= enemyAttack;
     
     return;
}

void ENEMY::SelectMove()
{
     srand((unsigned)time(0)); 
     random_number = (rand()%4)+1;
     
     if(enemyMove1 == empty) oslFatalError("Error! Enemy has no moves to use!!! found in SelectMoves();!!!");

     random_number = 1;
          
     
     if     (random_number == 1) enemyUsedMove = 1;
     else if(random_number == 2) enemyUsedMove = 2;
     else if(random_number == 3) enemyUsedMove = 3;
     else if(random_number == 4) enemyUsedMove = 4;
     else oslFatalError("Failed to apply int enemyUsedMove\nin function void ENEMY::SelectMove();");
     
     return;
}


void ENEMY::CheckDeath(int &enemyHealth, int XP, const char * name, const int enemy_type, OSL_IMAGE * image, OSL_IMAGE * playerSonymon, OSL_IMAGE * background)
{
     //check to see if enemy has lost all (or somehow less) health
     if(enemyHealth <= 0)
     {
         enemyHealth = 0;
         enemyAlive = 0;
         playDeathSound(enemy_type);
         animate.frontDie(image, XP, name, playerSonymon, background);
         exit = 1;
     }
     
     return;
}

ENEMY::ENEMY()
{
    enemyAttack = 0;
    random_number = 0;
    exit = 0;
    
    return;
}

ENEMY::~ENEMY()
{
    return;
}
