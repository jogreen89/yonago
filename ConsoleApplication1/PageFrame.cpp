#include "PageFrame.h"

#include <iostream>

PageFrame::PageFrame() {
	id = 0;
	priority = 0;
}


PageFrame::~PageFrame()
{
}

void PageFrame::helloPageFrame(void) {
	int id;
	id = getId();
	std::cout << "Hello, helloPageFrame!" << std::endl
		<< "The number of frames is : " << id << std::endl;

}

int PageFrame::getId(void) {
	return id;
}

int PageFrame::getPriority(void) {
	return priority;
}
