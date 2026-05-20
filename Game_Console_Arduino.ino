/*#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel matrix(16, 6, NEO_GRB + NEO_KHZ800);
int randomNum[6];
const int X = A2;
const int Y = A3;
const int SW = 4;

int position = 0;

void setup() {
  pinMode(SW, INPUT_PULLUP);
  matrix.begin();
  Serial.begin(9600);
  randomSeed(analogRead(0));

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
}

void loop() {
  int x = analogRead(X);

  if (x < 300) {
    position = position - 1;
    Serial.println(position);
    delay(300);
  } else if (x > 700) {
    position = position - 1;
    Serial.println(position);
    delay(300);
  }

  int y = analogRead(Y);
  int btn = digitalRead(SW);

  if (isClicked(btn) == LOW) {
    while(true) {
      matrix.setPixelColor(randomNum[5], 0, 5, 0);
      matrix.show();
      delay(750);
      matrix.setPixelColor(randomNum[5], 0, 0, 0);
      matrix.show();
      delay(750);
    }
  }
}

bool isClicked(int btn) {
  if(btn == LOW) {
    return true;
  }
  return false;
}*/






/*
int joystickX = A2;
int joystickY = A3;
int position = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int xValue = analogRead(joystickX);
  // Joystick moved LEFT
  if (xValue < 300) {
    position = position - 1;
    Serial.print("Horizontal : ");
    Serial.println(position);
    delay(300);
  }

  // Joystick moved RIGHT
  else if (xValue > 700) {
    position = position + 1;
    Serial.print("Horizontal : ");
    Serial.println(position);
    delay(300);
  }

  int yValue = analogRead(joystickY);
  // Joystick moved LEFT
  if (yValue < 300) {
    position = position - 1;
    Serial.print("Vertical : ");
    Serial.println(position);
    delay(300);
  }

  // Joystick moved RIGHT
  else if (yValue > 700) {
    position = position + 1;
    Serial.print("Vertical : ");
    Serial.println(position);
    delay(300);
  }
}
*/




#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#define SW 4
Adafruit_NeoPixel matrix(16, 6, NEO_GRB + NEO_KHZ800);

int joystickX = A2;
int position = 0;

void setup() {
  matrix.begin();
  Serial.begin(9600);

  pinMode(SW, INPUT_PULLUP);

  randomSeed(analogRead(A0));

  matrix.clear();
  matrix.show();
  
}

void loop() {
  int xValue = analogRead(joystickX);

  if (digitalRead(SW) == LOW) {
    position = random(16);
    Serial.print("Pixel : ");
    Serial.print(position);
    matrix.clear();
    matrix.setPixelColor(position, 5, 0, 0);
    Serial.println("");
    matrix.show();
    delay(1000);
    matrix.clear();
  }
  if (xValue < 300 && position < 15) {
    position--;
    matrix.clear();
    matrix.setPixelColor(position, 5, 0, 0);
    matrix.show();
    delay(200);
  }

  if (xValue > 700 && position > 0) {
    position++;
    matrix.clear();
    matrix.setPixelColor(position, 5, 0, 0);
    matrix.show();
    delay(200);
  }
  
}