#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#define SW 4
Adafruit_NeoPixel matrix(16, 6, NEO_GRB + NEO_KHZ800);

void(*resetFunc)(void) = 0;
int joystickX = A2;
int joystickY = A3;
int randomNum[6];
int position[2] = {0, 0};
// bool touch = false;

int convertPosition(int pos) {
  int row = pos / 4;
  int col = pos % 4;
  if (row % 2 == 1) {
    col = 3 - col;
  }
  return row * 4 + col;
}

void setup() {
  matrix.begin();
  matrix.show();
  Serial.begin(9600);
  randomSeed(analogRead(A0));
  pinMode(SW, INPUT_PULLUP);

  matrix.clear();
  int count = 0;
  
  while (count < 6) {
    int r = random(16);
    bool isReject = false;
  
      for (int i = 0; i < count; i++) {
        if ((randomNum[i] == r) || (randomNum[i] == r+1) || (randomNum[i] == r-1 )) {
          isReject = true;
          break;
        }
      }
  
  if (!isReject) {
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
    matrix.show();
    delay(5000);
    matrix.clear();

    Serial.print("Pixel Green : ");
    for (int i = 4; i<6; i++) {

      Serial.print(randomNum[i]);
      Serial.print(" ");
      matrix.setPixelColor(randomNum[i], 0, 5, 0);
    }
    Serial.println();
    matrix.show();
    delay(1000);

    

    position[0] = randomNum[4];
    position[1] = randomNum[5];
}

void loop() {
  int xValue = analogRead(joystickX);
  int yValue = analogRead(joystickY);

  if (xValue < 300 && position[0] % 4 > 0) {
    position[0]--;
    matrix.clear();
    int ledNumber = convertPosition(position[0]);
    matrix.setPixelColor(ledNumber, 0, 5, 0);
    matrix.setPixelColor(position[1], 0, 5, 0);
    matrix.show();
    delay(200);
  }
  if (xValue > 700 && position[0] % 4 < 3) {
    position[0]++;
    matrix.clear();
    int ledNumber = convertPosition(position[0]);
    matrix.setPixelColor(ledNumber, 0, 5, 0);
    matrix.setPixelColor(position[1], 0, 5, 0);
    matrix.show();
    delay(200);
  }
  if (yValue < 300 && position[0] < 12) {
    position[0] = position[0] + 4;
    matrix.clear();
    int ledNumber = convertPosition(position[0]);
    matrix.setPixelColor(ledNumber, 0, 5, 0);
    matrix.setPixelColor(position[1], 0, 5, 0);
    matrix.show();
    delay(200);
  }
  if (yValue > 700 && position[0] >= 4) {
    position[0] = position[0] - 4;
    matrix.clear();
    int ledNumber = convertPosition(position[0]);
    matrix.setPixelColor(ledNumber, 0, 5, 0);
    matrix.setPixelColor(position[1], 0, 5, 0);
    matrix.show();
    delay(200);
  }

  for (int i = 0; i < 4; i++) {
    if (convertPosition(position[0]) == convertPosition(randomNum[i])) {
      matrix.fill(matrix.Color(255, 0, 0));
      matrix.show();
      delay(5000);
      resetFunc();
    }
  }

  for (int i = 0; i < 4; i++) {
    if (convertPosition(position[0]) == convertPosition(position[1])) {
      matrix.fill(matrix.Color(0, 255, 0));
      matrix.show();
      delay(5000);
      resetFunc();
    }
  }

  if (digitalRead(SW) == LOW) {
    delay(50);
    resetFunc();
  }
}