#include "jammer.h"
#include <RF24.h>

extern RF24 RadioA;
extern RF24 RadioB;

void jammerSetup() {
  RadioA.startConstCarrier(RF24_PA_MAX, 40);
  RadioB.startConstCarrier(RF24_PA_MAX, 70);
}

void jammerLoop() {
  RadioA.setChannel(random(80));
  RadioB.setChannel(random(80));
  delayMicroseconds(random(60));
}