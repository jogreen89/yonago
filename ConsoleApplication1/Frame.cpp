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
		if (j < frameSize && i < frameSize) {
			frame.push_back(a[i]);
			addFault();
			i++;
			j++;
		} 
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
	int i = 0, j = 0;
	int frameSize = getFrameSize();
	while (i < max) {
		history.push_back(a[i]);
		if (j < frameSize && i < frameSize) {
			frame.push_back(a[i]);
			i++;
			j++;
		} 
		else if (j == frameSize) {
			i++;
			j++;
		}
		else {
			frame[j] = a[i];
			i++;
			j++;
		}
	}
	return;
}