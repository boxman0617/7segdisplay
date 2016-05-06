/**
	NumberDisplay.cpp
	Purpose: Display numbers on 4 digit 7segment display

	@author Alan Tirado <alan@deeplogik.com>
	@version 0.0.1 (05/05/2016)
 */

#include "Arduino.h"
#include "NumberDisplay.h"
#include "NumberLed.h"

/**
	NumberDisplay
	Creates instance of NumberDisplay and handles displaying numbers on a
	4 digit 7segment display.
	@constructor
	@param {int[4]} *digitPins - Array of pins to control what digit to display
	@param {int[8]} *segmentLedPins - Array of pins to pass to NumberLed
	@param {int} [refreshRate] - How fast to refresh the display (Defaults to 1000)
	@param {int} [brightness] - How bright the LEDs should be (Defaults to 500)
 */
NumberDisplay::NumberDisplay(int *digitPins, int *segmentLedPins, int refreshRate, int brightness) {
	_refreshRate = refreshRate;
	_digits = digitPins;
	_brightness = brightness;
	_n = new NumberLed(segmentLedPins);
}

/**
	setRefreshRate
	Sets the refresh rate
	@param {int} refreshRate - Sets {_refreshRate}
 */
void NumberDisplay::setRefreshRate(int refreshRate) {
	_refreshRate = refreshRate;
}

/**
	setBrightness
	Sets the brightness of the LEDs
	@param {int} brightness - Sets {_brightness}
 */
void NumberDisplay::setBrightness(int brightness) {
	_brightness = brightness;
}

/**
	display
	Displays 4 digits and dots on the 4 digit 7segment display using
	{NumberLed::displayNumber} to do the heavy lifting
	@param {int[4]} *numbers - Displays each number in the array on it's corresponding digit
	@param {int[4]} *dots - Displays a dot on the corresponding digit
 */
void NumberDisplay::display(int *numbers, int *dots) {
	int i;
	long beginTime = millis();

	while((millis() - beginTime) < _refreshRate) {
		for(i = 0; i < 4; i++) {
			_setDigit(i + 1);
			_n->displayNumber(numbers[i]);
			_displayDot(dots, i);
			delayMicroseconds(_brightness);
			_n->clear();
		}
	}
}

/**
	_setDigit
	Sets the digit to currently display
	@private
	@param {int} digit - Digit to display (0 will display all) (1-4)
 */
void NumberDisplay::_setDigit(int digit) {
	int i;
	for(i = 0; i < NUM_OF_DIGITS; i ++) {
		if(digit == 0 || digit == i + 1) {
			digitalWrite(_digits[i], LOW);
		} else {
			digitalWrite(_digits[i], HIGH);
		}
	}
}

/**
	_displayDot
	@private
	@param {int[4]} *dots - Array of which digit to display a dot on
	@param {int} currentDigit - Current digit we are displaying
 */
void NumberDisplay::_displayDot(int *dots, int currentDigit) {
	int i;
	int dpPin = _n->getDotPin();
	for(i = 0; i < NUM_OF_DIGITS; i++) {
		if(currentDigit == i && dots[i] == 1) {
			digitalWrite(dpPin, HIGH);
		} else {
			digitalWrite(dpPin, LOW);
		}
	}
}