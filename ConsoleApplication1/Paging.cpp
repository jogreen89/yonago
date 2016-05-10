// paging.cpp
//
// A simple C++ simulation of
// page replacement algorithms commonly used
// in operating systems.
// 2016 (c) zubernetes
#include <iostream>
#include <time.h>
#include <string>
#include <string.h>

// Local project headers
#include "Frame.h"

#define ARGS 2
#define PAGE_NUMBER_MAX 19
#define REF_STRING_LEN 100

void runFifo(void);
void runOptimal(void);
void runLru(void);
int* buildRefString(int);

using namespace std;

int main(int argc, char **argv) {
	// Verify that enough command arguments were provided 
	if (argc < ARGS) {
		cout << "Usage: paging [fifo|lru|optimal]" << endl;
		return 0;
	}
	// With enough arguments provided, run a Page Replacement algorithm
	cout << "Thank you for using this Page Replacement simulation." << endl;

	if (strcmp(argv[1], "fifo") == 0)
		runFifo();
	if (strcmp(argv[1], "optimal") == 0)
		runOptimal();
	if (strcmp(argv[1], "lru") == 0)
		runLru();
	
	return 0;
}

void runFifo(void) {
	int frameSize = 10;
	int referenceStringSize = rand() % REF_STRING_LEN + 1;
	cout << "Implementation of FIFO page replacement algorithm.\n" <<
		"The Frame Size is " << frameSize << "." << endl << 
		"and the Reference String Size is " << referenceStringSize << endl;

	// Build a reference string
	int *a = new int[referenceStringSize];
	a = buildRefString(referenceStringSize);

	// Build FIFO frame of size: 10
	Frame *f = new Frame();
	f->fillFrame(a, referenceStringSize, frameSize);

	// Test contents of frameCell
	for (int i = 0; i < f->getSize(); i++)
		cout << f->getFrame()[i] << endl;

}

void runOptimal(void) {
	cout << "Implementation of Optimal page replacement algorithm." << endl;
}

void runLru(void) {
	cout << "Implementation of LRU page replacement algorithm." << endl;
}

int* buildRefString(int size) {
	int *a = new int[size];
	srand(time(NULL));		// initialize random seed

	int i;
	for (i = 0; i < size; i++) {
		int x = rand() % PAGE_NUMBER_MAX + 1;
		a[i] = x;
	}

	return &a[0];
}