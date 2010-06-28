/*
 * System.h
 *
 *  Created on: 2010-06-28
 *      Author: Emile
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <stdio.h>

class System {
public:
	System();
	virtual ~System();

	static uint8_t getFileContent(const char*, char ** &, uint32_t&);
private:
	static uint32_t getLineCount(const char*);

};

#endif /* SYSTEM_H_ */
