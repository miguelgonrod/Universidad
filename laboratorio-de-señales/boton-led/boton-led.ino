int pulsador = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(53, OUTPUT);
  pinMode(45, INPUT);
}

void loop() {
  pulsador=digitalRead(45);
  if(pulsador == HIGH){
    digitalWrite(53, HIGH);
  }
  else{
    digitalWrite(53,LOW);
  }
}
