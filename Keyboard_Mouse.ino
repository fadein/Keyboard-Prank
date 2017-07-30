#include <Mouse.h>
#include <Keyboard.h>

#define MIN 5000 //5 seconds
#define MAX 15000 //15 seconds

#define KEYL 33 //Lowest Ascii Dec
#define KEYH 126 //High Ascii Dec

#define DEL 8 //Delete key

int mouseState = 0;
int LED = 17;
int choice = 0;

void setup() {
  Mouse.begin();
  Keyboard.begin();
  pinMode(LED, OUTPUT);
  randomSeed(analogRead(0));
  choice = random((100%4));
  Serial.begin(9600);
}


void loop(){
  Pick_Prank(choice);
//LED_Blink();
Serial.println(choice);
}


void Pick_Prank(int choice){
  switch (choice){
    case 1:
      random_click();
    break;

    case 2:
      sparatic();
    break;

    case 3:
      delete_Everything();
    break;

    case 4:
      random_Key();
    break;
  }
}


// sends random clicks
void random_click(){
  unsigned int interval =   random(MIN, MAX);
  delay(interval);
  Mouse.click(); 
}


//Sparatic Mouse movements
void sparatic(){
  int x = random(51) - 20;
  int y = random(51) - 20;
  Mouse.move(x,y);
  delay(50);
}


// sends random keypresses
void random_Key(){
  unsigned int interval = random(MIN, MAX);

  delay(interval);
  
  for (int i = 0; i <= (interval%5); i++){
    unsigned int key_value = random(KEYL, KEYH);
    Keyboard.write(key_value);
    delay(10);
    Keyboard.release(key_value);
  }
}


//hold down delete key
void delete_Everything(){
  Keyboard.write(DEL);
  delay(200);
}


//LED blinks just for testing purposes
void LED_Blink(){
  digitalWrite(LED, HIGH);
  delay(200);
  digitalWrite(LED, LOW);
  delay(200);
}


