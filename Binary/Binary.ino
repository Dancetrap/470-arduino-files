/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground through 220 ohm resistor
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int buttonPinTwo = 10; // the number of the pushbutton pin
const int ledPinOne =  5;      // the number of the LED pin
const int ledPinTwo =  7;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int speedState = 0;

int speed = 0;

String myText = "Hello World";
String readBinary = "";

bool on;

//char sym[];

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPinOne, OUTPUT);
  pinMode(ledPinTwo, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(buttonPinTwo, INPUT);

  for(int i=0; i<myText.length(); i++){

   char myChar = myText.charAt(i);
  
    for(int i=7; i>=0; i--){
      byte bytes = bitRead(myChar,i);
      readBinary += bytes;
    }

    readBinary += " ";
 }

  for(int i=0; i<readBinary.length(); i++)
    {
      char myChar = readBinary.charAt(i);
//      sym[i] = myChar;
    }
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  speedState = digitalRead(buttonPinTwo);

  if (speedState == HIGH)
  {
    speedState == 100;
  }
  else
  {
    speedState == 500;
  }

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    on = true;
  } else {
    on = false;
  }
    // turn LED on:
    if(on){
//      Serial.print(on);
//      Serial.print(readBinary.length());
    for(int i=0; i<readBinary.length(); i++)
    {
      char myChar = readBinary.charAt(i);
      if (myChar == '0')
      {
          digitalWrite(ledPinOne, LOW);
          digitalWrite(ledPinTwo, LOW);
          delay(50);
          digitalWrite(ledPinOne, HIGH);
          delay(speedState);
//          delay(500);
      }
      if (myChar == '1')
      {
          digitalWrite(ledPinOne, LOW);
          digitalWrite(ledPinTwo, LOW);
          delay(50);
          digitalWrite(ledPinTwo, HIGH);
          delay(speedState);
//          delay(500);
      }
      if (myChar == ' ')
      {
          digitalWrite(ledPinOne, LOW);
          digitalWrite(ledPinTwo, LOW);
          delay(speedState + 50);
//          delay(500);
      }
    }
    } else if(buttonState == LOW){
//       Serial.print(on);
       digitalWrite(ledPinOne, LOW);
       digitalWrite(ledPinTwo, LOW);
    }
}
  /*
  if 0 then
  digitalWrite(ledPinOne, LOW);
  digitalWrite(ledPinTwo, LOW);
  delay(10);
  digitalWrite(ledPinOne, HIGH);
  delay(500);

  if 1 then
  digitalWrite(ledPinOne, LOW);
  digitalWrite(ledPinTwo, LOW);
  delay(10);
  digitalWrite(ledPinTwo, HIGH);
  delay(500);

  if SPACE then
  digitalWrite(ledPinOne, LOW);
  digitalWrite(ledPinTwo, LOW);
  delay(510);
  */
