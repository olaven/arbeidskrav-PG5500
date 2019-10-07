#include <MD_MAX72xx.h>
#include <./letters.ino>


#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW
#define MAX_DEVICES 12

#define CLK_PIN 13  // or SCK
#define DATA_PIN 11 // or MOSI
#define CS_PIN 10   // or SS

MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

int loop_count = 0; 

void log(int row, int col)
{

    Serial.print(row);
    Serial.print("-");
    Serial.print(col);
    Serial.println();
}

void writeLetter(int origo, int letter[][20])
{

    for (int i = 0; i < 20; i++)
    {

        int row = letter[i][0];
        int col = origo + letter[i][1];
        //log(row, col);
        mx.setPoint(row, col, true);
    }
}




void setup()
{
    mx.begin();
    Serial.begin(9600);
}

void loop()
{

    mx.clear();
    loop_count++;

    int origo = loop_count % 8; 
    Serial.print("origo: ");
    Serial.println(origo);
    int word[] = {
        t, e, s, t
    };
    
    writeLetter(origo, t);
    delay(1000);
}
