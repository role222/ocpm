int color() {
  int col[3], coll;
  for (int i = 0; i < 3; i++) {
    float r, g, b;
    tcs.getRGB(&r, &g, &b);
    if (b > r && g > r && abs(g - b) < 15) col[i] = 3;               //синий
    else if (r > g && r > b) col[i] = 2;               //красный
    else if (r > b && g > b && abs(r - g) < 10) col[i] = 1;               //жёлтый
    else if (g > r && g > b) col[i] = 0;               //белый
    //Serial << r << " " << g " " << b << endl;
    Serial.print(b);
    Serial.print(" ");
    Serial.print(r);
    Serial.print(" ");
    Serial.println(g);
    disp.print(col[i]);
  }
  if ((col[1] == 0 && col[2] == 0) || (col[2] == 0 && col[0] == 0) || (col[1] == 0 && col[0] == 0)) {
    coll = 0;
  }
  if ((col[1] == 1 && col[2] == 1) || (col[2] == 1 && col[0] == 1) || (col[1] == 1 && col[0] == 1)) {
    coll = 1;
  }
  if ((col[1] == 2 && col[2] == 2) || (col[2] == 2 && col[0] == 2) || (col[1] == 2 && col[0] == 2)) {
    coll = 2;
  }
  if ((col[1] == 3 && col[2] == 3) || (col[2] == 3 && col[0] == 3) || (col[1] == 3 && col[0] == 3)) {
    coll = 3;
  }
  //Serial << coll <<endl;
  return (coll);
}
