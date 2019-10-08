#include "LedControl.h"

LedControl lc = LedControl(11, 13, 10, 1);
unsigned long delaytime = 500;
int beginning_position = 8; //NOTE: end of display + 1; 

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
        
        int adjusted_row = i + adjustment;
        lc.setRow(0, adjusted_row, letter[i]);
    }
}

void scroll_word(byte * word[7]) 
{

    for (int i = 0; i < 7; i++)
    {

        int adjustment = (i * 5) + beginning_position;
        write_letter(word[i], adjustment);
    }
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

//NOTE: not used yet 
int adjust_beginning(int current) 
{

    return current--; 
}

void loop()
{
    lc.clearDisplay(0); 
    write_arduino_on_matrix();
    beginning_position--; //TODO: adjust back when entire word is shown
    delay(delaytime);
}
