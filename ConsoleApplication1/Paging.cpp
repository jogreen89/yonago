// paging.cpp
//
// A simple C++ simulation of
// page replacement algorithms commonly used
// in operating systems.
// 2016 (c) zubernetes
#include <iostream>
#include <iomanip>
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
	cout << "Thank you for using this Page Replacement Simulation." << endl;

	if (strcmp(argv[1], "fifo") == 0 ||
		strcmp(argv[1], "FIFO") == 0)
		runFifo();
	if (strcmp(argv[1], "optimal") == 0 ||
		strcmp(argv[1], "OPTIMAL") == 0)
		runOptimal();
	if (strcmp(argv[1], "lru") == 0 ||
		strcmp(argv[1], "LRU") == 0)
		runLru();
	
	return 0;
}

// Run the FIFO page replacement algorithm. Build a 
// reference string, fill the frame and count the number
// of page faults.
void runFifo(void) {
	int refStringSize = rand() % REF_STRING_LEN + 1;
	// Create a new reference string
	int *a = new int[refStringSize];
	a = buildRefString(refStringSize);		// simple array of ints

	// Build FIFO frame of size: 8
	Frame *f = new Frame();
	f->setReferenceString(a, refStringSize);
	// Run FIFO replacement on reference string
	f->fillFIFO(a, f->getRefStringSize());

	// Test contents of reference string after fillFrame 
	cout << "The following is the Ref String --> " << endl;
	int m = f->getRefStringSize();
	for (int j = 0; j < m; j++)
		cout << f->getReferenceString()[j] << " ";
	cout << endl;

	// Test contents of frame of size : 8 
	cout << "The following is saved in the Frame." << endl;
	int n = f->getFrameSize();
	cout << "*----*" << endl << "| ";
	for (int i = 0; i < n; i++) {
		cout << setw(2) << f->getFrame()[i] << " |";
		if (i < n - 1) 
			cout << endl << "| ";
	}
	cout << endl << "*----*" << endl;

	// Page Faults
	cout << "::Page Faults::" << endl << "---------------" << endl;
	cout << setw(8) << f->getFault() << endl;

	return;
}

// Run the Optimal page replacement algorithm. Build a 
// reference string, fill the frame and count the number
// of page faults.
void runOptimal(void) {
	int refStringSize = rand() % REF_STRING_LEN + 1;
	// Create a new reference string
	int *a = new int[refStringSize];
	a = buildRefString(refStringSize);		// simple array of ints

	// Build FIFO frame of size: 8
	Frame *f = new Frame();
	f->setReferenceString(a, refStringSize);
	// Run FIFO replacement on reference string
	f->fillOptimal(a, f->getRefStringSize());

	// Test contents of reference string after fillFrame 
	cout << "The following is the Ref String --> " << endl;
	int m = f->getRefStringSize();
	for (int j = 0; j < m; j++)
		cout << f->getReferenceString()[j] << " ";
	cout << endl;

	// Test contents of frame of size : 8 
	cout << "The following is saved in the Frame." << endl;
	int n = f->getFrameSize();
	cout << "*----*" << endl << "| ";
	for (int i = 0; i < n; i++) {
		cout << setw(2) << f->getFrame()[i] << " |";
		if (i < n - 1) 
			cout << endl << "| ";
	}
	cout << endl << "*----*" << endl;

	// Page Faults
	cout << "::Page Faults::" << endl << "---------------" << endl;
	cout << setw(8) << f->getFault() << endl;

	return;
}

// Run the LRU page replacement algorithm. Build a 
// reference string, fill the frame and count the number
// of page faults.
void runLru(void) {
	int refStringSize = rand() % REF_STRING_LEN + 1;
	// Create a new reference string
	int *a = new int[refStringSize];
	a = buildRefString(refStringSize);		// simple array of ints

	// Build FIFO frame of size: 8
	Frame *f = new Frame();
	f->setReferenceString(a, refStringSize);
	// Run FIFO replacement on reference string
	f->fillLRU(a, f->getRefStringSize());

	// Test contents of reference string after fillFrame 
	cout << "The following is the Ref String --> " << endl;
	int m = f->getRefStringSize();
	for (int j = 0; j < m; j++)
		cout << f->getReferenceString()[j] << " ";
	cout << endl;

	// Test contents of frame of size : 8 
	cout << "The last pages saved in the frame." << endl;
	int n = f->getFrameSize();
	cout << "*----*" << endl << "| ";
	for (int i = 0; i < n; i++) {
		cout << setw(2) << f->getFrame()[i] << " |";
		if (i < n - 1) 
			cout << endl << "| ";
	}
	cout << endl << "*----*" << endl;

	// Page Faults
	cout << "::Page Faults::" << endl << "---------------" << endl;
	cout << setw(8) << f->getFault() << endl;

	return;
}

// Build a random string of integers for the Page
// Replacement simulation. Array of ints
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