/*
 * System.cpp
 *
 *  Created on: 2010-06-28
 *      Author: Emile
 */

#include "System.h"

System::System() {
}

System::~System() {
}

/************************************************
 * getLineCount - Read all the content of a file
 * Params:
 *  path - the path including the filename for the file you want to read
 * Return: the number of line on success or 0(NULL) on fail.
 *
 ************************************************/
uint32_t System::getLineCount(const char* path) {
	FILE * file = fopen(path, "rb"); // open the stream
	int32_t c = 0, b;
	while ((b = fgetc(file)) != EOF) {
		c += (b == 10) ? 1 : 0;
	}
	fclose(file);

	// if the counter c is less than zero, return 0
	if (c > 0)
		return c;
	return 0;
} // EndOF Function getLineCount

/************************************************
 * getFileContent - Read all the content of a file line by line
 * Params:
 *  path 	- the path including the filename for the file you want to read
 *  content	- reference to the content array
 *  len 	- reference to the number of line in the file
 * Return: 1 on success or 0(NULL) on fail.
 ************************************************/
uint8_t System::getFileContent(const char* path, char ** &content, uint32_t& len) {
	// local variable
	FILE *file;
	uint32_t cpt = 0;

	len = getLineCount(path); // get number of line in the file
	if (len == 0)
		return 0; // fail because file empty

	// set the array size according to the number of line in the file
	content = new char*[len];

	file = fopen(path, "rb"); // open the file

	if (file == 0) { // if opening file went wrong
		return 0; // return null on fail
	} else {
		// read all the file line by line and store the line in the content array
		while (fgets(content[cpt++] = new char[100], 100, file) != NULL);

		fclose(file); // close the file
	}
	return 1; // return true on succes
} // EndOF Function getFileContent
