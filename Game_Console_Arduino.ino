#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel matrix(16, 6, NEO_GRB + NEO_KHZ800);

void setup() {
  matrix.begin();
  Serial.begin(9600);
}

void loop() {
  matrix.clear();
  for (int i = 0; i<4; i++) {
    int pixel = random(16);
    Serial.print("Pixel : ");
    Serial.print(pixel);
    Serial.print(", ");
    
    matrix.setPixelColor(pixel, 5, 0, 0);
  }
    Serial.println("");
    matrix.show();
    delay(5000);
}