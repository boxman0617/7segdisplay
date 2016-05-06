#ifndef NumberDisplay_h
#define NumberDisplay_h
#include "Arduino.h"
#include "NumberLed.h"

class NumberDisplay {
	public:
		NumberDisplay(int *digitPins, int *segmentLedPins, int refreshRate = 1000, int brightness = 500);
		void setRefreshRate(int refreshRate);
		void setBrightness(int brightness);
		void display(int *numbers, int *dots);
		static const int NUM_OF_DIGITS = 4;
	private:
		NumberLed *_n;
		int *_digits;
		int _refreshRate;
		int _brightness;
		void _setDigit(int digit);
		void _displayDot(int *dots, int currentDigit);
};
#endif