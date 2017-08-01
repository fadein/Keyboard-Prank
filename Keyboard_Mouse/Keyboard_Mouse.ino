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
#define SPAN     400
#define HALFSPAN (SPAN / 2)
	int x = random(SPAN) - HALFSPAN;
	int y = random(SPAN) - HALFSPAN;
	Mouse.move(x, y);
}


void LED_Pulse() {
#define MAX 20
#define MIN  0

	int on  = MIN,
		off = MAX;
	for (; on < MAX; on++, off--) {
		digitalWrite(LED, LOW);
		delay(off);
		digitalWrite(LED, HIGH);
		delay(on);
	}
	delay(MAX);

	for (; on > MIN; on--, off++) {
		digitalWrite(LED, LOW);
		delay(off);
		digitalWrite(LED, HIGH);
		delay(on);
	}
	digitalWrite(LED, LOW);
}

void loop(){
	sporatic();
	LED_Pulse();
	delay(5000);
}
