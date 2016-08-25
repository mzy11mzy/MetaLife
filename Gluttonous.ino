const int buttons[4] = {22, 24, 26, 28},    //up, down, left, right
          matrix_anode[3][3] = {{30, 31, 32},//阳
                          {33, 34, 35},
                          {36, 37, 38}},
          matrix_cathode[3][3] = {{39, 40, 41},//阴
                          {42, 43, 44},
                          {45, 46, 47}};

int posX = 0, posY = 0; //original
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  for (int i = 0; i < 4; ++i) 
    pinMode(buttons[i], INPUT);
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) {
      pinMode(matrix_anode[i][j], OUTPUT);
      digitalWrite(matrix_anode[i][j], HIGH);
      pinMode(matrix_cathode[i][j], OUTPUT);
      digitalWrite(matrix_cathode[i][j], HIGH);
    }
  //digitalWrite(matrix_cathode[posX][posY], LOW);
}

bool trigger[4] = {false, false, false, false};
bool lastTrigger[4] = {false, false, false, false};
void loop() {
  // put your main code here, to run repeatedly:
  delay(20);
  for (int i = 0; i < 4; ++i)
    if (digitalRead(buttons[i]) == LOW) {
      Serial.println(i);
      if (trigger[i] == false) {
        if (lastTrigger[i] == true) {
          trigger[i] = true;
          if (i == 0 && posX > 0) {
            digitalWrite(matrix_cathode[posX][posY], HIGH);
            digitalWrite(matrix_anode[posX - 1][posY], HIGH);
            digitalWrite(matrix_anode[posX][posY], LOW);
            digitalWrite(matrix_cathode[posX - 1][posY], LOW);
            delay(3500);
            digitalWrite(matrix_anode[posX][posY], HIGH);
            digitalWrite(matrix_cathode[posX - 1][posY],HIGH);
            posX--;
          }
          if (i == 1 && posX < 2) {
            digitalWrite(matrix_cathode[posX][posY], HIGH);
            digitalWrite(matrix_anode[posX + 1][posY], HIGH);
            digitalWrite(matrix_anode[posX][posY], LOW);
            digitalWrite(matrix_cathode[posX + 1][posY], LOW);
            delay(3500);
            digitalWrite(matrix_anode[posX][posY], HIGH);
            digitalWrite(matrix_cathode[posX + 1][posY],HIGH);
            posX++;
          }
          if (i == 2 && posY > 0) {
            digitalWrite(matrix_cathode[posX][posY], HIGH);
            digitalWrite(matrix_anode[posX][posY - 1], HIGH);
            digitalWrite(matrix_anode[posX][posY], LOW);
            digitalWrite(matrix_cathode[posX][posY - 1], LOW);
            delay(3500);
            digitalWrite(matrix_anode[posX][posY], HIGH);
            digitalWrite(matrix_cathode[posX][posY - 1],HIGH);
            posY--;
          }
          if (i == 3 && posY < 2) {
            digitalWrite(matrix_cathode[posX][posY], HIGH);
            digitalWrite(matrix_anode[posX][posY + 1], HIGH);
            digitalWrite(matrix_anode[posX][posY], LOW);
            digitalWrite(matrix_cathode[posX][posY + 1], LOW);
            delay(3500);
            digitalWrite(matrix_anode[posX][posY], HIGH);
            digitalWrite(matrix_cathode[posX][posY + 1],HIGH);
            posY++;
          }
        }
        else {
          lastTrigger[i] = true;
          trigger[i] = false;
        }
      }
    }
    else {
      trigger[i] = false;
      lastTrigger[i] = false;
    }
    Serial.print(posX);
    Serial.print(",");
    Serial.println(posY);
}

