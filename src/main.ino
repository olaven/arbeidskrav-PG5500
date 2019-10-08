#include "LedControl.h"

LedControl lc = LedControl(11, 13, 10, 1);
unsigned long delaytime = 500;
int beginning_position = 8; //NOTE: end of display + 1; 

/**
 * Writes a single letter to the matrix, 
 * with adjusted from 0th row. 
 */
void write_letter(byte letter[5], int adjustment)
{
    for(int i = 0; i < 5; i++)
    {
        int adjusted_row = i + adjustment;
        lc.setRow(0, adjusted_row, letter[i]);
    }
}

/**
 * Scrolls given byte array (letters)
 * accross the matrix. 
 */
void scroll_word(byte * word[7]) 
{

    for (int i = 0; i < 7; i++)
    {
        int adjustment = (i * 5) + beginning_position;
        write_letter(word[i], adjustment);
    }
}

/**
 * If entire word has been displayed, 
 * the beginning is reset. Otherwize, 
 * the word moves one step.  
 */
int adjusted_beginning(int current)
{
    int restart_point = -7 * 5;
    if (current == restart_point)
    {
        return 8;
    }

    return --current;
}

void write_arduino_on_matrix()
{
    byte empty = B00000000; 
    byte a[5] = {B01111110, B00010001, B00010001, B00010001, B01111110}; 
    byte r[5] = {B01111100, B00001000, B00001000, B00000100, B00001000}; 
    byte d[5] = {B00111000, B01000100, B01000100, B01001000, B01111111}; 
    byte u[5] = {B00111100, B01000000, B01000000, B00100000, B01111100}; 
    byte i[5] = {B00000000, B01000100, B01111101, B01000000, B00000000}; 
    byte n[5] = {B01111100, B00001000, B00000100, B00000100, B01111000}; 
    byte o[5] = {B00011100, B00100010, B00100010, B00100010, B00011100}; 

    byte * arduino[7] = {a, r, d, u, i, n, o};
    scroll_word(arduino);
}

void setup()
{
    lc.shutdown(0, false);
    lc.setIntensity(0, 8);
    lc.clearDisplay(0);
}

void loop()
{
    lc.clearDisplay(0); 
    write_arduino_on_matrix();
    beginning_position = adjusted_beginning(beginning_position);
    delay(delaytime);
}
