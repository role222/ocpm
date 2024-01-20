#include <Wire.h>
#include <iarduino_I2C_Bumper.h>
iarduino_I2C_Bumper bum(0x0C);
#include <iarduino_I2C_Motor.h>
iarduino_I2C_Motor motR (0x0A);
iarduino_I2C_Motor motL (0x0B);
#include <iarduino_I2C_Matrix_8x8.h>
iarduino_I2C_Matrix_8x8 disp(0x09);
#include "Adafruit_TCS34725.h"
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);

#include <Streaming.h>

float sp = 30;
float sp1 = 80;

int naprv[10];
unsigned long int t;
void setup() {
  bum.begin();
  disp.begin();
  motL.begin();
  motR.begin();
  motL.setDirection(false);
  motR.setDirection(true);
  tcs.setIntegrationTime(230);
  //Serial.begin(9600);
  if (tcs.begin(0x29)) {
  } else {
    while (1);
  }
  Serial.println("start");
  while (!(bum.getCross(1, 500))) {
    motL.setSpeed(sp, MOT_PWM);
    motR.setSpeed(sp, MOT_PWM);
  }
  t = millis();
  while (millis() - t < 2100) {
    motL.setSpeed(sp + PD(), MOT_PWM);
    motR.setSpeed(sp - PD(), MOT_PWM);
  }
  for (int i = 0; i < 10; i++) {
    t = millis();
    while (millis() - t < 730) {
      motL.setSpeed(sp + PD(), MOT_PWM);
      motR.setSpeed(sp - PD(), MOT_PWM);
    }
    motR.setSpeed(0, MOT_PWM);
    motL.setSpeed(0, MOT_PWM);
    delay(1000);
    naprv[i] = color();
    Serial.println(naprv[i]);
  }

  int i = 0;
  while (i < 10) {
    disp.print(naprv[i]);
    if (bum.getCross(5, 500)) {
      if (naprv[i] == 0) {
        t = millis();
        while (millis() - t < 500) {
          motL.setSpeed(sp + PD(), MOT_PWM);
          motR.setSpeed(sp - PD(), MOT_PWM);
        }
        while (!(bum.getCross(5, 500))) {
          motL.setSpeed(sp1 + PD(), MOT_PWM);
          motR.setSpeed(sp1 - PD(), MOT_PWM);
        }
      }
      if (naprv[i] == 1) {
        turn_l();
      }
      if (naprv[i] == 2) {
        turn_180();
      }
      if (naprv[i] == 3) {
        turn_r();
      }
      Serial.println(naprv[i]);
      i += 1;
    }
    else {
      motL.setSpeed(sp1 + PD(), MOT_PWM);
      motR.setSpeed(sp1 - PD(), MOT_PWM);
    }
  }
  while (!bum.getCross(5, 500)) {
    motL.setSpeed(sp1 + PD(), MOT_PWM);
    motR.setSpeed(sp1 - PD(), MOT_PWM);
  }
  motR.setSpeed(0, MOT_PWM);
  motL.setSpeed(0, MOT_PWM);
  disp.fillScr(); delay(1000);
  disp.clrScr();  delay(1000);
  disp.fillScr(); delay(1000);
  disp.clrScr();  delay(1000);
  turn_180();
  while (i >= 0) {
    disp.print(naprv[i]);
    if (bum.getCross(5, 500)) {
      if (naprv[i] == 0) {
        t = millis();
        while (millis() - t < 500) {
          motL.setSpeed(sp + PD(), MOT_PWM);
          motR.setSpeed(sp - PD(), MOT_PWM);
        }
        while (!(bum.getCross(5, 500))) {
          motL.setSpeed(sp1 + PD(), MOT_PWM);
          motR.setSpeed(sp1 - PD(), MOT_PWM);
        }
      }
      if (naprv[i] == 1) {
        turn_r();
      }
      if (naprv[i] == 2) {
        turn_180();
      }
      if (naprv[i] == 3) {
        turn_l();
      }
      Serial.println(naprv[i]);
      i -= 1;
    }
    else {
      motL.setSpeed(sp1 + PD(), MOT_PWM);
      motR.setSpeed(sp1 - PD(), MOT_PWM);
    }
  }
  while (!bum.getCross(5, 500)) {
    motL.setSpeed(sp1 + PD(), MOT_PWM);
    motR.setSpeed(sp1 - PD(), MOT_PWM);
  }
  turn_l();
  while (!bum.getCross(5, 500)) {
    motL.setSpeed(sp1 + PD(), MOT_PWM);
    motR.setSpeed(sp1 - PD(), MOT_PWM);
  }
  turn_180();
  while (!bum.getCross(5, 500)) {
    motL.setSpeed(sp1 + PD(), MOT_PWM);
    motR.setSpeed(sp1 - PD(), MOT_PWM);
  }
  t = millis();
  while (millis() - t < 2600) {
    motL.setSpeed(sp, MOT_PWM);
    motR.setSpeed(sp, MOT_PWM);
  }
  motL.setSpeed(0, MOT_PWM);
  motR.setSpeed(0, MOT_PWM);
  Serial.println("stop");
}
void loop() {
}
