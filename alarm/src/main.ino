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
const int buttons[] = {A0, 2, 3, 4};
const int code[] = {HIGH, HIGH, LOW, LOW};  
// Distance sensor definitions
const int trigger_pin = 5; 
const int echo_pin = 6;    
int previous_distance = 0; 

// general logic 
int run_counter = 0; 
bool alarm_triggered = false;
const char *last_trigger_timestamp = "never triggered";

void init_display()
{
    tft.initR(INITR_BLACKTAB);
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

void draw_text(String text, uint16_t text_color, uint16_t background_color)
{
    tft.setCursor(0, 0);
    tft.setTextColor(text_color, background_color);
    tft.setTextSize(1); 
    tft.print("---- " + text + "----"); 
}

void get_current_timestamp(char** buffer)
{
    DateTime time = rtc.now();
    String as_string = time.timestamp(DateTime::TIMESTAMP_TIME);
    as_string.toCharArray(*buffer, 25);
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
    char *timestamp;
    get_current_timestamp(&timestamp);
    draw_text(timestamp, ST7735_BLACK, ST7735_GREEN);
}

void render_triggered_screen()
{
    draw_text(last_trigger_timestamp, ST7735_WHITE, ST7735_BLUE);
    player.play(NOTE_C4);
}

boolean button_combinations_are_valid() {

    for(int i = 0; i < 4; i++) {

        const int pin = buttons[i]; 
        const int expected = code[i]; 
        const int actual = digitalRead(pin); 

        if (expected != actual) {
            return false; 
        }
    }

    return true; 
}

void loop()
{
    long distance = get_current_distance();
    run_counter += 1;

    if (run_counter > 10) //will have invalid `previous_distance`
    {

        long difference = distance - previous_distance;
        if (difference > 250 || difference < -250)
        {

            get_current_timestamp(&last_trigger_timestamp);
            tft.fillScreen(ST7735_BLUE); //renders as RED. Error in library?
            alarm_triggered = true;
        }
    }

    previous_distance = distance; 


    if (alarm_triggered)
    {
        render_triggered_screen();
    }
    else
    {
        render_idle_screen();
    }


    if (button_combinations_are_valid()) 
    {
        alarm_triggered = false;
        tft.fillScreen(ST7735_GREEN);
        player.stop(); 
    }
}