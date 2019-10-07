#include <./mx.ino>
#include <./letters.ino>

MD_MAX72XX mx = configuredMX();
int loop_count = 0;
const int letter_width = 4; 

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

    
    //int word[] = {t, e, s, t};

    writeLetter(0, t);
    /* loop_count++;
    int origo = loop_count % 8;
    for(int i = 0; i < word; i++) {
    
        //TODO: use origo
        Serial.print("letter width: ");
        Serial.println(letter_width);
        writeLetter(i * letter_width, word[i]);
    }  */

    
}
