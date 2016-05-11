#include "Frame.h"

Frame::Frame() {
	frameSize = 8;
}

Frame::~Frame() {	
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

void Frame::setReferenceString(int *a) {
	int n = getRefStringSize();
	for (int i = 0; i < n; i++)
		referenceString.push_back(a[i]);
	return;
}

void Frame::fillFrame(int *a, int max) {
	int i = 0, j = 0;
	while (i < max) {
		while (j < frameSize) {
			frame.push_back(a[i]);
			referenceString.push_back(a[i]);
			i++;
			j++;
		}
		j = 0;
		referenceString.push_back(a[i]);
		i++;
	}
	return;
}