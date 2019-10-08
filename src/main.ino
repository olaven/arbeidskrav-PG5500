#include "LedControl.h"

LedControl lc = LedControl(11, 13, 10, 1);
unsigned long delaytime = 500;

void setup()
{
    lc.shutdown(0, false);
    lc.setIntensity(0, 8);
    lc.clearDisplay(0);
}

void write_letter(byte letter[5], int adjustment)
{

    for(int i = 0; i < 5; i++)
    {
        
        int adjusted = i + adjustment;
        lc.setRow(0, adjusted, letter[i]);
    }
}

void scroll_word(byte * word[7]) 
{

    int adjustment = calculate_adjustment(); 

    for (int i = 0; i < 7; i++)
    {
        write_letter(word[i], adjustment);
        delay(delaytime);
    }
}

int calculate_adjustment()
{

    return 0; //TODO 
}

void write_arduino_on_matrix()
{

    byte a[5] = {B01111110, B00010001, B00010001, B00010001, B01111110}; //no need
    byte r[5] = {B01111100, B00001000, B00001000, B00000100, B00001000}; //flipped
    byte d[5] = {B00111000, B01000100, B01000100, B01001000, B01111111}; //flipped 
    byte u[5] = {B00111100, B01000000, B01000000, B00100000, B01111100}; //flipped
    byte i[5] = {B00000000, B01000100, B01111101, B01000000, B00000000}; //flipped 
    byte n[5] = {B01111100, B00001000, B00000100, B00000100, B01111000}; //flipped
    byte o[5] = {B00011100, B00100010, B00100010, B00100010, B00011100}; //no need

    byte * arduino[7] = {a, r, d, u, i, n, o};

    scroll_word(arduino);
}



void loop()
{
    write_arduino_on_matrix();
}
