// Use the MD_MAX72XX library to Print some text on the display
//
// Demonstrates the use of the library to print text.
//
// User can enter text on the serial monitor and this will display as a
// message on the display.

#include <MD_MAX72xx.h>
#include <SPI.h>
#include <./letters.ino>


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

void log(int row, int col) 
{

    Serial.print(row);
    Serial.print("-");
    Serial.print(col);
    Serial.println();
}

void writeLetter(int letter[][20]) {

    for (int i = 0; i < 20; i++)
    {

        int row = letter[i][0];
        int col = letter[i][1];
        log(row, col);
        mx.setPoint(row, col, true);
    }
}


void loop()
{

    int word[] = {
        t, e, s, t
    };
    
    for(int i = 0; i < 4; i++){

        mx.clear();
        delay(1000);
        writeLetter(word[i]);
    }
}
