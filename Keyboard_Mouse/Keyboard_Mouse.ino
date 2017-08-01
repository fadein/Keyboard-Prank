#include <Mouse.h>

int LED = 13;

void setup() {
  Mouse.begin();
  pinMode(LED, OUTPUT);
  randomSeed(analogRead(0));
  Serial.begin(9600);
}


//Sparatic Mouse movements
void sporatic() {
  int x = random(10) - 5;
  int y = random(10) - 5;
  Mouse.move(x, y);
}

//LED blinks just for testing purposes
void LED_Blink() {
  digitalWrite(LED, HIGH);
  delay(200);
  digitalWrite(LED, LOW);
  delay(200);
}

void loop(){
  for (int i = 0; i < 10; ++i)
    LED_Blink();
  sporatic();
}

