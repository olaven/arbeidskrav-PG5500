#ifndef ARBEIDSKRAV_CONFIGURE_MX
#define ARBEIDSKRAV_CONFIGURE_MX

#include <MD_MAX72xx.h>
#include <./letters.ino>

#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW
#define MAX_DEVICES 12

#define CLK_PIN 13  // or SCK
#define DATA_PIN 11 // or MOSI
#define CS_PIN 10   // or SS


MD_MAX72XX configuredMX()
{

    return MD_MAX72XX(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
}

#endif