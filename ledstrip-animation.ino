/// @file    FirstLight.ino
/// @brief   Animate a white dot moving along a strip of LEDs
/// @example FirstLight.ino

#include <FastLED.h> 

#define NUM_LEDS 60
#define Pin 2 // We define pin 2 here and we have connected this with the touch sensor
#define DATA_PIN 3


// This is an array of leds.  One item for each led in your strip.
CRGB leds[NUM_LEDS];

int ledPin = 13; // Here we make a variable ledPin 13 and this is connected with the light on the breadboard
 

void setup() {
   	delay(2000);
     Serial.begin(9600);
pinMode(ledPin, OUTPUT);
pinMode(Pin, INPUT);
//FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);

    FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);

}

// your leds.
void loop() {
   // Move a single white led 

     int Value = digitalRead(Pin); 
  if (Value == HIGH)
  {
    for(int whiteLed = 60; whiteLed > 0; whiteLed--) {
      // Turn our current led on to white, then show the leds
      leds[whiteLed] = 0x2F4F4F;

      // Show the leds (only one of which is set to white, from above)
      FastLED.show();

      // Wait a little bit
      delay(10);
  

    //digitalWrite(ledPin, HIGH);
    Serial.println("TOUCHED");
    }
    FastLED.show();
  }
  else // If the ledPin is low, the serial print send 'not touched' and the ledPin 13 turned off
  {
       digitalWrite(ledPin,LOW);
    Serial.println("not touched");
    for (int i=0; i<NUM_LEDS; i++){
         leds[i] = CRGB::Black;
    }
    FastLED.show();
  }
  delay(10);  // We do here a delay so we can read the serial print
}
