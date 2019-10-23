// Display dependencies: 
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>

// Clock dependencies:
#include "RTClib.h"

#if defined(ESP32)
#elif defined(ESP8266)

#else
// For the breakout board, you can use any 2 or 3 pins.
// These pins will also work for the 1.8" TFT shield.
#define TFT_CS 10
#define TFT_RST 9 // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC 8
#endif

RTC_DS1307 rtc;
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);


void init_display() {

    tft.initR(INITR_BLACKTAB); 
    tft.fillScreen(ST77XX_BLACK);
}

void init_clock() {

    rtc.begin();
    if (!rtc.isrunning()) {
        Serial.println("RTC is NOT running!");
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }
}

void setup(void)
{
    
    init_display(); 
    init_clock();
}

void loop()
{

    DateTime time = rtc.now();
    String as_string = time.toString("hh:mm:ss");
    char time_buffer[25];
    as_string.toCharArray(time_buffer, 25); 
    testdrawtext(time_buffer, ST77XX_WHITE);

    //Full Timestamp
    Serial.println(String("DateTime::TIMESTAMP_FULL:\t") + time.timestamp(DateTime::TIMESTAMP_FULL));

    //Date Only
    Serial.println(String("DateTime::TIMESTAMP_DATE:\t") + time.timestamp(DateTime::TIMESTAMP_DATE));

    //Full Timestamp
    Serial.println(String("DateTime::TIMESTAMP_TIME:\t") + time.timestamp(DateTime::TIMESTAMP_TIME));

    delay(5000);
}

void testdrawtext(char* text, uint16_t color)
{
    tft.setCursor(0, 0);
    tft.setTextColor(color);
    tft.setTextWrap(true);
    tft.print(text);
}
