#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd(50, 48, 46, 44, 42, 40);	// pines RS, E, D4, D5, D6, D7 de modulo 1602A
int servoPin = 4;
Servo myServo;
String inputString = "";      // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete

void setup() {
  lcd.begin(16, 2);
  Serial.begin(115200);
  inputString.reserve(200);
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Llega: ");
  if (stringComplete) {
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print(inputString);
    Serial.print(inputString);
    if(inputString = 'a'){
      myServo.write(0);
    }else if(inputString = 'b'){
      myServo.write(90);
    }else{
      myServo.write(45);
    }
    inputString = "";
    stringComplete = false;
  }
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
    Serial.println(inputString);
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
