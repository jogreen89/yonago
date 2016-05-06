#ifndef REFSTRING_H
#define REFSTRING_H

#include <iostream> 
#include <stdlib.h>
#include <string>
#include <time.h>

#define PAGE_NUMBER_MAX 19

void genPageRefString(int);

void genPageRefString(int stringSize) {
	int i;
	// obtain a seed from the system clock:
	// ref: std::linear_congruential_engine::operator() cplusplus.com
	std::string refString;

	srand(time(NULL)); // initialize random seed

	for (i = 0; i < stringSize; i++) {
		int x = rand() % PAGE_NUMBER_MAX + 1;
		std::string str = std::to_string(x);
		refString.append(str+',');
	}

	i = 0;

	// print refString to console
	while (i < stringSize) {
		char n = refString[i];		
		if (n == ',')
			std::cout << ' ';
		else
			std::cout << n;
		i++;
	}
}

#endif // !REFSTRING_H