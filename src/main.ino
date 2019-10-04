// Use the MD_MAX72XX library to Print some text on the display
//
// Demonstrates the use of the library to print text.
//
// User can enter text on the serial monitor and this will display as a
// message on the display.

#include <MD_MAX72xx.h>
#include <SPI.h>


#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW
#define MAX_DEVICES 12

#define CLK_PIN 13  // or SCK
#define DATA_PIN 11 // or MOSI
#define CS_PIN 10   // or SS

MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);



void setup()
{
    mx.begin();
    Serial.begin(9600);
}

int t[][5] = {
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
    {4, 4},
    {4, 5},
    //middle
    {2, 0},
    {2, 1},
    {2, 2},
    {2, 3},
    {2, 4},
    {2, 5},
    //bottom
    {0, 0},
    {0, 1},
    {0, 2},
    {0, 3},
    {0, 4},
    {0, 5},
    //missing parts of "trunk"
    {1, 5},
    {3, 5}
};


void loop()
{

    for(int i = 0; i < 20; i++) {

        int row = e[i][0];
        int col = e[i][1];
        Serial.print(row);
        Serial.print("-");
        Serial.print(col);
        Serial.println(); 
        mx.setPoint(row, col, true); 
    }
    /* //Letters, relative to an origin
    //row, column
    int t[1][6] = {
        {3, 0},
        {3, 1},
        {3, 2},
        {3, 3},
        {3, 4},
        {0, 2}
    };  */
    
    /* mx.setPoint(4, 0, true);
    mx.setPoint(4, 1, true);
    mx.setPoint(4, 2, true);
    mx.setPoint(4, 3, true);
    mx.setPoint(4, 4, true);

    mx.setPoint(2, 4, true);
    mx.setPoint(2, 4, true); */
}
