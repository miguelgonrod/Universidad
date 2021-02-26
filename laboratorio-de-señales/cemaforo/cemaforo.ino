int azul = 51;
int verde = 52;
int rojo = 53;

void setup() {
  pinMode(azul, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(rojo, OUTPUT);

}

void loop() {
  digitalWrite(verde, HIGH);
  delay(2000);
  digitalWrite(rojo, HIGH);
  delay(2000);
  digitalWrite(verde, LOW);
  delay(2000);
  digitalWrite(rojo, LOW);
}
