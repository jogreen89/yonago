#ifndef REFSTRING_H
#define REFSTRING_H

#include <stdlib.h>
#include <string>
#include <time.h>
#include <vector>
#include <iostream>

#define PAGE_NUMBER_MAX 19

int* buildRefString(int);
void parseRefString(int*, int);

int* buildRefString(int size) {
	int *a = new int[size];
	// obtain a seed from the system clock:
	// ref: std::linear_congruential_engine::operator() cplusplus.com
	srand(time(NULL)); // initialize random seed

	int i;
	for (i = 0; i < size; i++) {
		int x = rand() % PAGE_NUMBER_MAX + 1;
		a[i] = x;
	}

	return &a[0];
}

void parseRefString(int *a, int size) {
	int i;
	for (i = 0; i < size; i++) {
		std::cout << a[i] << std::endl;
	}
}

#endif // !REFSTRING_H