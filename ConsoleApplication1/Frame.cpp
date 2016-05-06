#include "Frame.h"

Frame::Frame() {
	data = 0;
	next = NULL;
}

Frame::~Frame() {
	if (next) {
		delete next;
	}
}

void Frame::setData(int val) {
	data = val;
}

void Frame::setNext(Frame *frame) {
	next = frame;
}
