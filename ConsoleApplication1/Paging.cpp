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
#include "refString.h"

#define ARGS 2

void runFifo(void);
void runOptimal(void);
void runLru(void);

int main(int argc, char **argv) {
	// Verify that enough command arguments were provided 
	if (argc < ARGS) {
		std::cout << "Usage: paging [fifo|lru|optimal]" 
			<< std::endl;
		return 0;
	}

	// With enough arguments provided, run a Page Replacement algorithm
	std::cout << "Thank you for using this Page Replacement simulation." << std::endl;

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
	genPageRefString();
	
}

void runOptimal(void) {
	std::cout << "Implementation of Optimal page replacement algorithm."
		<< std::endl;
}

void runLru(void) {
	std::cout << "Implementation of LRU page replacement algorithm."
		<< std::endl;
}