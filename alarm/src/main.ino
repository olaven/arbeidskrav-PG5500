// Display definitions:
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>
#if defined(ESP32)
#elif defined(ESP8266)
#else
#define TFT_CS 10
#define TFT_RST 9 // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC 8
#endif
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

// Clock definitions:
#include "RTClib.h"
RTC_DS1307 rtc;

// Speaker definitions:
#include "Tone.h"
const int speaker_pin = 7;
Tone player;

// Button definitions
const int buttons[] = {1, 2, 3, 4};

// Distance sensor definitions
const int trigger_pin = 5; //Trig pin
const int echo_pin = 6;    //Echo pin
long Duration = 0;

const bool alarm_triggered = false;
const char *last_trigger_timestamp = "never triggered";

void init_display()
{

    tft.initR(INITR_BLACKTAB);
    tft.fillScreen(ST77XX_BLACK);
    tft.invertDisplay(true);
}

void init_clock()
{

    rtc.begin();
    if (!rtc.isrunning())
    {
        Serial.println("RTC is NOT running!");
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }
}

void init_speaker()
{
    player.begin(speaker_pin);
}

void setup(void)
{

    Serial.begin(9600); 
    init_display();
    init_clock();
    init_speaker();
}

void draw_text(char *text, uint16_t color)
{
    Serial.println(text);
    Serial.println(color);
    tft.setCursor(0, 0);
    tft.setTextColor(color);
    tft.setTextWrap(true);
    tft.setTextSize(20);
    tft.print(text);
}

char *get_current_timestamp()
{

    DateTime time = rtc.now();
    String as_string = time.toString("hh:mm:ss");
    char time_buffer[25];
    as_string.toCharArray(time_buffer, 25);

    return time_buffer;
}

long Distance(long time)
{
    // Calculates the Distance in mm
    // ((time)*(Speed of sound))/ toward a
    
    long DistanceCalc = ((time /2.9) / 2);     // Actual calculation in mm
    return DistanceCalc;                       // return calculated value
}

long get_current_distance() {

    digitalWrite(trigger_pin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigger_pin, HIGH);        // Trigger pin to HIGH
    delayMicroseconds(10);                 // 10us high
    digitalWrite(trigger_pin, LOW);         // Trigger pin to HIGH
    Duration = pulseIn(echo_pin, HIGH);     // Waits for the echo pin to get high & returns the Duration in microseconds
    long Distance_mm = Distance(Duration); // Use function to calculate the distance
    Serial.print("Distance = ");           // Output to serial
    Serial.print(Distance_mm);
    Serial.println(" mm");
    delay(50);

    return Distance_mm; 
}

void render_idle_screen() {

    tft.fillScreen(ST7735_GREEN);

    char *timestamp = get_current_timestamp();
    draw_text(timestamp, ST7735_BLACK); 
}

void render_triggered_screen() 
{

    //TODO: Implement
}

//NOTE: avstandssensor på 6 og 5
void loop()
{

    long distance = get_current_distance(); 
    Serial.print("Distance: "); 
    Serial.println(distance); 

    if (alarm_triggered)
    {
        render_triggered_screen();
    }
    else
    {
        render_idle_screen();
    }
    //player.play(NOTE_A3);
}