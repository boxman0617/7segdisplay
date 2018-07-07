#include "NumberLed.h"
#include "NumberDisplay.h"

//-----------------------------------------(d1, d2, d3, d4)
int digits[NumberDisplay::NUM_OF_DIGITS] = {9, 10, 11, 12};
int timer[NumberDisplay::NUM_OF_DIGITS] = {0, 0, 0, 0}; // m m s s

//----------------------------------{a, b, c, d, e, f, g, dp}
int pins[NumberLed::NUM_OF_PINS] = {8, 6, 4, 3, 2, 7, 5, 13};
int dotToDisplay[NumberDisplay::NUM_OF_DIGITS] = {0, 1, 0, 0};

NumberLed *n = new NumberLed(pins);
NumberDisplay *nDisplay = new NumberDisplay(digits, pins, 1000, 1500);

void setup() {
	int i;
	for(i = 2; i < 13; i++) {
		pinMode(i, OUTPUT);
	}
}

void loop() {
	while(1) {
		tick();
		nDisplay->display(timer, dotToDisplay);
	}
}

void tick() {
	timer[3] = timer[3] + 1;
	if(timer[3] > 9) {
		timer[3] = 0;
		timer[2] = timer[2] + 1;
		if(timer[2] > 5) {
			timer[2] = 0;
			timer[1] = timer[1] + 1;
			if(timer[1] > 9) {
				timer[1] = 0;
				timer[0] = timer[0] + 1;
				if(timer[0] > 9) {
					timer[0] = 0;
				}
			}
		}
	}
}
