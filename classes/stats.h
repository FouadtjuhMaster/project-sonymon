class STATS : public SONYMON
{
      public:
              //constructor and destructor
              STATS();
              ~STATS();
              
              //record specific members
              char setRecordName(int id, const char * name);
              void setPartyImage(int x, int id);
              char * Description(const int id);
              
              //player sonymon specific members
              char setName(int type, int slot);
              void SetMaxXP(int slot, int id);
              void setMoveNames(int slot);
              void XPGain(int &xp, int id, int level);
              void LEVEL_UP(int slot, int id);
              
              //enemy specific members
              char setEnemyType(int id, int level, OSL_IMAGE *enemy);
              void setEnemyMoves(int id, int level);
              
              //general stats members
              OSL_IMAGE * makeImage(const int id);
              OSL_IMAGE * setImage(int id);
              void setMoves(int slot, int id, int level);
              void playRoar(const int id);
              void setImageUnspecified(int id, OSL_IMAGE * image);
              int setHealth(int &health, int id, int level);
              int setAttackPower(int &attack, int id, int level);
              int setDefense(int &defense, int id, int level);
              int setType(int &manipType, int id);
             
      private:
              OSL_IMAGE * image;
              const char * name;
              const char * moveName1;
              const char * moveName2;
              const char * moveName3;
              const char * moveName4;
              int move1;
              int move2;
              int move3;
              int move4;
}stats;

STATS::STATS()
{
    moveName1 = NULL;
    moveName2 = NULL;
    moveName3 = NULL;
    moveName4 = NULL;
    move1 = 0;
    move2 = 0;
    move3 = 0;
    move4 = 0;
    name = "-- --";
    image = unknown_back;
    
    return;
}

STATS::~STATS()
{
     return;
}

void STATS::setEnemyMoves(int id, int level)
{
     int move1, move2, move3, move4;
     move1 = empty;
     move2 = empty;
     move3 = empty;
     move4 = empty;
     
     if(id == 1){
           if(level > 1) move1 = steroids;
     }
     else if(id == 2){
           if(level > 1) move1 = leech;
           if(level > 4) move2 = tackle;
     }
     else if(id == 3){
          if(level > 1) move1 = tackle;
          if(level > 6) move2 = clobber;
     }
     else if(id == 4){
          if(level > 1) move1 = pound;
          if(level > 7) move2 = uplink;
     }
     else if(id == 5){
          if(level > 1) move1 = tackle;
          if(level > 3) move2 = leech;
     }
     else if(id == 6){
          if(level > 1) move1 = tackle;
          if(level > 3) move2 = pound;
          if(level > 8) move3 = uplink;
     }
     else if(id == 7){
          if(level > 1) move1 = tackle;
          if(level > 6) move2 = clobber;
          if(level > 11) move3 = slam;
     }
     else if(id == 8){
          if(level > 1) move1 = pound;
          if(level > 6) move2 = uplink;
     }
     else if(id == 9){
          if(level > 1) move1 = tackle;
          if(level > 4) move2 = waterGun;
     }
     else if(id == 10){
          if(level > 1) move1 = tackle;
          if(level > 8) move2 = uplink;
          if(level > 15) move3 = contaminate;
     }
     else if(id == 11){
          if(level > 1) move1 = tackle;
          if(level > 3) move2 = slam;
     }
     else if(id == 12){
          if(level > 1) move1 = clobber;
     }
     else if(id == 13){
          if(level > 1) move1 = pound;
          if(level > 6) move2 = clobber;
     }
     else if(id == 14){
          if(level > 1) move1 = tackle;
          if(level > 7) move2 = slam;
     }
     else if(id == 15){
          if(level > 1) move1 = slam;
          if(level > 5) move2 = blaze;
          if(level > 8) move3 = tackle;
     }
     else if(id == 16){
          if(level > 1) move1 = tackle;
          if(level > 5) move2 = uplink;
          if(level > 8) move3 = contaminate;
     }
     else if(id == 17){
          if(level > 1) move1 = tackle;
          if(level > 5) move2 = slam;
          if(level > 8) move3 = clobber;
     }
     else oslFatalError("Failed to assign moves! Found in function setMoves()!!!");
     
     //now apply!
     enemyMove1 = move1;
     enemyMove2 = move2;
     enemyMove3 = move3;
     enemyMove4 = move4;
     
     //now check for errors...
     if(enemyMove1 == empty) oslWarning("Warning! Failed to apply a move value to enemy move slot #1!!");
     
     return;
}

void STATS::setMoves(int slot, int id, int level)
{
     int move1, move2, move3, move4;
     move1 = empty;
     move2 = empty;
     move3 = empty;
     move4 = empty;
     
     if(id == 1){
           if(level > 1) move1 = steroids;
     }
     else if(id == 2){
           if(level > 1) move1 = leech;
           if(level > 4) move2 = tackle;
     }
     else if(id == 3){
          if(level > 1) move1 = tackle;
          if(level > 6) move2 = clobber;
     }
     else if(id == 4){
          if(level > 1) move1 = pound;
          if(level > 7) move2 = uplink;
     }
     else if(id == 5){
          if(level > 1) move1 = tackle;
          if(level > 3) move2 = leech;
     }
     else if(id == 6){
          if(level > 1) move1 = tackle;
          if(level > 3) move2 = pound;
          if(level > 8) move3 = uplink;
     }
     else if(id == 7){
          if(level > 1) move1 = tackle;
          if(level > 6) move2 = clobber;
          if(level > 11) move3 = slam;
     }
     else if(id == 8){
          if(level > 1) move1 = pound;
          if(level > 6) move2 = uplink;
     }
     else if(id == 9){
          if(level > 1) move1 = tackle;
          if(level > 4) move2 = waterGun;
     }
     else if(id == 10){
          if(level > 1) move1 = tackle;
          if(level > 8) move2 = uplink;
          if(level > 15) move3 = contaminate;
     }
     else if(id == 11){
          if(level > 1) move1 = tackle;
          if(level > 3) move2 = slam;
     }
     else if(id == 12){
          if(level > 1) move1 = clobber;
          if(level > 7) move2 = slam;
     }
     else if(id == 13){
          if(level > 1) move1 = pound;
          if(level > 6) move2 = clobber;
     }
     else if(id == 14){
          if(level > 1) move1 = tackle;
          if(level > 7) move2 = slam;
     }
     else if(id == 15){
          if(level > 1) move1 = slam;
          if(level > 5) move2 = blaze;
          if(level > 8) move3 = tackle;
     }
     else if(id == 16){
          if(level > 1) move1 = tackle;
          if(level > 5) move2 = uplink;
          if(level > 8) move3 = contaminate;
     }
     else if(id == 17){
          if(level > 1) move1 = tackle;
          if(level > 5) move2 = slam;
          if(level > 8) move3 = clobber;
     }
     else oslFatalError("Failed to assign moves! Found in function setMoves()!!!");
     
     //now apply!
     if(slot == 1) {sonymon1.move1 = move1; sonymon1.move2 = move2; sonymon1.move3 = move3; sonymon1.move4 = move4;}
     else if(slot == 2) {sonymon2.move1 = move1; sonymon2.move2 = move2; sonymon2.move3 = move3; sonymon2.move4 = move4;}
     else if(slot == 3) {sonymon3.move1 = move1; sonymon3.move2 = move2; sonymon3.move3 = move3; sonymon3.move4 = move4;}
     
     return;
}

void STATS::LEVEL_UP(int slot, int id)
{
     if(slot == 1){
             sonymon1.level += 1;
             sonymon1.xp = 0;
             create.ASSIGN_SONYMON(slot, id, sonymon1.level);
     }
     else if(slot == 2){
             sonymon2.level += 1;
             sonymon2.xp = 0;
             create.ASSIGN_SONYMON(slot, id, sonymon2.level);
     }
     else if(slot == 3){
             sonymon3.level += 1;
             sonymon3.xp = 0;
             create.ASSIGN_SONYMON(slot, id, sonymon3.level);
     }
     else oslWarning("Failed to Level up sonymon! found in function STATS::LEVEL_UP(int slot, int id);!!");
     
     return;
}

void STATS::SetMaxXP(int slot, int id)
{
     int max_xp = 0;
     
     //amount of xp for each sonymon is solely based on how powerful they are... the higher the stronger
     
     if(id == 1) max_xp = 6; //???
     else if(id == 2) max_xp = 9; //Blumkins
     else if(id == 3) max_xp = 13; //Arsande
     else if(id == 4) max_xp = 12; //Myboross
     else if(id == 5) max_xp = 11; //Argrasse
     else if(id == 6) max_xp = 12; //Norbonkge
     else if(id == 7) max_xp = 21; //Blowess
     else if(id == 8) max_xp = 12; //Cemes
     else if(id == 9) max_xp = 14; //Waterserore
     else if(id == 10) max_xp = 19; //vandel
     else if(id == 11) max_xp = 9; //Lieosaur
     else if(id == 12) max_xp = 8; //Sturk
     else if(id == 13) max_xp = 7; //Blip
     else if(id == 14) max_xp = 11; //Cecei
     else if(id == 15) max_xp = 20; //Fanz
     else if(id == 16) max_xp = 13; //darck
     else if(id == 17) max_xp = 12; //feesh
     
     if(max_xp <= 1) oslWarning("Failed to set a value to max_xp!!! found in function STATS::SetMaxXP(int slot, int id)");
     
     if(slot == 1)      sonymon1.max_xp = max_xp * sonymon1.level;
     else if(slot == 2) sonymon2.max_xp = max_xp * sonymon2.level;
     else if(slot == 3) sonymon3.max_xp = max_xp * sonymon3.level;
     else oslWarning("Failed to set a value to max_xp!!! found in function STATS::SetMaxXP(int slot, int id)");
     if(max_xp <= 1) oslWarning("Failed to set a value to max_xp!!! found in function STATS::SetMaxXP(int slot, int id)");
     
     return;
}

void STATS::XPGain(int &xp, int id, int level)
{
     float manipXP = 1;
     
     if(id == 1){xp = 1; manipXP = 1;}
     else if(id == 2){xp = 10; manipXP = 1.11;}
     else if(id == 3){xp = 25; manipXP = 1.12;}
     else if(id == 4){xp = 21; manipXP = 1.21;}
     else if(id == 5){xp = 12; manipXP = 1.12;}
     else if(id == 6){xp = 17; manipXP = 1.2;}
     else if(id == 7){xp = 36; manipXP = 1.5;}
     else if(id == 8){xp = 11; manipXP = 1.37;}
     else if(id == 9){xp = 14; manipXP = 1.1;}
     else if(id == 10){xp = 24; manipXP = 1.4;}
     else if(id == 11){xp = 18; manipXP = 1.1;}
     else if(id == 12){xp = 12; manipXP = 1.1;}
     else if(id == 13){xp = 14; manipXP = 1.3;}
     else if(id == 14){xp = 17; manipXP = 1.2;}
     else if(id == 15){xp = 14; manipXP = 1.2;}
     else if(id == 16){xp = 16; manipXP = 1.12;}
     else if(id == 17){xp = 18; manipXP = 1.25;}
     else oslWarning("Failed to apply value to int manipXP and int xp found in function STATS::XPGain()!!!");
     
     xp = xp + (manipXP * level);
     
     return;
}

void STATS::setMoveNames(int slot)
{    
     /*
        MOVE VALUES (defined in enum moves{})
        -tackle
        -slam
        -pound
        -jumpkick
        -waterGun
        -blaze
        -steroids
        -uplink
        -contaminate
        -leech
        -gust
        -clobber
     */
     
     //give values to integers based on sonymon move values
     if(slot == 1){
             moveName1 = sonymon1.moveName1;
             moveName2 = sonymon1.moveName2;
             moveName3 = sonymon1.moveName3;
             moveName4 = sonymon1.moveName4;
             move1 = sonymon1.move1;
             move2 = sonymon1.move2;
             move3 = sonymon1.move3;
             move4 = sonymon1.move4;
     }
     else if(slot == 2){
             moveName1 = sonymon2.moveName1;
             moveName2 = sonymon2.moveName2;
             moveName3 = sonymon2.moveName3;
             moveName4 = sonymon2.moveName4;
             move1 = sonymon2.move1;
             move2 = sonymon2.move2;
             move3 = sonymon2.move3;
             move4 = sonymon2.move4;
     }
     else if(slot == 3){
             moveName1 = sonymon3.moveName1;
             moveName2 = sonymon3.moveName2;
             moveName3 = sonymon3.moveName3;
             moveName4 = sonymon3.moveName4;
             move1 = sonymon3.move1;
             move2 = sonymon3.move2;
             move3 = sonymon3.move3;
             move4 = sonymon3.move4;
     }
     
        
     //based on the integers give values
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
     else if(move4 == contaminate)   moveName4 = "contaminate";
     else if(move4 == leech)         moveName4 = "leech";
     else if(move4 == gust)          moveName4 = "gust";
     else if(move4 == clobber)       moveName4 = "clobber";
     
     if(moveName1 == NULL) moveName1 = "-- --";
     if(moveName2 == NULL) moveName2 = "-- --";
     if(moveName3 == NULL) moveName3 = "-- --";
     if(moveName4 == NULL) moveName4 = "-- --";
     
     //now apply those values to the desired sonymon slot
     if(slot == 1){
             sonymon1.moveName1 = moveName1;
             sonymon1.moveName2 = moveName2;
             sonymon1.moveName3 = moveName3;
             sonymon1.moveName4 = moveName4;
     }
     else if(slot == 2){
             sonymon2.moveName1 = moveName1;
             sonymon2.moveName2 = moveName2;
             sonymon2.moveName3 = moveName3;
             sonymon2.moveName4 = moveName4;
     }
     else if(slot == 3){
             sonymon3.moveName1 = moveName1;
             sonymon3.moveName2 = moveName2;
             sonymon3.moveName3 = moveName3;
             sonymon3.moveName4 = moveName4;
     }
     
     return;
}

char STATS::setName(int id, int slot)
{
     const char * name = "";
     
     if(id == 1)      {name = "???";}
	 else if(id == 2) {name = "BLUMDINS";}
	 else if(id == 3) {name = "ARSANDE";}
	 else if(id == 4) {name = "MYBOROSS";}
 	 else if(id == 5) {name = "ARGRASSE";}
	 else if(id == 6) {name = "NORBONKGE";}
	 else if(id == 7) {name = "BLOWESS";}
	 else if(id == 8) {name =  "CEMES";}
	 else if(id == 9) {name = "WATERSERORE";}
	 else if(id == 10) {name = "VANDEL";}
	 else if(id == 11) {name = "LIEOSAUR";}
	 else if(id == 12) {name = "STURK";}
	 else if(id == 13) {name =  "BLIP";}
	 else if(id == 14) {name =  "CECEI";}
	 else if(id == 15) {name =  "FANZ";}
	 else if(id == 16) {name =  "DARCK";}
	 else if(id == 17) {name =  "FEESH";}
     else oslFatalError("failed to apply a name to char * name\nin char setName function");
     
     //a NULL char crashes the game...so check for it
     if(name == NULL) oslFatalError("char value equals NULL!!!\nfound in function setName!!!");
     
     //apply
     if(slot == 1)      sonymon1.name = name;
     else if(slot == 2) sonymon2.name = name;
     else if(slot == 3) sonymon3.name = name;
     
     return  * name;
}

char STATS::setRecordName(int id, const char * name)
{
     if(id == 1)      {name = "???";}
	 else if(id == 2) {name = "BLUMDINS";}
	 else if(id == 3) {name = "ARSANDE";}
	 else if(id == 4) {name = "MYBOROSS";}
 	 else if(id == 5) {name = "ARGRASSE";}
	 else if(id == 6) {name = "NORBONKGE";}
	 else if(id == 7) {name = "BLOWESS";}
	 else if(id == 8) {name =  "CEMES";}
	 else if(id == 9) {name = "WATERSERORE";}
	 else if(id == 10) {name = "VANDEL";}
	 else if(id == 11) {name = "LIEOSAUR";}
	 else if(id == 12) {name = "STURK";}
	 else if(id == 13) {name =  "BLIP";}
	 else if(id == 14) {name =  "CECEI";}
	 else if(id == 15) {name =  "FANZ";}
	 else if(id == 16) {name =  "DARCK";}
	 else if(id == 17) {name =  "FEESH";}
     else oslFatalError("failed to apply a name to char * name\nin char setName function");
     
     //a NULL char crashes the game...so check for it
     if(name == NULL) oslFatalError("char value equals NULL!!!\nfound in function setRecordName!!!");
     
     //apply
     RecordName = name;
     
     return  * name;
}

void STATS::playRoar(const int id)
{
    if(id == 1)      {oslPlaySound(unknown, 4);}
	else if(id == 2) {oslPlaySound(blumkins, 4);}
	else if(id == 3) {oslPlaySound(arsande, 4);}
	else if(id == 4) {oslPlaySound(myboross, 4);}
	else if(id == 5) {oslPlaySound(argrasse, 4);}
	else if(id == 6) {oslPlaySound(norbonkge, 4);}
	else if(id == 7) {oslPlaySound(blowess, 4);}
	else if(id == 8) {oslPlaySound(cemes, 4);}
	else if(id == 9) {oslPlaySound(waterserore, 4);}
	else if(id == 10) {oslPlaySound(vandel, 4);}
	else if(id == 11) {oslPlaySound(lieosaur, 4);}
	else if(id == 12) {oslPlaySound(sturk, 4);}
	else if(id == 13) {oslPlaySound(blip, 4);}
	else if(id == 14) {oslPlaySound(cecei, 4);}
	else if(id == 15) {oslPlaySound(fanz, 4);}
	else if(id == 16) {oslPlaySound(darck, 4);}
	else if(id == 17) {oslPlaySound(feesh, 4);}
    else oslWarning("Incorrect parameter passed to void STATS::playRoar! Cannot play sound!");
    
    return;
}

char STATS::setEnemyType(int id, int level, OSL_IMAGE *enemy)
{
     
	if(id == 1)      {oslPlaySound(unknown, 4);     enemyName = "???";}
	else if(id == 2) {oslPlaySound(blumkins, 4);    enemyName = "BLUMDINS";}
	else if(id == 3) {oslPlaySound(arsande, 4);     enemyName = "ARSANDE";}
	else if(id == 4) {oslPlaySound(myboross, 4);    enemyName = "MYBOROSS";}
	else if(id == 5) {oslPlaySound(argrasse, 4);    enemyName = "ARGRASSE";}
	else if(id == 6) {oslPlaySound(norbonkge, 4);   enemyName = "NORBONKGE";}
	else if(id == 7) {oslPlaySound(blowess, 4);     enemyName = "BLOWESS";}
	else if(id == 8) {oslPlaySound(cemes, 4);       enemyName =  "CEMES";}
	else if(id == 9) {oslPlaySound(waterserore, 4); enemyName = "WATERSERORE";}
	else if(id == 10) {oslPlaySound(vandel, 4);     enemyName = "VANDEL";}
	else if(id == 11) {oslPlaySound(lieosaur, 4);   enemyName = "LIEOSAUR";}
	else if(id == 12) {oslPlaySound(sturk, 4);      enemyName = "STURK";}
	else if(id == 13) {oslPlaySound(blip, 4);       enemyName =  "BLIP";}
	else if(id == 14) {oslPlaySound(cecei, 4);      enemyName =  "CECEI";}
	else if(id == 15) {oslPlaySound(fanz, 4);       enemyName =  "FANZ";}
	else if(id == 16) {oslPlaySound(darck, 4);      enemyName =  "DARCK";}
	else if(id == 17) {oslPlaySound(feesh, 4);      enemyName =  "FEESH";}
    else oslFatalError("failed to apply a name to char * name\nin char setEnemyType function");
     
     if(enemyName == NULL) oslFatalError("char value equals NULL!!!\nfound in function setEnemyType!!!");
     
     //set default stats...
     enemyAlive = 1;
     
     return * enemyName;
}

int STATS::setHealth(int &health, int id, int level)
{
    //this function performs the following math equation:
    //h = B + xy
    //h being int health, B being base health, x being int level, and y being manipLevel
           
    health = 1; //the returned value for enemyMaxHealth
    int manipHealth = 0;
    float manipLevel = 1; //will manipulate the health based on int level, the higher the more health
    
    /* base health (before manipLevel is apllied) & manipLeve
       -??? = 1 + 1
       -blumkins = 10 + 2
       -arsande = 20 + 2.4
       -Myboross = 10 + 1.8
       -Argasse = 10 + 2.2
       -Norbonk = 13 + 2
       -Blowess = 14 + 1.9
       -Cemes = 18 + 2.1
       -Waterserore = 10 + 2.5
       -Vandel = 23 + 2.2
       -Lieosaur = 15 + 2.1
       -sturk = 12 + 1.5
       -blip = 14 + 1.8
       -cecei = 15 + 2
       -fanz = 21 + 2.1
       -darck = 18 + 2.31
       -feesh = 16 + 2.38
    */
    
    if(id == 1)       {health = 1; manipLevel = 1;}
    else if(id == 2)  {health = 10; manipLevel = 2;}
    else if(id == 3)  {health = 20; manipLevel = 2.4;}
    else if(id == 4)  {health = 8; manipLevel = 1.8;}
    else if(id == 5)  {health = 10; manipLevel = 2.2;}
    else if(id == 6)  {health = 13; manipLevel = 2;}
    else if(id == 7)  {health = 14; manipLevel = 1.9;}
    else if(id == 8)  {health = 18; manipLevel = 2.1;}
    else if(id == 9)  {health = 10; manipLevel = 2.5;}
    else if(id == 10) {health = 23; manipLevel = 2.2;}
    else if(id == 11) {health = 15; manipLevel = 2.1;}
    else if(id == 12) {health = 12; manipLevel = 1.5;}
    else if(id == 13) {health = 14; manipLevel = 1.8;}
    else if(id == 14) {health = 15; manipLevel = 2;}
    else if(id == 15) {health = 21; manipLevel = 2.1;}
    else if(id == 16) {health = 18; manipLevel = 2.31;}
    else if(id == 17) {health = 16; manipLevel = 2.38;}
    else oslFatalError("failed to apply a value to int health\nin int setHealth function");
    
    manipHealth = level * manipLevel; //find our incremented value
    health += manipHealth; //add that value to the base health and voila!!!
    
    return health;
}

int STATS::setAttackPower(int &attack, int id, int level)
{
    attack = 1;
    int addOn;
    float manipAttack = 0.0;
    //this function performs the following equation:
    //A = mL
    //where A = int attack, m = int manipAttack, and L = int level
    
    /*DECIDED attack values for each sonymon:
              ???: 5000
              blumkins: 6.1
              arsande: 5.2
              myboross: 6.1
              argasse: 6.2
              norbonk: 5.2
              blowess: 7.1
              cemes: 4.4
              waterserore: 6.2
              vandel: 6.3
              lieosaur: 4
              sturk: 6.1
              blip: 4.1
              cecei: 6.2
              fanz: 6.5
              darck: 5
              feesh: 6.1
    */
                       
    if(id == 1)       {manipAttack = 50;}
    else if(id == 2)  {manipAttack = 6.1;}
    else if(id == 3)  {manipAttack = 5.2;}
    else if(id == 4)  {manipAttack = 6.1;}
    else if(id == 5)  {manipAttack = 6.2;}
    else if(id == 6)  {manipAttack = 5.2;}
    else if(id == 7)  {manipAttack = 7.1;}
    else if(id == 8)  {manipAttack = 4.4;}
    else if(id == 9)  {manipAttack = 6.2;}
    else if(id == 10) {manipAttack = 6.3;}
    else if(id == 11) {manipAttack = 4;}
    else if(id == 12) {manipAttack = 6.1;}
    else if(id == 13) {manipAttack = 4.1;}
    else if(id == 14) {manipAttack = 6.2;}
    else if(id == 15) {manipAttack = 6.5;}
    else if(id == 16) {manipAttack = 5;}
    else if(id == 17) {manipAttack = 6.1;}
    else oslFatalError("failed to apply a value to int manipAttack\nin int setAttackPower function");
    
    addOn = manipAttack * level;
    attack += addOn;
    return attack;
}

int STATS::setDefense(int &defense, int id, int level)
{
     defense = 1;
     float manipDefense = 0.0;
     int addOn;
     //this function performs the same equation as the above function...
    
    /*DECIDED attack values for each sonymon:
              ???: 1
              blumkins: 1.5
              arsande:  7.6
              myboross: 1.3
              argasse: 2.1
              norbonkge: 5.8
              blowess: 7.7
              cemes: 3.2
              waterserore: 5.1
              vandel: 4.3
              lieosaur: 2.1
              sturk: 3.3
              blip: 2.5
              cecei: 4.1
              fanz: 6.5
              darck: 4.5
              feesh: 3.5
    */
    
    if(id == 1)       {manipDefense = 1;}
    else if(id == 2)  {manipDefense = 3.5;}
    else if(id == 3)  {manipDefense = 7.6;}
    else if(id == 4)  {manipDefense = 2.3;}
    else if(id == 5)  {manipDefense = 3.1;}
    else if(id == 6)  {manipDefense = 6.8;}
    else if(id == 7)  {manipDefense = 8.7;}
    else if(id == 8)  {manipDefense = 4.2;}
    else if(id == 9)  {manipDefense = 6.1;}
    else if(id == 10) {manipDefense = 5.3;}
    else if(id == 11) {manipDefense = 3.1;}
    else if(id == 12) {manipDefense = 3.3;}
    else if(id == 13) {manipDefense = 2.5;}
    else if(id == 14) {manipDefense = 4.1;}
    else if(id == 15) {manipDefense = 6.5;}
    else if(id == 16) {manipDefense = 4.5;}
    else if(id == 17) {manipDefense = 3.5;}
    else oslFatalError("failed to apply a value to int manipDefense\nin int setDefense function");
    
    addOn = manipDefense * level;
    defense += addOn;
    
    return defense;
}

int STATS::setType(int &manipType, int id)
{
    manipType = UNDEFINED;
    
    if(id == 1)       {manipType = UNDEFINED;}
    else if(id == 2)  {manipType = GRASS;}
    else if(id == 3)  {manipType = ROCK;}
    else if(id == 4)  {manipType = STATIC;}
    else if(id == 5)  {manipType = GRASS;}
    else if(id == 6)  {manipType = STATIC;}
    else if(id == 7)  {manipType = NORMAL;}
    else if(id == 8)  {manipType = NORMAL;}
    else if(id == 9)  {manipType = WATER;}
    else if(id == 10) {manipType = ULTRAVIOLET;}
    else if(id == 11) {manipType = NORMAL;}
    else if(id == 12) {manipType = ROCK;}
    else if(id == 13) {manipType = NORMAL;}
    else if(id == 14) {manipType = NORMAL;}
    else if(id == 15) {manipType = FIRE;}
    else if(id == 16) {manipType = STATIC;}
    else if(id == 17) {manipType = WATER;}
    else oslFatalError("failed to apply a value to int type in function\nint setType(int type)!!!");
    
    return manipType;
}

void STATS::setImageUnspecified(int id, OSL_IMAGE * image)
{    
     if(id == 1)       {image = unknown_back;}
     else if(id == 2)  {image = blumkins_back;}
     else if(id == 3)  {image = arsande_back;}
     else if(id == 4)  {image = myboross_back;}
     else if(id == 5)  {image = argrasse_back;}
     else if(id == 6)  {image = norbonkge_back;}
     else if(id == 7)  {image = blowhole_back;}
     else if(id == 8)  {image = cemes_back;}
     else if(id == 9)  {image = waterserore_back;}
     else if(id == 10) {image = vandel_back;}
     else if(id == 11) {image = lieosaur_back;}
     else if(id == 12) {image = sturk_back;}
     else if(id == 13) {image = blip_back;}
     else if(id == 14) {image = cecei_back;}
     else if(id == 15) {image = fanz_back;}
     else if(id == 16) {image = darck_back;}
     else if(id == 17) {image = feesh_back;}
     
     //if an image is drawn when NULL it causes the game crash....so check for it
     if(image == NULL) oslFatalError("MEM ISSUE!! FOUND IN function void setImageUnspecified(int id, OSL_IMAGE * image)!!!");
     
     return;
}

OSL_IMAGE * STATS::setImage(int id)
{    
     if(id == 1)       {image = unknown_back;}
     else if(id == 2)  {image = blumkins_back;}
     else if(id == 3)  {image = arsande_back;}
     else if(id == 4)  {image = myboross_back;}
     else if(id == 5)  {image = argrasse_back;}
     else if(id == 6)  {image = norbonkge_back;}
     else if(id == 7)  {image = blowhole_back;}
     else if(id == 8)  {image = cemes_back;}
     else if(id == 9)  {image = waterserore_back;}
     else if(id == 10) {image = vandel_back;}
     else if(id == 11) {image = lieosaur_back;}
     else if(id == 12) {image = sturk_back;}
     else if(id == 13) {image = blip_back;}
     else if(id == 14) {image = cecei_back;}
     else if(id == 15) {image = fanz_back;}
     else if(id == 16) {image = darck_back;}
     else if(id == 17) {image = feesh_back;}
     
     //if an image is drawn when NULL it causes the game crash....so check for it
     if(image == NULL) oslFatalError("MEM ISSUE!! FOUND IN function void setImage(int id, int slot)!!!");
     
     return image;
}
OSL_IMAGE * STATS::makeImage(const int id)
{
    OSL_IMAGE * image;
    image = NULL;
    
    if(id == 1)       image = oslLoadImageFilePNG((char*)"img/sonymon/unknownf.png", OSL_IN_RAM, OSL_PF_5551);
	else if(id == 3)  image = oslLoadImageFilePNG((char*)"img/sonymon/arsande_front.png", OSL_IN_RAM, OSL_PF_5551);
	else if(id == 2)  image = oslLoadImageFilePNG((char*)"img/sonymon/blumkins_front.png", OSL_IN_RAM, OSL_PF_5551);
	else if(id == 5)  image = oslLoadImageFilePNG((char*)"img/sonymon/argrasse_front.png", OSL_IN_RAM, OSL_PF_5551);
	else if(id == 4)  image = oslLoadImageFilePNG((char*)"img/sonymon/myboross_front.png", OSL_IN_RAM, OSL_PF_5551);
	else if(id == 6)  image = oslLoadImageFilePNG((char*)"img/sonymon/norbonkge_front.png", OSL_IN_RAM, OSL_PF_5551);
	else if(id == 7)  image = oslLoadImageFilePNG((char*)"img/sonymon/blowhole_front.png", OSL_IN_RAM, OSL_PF_5551);
	else if(id == 8)  image = oslLoadImageFilePNG((char*)"img/sonymon/cemes_front.png", OSL_IN_RAM, OSL_PF_5551);
	else if(id == 9)  image = oslLoadImageFilePNG((char*)"img/sonymon/waterserore_front.png", OSL_IN_RAM, OSL_PF_5551);
	else if(id == 10) image = oslLoadImageFilePNG((char*)"img/sonymon/vandel_front.png", OSL_IN_RAM, OSL_PF_5551);
	else if(id == 11) image = oslLoadImageFilePNG((char*)"img/sonymon/lieosaur_front.png", OSL_IN_RAM, OSL_PF_5551);
	else if(id == 12) image = oslLoadImageFilePNG((char*)"img/sonymon/sturk_front.png", OSL_IN_RAM, OSL_PF_5551);
	else if(id == 13) image = oslLoadImageFilePNG((char*)"img/sonymon/blip_front.png", OSL_IN_RAM, OSL_PF_5551);
	else if(id == 14) image = oslLoadImageFilePNG((char*)"img/sonymon/cecei_front.png", OSL_IN_RAM, OSL_PF_5551);
	else if(id == 15) image = oslLoadImageFilePNG((char*)"img/sonymon/fanz_front.png", OSL_IN_RAM, OSL_PF_5551);
	else if(id == 16) image = oslLoadImageFilePNG((char*)"img/sonymon/darck_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 17) image = oslLoadImageFilePNG((char*)"img/sonymon/feesh_front.png", OSL_IN_RAM, OSL_PF_5551);
       
    //if an image is drawn when NULL it causes the game crash....so check for it
    if(!image) oslFatalError("MEM ISSUE!! FOUND IN function\nvoid makeImage(const int id, OSL_IMAGE * image)!!!");
     
    return image;
}

void STATS::setPartyImage(int x, int id)
{    
     if(x == 1)
     {

       if(id == 1)       temp1 = oslLoadImageFilePNG((char*)"img/sonymon/unknownf.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 3)  temp1 = oslLoadImageFilePNG((char*)"img/sonymon/arsande_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 2)  temp1 = oslLoadImageFilePNG((char*)"img/sonymon/blumkins_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 5)  temp1 = oslLoadImageFilePNG((char*)"img/sonymon/argrasse_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 4)  temp1 = oslLoadImageFilePNG((char*)"img/sonymon/myboross_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 6)  temp1 = oslLoadImageFilePNG((char*)"img/sonymon/norbonkge_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 7)  temp1 = oslLoadImageFilePNG((char*)"img/sonymon/blowhole_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 8)  temp1 = oslLoadImageFilePNG((char*)"img/sonymon/cemes_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 9)  temp1 = oslLoadImageFilePNG((char*)"img/sonymon/waterserore_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 10) temp1 = oslLoadImageFilePNG((char*)"img/sonymon/vandel_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 11) temp1 = oslLoadImageFilePNG((char*)"img/sonymon/lieosaur_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 12) temp1 = oslLoadImageFilePNG((char*)"img/sonymon/sturk_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 13) temp1 = oslLoadImageFilePNG((char*)"img/sonymon/blip_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 14) temp1 = oslLoadImageFilePNG((char*)"img/sonymon/cecei_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 15) temp1 = oslLoadImageFilePNG((char*)"img/sonymon/fanz_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 16) temp1 = oslLoadImageFilePNG((char*)"img/sonymon/darck_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 17) temp1 = oslLoadImageFilePNG((char*)"img/sonymon/feesh_front.png", OSL_IN_RAM, OSL_PF_5551);
       
       //if an image is drawn when NULL it causes the game crash....so check for it
     if(!temp1) oslFatalError("MEM ISSUE!! FOUND IN function\nvoid setPartyImage(int type, int slot)!!!");
     }
     
     else if(x == 2)
     {

       if(id == 1)       temp2 = oslLoadImageFilePNG((char*)"img/sonymon/unknownf.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 2)  temp2 = oslLoadImageFilePNG((char*)"img/sonymon/arsande_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 3)  temp2 = oslLoadImageFilePNG((char*)"img/sonymon/blumkins_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 5)  temp2 = oslLoadImageFilePNG((char*)"img/sonymon/argrasse_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 4)  temp2 = oslLoadImageFilePNG((char*)"img/sonymon/myboross_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 6)  temp2 = oslLoadImageFilePNG((char*)"img/sonymon/norbonkge_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 7)  temp2 = oslLoadImageFilePNG((char*)"img/sonymon/blowhole_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 8)  temp2 = oslLoadImageFilePNG((char*)"img/sonymon/cemes_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 9)  temp2 = oslLoadImageFilePNG((char*)"img/sonymon/waterserore_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 10) temp2 = oslLoadImageFilePNG((char*)"img/sonymon/vandel_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 11) temp2 = oslLoadImageFilePNG((char*)"img/sonymon/lieosaur_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 12) temp2 = oslLoadImageFilePNG((char*)"img/sonymon/sturk_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 13) temp2 = oslLoadImageFilePNG((char*)"img/sonymon/blip_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 14) temp2 = oslLoadImageFilePNG((char*)"img/sonymon/cecei_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 15) temp2 = oslLoadImageFilePNG((char*)"img/sonymon/fanz_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 16) temp2 = oslLoadImageFilePNG((char*)"img/sonymon/darck_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 17) temp2 = oslLoadImageFilePNG((char*)"img/sonymon/feesh_front.png", OSL_IN_RAM, OSL_PF_5551);
       
     //if an image is drawn when NULL it causes the game crash....so check for it
     if(!temp2) oslFatalError("MEM ISSUE!! FOUND IN function\nvoid setPartyImage(int type, int slot)!!!");
     }
     
     else if(x == 3)
     {

       if(id == 1)       temp3 = oslLoadImageFilePNG((char*)"img/sonymon/unknownf.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 2)  temp3 = oslLoadImageFilePNG((char*)"img/sonymon/arsande_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 3)  temp3 = oslLoadImageFilePNG((char*)"img/sonymon/blumkins_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 5)  temp3 = oslLoadImageFilePNG((char*)"img/sonymon/argrasse_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 4)  temp3 = oslLoadImageFilePNG((char*)"img/sonymon/myboross_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 6)  temp3 = oslLoadImageFilePNG((char*)"img/sonymon/norbonkge_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 7)  temp3 = oslLoadImageFilePNG((char*)"img/sonymon/blowhole_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 8)  temp3 = oslLoadImageFilePNG((char*)"img/sonymon/cemes_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 9)  temp3 = oslLoadImageFilePNG((char*)"img/sonymon/waterserore_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 10) temp3 = oslLoadImageFilePNG((char*)"img/sonymon/vandel_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 11) temp3 = oslLoadImageFilePNG((char*)"img/sonymon/lieosaur_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 12) temp3 = oslLoadImageFilePNG((char*)"img/sonymon/sturk_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 13) temp3 = oslLoadImageFilePNG((char*)"img/sonymon/blip_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 14) temp3 = oslLoadImageFilePNG((char*)"img/sonymon/cecei_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 15) temp3 = oslLoadImageFilePNG((char*)"img/sonymon/fanz_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 16) temp3 = oslLoadImageFilePNG((char*)"img/sonymon/darck_front.png", OSL_IN_RAM, OSL_PF_5551);
	   else if(id == 17) temp3 = oslLoadImageFilePNG((char*)"img/sonymon/feesh_front.png", OSL_IN_RAM, OSL_PF_5551);
       
       //if an image is drawn when NULL it causes the game crash....so check for it
     if(!temp3) oslFatalError("MEM ISSUE!! FOUND IN function\nvoid setPartyImage(int type, int slot)!!!");
     }
     
     else oslWarning("Failed to assign slot for party images!");
     

     
     return;
}

char * STATS::Description(const int id)
{
    char * message = (char*)"null";

    if(id == 1) {
        des1 = (char*)"This sonymon is only partially existent. ??? ";
        des2 = (char*)"coexists between two demensions.";
        des3 = (char*)"";
        des4 = (char*)"";
        des5 = (char*)"";
    }
    
    else if(id == 2) {
        des1 = (char*)"Blumdins like to hide in the grass, not to";
        des2 = (char*)"hide from predators, they just like";
        des3 = (char*)"grass";
        des4 = (char*)"";
        des5 = (char*)"";
    }

    else if(id == 3) {
        des1 = (char*)"Using its huge and powerful arms, ";
        des2 = (char*)"arsande can scale tall mountains in only";
        des3 = (char*)"a few minutes. It also likes to stack";
        des4 = (char*)"rocks on itself for protection.";
        des5 = (char*)"";
    }
    
    else if(id == 4) {
        des1 = (char*)"Myboross is a tricky sonymon who is always";
        des2 = (char*)"prone to shock any approaching object.";
        des3 = (char*)"";
        des4 = (char*)"";
        des5 = (char*)"";
    }
    
    else if(id == 5) {
        des1 = (char*)"This plant sonymon can always be found bathing";
        des2 = (char*)"in sunlight and bullying a blumdin.";
        des3 = (char*)"";
        des4 = (char*)"";
        des5 = (char*)"";
    }
    
    else if(id == 6) {
        message = (char*)"Like Myboross this sonymon shocks any intruder. Very violent and sneaky, beware of this sonymon.";
        des1 = (char*)"This plant sonymon can always be found bathing";
        des2 = (char*)"in sunlight and bullying a blumdin.";
        des3 = (char*)"";
        des4 = (char*)"";
        des5 = (char*)"";
    }
    
    else if(id == 7) {
        des1 = (char*)"Large and in charge. Short temper and";
        des2 = (char*)"feared by many other sonymon.";
        des3 = (char*)"";
        des4 = (char*)"";
        des5 = (char*)"";
    }
    
    else if(id == 8) {
        des1 = (char*)"A little timid creature who usually can found";
        des2 = (char*)"during the night time.";
        des3 = (char*)"";
        des4 = (char*)"";
        des5 = (char*)"";
    }
    
    else if(id == 9) {
        des1 = (char*)"One of the most aggressive fish sonymon there are!";
        des2 = (char*)"Constantly fights with others and disrupts";
        des3 = (char*)"any and all surrounding sonymon.";
        des4 = (char*)"";
        des5 = (char*)"";
    }
    
    else if(id == 10) {
        des1 = (char*)"There are many horror stories including";
        des2 = (char*)"this sonymon. This ghost-like creature";
        des3 = (char*)"can phase through walls and send you";
        des4 = (char*)"flying backwards with an energy blast.";
        des5 = (char*)"";
   }
    
    else if(id == 11) {
        des1 = (char*)"A Small reptillian creature who searches for";
        des2 = (char*)"food constantly.";
        des3 = (char*)"";
        des4 = (char*)"";
        des5 = (char*)"";
    }
    
    else if(id == 12) {
        des1 = (char*)"A small rock-like creature. Always in danger";
        des2 = (char*)"of being eaten. One of the weaker sonymons";
        des3 = (char*)"out there.";
        des4 = (char*)"";
        des5 = (char*)"";
    }
    
    else if(id == 13) {
        des1 = (char*)"This sonymon can always be found clowning around!";
        des2 = (char*)"The jokster of all sonymon.";
        des3 = (char*)"";
        des4 = (char*)"";
        des5 = (char*)"";
    }
    
    else if(id == 14) {
        des1 = (char*)"Attempts to intimidate other sonymon but always";
        des2 = (char*)"ends up creating infatuation, a very";
        des3 = (char*)"misunderstood sonymon.";
        des4 = (char*)"";
        des5 =  (char*)"";
    }
    
    else if(id == 15) {
        des1 = (char*)"An unpredictable annoyance. Likes to sneak up";
        des2 = (char*)"on campers and scare them before running off";
        des3 = (char*)"with all of their food";
        des4 = (char*)"";
        des5 = (char*)"";
    }
    
    else if(id == 16) {
        des1 = (char*)"Very timid. Likes to seclude itself from";
        des2 = (char*)"other sonymon.";
        des3 = (char*)"";
        des4 = (char*)"";
        des5 = (char*)"";
    }
    
    else if(id == 17) {
        des1 = (char*)"Extreemly fast sonymon. Can whip through water";
        des2 = (char*)"at amazingly high speeds to catch prey.";
        des3 = (char*)"";
        des4 = (char*)"";
        des5 = (char*)"";
    }
    else {oslWarning("Failed to apply a value to message! Cannot create description!"); message = (char*)"(error)";}
    
    return message;
}
