const int pins[] = {7,/*A*/ 6,/*B*/ 5,/*C*/ 11,/*D*/ 10,/*E*/ 8,/*F*/ 9,/*G*/ 4/*DP*/};

const int displayDelay = 2000; 

const int displayNumbers[][8] = {
  {1, 1, 1, 1, 1, 1, 0, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1, 0}, // 2
  {1, 1, 1, 1, 0, 0, 1, 0}, // 3
  {0, 1, 1, 0, 0, 1, 1, 0}, // 4
  {1, 0, 1, 1, 0, 1, 1, 0}, // 5
  {1, 0, 1, 1, 1, 1, 1, 0}, // 6
  {1, 1, 1, 0, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1, 0}, // 8
  {1, 1, 1, 1, 0, 1, 1, 0}, // 9
};

void displayNumber(int number, bool dot) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(pins[i], displayNumbers[number][i]);
  }
  digitalWrite(pins[7], dot); // Set DP pin
}

void cleanDisplay() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(pins[i], LOW);
    delay(50);
  }

  delay(500);

  for (int i = 0; i < 8; i++) {
    digitalWrite(pins[i], LOW);
  }
}

void tripleBar() {
  digitalWrite(pins[0], HIGH); // A
  delay(100);
  digitalWrite(pins[6], HIGH); // G
  delay(100);
  digitalWrite(pins[3], HIGH); // D
}
void cleanTriple() {
  digitalWrite(pins[3], LOW); // D
  delay(100);
  digitalWrite(pins[6], LOW); // G
  delay(100);
  digitalWrite(pins[0], LOW); // A
  delay(100);
}

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  /*for (int i = 0; i <= 9; i++) {
    displayNumber(i, true);
    delay(displayDelay);
    cleanDisplay();
  }*/
  tripleBar();
  delay(displayDelay);
  cleanTriple();
}
