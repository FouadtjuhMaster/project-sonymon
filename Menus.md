**Menus are quite easy to add to a game or application when you break them down.**


First, create a local menu manipulator variable:
```
int menuChoice = 1;
```

Then, in your menu loop, read what buttons the player presses and manipulate our menu manipulator accordingly:
```
while(1)
{
   oslReadKeys();
   
   //handle int menuChoice;
   if(osl_keys->pressed.down && menuChoice > 1) menuChoice--;
   else if(osl_keys->pressed.up && menuChoice < 4) menuChoice++;
}
```
menuChoice is lowered is the player presses the down key and heightened when the player presses the up key. Boundaries are also placed so menuChoice stays within 1-4 numerical values.

Now draw whatever background image you have for the menu and have a selector that will appear highlighted underneath the menu item that menuChoice is currently on. Lets add some standard C macros so we do not have to memorize the values of our menu items:
```
//some standard C macros
#define START 1
#define OPTIONS 2
#define CREDITS 3
#define EXIT 4

//pointers toward our images
OSL_IMAGE *background, *selector;

//local menu manipulator variable
int menuChoice = 1;

//load images
background = /* load image */
selector = /*load image*/

while(1)
{
   oslReadKeys();
   
   //handle int menuChoice;
   if(osl_keys->pressed.down && menuChoice > 1) menuChoice--;
   else if(osl_keys->pressed.up && menuChoice < 4) menuChoice++;
   
   //draw the selector at different points based on what value menuChoice has
   if(menuChoice == START){/*draw selector where the start icon is */}

   if(menuChoice == OPTIONS){/*draw selector where the options icon is */}

   else if(menuChoice == CREDITS){/*draw selector where the credits icon is */}

   else if(menuChoice == EXIT){/*draw selector where the exit icon is */}
   //draw images
   oslStartDrawing();
   oslDrawImage(background);
   oslDrawImage(selector);
   oslEndDrawing();
   oslSyncFrame();
}
```
Good, now just allow the user to actually use the buttons by checking if the user pressed the start or x button while menuChoice is being used at that slot.
```
//some standard C macros
#define START 1
#define OPTIONS 2
#define CREDITS 3
#define EXIT 4

//pointers toward our images
OSL_IMAGE *background, *selector;

//local menu manipulator variable
int menuChoice = 1;

//load images
background = /* load image */
selector = /*load image*/

while(1)
{
   oslReadKeys();
   
   //handle int menuChoice;
   if(osl_keys->pressed.down && menuChoice > 1) menuChoice--;
   else if(osl_keys->pressed.up && menuChoice < 4) menuChoice++;
   
   //draw the selector at different points based on what value menuChoice has
   if(menuChoice == START)
   {
     /*draw selector where the start icon is */
     if(pressed.cross) { /* start game */ }
   }

   else if(menuChoice == OPTIONS)
   {
     /*draw OPTIONS where the start icon is */
     if(pressed.cross) { /* show options */ }
   }

   else if(menuChoice == CREDITS)
   {
     /*draw CREDITS where the start icon is */
     if(pressed.cross) { /* show credits */ }
   }

   else if(menuChoice == EXIT)
   {
     /*draw EXIT where the start icon is */
     if(pressed.cross) { /* exit game */ }
   }

   //draw images
   oslStartDrawing();
   oslDrawImage(background);
   oslDrawImage(selector);
   oslEndDrawing();
   oslSyncFrame();
}
```