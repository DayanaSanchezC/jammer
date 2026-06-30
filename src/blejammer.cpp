#include "blejammer.h"
#if __has_include(<RF24/RF24.h>)
#include <RF24/RF24.h>
#elif __has_include(<RF24.h>)
#include <RF24.h>
#else
#error "RF24 header not found. Update your includePath or install the RF24 library."
#endif

extern RF24 RadioA;
extern RF24 RadioB;

// Canales BLE mapeados a nRF24: ch37=2, ch38=26, ch39=80
const uint8_t bleChannels[] = {2, 26, 80};
uint8_t bleIndex = 0;

void blejammerSetup() {
  RadioA.startConstCarrier(RF24_PA_MAX, bleChannels[0]);
  RadioB.startConstCarrier(RF24_PA_MAX, bleChannels[1]);
}

void blejammerLoop() {
  bleIndex = (bleIndex + 1) % 3;
  RadioA.setChannel(bleChannels[bleIndex]);
  RadioB.setChannel(bleChannels[(bleIndex + 1) % 3]);
  delayMicroseconds(150);
}