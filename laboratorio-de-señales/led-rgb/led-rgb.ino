void setup() {
  pinMode(53,OUTPUT);
  pinMode(52,OUTPUT);
  pinMode(51,OUTPUT);
}

void loop() {
  digitalWrite(53, HIGH);
  delay(1000);
  digitalWrite(53, LOW);
  digitalWrite(52, HIGH);
  delay(1000);
  digitalWrite(52, LOW);
  digitalWrite(51, HIGH);
  delay(1000);
  digitalWrite(51, LOW);
}
