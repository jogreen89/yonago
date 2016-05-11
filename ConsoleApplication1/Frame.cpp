#include "Frame.h"

Frame::Frame() {
	frameSize = 8;
}

Frame::~Frame() {	
}

int Frame::getFault() {
	return faults;
}

int Frame::getFrameSize() {
	return frameSize;
}

int Frame::getRefStringSize() {
	return referenceStringSize;
}

std::vector<int> Frame::getFrame() {
	return frame;
}

std::vector<int> Frame::getHistory() {
	return history;
}

std::vector<int> Frame::getReferenceString() {
	return referenceString;
}

void Frame::addFault(void) {
	faults++;
	return;
}

void Frame::setReferenceString(int *a, int size) {
	referenceStringSize = size;
	int n = getRefStringSize();
	for (int i = 0; i < n; i++)
		referenceString.push_back(a[i]);
	return;
}

void Frame::fillFIFO(int *a, int max) {
	int i = 0, j = 0;
	int frameSize = getFrameSize();
	while (i < max) {
		// If the frame is not full, add incoming pages and 
		// count page faults
		if (j < frameSize && i < frameSize) {
			frame.push_back(a[i]);
			addFault();
			i++;
			j++;
		} 
		// If the frame is full, reset the count and replace
		// pages in FIFO order
		else if (j == frameSize) {
			j = 0;
			if (frame[j] == a[i])
				frame[j] = a[i];
			else {
				frame[j] = a[i];
				addFault();
			}
			i++;
			j++;
		}
		// If the frame is full but not the size of the frame,
		// replace page at position j
		else {
			if (frame[j] == a[i])
				frame[j] = a[i];
			else {
				frame[j] = a[i];
				addFault();
			}
			i++;
			j++;
		}
	}
	return;
}

void Frame::fillOptimal(int *a, int max) {
	int i = 0, j = 0, opt = 0;
	int frameSize = getFrameSize();
	while (i < max) {
		history.push_back(a[i]);
		// If the frame is not full, add incoming pages and 
		// count page faults
		if (j < frameSize && i < frameSize) {
			frame.push_back(a[i]);
			addFault();
			i++;
			j++;
		} else  {
			// Lookup in reference string for optimal page
			for (int k = 0; k < frameSize; k++)
				for (int l = 0; l < referenceStringSize; l++) 
					if (frame[k] == referenceString[l]) {
						opt = k;
						i++;
						j++;
					}
			// Finding the optimal page to replace
			if (opt != 0) {
				frame[opt] = a[i];
				addFault();
			}
			// If optimal page not found, choose j
			else {
				frame[j] = a[i];
				addFault();
				i++;
				j++;
			}
		}
	}
}

void Frame::fillLRU(int *a, int max) {
	int i = 0, j = 0, opt;
	int frameSize = getFrameSize();
	while (i < max) {
		history.push_back(a[i]);
		// If the frame is not full, add incoming pages and 
		// count page faults
		if (j < frameSize && i < frameSize) {
			frame.push_back(a[i]);
			addFault();
			i++;
			j++;
		} else {
			// Lookup in page history for LRU page
			// starting from the most recent history
			for (int k = 0; k < frameSize; k++)
				for (int l = history.size() - 1; l > 0; l--)
					if (frame[k] == history[l]) {
						opt = frame[k];
						addFault();
						i++;
						j++;
					}
			// Finding the LRU page to replace
			if (opt != 0) {
				frame[opt] = a[i];
				addFault();
			}
			// If the LRU page not found, choose j
			else {
				frame[j] = a[i];
				addFault();
				i++;
				j++;
			}
		}
	}
}