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
	static enum { RIGHT, DOWN, LEFT, UP, END } state = UP;
	int x, y;

	switch (state) {
		case UP:
			x = 0;
			y = -1;
#ifdef DEBUG
			Serial.println("UP ");
#endif
			break;

		case DOWN:
			x = 0;
			y = 1;
#ifdef DEBUG
			Serial.println("DOWN ");
#endif
			break;

		case LEFT:
			x = -1;
			y = 0;
#ifdef DEBUG
			Serial.println("LEFT ");
#endif
			break;

		case RIGHT:
			x = 1;
			y = 0;
#ifdef DEBUG
			Serial.println("RIGHT ");
#endif
			break;

		default:
#ifdef DEBUG
			Serial.println("DEFAULT: This shouldn't happen... ");
#endif
			x = y = 0;
	}

#ifdef DEBUG
	Serial.print("Moving the mouse by (");
	Serial.print(x);
	Serial.print(", ");
	Serial.print(y);
	Serial.println(")");
#endif

	Mouse.move(x, y);
	state = (state + 1) % END;
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
#define PULSES_PER_MOUSE_MOVE 11
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
