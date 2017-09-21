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


#define SPAN     3
#define HALFSPAN (SPAN / 2)
//Sporatic Mouse movements
void sporatic() {
	int x = random(SPAN) - HALFSPAN;
	int y = random(SPAN) - HALFSPAN;

#ifdef DEBUG
	Serial.print("Moving the mouse by (");
	Serial.print(x);
	Serial.print(", ");
	Serial.print(y);
	Serial.println(")");
#endif

	Mouse.move(x, y);
}

#define MAX 20
#define MED 10
#define MIN  0
void LED_Pulse(int maxi) {
	int on  = MIN,
		off = maxi;

#ifdef DEBUG
	Serial.print("Pulsing the light ");
	Serial.println(maxi);
#endif

	for (; on < maxi; on++, off--) {
		digitalWrite(LED, LOW);
		delay(off);
		digitalWrite(LED, HIGH);
		delay(on);
	}

	delay(MAX * 2);

	for (; on > MIN; on--, off++) {
		digitalWrite(LED, LOW);
		delay(off);
		digitalWrite(LED, HIGH);
		delay(on);
	}
	digitalWrite(LED, LOW);
}


#define PULSE_DELAY 5000
#define PULSES_PER_MOUSE_MOVE 12
void loop() {
	int i = PULSES_PER_MOUSE_MOVE;
	for (; i >= 0; --i) {
		delay(PULSE_DELAY);
		LED_Pulse(MED);
	}
	delay(PULSE_DELAY);
	LED_Pulse(MAX);
	sporatic();	
}
