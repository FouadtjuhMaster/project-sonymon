#include <oslib/oslib.h>
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

class ITEM
{
      public:
             void Populate(OSL_MAP * map, int mapChoice);
             void Draw(int area);
             void Use(int item);
             void Obtain(const int item);
             void Delete(const int index);
             void Place();
             
             bool active;
             int x;
             int y;
             int mapX;
             int mapY;
             OSL_IMAGE * image;
             OSL_IMAGE * imageFlash;
             int itemID;
             
      private:
             
}items, sonyball1, sonyball2, sonyball3, sonyball4, sonyball5;



void ITEM::Delete(const int index)
{
     //VERY EASY TO DO...just set specified index in inventory[] array to zero...
     inventory[index] = 0;
     
     //play some type of sound effect
     
     return;
}

void ITEM::Use(int item)
{
     int count = 0; //count number of items in player inventory
     int m, i; //loop manipulating variables
     int scroll = 0; //menu variable
     const char * itemName = "-- --"; //name of item
     
     short posy;
     short posx;

     for(m = 0; m < 200; m++)
         if(inventory[m] != 0 && inventory[m] != 0.0) count++;
         
     for(;;)
     {
             oslReadKeys();
             
             if(osl_keys->pressed.circle) {oslPlaySound(beep, 2); break;}
             else if(osl_keys->pressed.down && scroll < (count - 1)) {oslPlaySound(beep, 2); scroll++;}
             else if(osl_keys->pressed.up && scroll > 0){oslPlaySound(beep, 2); scroll--;}
             
             oslStartDrawing();
             oslClearScreen(BLACK);
             
             oslSetFont(normal);
             oslSetBkColor(RGBA(0,0,0,0));
             oslSetTextColor(WHITE);
             oslDrawString(5, 5,"INVENTORY");
         
             oslSetFont(verdana);
             oslSetBkColor(RGBA(0,0,0,0));
             oslSetTextColor(WHITE);
             
             //adjust
             posx = 5;
             posy = 45;
  
             for(i = 0; i < count; i++)
             {
                   //selector color
                   if(inventory[scroll] == inventory[i]) oslSetTextColor(RED);
                   else oslSetTextColor(WHITE);
                   
                   if(inventory[i] == potion)            itemName = "-potion";
                   else if(inventory[i] == super_potion) itemName = "-super potion";
                   else if(inventory[i] == hyper_potion) itemName = "-hyper potion";
                   else if(inventory[i] == wonder_drug)  itemName = "-wonder drug";
                   else if(inventory[i] == MP_boost)     itemName = "-MP boost";
                   else if(inventory[i] == LUJ)          itemName = "-LUJ";
                   else{
                        if(inventory[i] == DEFAULT) {oslWarning("ERROR!! inventory[i] is equal to 0!! Exiting function to avoid a crash!"); break;}
                        else oslFatalError("THERE WAS A SERIOUS PROBLEM IN INVENTORY FUNCTION!! SHUTTING DOWN!");
                   }
                   
                   //actually display the character pointer
                   oslPrintf_xy(posx, posy, "%s", itemName);
                   
                   posy += 15;
                   if(posy > 272) {posy = 45; posx += 100; }
             }
             
             if(count == 0) oslPrintf_xy(5, 45, "(empty)");
             
             oslEndDrawing();
             oslSyncFrame();
     }
     
     return;
}

void ITEM::Obtain(const int item)
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

void ITEM::Populate(OSL_MAP * map, int mapChoice)
{
     if(InsideCenter)
         return;
         
     if(mapChoice == 0)
     {
        item1->x = 508 - map->scrollX;
        item1->y = 90 - map->scrollY;
        item2->x = item1->x;
        item2->y = item1->y;
        item3->x = item1->x;
        item3->y = item1->y;
     }
   
     return;
}

void ITEM::Draw(int area)
{
     if(InsideCenter)
         return;
     
     if(area != 0)
         return;
         
     itemSwapManip++;
   
     if(itemSwapManip > 25) {itemSwap++; itemSwapManip = 0;}
     if(itemSwap > 2)       itemSwap = 1;
     
     //draw item faces
     if(itemSwap == 1)      oslDrawImage(item1);
     else if(itemSwap == 2) oslDrawImage(item2);
   
     collide = collision(zero,zero->x, zero->y,item1,item1->x,item1->y );
     if(collide && sprite_position == FACING_RIGHT)     {seenItem = 1; Obtain(1);}
     else if(collide && sprite_position == FACING_LEFT) {seenItem = 1; Obtain(1);}
     else if(collide && sprite_position == FACING_UP)   {seenItem = 1; Obtain(1);}
     else if(collide && sprite_position == FACING_DOWN) {seenItem = 1; Obtain(1);}
     else seenItem = 0;
 
     return;
}
