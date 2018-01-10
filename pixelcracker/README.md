# Small Processing 3 script to convert monocolour images and icons into 2d arrays

Checks if pixels are black and if they are, stores their x and y values in a 2d array.
This is mostly useful when needing to display complex shapes without using bitmap rendering. Remember that size on the chips are definitly a concern.

Right now the script looks for everything that resembles black and treats every other pixel to be not needed. By editing line 33 one can change its filter critera.
```cpp

if(r < 10 && g < 10 && b < 10){

```

In case of using a tft or oled display with the Adafruit GFX library you can use the following function:

```cpp
void drawIcon(uint8_t drawing[][2],int l, int x, int y, uint16_t color){
  //script to readout arryas generated by pauline and draw them somwhere on the screen
  for(int i = 0; i < l; i++){
    //pixel packets are here
    tft.drawPixel(drawing[i][0] + x,drawing[i][1] + y,color);
  }
}
```
(array that holds the pixel coordinates, length of the array, position x, position y, colour that it should be drawn in)