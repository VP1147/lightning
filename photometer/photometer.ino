int l;
int photo = A0;
int out = 2;

void setup() {
  Serial.begin(9600);
  pinMode(photo, INPUT);
  pinMode(out, OUTPUT);
  digitalWrite(out, LOW);
}

void loop() {
  l = analogRead(photo);
  //Serial.print(float((5000*l)/1024)); Serial.println(" mV");
  delay(1);
  if((analogRead(photo) - l) > 15) {
    //Serial.println(">> Trigger signal sent");
    digitalWrite(out, HIGH);
    delay(200);
    digitalWrite(out, LOW);
    delay(1000);
  }
}
