// paging.cpp
//
// A simple C++ simulation of
// page replacement algorithms commonly used
// in operating systems.
// 2016 (c) zubernetes
#include <iostream>
#include <string>
#include <string.h>
// Local project headers
#include "PageFrame.h"

#define ARGS 2

void runFifo(void);
void runOptimal(void);
void runLru(void);

int main(int argc, char **argv) {
	// Verify that enough command arguments were provided 
	if (argc < ARGS) {
		std::cout << "Usage: paging [fifo|lru|optimal]" << std::endl;
		return 0;
	}

	// With enough arguments provided, run a Page Replacement algorithm
	// Build a reference string, ask the user for the length.
	std::string refString;
	std::cout << "Please provide the length of the reference string: ";
	std::cin >> refString;
	std::cout << "This is your reference string = " << refString << std::endl;

	int x, i;
	for (i = 0; i < refString.size(); i++) {
		std::cout << "This is a char " << refString[i] << std::endl;
	}

	if (strcmp(argv[1], "fifo") == 0)
		runFifo();
	if (strcmp(argv[1], "optimal") == 0)
		runOptimal();
	if (strcmp(argv[1], "lru") == 0)
		runLru();
	
	return 0;
}

void runFifo(void) {
	std::cout << "Implementation of FIFO page replacement algorithm."
		<< std::endl;
}

void runOptimal(void) {
	std::cout << "Implementation of Optimal page replacement algorithm."
		<< std::endl;
}

void runLru(void) {
	std::cout << "Implementation of LRU page replacement algorithm."
		<< std::endl;
}