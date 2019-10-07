
#include <./mx.ino>
#include <./letters.ino>

MD_MAX72XX mx = configuredMX();
//LedControl lc = LedControl(11, 13, 10, 1);
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

    mx.clear(); 
    loop_count++;
    int word[] = {t, e, s, t};
    int origo = loop_count % 8;
    //int origo = calculate_origo(); 
    
    for(int i = 0; i < word; i++) {
    
        int adjustment = i * letter_width; 
        int base = origo - adjustment; 
        writeLetter(base, word[i]);
    }
}
