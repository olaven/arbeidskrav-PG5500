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

void init_distance_sensor()
{

    pinMode(trigger_pin, OUTPUT); // Trigger is an output pin
    pinMode(echo_pin, INPUT);
}

void setup(void)
{

    Serial.begin(9600);
    init_display();
    init_clock();
    init_speaker();
    init_distance_sensor();
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

long get_current_distance()
{

    digitalWrite(trigger_pin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigger_pin, HIGH);    
    delayMicroseconds(10);              
    digitalWrite(trigger_pin, LOW);     

    long duration = pulseIn(echo_pin, HIGH);
    long distance = ((duration / 2.9) / 2);

    return distance;
}

void render_idle_screen()
{

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