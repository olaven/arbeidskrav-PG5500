#ifndef ARBEIDSKRAV_LETTERS
#define ARBEIDSKRAV_LETTERS

#include "LedControl.h"

//NOTE: BELOW IS NEW APPROACH, WITH LEDCONTROL
/* here is the data for the characters */
byte a[5] = {B01111110, B10001000, B10001000, B10001000, B01111110};
byte r[5] = {B00111110, B00010000, B00100000, B00100000, B00010000};
byte d[5] = {B00011100, B00100010, B00100010, B00010010, B11111110};
byte u[5] = {B00111100, B00000010, B00000010, B00000100, B00111110};
byte i[5] = {B00000000, B00100010, B10111110, B00000010, B00000000};
byte n[5] = {B00111110, B00010000, B00100000, B00100000, B00011110};
byte o[5] = {B00011100, B00100010, B00100010, B00100010, B00011100};

//NOTE: BELOW IS OLD APROACH WITH MD-library
int t[][20] = {
    //horizontal part
    {4, 0},
    {4, 1},
    {4, 2},
    {4, 3},
    {4, 4},
    //vertical part
    {0, 2},
    {1, 2},
    {2, 2},
    {3, 2},
};

int e[][20] = {
    //top
    {4, 0},
    {4, 1},
    {4, 2},
    {4, 3},
    //middle
    {2, 0},
    {2, 1},
    {2, 2},
    {2, 3},
    //bottom
    {0, 0},
    {0, 1},
    {0, 2},
    {0, 3},
    //missing parts of "trunk"
    {1, 3}, //Does not render on my display. TODO: check on someone elses
    {3, 3}};

int s[][20] = {
    // bottom
    {0, 0},
    {0, 1},
    {0, 2},
    {0, 3},
    // right trunk
    {1, 0},
    // middle
    {2, 0},
    {2, 1},
    {2, 2},
    {2, 3},
    // left trunk
    {3, 3},
    // top
    // middle
    {4, 0},
    {4, 1},
    {4, 2},
    {4, 3}};

#endif