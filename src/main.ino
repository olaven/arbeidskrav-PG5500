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
    {3, 3}
};

int s[][10] = {
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

void log(int row, int col) 
{

    Serial.print(row);
    Serial.print("-");
    Serial.print(col);
    Serial.println();
}

void loop()
{

    for(int i = 0; i < 20; i++) {

        int row = s[i][0];
        int col = s[i][1];
        log(row, col);
        mx.setPoint(row, col, true); 
    }
}
