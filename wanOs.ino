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

static const uint8_t wanLogo[759][2] = {{18,0},{19,0},{20,0},{21,0},{38,0},{39,0},{40,0},{41,0},{18,1},{19,1},{20,1},{21,1},{38,1},{39,1},{40,1},{41,1},{14,2},{15,2},{16,2},{17,2},{18,2},{19,2},{20,2},{21,2},{22,2},{23,2},{24,2},{25,2},{26,2},{27,2},{28,2},{29,2},{30,2},{31,2},{32,2},{33,2},{34,2},{35,2},{36,2},{37,2},{38,2},{39,2},{40,2},{41,2},{42,2},{43,2},{44,2},{45,2},{46,2},{47,2},{14,3},{15,3},{16,3},{17,3},{18,3},{19,3},{20,3},{21,3},{22,3},{23,3},{24,3},{25,3},{26,3},{27,3},{28,3},{29,3},{30,3},{31,3},{32,3},{33,3},{34,3},{35,3},{36,3},{37,3},{38,3},{39,3},{40,3},{41,3},{42,3},{43,3},{44,3},{45,3},{46,3},{47,3},{8,4},{9,4},{10,4},{11,4},{12,4},{13,4},{14,4},{15,4},{20,4},{21,4},{22,4},{23,4},{36,4},{37,4},{38,4},{39,4},{44,4},{45,4},{46,4},{47,4},{48,4},{49,4},{50,4},{51,4},{8,5},{9,5},{10,5},{11,5},{12,5},{13,5},{14,5},{15,5},{20,5},{21,5},{22,5},{23,5},{36,5},{37,5},{38,5},{39,5},{44,5},{45,5},{46,5},{47,5},{48,5},{49,5},{50,5},{51,5},{4,6},{5,6},{6,6},{7,6},{8,6},{9,6},{10,6},{11,6},{20,6},{21,6},{38,6},{39,6},{40,6},{41,6},{48,6},{49,6},{50,6},{51,6},{52,6},{53,6},{54,6},{55,6},{4,7},{5,7},{6,7},{7,7},{8,7},{9,7},{10,7},{11,7},{20,7},{21,7},{38,7},{39,7},{40,7},{41,7},{48,7},{49,7},{50,7},{51,7},{52,7},{53,7},{54,7},{55,7},{2,8},{3,8},{4,8},{5,8},{18,8},{19,8},{20,8},{21,8},{38,8},{39,8},{40,8},{41,8},{54,8},{55,8},{56,8},{57,8},{2,9},{3,9},{4,9},{5,9},{18,9},{19,9},{20,9},{21,9},{38,9},{39,9},{40,9},{41,9},{54,9},{55,9},{56,9},{57,9},{2,10},{3,10},{4,10},{5,10},{18,10},{19,10},{20,10},{21,10},{40,10},{41,10},{54,10},{55,10},{56,10},{57,10},{2,11},{3,11},{4,11},{5,11},{18,11},{19,11},{20,11},{21,11},{40,11},{41,11},{54,11},{55,11},{56,11},{57,11},{2,12},{3,12},{4,12},{5,12},{16,12},{17,12},{18,12},{19,12},{40,12},{41,12},{42,12},{43,12},{54,12},{55,12},{56,12},{57,12},{2,13},{3,13},{4,13},{5,13},{16,13},{17,13},{18,13},{19,13},{40,13},{41,13},{42,13},{43,13},{54,13},{55,13},{56,13},{57,13},{2,14},{3,14},{4,14},{5,14},{16,14},{17,14},{18,14},{19,14},{42,14},{43,14},{56,14},{57,14},{2,15},{3,15},{4,15},{5,15},{16,15},{17,15},{18,15},{19,15},{42,15},{43,15},{56,15},{57,15},{2,16},{3,16},{14,16},{15,16},{16,16},{17,16},{42,16},{43,16},{44,16},{45,16},{56,16},{57,16},{2,17},{3,17},{14,17},{15,17},{16,17},{17,17},{42,17},{43,17},{44,17},{45,17},{56,17},{57,17},{2,18},{3,18},{12,18},{13,18},{14,18},{15,18},{44,18},{45,18},{46,18},{47,18},{56,18},{57,18},{2,19},{3,19},{12,19},{13,19},{14,19},{15,19},{44,19},{45,19},{46,19},{47,19},{56,19},{57,19},{2,20},{3,20},{12,20},{13,20},{14,20},{15,20},{46,20},{47,20},{56,20},{57,20},{2,21},{3,21},{12,21},{13,21},{14,21},{15,21},{46,21},{47,21},{56,21},{57,21},{2,22},{3,22},{10,22},{11,22},{12,22},{13,22},{46,22},{47,22},{48,22},{49,22},{56,22},{57,22},{2,23},{3,23},{10,23},{11,23},{12,23},{13,23},{46,23},{47,23},{48,23},{49,23},{56,23},{57,23},{2,24},{3,24},{8,24},{9,24},{10,24},{11,24},{48,24},{49,24},{50,24},{51,24},{56,24},{57,24},{2,25},{3,25},{8,25},{9,25},{10,25},{11,25},{48,25},{49,25},{50,25},{51,25},{56,25},{57,25},{2,26},{3,26},{6,26},{7,26},{8,26},{9,26},{10,26},{11,26},{20,26},{21,26},{38,26},{39,26},{48,26},{49,26},{50,26},{51,26},{52,26},{53,26},{56,26},{57,26},{2,27},{3,27},{6,27},{7,27},{8,27},{9,27},{10,27},{11,27},{20,27},{21,27},{38,27},{39,27},{48,27},{49,27},{50,27},{51,27},{52,27},{53,27},{56,27},{57,27},{2,28},{3,28},{4,28},{5,28},{6,28},{7,28},{10,28},{11,28},{20,28},{21,28},{38,28},{39,28},{48,28},{49,28},{52,28},{53,28},{54,28},{55,28},{56,28},{57,28},{2,29},{3,29},{4,29},{5,29},{6,29},{7,29},{10,29},{11,29},{20,29},{21,29},{38,29},{39,29},{48,29},{49,29},{52,29},{53,29},{54,29},{55,29},{56,29},{57,29},{2,30},{3,30},{4,30},{5,30},{10,30},{11,30},{12,30},{13,30},{20,30},{21,30},{38,30},{39,30},{48,30},{49,30},{54,30},{55,30},{56,30},{57,30},{2,31},{3,31},{4,31},{5,31},{10,31},{11,31},{12,31},{13,31},{20,31},{21,31},{38,31},{39,31},{48,31},{49,31},{54,31},{55,31},{56,31},{57,31},{10,32},{11,32},{12,32},{13,32},{46,32},{47,32},{48,32},{49,32},{10,33},{11,33},{12,33},{13,33},{46,33},{47,33},{48,33},{49,33},{12,34},{13,34},{46,34},{47,34},{12,35},{13,35},{46,35},{47,35},{12,36},{13,36},{14,36},{15,36},{44,36},{45,36},{46,36},{47,36},{12,37},{13,37},{14,37},{15,37},{44,37},{45,37},{46,37},{47,37},{14,38},{15,38},{44,38},{45,38},{46,38},{47,38},{14,39},{15,39},{44,39},{45,39},{46,39},{47,39},{14,40},{15,40},{16,40},{17,40},{24,40},{25,40},{26,40},{27,40},{28,40},{29,40},{30,40},{31,40},{32,40},{33,40},{34,40},{35,40},{42,40},{43,40},{44,40},{45,40},{14,41},{15,41},{16,41},{17,41},{24,41},{25,41},{26,41},{27,41},{28,41},{29,41},{30,41},{31,41},{32,41},{33,41},{34,41},{35,41},{42,41},{43,41},{44,41},{45,41},{16,42},{17,42},{18,42},{19,42},{28,42},{29,42},{30,42},{31,42},{42,42},{43,42},{44,42},{45,42},{16,43},{17,43},{18,43},{19,43},{28,43},{29,43},{30,43},{31,43},{42,43},{43,43},{44,43},{45,43},{16,44},{17,44},{18,44},{19,44},{20,44},{21,44},{28,44},{29,44},{30,44},{31,44},{40,44},{41,44},{42,44},{43,44},{16,45},{17,45},{18,45},{19,45},{20,45},{21,45},{28,45},{29,45},{30,45},{31,45},{40,45},{41,45},{42,45},{43,45},{18,46},{19,46},{20,46},{21,46},{22,46},{23,46},{36,46},{37,46},{38,46},{39,46},{40,46},{41,46},{18,47},{19,47},{20,47},{21,47},{22,47},{23,47},{36,47},{37,47},{38,47},{39,47},{40,47},{41,47},{20,48},{21,48},{22,48},{23,48},{24,48},{25,48},{26,48},{27,48},{28,48},{29,48},{30,48},{31,48},{32,48},{33,48},{34,48},{35,48},{36,48},{37,48},{38,48},{39,48},{20,49},{21,49},{22,49},{23,49},{24,49},{25,49},{26,49},{27,49},{28,49},{29,49},{30,49},{31,49},{32,49},{33,49},{34,49},{35,49},{36,49},{37,49},{38,49},{39,49},{24,50},{25,50},{26,50},{27,50},{28,50},{29,50},{30,50},{31,50},{32,50},{33,50},{34,50},{35,50},{24,51},{25,51},{26,51},{27,51},{28,51},{29,51},{30,51},{31,51},{32,51},{33,51},{34,51},{35,51}};
static const uint8_t keyIcon[33][2] = {{4,0},{5,0},{6,0},{3,1},{4,1},{6,1},{7,1},{3,2},{4,2},{5,2},{6,2},{7,2},{3,3},{4,3},{5,3},{6,3},{7,3},{4,4},{5,4},{6,4},{5,5},{6,5},{5,6},{6,6},{5,7},{6,7},{4,8},{5,8},{6,8},{4,9},{5,9},{6,9},{5,10}};
static const uint8_t heartIcon[85][2] = {{1,0},{2,0},{3,0},{7,0},{8,0},{9,0},{0,1},{1,1},{2,1},{3,1},{4,1},{6,1},{7,1},{8,1},{9,1},{10,1},{0,2},{1,2},{2,2},{3,2},{4,2},{5,2},{6,2},{7,2},{8,2},{9,2},{10,2},{0,3},{1,3},{2,3},{3,3},{4,3},{5,3},{6,3},{7,3},{8,3},{9,3},{10,3},{0,4},{1,4},{2,4},{3,4},{4,4},{5,4},{6,4},{7,4},{8,4},{9,4},{10,4},{0,5},{1,5},{2,5},{3,5},{4,5},{5,5},{6,5},{7,5},{8,5},{9,5},{10,5},{1,6},{2,6},{3,6},{4,6},{5,6},{6,6},{7,6},{8,6},{9,6},{2,7},{3,7},{4,7},{5,7},{6,7},{7,7},{8,7},{3,8},{4,8},{5,8},{6,8},{7,8},{4,9},{5,9},{6,9},{5,10}};
static const uint8_t gpsIcon[46][2] = {{9,0},{10,0},{7,1},{8,1},{9,1},{10,1},{5,2},{6,2},{7,2},{8,2},{9,2},{3,3},{4,3},{5,3},{6,3},{7,3},{8,3},{9,3},{1,4},{2,4},{3,4},{4,4},{5,4},{6,4},{7,4},{8,4},{0,5},{1,5},{2,5},{3,5},{4,5},{5,5},{6,5},{7,5},{8,5},{5,6},{6,6},{7,6},{5,7},{6,7},{7,7},{5,8},{6,8},{5,9},{6,9},{5,10}};
static const uint8_t batteryIcon[58][2] = {{0,2},{1,2},{2,2},{3,2},{4,2},{5,2},{6,2},{7,2},{8,2},{9,2},{0,3},{1,3},{2,3},{3,3},{9,3},{0,4},{1,4},{2,4},{3,4},{4,4},{9,4},{10,4},{0,5},{1,5},{2,5},{3,5},{4,5},{5,5},{9,5},{10,5},{0,6},{1,6},{2,6},{3,6},{4,6},{5,6},{6,6},{9,6},{10,6},{0,7},{1,7},{2,7},{3,7},{4,7},{5,7},{6,7},{7,7},{9,7},{0,8},{1,8},{2,8},{3,8},{4,8},{5,8},{6,8},{7,8},{8,8},{9,8}};

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
      if(analogStatesNew[i] == 0){
        popupTrigger(0);
      }
      else{
      int k = i +1;
      popupTrigger(k);
      changedChip = true;
      }
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
      drawPopup("Your food preferences have been registered with the nearest supermarket." , -0.2);
      delay(5000);
      drawBaseInterface(analogStatesNew);
    break;
    case 2:
    drawPopup("New Contacts added! You have 43 new friends!" , -0.5);
      delay(5000);
      drawBaseInterface(analogStatesNew);
    break;
    case 3:
      drawPopup("You should be at work right now! Hurry!" , 5.3);
      delay(5000);
      drawBaseInterface(analogStatesNew);
    break;
    case 4:
      drawPopup("The new Spice and Wolf season is airing right now! Go watch it!" , 1.5);
      delay(5000);
      drawBaseInterface(analogStatesNew);
    break;
    case 5:
      drawPopup("Don't forget to go to the football viewing party tonight." , -0.5);
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
  tft.setCursor(30,42);
  tft.setTextColor(DARK_CYAN);
  tft.setTextSize(2);
  tft.println("wanOs");
  tft.setTextSize(1);
  tft.setCursor(3,86);
  tft.setTextColor(GREEN);
  if(divient < 0){
    divient = 0;
  }
  String b = "% divergent";
  String a = divient + b;
  tft.println(a);

  //drawIcon(wanLogo, 756, 34,28,DARK_CYAN);
  drawIcon(keyIcon, 33, 2,2,DARK_CYAN);
  drawIcon(heartIcon, 85, 15,2,DARK_CYAN);
  drawIcon(gpsIcon, 46, 28,2,DARK_CYAN);
  drawIcon(batteryIcon, 58, 41,2,DARK_CYAN);

  /*for(int i =0; i < 5; i++){
    switch(analogStatesNew[i]){
      case 0:
        //drawIcon(logoArray, 0,0,RED);
      break;
      //more stuff for different states
    }
  }*/
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

//icons should be 11 by 11
void drawIcon(uint8_t drawing[][2],int l, int x, int y, uint16_t color){
  //script to readout arryas generated by pauline and draw them somwhere on the screen
  for(int i = 0; i < l; i++){
    //pixel packets are here
    tft.drawPixel(drawing[i][0] + x,drawing[i][1] + y,color);
  }
}
