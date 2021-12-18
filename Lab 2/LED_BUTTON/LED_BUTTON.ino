
void setup() {
  pinMode(23, OUTPUT);
  pinMode(34, INPUT);

}

void loop() {
  int button = digitalRead(34);
  if (button == LOW){
    digitalWrite(23, HIGH);
  }
  else{
    digitalWrite(23, LOW);
  }

}
