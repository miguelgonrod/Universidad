void setup() {
  pinMode(53,OUTPUT);
}

void loop() {
  digitalWrite(53, HIGH);
  delay(1000);
  digitalWrite(53, LOW);
  delay(1000);
}
