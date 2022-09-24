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
const int buttonPin = 7;     // the number of the pushbutton pin
const int ledPin1 =  10;      // the number of the LED pin
const int ledPin2 =  8;      // the number of the LED pin
const int ledPin3 =  6;      // the number of the LED pin
const int ledPin4 =  4;      // the number of the LED pin
const int ledPin5 =  2;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  int sensorValue = analogRead(A4);
//  int sensorValue = analogRead(D12);
  int lightValue = analogRead(A2);
  // print out the value you read:
  Serial.println(lightValue);
  delay(1);        // delay in between reads for stability

//  This will change the dimness of the value
  int output = ceil(sensorValue/5);
  if(lightValue <= 200)
  {
    analogWrite(ledPin3, output);    
  }
  else
  {
    analogWrite(ledPin3, LOW);    
  }

  if(lightValue <= 100)
  {
    analogWrite(ledPin2, output);
    analogWrite(ledPin4, output);    
  }
  else
  {
    analogWrite(ledPin2, LOW);
    analogWrite(ledPin4, LOW);    
  }

  if(lightValue <= 50)
  {
    analogWrite(ledPin1, output);
    analogWrite(ledPin5, output);    
  }
  else
  {
    analogWrite(ledPin1, LOW);
    analogWrite(ledPin5, LOW);    
  }

//  } else {
    // turn LED off:
//    digitalWrite(ledPin1, LOW);
//  }
}
