
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>

#if defined(ESP32)
#elif defined(ESP8266)

#else
// For the breakout board, you can use any 2 or 3 pins.
// These pins will also work for the 1.8" TFT shield.
#define TFT_CS 10
#define TFT_RST 9 // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC 8
#endif


Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);


float p = 3.1415926;

void setup(void)
{
    
    // Use this initializer if using a 1.8" TFT screen:
    tft.initR(INITR_BLACKTAB); // Init ST7735S chip, black tab

    uint16_t time = millis();
    tft.fillScreen(ST77XX_BLACK);
    time = millis() - time;


    delay(500);

    // large block of text

    testdrawtext("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur adipiscing ante sed nibh tincidunt feugiat. Maecenas enim massa, fringilla sed malesuada et, malesuada sit amet turpis. Sed porttitor neque ut ante pretium vitae malesuada nunc bibendum. Nullam aliquet ultrices massa eu hendrerit. Ut sed nisi lorem. In vestibulum purus a tortor imperdiet posuere. ", ST77XX_WHITE);
}

void loop()
{
    tft.invertDisplay(true);
    delay(500);
    tft.invertDisplay(false);
    delay(500);

    testdrawtext("hei, hei, hei, hei, hei, hei, hei, hei, hei, hei, hei, hei, hei, hei, hei, hei, hei, hei, hei, hei, hei, ", ST77XX_GREEN);
}

void testdrawtext(char *text, uint16_t color)
{
    tft.setCursor(0, 0);
    tft.setTextColor(color);
    tft.setTextWrap(true);
    tft.print(text);
}
