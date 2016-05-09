#include "Frame.h"

Frame::Frame() {
	size = 0;

}

Frame::~Frame() {	
}

void Frame::setSize(int val) {
	size = val;
}

void Frame::setFrameSize(int size) {
	frameCell.resize(size);
}