//#include <Wire.h>

/*
  Arduino LSM6DS3 - Simple Accelerometer
  This example reads the acceleration values from the LSM6DS3
  sensor and continuously prints them to the Serial Monitor
  or Serial Plotter.
  The circuit:
  - Arduino Uno WiFi Rev 2 or Arduino Nano 33 IoT
  created 10 Jul 2019
  by Riccardo Rizzo
  This example code is in the public domain.
*/

#include <Arduino_LSM6DS3.h>
//
//const int lightone = 2;
//const int lighttwo = 3;
//const int lightthree = 4;
//const int lightfour = 5;
//const int lightfive = 6;
//const int lightsix = 7;
//const int lightseven = 8;
//const int lighteight = 9;
//const int lightnine = 10;
//const int lightten = 11;


void setup() {
//  pinMode(lightone, OUTPUT);
//  pinMode(lighttwo, OUTPUT);
//  pinMode(lightthree, OUTPUT);
//  pinMode(lightfour, OUTPUT);
//  pinMode(lightfive, OUTPUT);
//  pinMode(lightsix, OUTPUT);
//  pinMode(lightseven, OUTPUT);
//  pinMode(lighteight, OUTPUT);
//  pinMode(lightnine, OUTPUT);
//  pinMode(lightten, OUTPUT);
  Serial.begin(9600);
  while (!Serial);
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");

    while (1);
  }

  Serial.print("Accelerometer sample rate = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Acceleration in g's");
  Serial.println("X\tY\tZ");
}

void loop() {
//    digitalWrite(lightone, HIGH);

//    int buttonstate = digitalRead(A2);
//    Serial.println(buttonstate);
//  digitalWrite(lighttwo, HIGH);
//  digitalWrite(lightthree, HIGH);
//  digitalWrite(lightfour, HIGH);
//  digitalWrite(lightfive, HIGH);
  float x, y, z;
  double pitch = 0.00;
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);
  double x_Buff = float(x);
  double y_Buff = float(y);
  double z_Buff = float(z);
  pitch = atan2((- x_Buff) , sqrt(y_Buff * y_Buff + z_Buff * z_Buff)) * 57.3;
  Serial.write(pitch);
// At the time being, my Nano port is not connecting to any device, so these variables may not be right
//  if(pitch < 0)
//  {
//    digitalWrite(lightsix, LOW);
//    digitalWrite(lightseven, LOW);
//    digitalWrite(lighteight, LOW);
//    digitalWrite(lightnine, LOW);
//    digitalWrite(lightten, LOW);
//    digitalWrite(lightone, HIGH);
//
//    if(pitch < 0.2)
//    {
//      digitalWrite(lighttwo, HIGH);
//    }
//    else if(pitch < 0.4)
//    {
//      digitalWrite(lightthree, HIGH);
//    }
//    else if(pitch < 0.6)
//    {
//      digitalWrite(lightfour, HIGH);
//    }
//    else if(pitch < 0.8)
//    {
//      digitalWrite(lightfive, HIGH);
//    }
//    
//  }
//  else if(pitch > 0)
//  {
//    digitalWrite(lightone, LOW);
//    digitalWrite(lighttwo, LOW);
//    digitalWrite(lightthree, LOW);
//    digitalWrite(lightfour, LOW);
//    digitalWrite(lightfive, LOW);
//    digitalWrite(lightsix, HIGH);
//
//    if(pitch > -0.2)
//    {
//      digitalWrite(lightseven, HIGH);
//    }
//    else if(pitch > -0.4)
//    {
//      digitalWrite(lighteight, HIGH);
//    }
//    else if(pitch > -0.6)
//    {
//      digitalWrite(lightnine, HIGH);
//    }
//    else if(pitch > -0.8)
//    {
//      digitalWrite(lightten, HIGH);
//    }
//  }
  
//  Serial.println(pitch);
//    Serial.write(x);
//    Serial.print(x);
//    Serial.print('\t');
//    Serial.print(y);
//    Serial.print('\t');
//    Serial.println(z);
//Serial.println(y);
// Probably going to use/write z
  }
}
