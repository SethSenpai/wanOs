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

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1351.h>
#include <SPI.h>

Adafruit_SSD1351 tft = Adafruit_SSD1351(cs, dc, rst);

int analogStatesNew[] = {0,0,0,0,0};
int analogStatesOld[] = {0,0,0,0,0};
bool changedChip = false;
float p = 3.1415926;

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
  uint16_t time = millis();
  tft.fillRect(0, 0, 96, 128, BLACK);
  time = millis() - time;
  //setup screen and make it black

  drawBaseInterface(analogStatesNew);
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
    int temp = analogRead(i); //check so we can autocreate the right analogport
    delay(1);
    if(temp > 0 && temp < 10){
      analogStatesNew[i] = 0;
    }

    //repeat above if statement for all aprpopriate chip values
  }
}

void checkArrayStatus(){
  for(int i =0; i <5; i++){
    if(analogStatesNew[i] != analogStatesOld[i]){
      analogStatesOld[i] = analogStatesNew[i];
      popupTrigger(analogStatesNew[i]);
      changedChip = true;
    }
    else{
      analogStatesOld[i] = analogStatesNew[i];
      if(timer has expried){
        //in case of no changes and when timer expired release the changechip bool to allow for random events to happen. timeout should prob be around 30 sec;
        changedChip = false;
      }
    }
  }
}

void popupTrigger(int value){
  switch(value){
    case 0:
      drawBaseInterface(analogStatesNew[i]);
    break;
    //repeat for amount of triggers
  }
}

void randomEventTrigger(){
  if(changedChip){
    return;
  }
  else {
    // generate timer that triggers between 30 and 50 seconds or so
  }
}

void drawBaseInterface(int valuesOfPorts[]) {
  //interface design goes here
}

