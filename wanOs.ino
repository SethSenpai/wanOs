// DONT CHANGE PINS 15 AND 16
#define sclk 15 //cl
#define mosi 16 //si
#define dc   2 
#define cs   5 //OC
#define rst  3 

// Color definitions
#define BLACK           0x0000
#define BLUE            0x001F
#define RED             0xF800
#define GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0  
#define WHITE           0xFFFF
#define DARK_CYAN       0x0124
#define MEDIUM_CYAN     0x046F

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1351.h>
#include <SPI.h>

Adafruit_SSD1351 tft = Adafruit_SSD1351(cs, dc, rst);

static const uint8_t testicon[49][2] = {{0,0},{5,0},{6,0},{7,0},{8,0},{9,0},{10,0},{11,0},{0,1},{5,1},{8,1},{10,1},{0,2},{2,2},{5,2},{8,2},{10,2},{0,3},{3,3},{5,3},{10,3},{0,4},{5,4},{10,4},{0,5},{5,5},{6,5},{7,5},{10,5},{0,6},{1,6},{2,6},{3,6},{4,6},{5,6},{7,6},{8,6},{9,6},{10,6},{2,7},{3,7},{9,7},{3,8},{4,8},{5,8},{6,8},{7,8},{8,8},{9,8}};

//array so we can loop over the analog ports
static const uint8_t analog_pins[] = {A1,A2,A3,A4,A5};

//arrays that hold the old and new status of the analog ports, each number coresponds with a specific chips
int analogStatesNew[] = {0,0,0,0,0};
int analogStatesOld[] = {0,0,0,0,0};

//bool that turns true when a value has been changed
bool changedChip = false;

//timers variables
long millisOld = 0;
long millisOldEvent = 0;
int timeOutPopup = 15000;
int timeOutChipChange = 10000;
long timeOutEvent = 20000;

//divergence meter
float divient = 0;

//legacy function because why not
void fillpixelbypixel(uint16_t color) {
  for (uint8_t x=0; x < tft.width(); x++) {
    for (uint8_t y=0; y < tft.height(); y++) {
      tft.drawPixel(x, y, color);
    }
  }
}

void setup(void) {

  tft.begin();
  tft.setRotation(0);
  tft.fillRect(0, 0, 96, 128, BLACK);
  //setup screen and make it black

  drawBaseInterface(analogStatesNew);
  //drawIcon(testicon,49,20,20,RED);
  // draw the basic interface
}

void loop() {
  // readout the values on analogpin's 0 trough 5 and set variables accordingly
  readoutAnalogPins();

  // check if the setting for that port is new, if so run the assosiated function (this should be a range of voltages)
  checkArrayStatus();
  
  // check if random event triggers (this cannot happen if there is a change on the ports
  randomEventTrigger();
  
}

void readoutAnalogPins(){
  for(int i =0; i < 5; i++){
    int temp = analogRead(analog_pins[i]); //check so we can autocreate the right analogport
    delay(1);
    if(temp > 300){
      analogStatesNew[i] = 0;
    }
    if(temp > 0 && temp < 200){
      analogStatesNew[i] = 1;
    }
    //repeat above if statement for all aprpopriate chip values
  }
}

void checkArrayStatus(){
  for(int i =0; i <5; i++){
    /*
    Serial.print(analogStatesNew[i]);
    Serial.print(analogStatesOld[i]);
    Serial.print("|");
    */
    if(analogStatesNew[i] != analogStatesOld[i]){
      analogStatesOld[i] = analogStatesNew[i];
      popupTrigger(analogStatesNew[i]);
      changedChip = true;
    }
    else{
      analogStatesOld[i] = analogStatesNew[i];
      if(millisOld + timeOutChipChange < millis()){
        millisOld = millis();
        //in case of no changes and when timer expired release the changechip bool to allow for random events to happen. timeout should prob be around 30 sec;
        changedChip = false;
      }
    }
  }
  //Serial.println(",");
}

void popupTrigger(int value){
  switch(value){
    case 0:
      drawBaseInterface(analogStatesNew);
    break;
    case 1:
      drawPopup("New key added! Please enjoy your new privilage." , 0.3);
      delay(5000);
      drawBaseInterface(analogStatesNew);
    break;
    //repeat for amount of triggers
  }
}

void randomEventTrigger(){
  if(changedChip){
    return;
  }
  else {
    //Serial.print("chip is not true, ");
    //Serial.println((millisOldEvent + timeOutEvent) - millis());
    if((millisOldEvent + timeOutEvent) < millis()){
      //we popup with a random event here
      //Serial.println("timer triggered");
      millisOldEvent = millis(); // update our counter with the last trigger event
      timeOutEvent = random(20000,60000);
      Serial.println(timeOutEvent);
      int r = random(0,5);
      int d = 5000;
      switch(r){
        case 1:
          drawPopup("2 Friends have been removed from your contacts." , 0.1);
          delay(d);
          drawBaseInterface(analogStatesNew);
        break;

        case 2:
          drawPopup("You should head over to the canteen for your daily Latté" , -0.5);
          delay(d);
          drawBaseInterface(analogStatesNew);
        break;

        case 3:
          drawPopup("You're late for your appointment! Hurry!" , 2.0);
          delay(d);
          drawBaseInterface(analogStatesNew);
        break;

        case 4:
          drawPopup("Todays food has been deliverd to your house." , -0.2);
          delay(d);
          drawBaseInterface(analogStatesNew);
        break;
      }
    }
  }
}

void drawBaseInterface(int valuesOfPorts[]) {
  //interface design goes here
  tft.fillScreen(BLACK);
  tft.fillRect(0,0,128,15,MEDIUM_CYAN);
  tft.drawRect(0,0,128,96,MEDIUM_CYAN);
  tft.setCursor(32,48);
  tft.setTextColor(DARK_CYAN);
  tft.setTextSize(2);
  tft.println("wanOs");
  tft.setCursor(2,2);
  tft.setTextColor(DARK_CYAN);
  tft.setTextSize(1);
  tft.println("icons go in thIS bar");
  tft.setCursor(3,86);
  tft.setTextColor(GREEN);
  if(divient < 0){
    divient = 0;
  }
  String b = "% divergent";
  String a = divient + b;
  tft.println(a);
  for(int i =0; i < 5; i++){
    switch(analogStatesNew[i]){
      case 0:
        //drawIcon(logoArray, 0,0,RED);
      break;
      //more stuff for different states
    }
  }
}

void drawPopup(String message, float divi){
  tft.drawRect(10,10,108,76,WHITE);
  tft.fillRect(11,11,106,74,BLACK);

  int x = 13;
  int y = 13;
  //looping over the string so we can align the text in the popup box
  for(int i = 0; i < message.length(); i++){
    char a = message.charAt(i);
    if(i%16 == 0 && i != 0){ //if we have written 16 characters on a new line skip to the next line.
      x = 13;
      y = y + 8;
    }
    tft.drawChar(x,y,a,WHITE,BLACK,1);
    x = x + 6;
  }
    
  divient = divient + divi;
}

void drawIcon(uint8_t drawing[][2],int l, int x, int y, uint16_t color){
  //script to readout arryas generated by pauline and draw them somwhere on the screen
  for(int i = 0; i < l; i++){
    //pixel packets are here
    tft.drawPixel(drawing[i][0] + x,drawing[i][1] + y,color);
  }
}
