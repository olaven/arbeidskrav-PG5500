#include "LedControl.h"                    //  need the library
LedControl lc = LedControl(12, 11, 10, 1); //

// pin 12 is connected to the MAX7219 pin 1
// pin 11 is connected to the CLK pin 13
// pin 10 is connected to LOAD pin 12
// 1 as we are only using 1 MAX7219

void setup()
{
    // the zero refers to the MAX7219 number, it is zero for 1 chip
    lc.shutdown(0, false); // turn off power saving, enables display
    lc.setIntensity(0, 1); // sets brightness (0~15 possible values)
    lc.clearDisplay(0);    // clear screen
}
void loop()
{
    delay(1500); 
    light_all();
    delay(1500);
    dark_all(); 
    light(6, 2);
    light(1, 2);
}

void light(int col, int row) {

    lc.setLed(0, col, row, true);
    delay(25);
}

void dark(int col, int row) {

    lc.setLed(0, col, row, false);
    delay(25);
}

void light_all() {

    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            light(col, row); 
        }
    }
}

void dark_all()
{

    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            dark(col, row); 
        }
    }
}