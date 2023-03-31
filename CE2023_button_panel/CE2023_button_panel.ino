

unsigned long lastChange1, lastChange2, lastChange3;

int flashSpeed1, flashSpeed2, flashSpeed3;
bool ledState1, ledState2, ledState3 = 0;

void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {

  flashSpeed1 = map(analogRead(A1), 0, 890, 0, 3000);
  flashSpeed2 = map(analogRead(A2), 0, 890, 0, 3000);
  flashSpeed3 = map(analogRead(A3), 0, 890, 0, 3000);


  if (millis() > lastChange1 + flashSpeed1) {
    ledState1 = !ledState1;
    
    lastChange1 = millis();
  }

  if (millis() > lastChange2 + flashSpeed2) {
    ledState2 = !ledState2;
    lastChange2 = millis();
  }

  if (millis() > lastChange3 + flashSpeed3) {
    ledState3 = !ledState3;
    lastChange3 = millis();
  }

  digitalWrite(9, ledState1);
  digitalWrite(10, ledState2);
  digitalWrite(11, ledState3);
  digitalWrite(12, !ledState3);

}
