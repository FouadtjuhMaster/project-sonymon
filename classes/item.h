class ITEM {
      public:
             ITEM();
             ~ITEM();
             
             //properties
             long inventory[200];
             
             //behaviors
             void Use(long item);
             void Obtain(const long item);
             void Delete(const long index);
             long Activate(long &item);
             
      private:
            inline void Update();
             
}bag;

/* 
DESCRIPTION:
   -below are the decided values for each item...
     -DEFAULT/NULL: 0
     
     -potion: 1
     -super_potion:  2
     -hyper_potion:  3
     -wonder_drug:  4
     -MP_boost:  99,
     
     -LUJ (level up juice): 98
*/

long ITEM::Activate(long &item)
{
    //play some sound
    oslPlaySound(healthBoost, 4);
    
    //delete item after use
    Delete(item);
    
    return 0;
}

void ITEM::Delete(const long index)
{
     //VERY EASY TO DO...just set specified index in inventory[] array to zero...
     inventory[index] = 0;
     
     //play some type of sound effect
     
     return;
}

void ITEM::Use(long item)
{
     int count = 0; //count number of items in player inventory
     int m, i; //loop manipulating variables
     int scroll = 0; //menu variable
     const char * itemName = "-- --"; //name of item
     
     short posy;
     short posx;

     for(m = 0; m < 200; m++) if(inventory[m] != 0 && inventory[m] != 0.0) count++;
         
     for(;;)
     {
             oslReadKeys();
             
             if(osl_keys->pressed.circle) {oslPlaySound(beep, 2); break;}
             else if(osl_keys->pressed.down && scroll < (count - 1)) {oslPlaySound(beep, 2); scroll++;}
             else if(osl_keys->pressed.up && scroll > 0){oslPlaySound(beep, 2); scroll--;}
             else if(osl_keys->pressed.cross) Activate(inventory[scroll]);
             
             oslStartDrawing();
             oslClearScreen(BLACK);
             
             oslSetFont(normal);
             oslSetBkColor(RGBA(0,0,0,0));
             oslSetTextColor(WHITE);
             oslPrintf_xy(5, 15,"INVENTORY");
         
             oslSetFont(verdana);
             oslSetBkColor(RGBA(0,0,0,0));
             oslSetTextColor(WHITE);
             
             //adjust
             posx = 5;
             posy = 55;
             
             //update inventory
             Update();
             
             if(count == 0) oslPrintf_xy(5, 55, "(player inventory is empty)");
             
             else
             {
               for(i = 0; i < count; i++)
               {
                   //selector color
                   if(inventory[scroll] == inventory[i]) oslSetTextColor(RED);
                   else oslSetTextColor(WHITE);
                   
                   if(inventory[i] == potion)            itemName = "POTION";
                   else if(inventory[i] == super_potion) itemName = "SUPER POTION";
                   else if(inventory[i] == hyper_potion) itemName = "HYPER POTION";
                   else if(inventory[i] == wonder_drug)  itemName = "WONDER DRUG";
                   else if(inventory[i] == MP_boost)     itemName = "MP BOOST";
                   else if(inventory[i] == LUJ)          itemName = "LUJ";
                   else{
                        if(inventory[i] == DEFAULT) {oslWarning("ERROR!! inventory[i] is equal to 0!! Exiting function to avoid a crash!"); return;}
                        else {oslWarning("THERE WAS A SERIOUS PROBLEM IN INVENTORY FUNCTION!!"); return;}
                   }
                   
                   //actually display the character pointer
                   oslPrintf_xy(posx, posy, "-%s", itemName);
                   
                   posy += 15;
                   if(posy > 272) {posy = 55; posx += 100; }
               }
             }
        
             
             oslEndDrawing();
             oslSyncFrame();
     }
     
     return;
}

void ITEM::Obtain(const long item)
{
     int newItem = 0;
     
     //look for the first empty slot in the inventory[] array
     unsigned i;
     for(i = 0; i < 200; i++)
         if(inventory[i] == 0) {newItem = i; break;}
     
     //check for a full inventory/error
     if(newItem == 0) {oslWarning("ERROR! Cannot obtain item! Inventory is full!!!"); return;}
     
     //assign value
     inventory[newItem] = item; 
     oslPlaySound(found, 2);
       
     return;
}

inline void ITEM::Update()
{
    return;
}

ITEM::ITEM()
{
    return;
}

ITEM::~ITEM()
{
    return;
}
