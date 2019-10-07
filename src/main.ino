
#include <letters.ino>
#include "LedControl.h"


LedControl lc = LedControl(11, 13, 10, 1);

/* we always wait a bit between updates of the display */
unsigned long delaytime = 500;

void setup()
{
    /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
    lc.shutdown(0, false);
    /* Set the brightness to a medium values */
    lc.setIntensity(0, 8);
    /* and clear the display */
    lc.clearDisplay(0);
}

void writeLetter(byte letter[5], int d = 300) 
{
    for(int i = 0; i < 5; i++) 
    {
        lc.setRow(0, i, letter[i]);
        delay(d);
    }
}

void writeArduinoOnMatrix()
{
    /* here is the data for the characters */
    byte a[5] = {B01111110, B10001000, B10001000, B10001000, B01111110};
    byte r[5] = {B00111110, B00010000, B00100000, B00100000, B00010000};
    byte d[5] = {B00011100, B00100010, B00100010, B00010010, B11111110};
    byte u[5] = {B00111100, B00000010, B00000010, B00000100, B00111110};
    byte i[5] = {B00000000, B00100010, B10111110, B00000010, B00000000};
    byte n[5] = {B00111110, B00010000, B00100000, B00100000, B00011110};
    byte o[5] = {B00011100, B00100010, B00100010, B00100010, B00011100};

    byte arduino[][7] = {a, r, d, u, i, n, o};

    /* now display them one by one with a small delay */
    for(int i = 0; i < 7; i++) 
    {
        writeLetter(arduino[i]);
    }
}



void loop()
{
    writeArduinoOnMatrix();
    
}
