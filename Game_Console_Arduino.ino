#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel matrix(16, 6, NEO_GRB + NEO_KHZ800);
int randomNum[6];

void setup() {
  matrix.begin();
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  matrix.clear();
  int count = 0;
  
  while (count < 6) {
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
    matrix.clear();

    Serial.print("Pixel Red : ");
    for (int i = 0; i<4; i++) {
      Serial.print(randomNum[i]);
      Serial.print(" ");
      matrix.setPixelColor(randomNum[i], 5, 0, 0);
    }
    

    Serial.print("Pixel Green : ");
    for (int i = 4; i<6; i++) {
      Serial.print(randomNum[i]);
      Serial.print(" ");
      matrix.setPixelColor(randomNum[i], 0, 5, 0);
    }
    Serial.println();
    matrix.show();
    delay(1000);
  }

