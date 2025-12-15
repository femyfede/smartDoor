#include <Keypad.h>
#include <Servo.h>

Servo doorServo;

// -------- Keypad Setup --------
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'D','C','B','A'},
  {'#','9','6','3'},
  {'0','8','5','2'},
  {'*','7','4','1'}
};

// Keypad pins labeled 1–8
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// -------- Components --------
const int buzzerPin = 11;
const int servoPin  = 10;

// -------- Servo Logic --------
const int LOCK_ANGLE   = 0;     // Adjust for your door
const int UNLOCK_ANGLE = 45;    // Adjust for your door
bool doorOpen = false;

// -------- Password --------
String password = "1234";
String input = "";

void setup() {
  pinMode(buzzerPin, OUTPUT);
  doorServo.attach(servoPin);
  lockDoor();                   // Ensure door starts locked
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    // 🔔 Beep on every key press
    tone(buzzerPin, 1200, 80);

    if (key == '#') {        // Confirm PIN
      if (input == password && !doorOpen) {
        unlockDoor();
      } else if (input != password) {
        wrongPasswordAlarm();
      }
      input = "";
    }
    else if (key == '*') {  // Clear input
      input = "";
    }
    else {
      input += key;
    }
  }
}

// -------- Servo Functions --------
void unlockDoor() {
  doorOpen = true;

  tone(buzzerPin, 2000, 300);   // Success beep
  delay(300);

  smoothMove(LOCK_ANGLE, UNLOCK_ANGLE);   // Open door
  delay(5000);                              // Door open time
  smoothMove(UNLOCK_ANGLE, LOCK_ANGLE);   // Lock door

  doorOpen = false;
}

void lockDoor() {
  doorServo.write(LOCK_ANGLE);
}

// -------- Smooth Servo Movement --------
void smoothMove(int fromAngle, int toAngle) {
  if (fromAngle < toAngle) {
    for (int pos = fromAngle; pos <= toAngle; pos++) {
      doorServo.write(pos);
      delay(15);
    }
  } else {
    for (int pos = fromAngle; pos >= toAngle; pos--) {
      doorServo.write(pos);
      delay(15);
    }
  }
}

// -------- Continuous Alarm --------
void wrongPasswordAlarm() {
  unsigned long startTime = millis();

  // 🚨 Alarm for 5 seconds
  while (millis() - startTime < 5000) {
    tone(buzzerPin, 600);
    delay(200);
    noTone(buzzerPin);
    delay(200);
  }
}