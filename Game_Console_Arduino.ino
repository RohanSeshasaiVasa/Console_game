#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel matrix(16, 6, NEO_GRB + NEO_KHZ800);
int randomNum[4];

void setup() {
  matrix.begin();
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  int count = 0;
  matrix.clear();
  
  while (count < 4) {
    int r = random(16);
    bool isDuplicate = false;
  
      for (int i = 0; i < count; i++) {
        if (randomNum[i] == r) {
          isDuplicate = true;
          break;
        }
      }
  
  if (!isDuplicate) {
    randomNum[count] = r;
    count++;
      }
    }
  
    Serial.print("Pixel : ");
    for (int i = 0; i<4; i++) {
      Serial.print(randomNum[i]);
      Serial.print(" ");

      matrix.setPixelColor(randomNum[i], 100, 0, 0);
    }
    Serial.println();
    matrix.show();
    delay(5000);
  }

