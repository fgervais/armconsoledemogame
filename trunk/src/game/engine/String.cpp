/*
 * String.cpp
 *
 *  Created on: 2010-07-29
 *      Author: Emile
 */

#include "String.h"

String::String() {
	this->content = (char *) "";
	this->lengthvalue = 0;
}
String::String(char * str) {
	this->content = str;
	this->lengthvalue = getLength(str);
}
String::~String() {
}

void String::append(const char * str) {
	uint32_t cpt = 0, lengthSecond = getLength(str);
	// Declare a new char array of the total length
	char * result = new char[this->lengthvalue + lengthSecond];

	// copy all the char pointers in the new longer char array
	for (uint32_t i = 0; i < this->lengthvalue; i++) {
		result[cpt++] = this->content[i];
	}
	for (uint32_t i = 0; i < lengthSecond; i++) {
		result[cpt++] = str[i];
	}

	this->content = result;
	this->lengthvalue += lengthSecond;
}

void String::append(String * str) {
	uint32_t cpt = 0;
	// Declare a new char array of the total length
	char * result = new char[this->lengthvalue + str->length()];

	// copy all the char pointers in the new longer char array
	for (uint32_t i = 0; i < this->lengthvalue; i++) {
		result[cpt++] = this->content[i];
	}
	for (uint32_t i = 0; i < str->length(); i++) {
		result[cpt++] = str->value()[i];
	}

	this->content = result;
	this->lengthvalue += str->length();
}

/************************************************
 * concatString - gets the length of two (2) pointers
 * 			array of characters and concatenated them.
 * Params:
 *  first, second - the two (2) array of char pointers
 * Return: the sum of the two strings
 *
 */
char * String::concatString(const char* first, const char* second) {
	// Deleclaration list
	uint32_t cptFirst, cptSecond, cpt = 0;

	// get length of each strings
	cptFirst = String::getLength(first);
	cptSecond = String::getLength(second);

	// Declare a new char array of the total length
	char * result = new char[cptFirst + cptSecond];

	// copy all the char pointers in the new longer char array
	for (uint32_t i = 0; i < cptFirst; i++) {
		result[cpt++] = first[i];
	}
	for (uint32_t i = 0; i < cptSecond; i++) {
		result[cpt++] = second[i];
	}

	return result;
}

/************************************************
 * concatString - gets the length of two (2) pointers
 * 			array of characters and concatenated them.
 * Params:
 *  first, second - the two (2) array of char pointers
 * Return: the sum of the two strings
 *
 */
char * String::concatString(const char* first, const uint32_t lengthFirst, const char* second, const uint32_t lengthSecond) {
	uint32_t cpt = 0;
	// Declare a new char array of the total length
	char * result = new char[lengthFirst + lengthSecond];

	// copy all the char pointers in the new longer char array
	for (uint32_t i = 0; i < lengthFirst; i++) {
		result[cpt++] = first[i];
	}
	for (uint32_t i = 0; i < lengthSecond; i++) {
		result[cpt++] = second[i];
	}

	return result;
}

/************************************************
 * getLength - Measure length of char pointer array
 * Params:
 *  str - the string you want to know the length
 * Return: the length.
 *
 */
uint32_t String::getLength(const char* str) {
	uint32_t cpt = 0;
	while (str[cpt++] != '\0')
		;
	return cpt -= 1;
}
