#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel matrix(16, 6, NEO_GRB + NEO_KHZ800);

void setup() {
  matrix.begin();
}

void loop() {
  for (int i = 0; i < matrix.numPixels(); i++) {
    matrix.setPixelColor(i, 0, 5, 0);
    matrix.show();
    delay(200);
  }

  for (int i = 0; i < matrix.numPixels(); i++) {
    matrix.setPixelColor(i, 0, 0, 0);
    matrix.show();
  }
}