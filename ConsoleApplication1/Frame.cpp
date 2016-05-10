#include "Frame.h"

Frame::Frame() {
	size = 0;
}

Frame::~Frame() {	
}

void Frame::setFrame(int *a, int k) {
	size = k;
	for (int i = 0; i < k; i++)
		frameCell.push_back(a[i]);
}

int Frame::getSize() {
	return size;
}

std::vector<int> Frame::getFrame() {
	return frameCell;
}