/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */

int switchIn = 0;
int photoIn = 0;

bool rewardEmpty = true;

int breakOnset = 0;
int breakActual = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(13, OUTPUT);
  pinMode(3, OUTPUT);

  pinMode(6, INPUT);

  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  switchIn = digitalRead(6);
  photoIn = analogRead(0);
  
  //Serial.println(photoIn);
  //delay(300);

  if (photoIn < 500) {
    breakActual = millis();

    if (breakOnset == 0) {
      breakOnset = breakActual;
    }

    if ((breakActual - breakOnset) > 1000) {
      rewardEmpty = true;

      for (int i = 0; i < 2; i++) {
        digitalWrite(13, HIGH);   // turn the LED on
        delay(100);
        digitalWrite(13, LOW);   // turn the LED off
        delay(100);
      }
    }
  } else {
    breakOnset = 0;
  }

  if (switchIn > 0 && rewardEmpty) {
    digitalWrite(3, HIGH);   // open the Valve
    digitalWrite(13, HIGH);   // turn the LED on
    
    delay(500);

    digitalWrite(3, LOW);    // close the Valve
    digitalWrite(13, LOW);   // turn the LED off
    rewardEmpty = false;     // reward should be full now

    delay(1000); // delay to ensure valve is closed
  }
}
