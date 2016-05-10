#include "Frame.h"

Frame::Frame() {
	size = 0;
}

Frame::~Frame() {	
}

int Frame::getSize() {
	return size;
}

std::vector<int> Frame::getFrame() {
	return frameCell;
}

std::vector<int> Frame::getHistory() {
	return history;
}

void Frame::fillFrame(int *a, int max, int fSize) {
	size = fSize;
	for (int i = 0; i < max; i++) {
		while (i < fSize) {
			frameCell.push_back(a[i]);
			history.push_back(a[i]);
			i++;
		}
		history.push_back(a[i]);
	}
}