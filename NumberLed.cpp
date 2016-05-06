#include "Arduino.h"
#include "NumberLed.h"

NumberLed::NumberLed(int *pins) {
	_pins = pins;

	int i;
	for(i = 0; i < NUM_OF_PINS; i++) {
		pinMode(_pins[i], OUTPUT);
	}
}

void NumberLed::clear() {
	int i;
	for(i = 0; i < NUM_OF_PINS; i++) {
		digitalWrite(_pins[i], LOW);
	}
}

void NumberLed::loading(int times) {
	clear();
	int i;
	int ii;
	int prev;
	for(i = 0; i < times; i++) {
		prev = 5;
		for(ii = 0; ii < 6; ii++) {
			digitalWrite(_pins[prev], LOW);
			digitalWrite(_pins[ii], HIGH);
			prev = ii;
			delay(100);
		}
	}
}

void NumberLed::displayNumber(int num) {
	int i;
	for(i = 0; i < NUM_OF_PINS; i++) {
		digitalWrite(_pins[i], _numbers[num][i]);
	}
}

int NumberLed::getDotPin() {
	return _pins[NUM_OF_PINS - 1];
}