void turn_l() {
  motR.setSpeed(sp, MOT_PWM);
  motL.setSpeed(sp, MOT_PWM);
  delay(1500);
  motR.setSpeed( sp, MOT_PWM);
  motL.setSpeed(-sp, MOT_PWM);
  delay(100);
  while (!(bum.getLineDigital(1))) {
    motR.setSpeed( sp, MOT_PWM);
    motL.setSpeed(-sp, MOT_PWM);
  }
  while (!(bum.getLineDigital(5))) {
    motR.setSpeed( sp, MOT_PWM);
    motL.setSpeed(-sp, MOT_PWM);
  }
  motR.setSpeed(0, MOT_PWM);
  motL.setSpeed(0, MOT_PWM);
}
void turn_r() {
  motR.setSpeed(sp, MOT_PWM);
  motL.setSpeed(sp, MOT_PWM);
  delay(1500);
  motR.setSpeed(-sp, MOT_PWM);
  motL.setSpeed( sp, MOT_PWM);
  delay(100);
  while (!(bum.getLineDigital(9))) {
    motR.setSpeed(-sp, MOT_PWM);
    motL.setSpeed( sp, MOT_PWM);
  }
  while (!(bum.getLineDigital(5))) {
    motR.setSpeed(-sp, MOT_PWM);
    motL.setSpeed( sp, MOT_PWM);
  }
  motR.setSpeed(0, MOT_PWM);
  motL.setSpeed(0, MOT_PWM);
}
void turn_180() {
  motR.setSpeed(sp, MOT_PWM);
  motL.setSpeed(sp, MOT_PWM);
  delay(1500);
  motR.setSpeed(-sp, MOT_PWM);
  motL.setSpeed( sp, MOT_PWM);
  delay(100);
  while (!(bum.getLineDigital(9))) {
    motR.setSpeed(-sp, MOT_PWM);
    motL.setSpeed( sp, MOT_PWM);
  }
  while (!(bum.getLineDigital(5))) {
    motR.setSpeed(-sp, MOT_PWM);
    motL.setSpeed( sp, MOT_PWM);
  }
  motR.setSpeed(-sp, MOT_PWM);
  motL.setSpeed( sp, MOT_PWM);
  delay(100);
  while (!(bum.getLineDigital(9))) {
    motR.setSpeed(-sp, MOT_PWM);
    motL.setSpeed( sp, MOT_PWM);
  }
  while (!(bum.getLineDigital(5))) {
    motR.setSpeed(-sp, MOT_PWM);
    motL.setSpeed( sp, MOT_PWM);
  }
  motR.setSpeed(0, MOT_PWM);
  motL.setSpeed(0, MOT_PWM);
}
