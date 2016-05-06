#ifndef NumberLed_h
#define NumberLed_h
#include "Arduino.h"

class NumberLed {
	public:
		NumberLed(int *pins);
		static const int NUM_OF_PINS = 8;
		void clear();
		void loading(int times);
		void displayNumber(int num);
		int getDotPin();
	private:
		int *_pins;
		int zero[NUM_OF_PINS] = {1, 1, 1, 1, 1, 1, 0, 0};
		int one[NUM_OF_PINS] = {0, 1, 1, 0, 0, 0, 0, 0};
		int two[NUM_OF_PINS] = {1, 1, 0, 1, 1, 0, 1, 0};
		int three[NUM_OF_PINS] = {1, 1, 1, 1, 0, 0, 1, 0};
		int four[NUM_OF_PINS] = {0, 1, 1, 0, 0, 1, 1, 0};
		int five[NUM_OF_PINS] = {1, 0, 1, 1, 0, 1, 1, 0};
		int six[NUM_OF_PINS] = {1, 0, 1, 1, 1, 1, 1, 0};
		int seven[NUM_OF_PINS] = {1, 1, 1, 0, 0, 0, 0, 0};
		int eight[NUM_OF_PINS] = {1, 1, 1, 1, 1, 1, 1, 0};
		int nine[NUM_OF_PINS] = {1, 1, 1, 1, 0, 1, 1, 0};
		int *_numbers[10] = {zero, one, two, three, four, five, six, seven, eight, nine};
};
#endif