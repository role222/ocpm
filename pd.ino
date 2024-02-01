float PD() {
  float i, j;
  float kp = 3 + 0.125 * (sp - 20);
  float kd = sp * sp / 250;
  i = -bum.getErrPID();
  return ((i * kp) + ((i - j) * kd));
  j = i;
}
