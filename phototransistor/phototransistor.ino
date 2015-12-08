/*
  Simple sketch to test the phototransistor.

  Prints to Serial the input from phototransistor with 
  a delay of half a second.
 */

int val = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(13, OUTPUT);
  
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  val = analogRead(0);
  Serial.println(val);

  if (val > 700) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
  
  delay(500);              // wait for a second
}
