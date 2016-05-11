#ifndef FRAME_H
#define FRAME_H

#include <vector>
#include <iostream>

class Frame {
public:
	Frame();
	~Frame();

	int getFault(void);
	int getFrameSize(void);
	int getRefStringSize(void);
	std::vector<int> getFrame(void);
	std::vector<int> getHistory(void);
	std::vector<int> getReferenceString(void);

	void addFault(void);
	void setReferenceString(int*, int);
	void fillFIFO(int*, int);
	void fillOptimal(int*, int);
	void fillLRU(int*, int);
	
private:
	int faults = 0;					// number of page faults
	int frameSize;				// frame size
	int referenceStringSize;	// reference string
	std::vector<int> frame;		// frame container
	std::vector<int> history;	// history container for LRU/Optimal
	std::vector<int> referenceString; // reference string of jobs
};

#endif