#include "Arduboy2.h" //include the arduboy2 library
Arduboy2 ab; //this isnt realy needed but it saves on the typing shortening arduboy to ab
#define TITLE                0 //title screen
#define GAME_PLAY                1 // player select
#define PAUSE                     2 // gameplay
#define WIN                     3 // pause

int GameState = 0; //starts you at the title screen
void setup() { //initial set up of game
  ab.begin(); //starts up the arduboy 
  ab.setFrameRate(1); //speed controll
  ab.clear(); //clears the screen
  Serial.begin(9600); //opens a conection through the microusb port
}

void loop() { //everything in here is your game
  if (!(ab.nextFrame())) //checks to see if it is time for the next frame
    return; //if its not check again
  ab.pollButtons();
  
  switch (GameState) {
    case TITLE:
  
    //title screen
    break;
    
    case PLAY:
      if (ab.justPressed(A_BUTTON)) { GameState = 2; } //pause if you press a
      
    break;
      
    case PAUSE:
    //pause
      if (ab.justPressed(A_BUTTON)) { GameState = 2; }// unpause if you press a
    break;
   
    case WIN:
   //win /lose screen 
  break;
Serial.write(ab.getBuffer(), 128 * 64 / 8); //ssend the screen over the microusb (i use it for craits screen mirror)
ab.display();
}
