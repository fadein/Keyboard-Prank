#include <Mouse.h>

#undef DEBUG

#define LED  13

void setup() {
	Mouse.begin();
	pinMode(LED, OUTPUT);
	randomSeed(analogRead(0));
#ifdef DEBUG
	Serial.begin(9600);
#endif
}


#define SPAN     2
#define HALFSPAN (SPAN / 2)
//Sporatic Mouse movements
void sporatic() {
	int x = random(SPAN) - HALFSPAN;
	int y = random(SPAN) - HALFSPAN;
	Mouse.move(x, y);
}

#define MAX 20
#define MED 10
#define MIN  0
void LED_Pulse(int maxi) {
	int on  = MIN,
		off = maxi;
	for (; on < maxi; on++, off--) {
		digitalWrite(LED, LOW);
		delay(off);
		digitalWrite(LED, HIGH);
		delay(on);
	}
	delay(20);

	for (; on > MIN; on--, off++) {
		digitalWrite(LED, LOW);
		delay(off);
		digitalWrite(LED, HIGH);
		delay(on);
	}
	digitalWrite(LED, LOW);
}


void loop() {
	int i = 12;
	for (; i >= 0; --i) {
		LED_Pulse(MED);
		delay(1000);
	}
	LED_Pulse(MAX);
	sporatic();	
}
