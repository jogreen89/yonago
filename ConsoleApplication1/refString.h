#ifndef REFSTRING_H
#define REFSTRING_H

#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>

#define PAGE_NUMBER_MAX 19

void genPageRefString(int);

void genPageRefString(int stringSize) {
	int i;
	// obtain a seed from the system clock:
	// ref: std::linear_congruential_engine::operator() cplusplus.com
	std::vector<int> refString;

	srand(time(NULL)); // initialize random seed

	for (i = 0; i < stringSize; i++) {
		int x = rand() % PAGE_NUMBER_MAX + 1;
		refString.
	}
	i = 0;

}

#endif // !REFSTRING_H