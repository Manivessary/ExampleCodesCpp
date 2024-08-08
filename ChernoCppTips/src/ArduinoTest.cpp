#pragma once
#include "pch.h"


const char* getPhoneNumber(const char*& inputText) {
	int arraySize = 14;
	char* phoneNumber = new char[arraySize] {};

	const char* found = strstr(inputText, "+CMT");
	found = found + 7;

	if (found != NULL) {
		for (int i = 0; i < 13; i++) {
			phoneNumber[i] = *found++;
		}
	}

	phoneNumber[arraySize - 1] = '\0';
	return phoneNumber;
}


void Test() {
	const char* inputText = "+CMT: \"+905413232435\", \"Name of the person sending SMS\", \"8/8/24,11:00:00+22\" \nThis is text message";
	const char* phoneNumber = getPhoneNumber(inputText);

	std::cout << "Input Text: " << inputText << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;

	delete[] phoneNumber;
}

