
// Credit goes to me and my dad
const int readlog = A1;

void setup() {
  // put your setup code here, to run once:
  pinMode(6, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int input = analogRead(readlog);

  if(input > 700)
  {
    Serial.write(input);
    SnoopyPress();
    delay(10000);
  }
}

void SnoopyPress()
{
  digitalWrite(6, HIGH); // sets the digital pin 6 on
  delay(1000);            // waits for a second
  digitalWrite(6, LOW);  // sets the digital pin 6 off
}
