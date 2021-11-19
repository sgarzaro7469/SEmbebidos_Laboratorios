int pinLed = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinLed, OUTPUT);
}

void loop() {
  digitalWrite(pinLed, HIGH);
  delay(1000);
  digitalWrite(pinLed, LOW);
  // put your main code here, to run repeatedly:
  delay(1000);
}
