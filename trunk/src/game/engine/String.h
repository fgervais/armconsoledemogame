/*
 * String.h
 *
 *  Created on: 2010-07-29
 *      Author: Emile
 */

#ifndef STRING_H_
#define STRING_H_

#include <stdio.h>

class String {
public:
	String();										// default new string without any value
	String(char *);									// new string with new value
	virtual ~String();
	char * value(){return this->content;}			// get String value
	uint32_t length(){return this->lengthvalue;}	// get String length
	void append(const char *);						// append a char array to the current String
	void append(String*);							// append another string to the current one


	static uint32_t getLength(const char*);
	static char * concatString(const char*, const char*);
	static char * concatString(const char*, const uint32_t, const char*, const uint32_t);
private:
	char * content;
	uint32_t lengthvalue;

};

#endif /* STRING_H_ */
