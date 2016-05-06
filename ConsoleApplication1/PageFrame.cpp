#include "PageFrame.h"

PageFrame::PageFrame() {
	id = 0;
	priority = 0;
}

PageFrame::~PageFrame()
{
}

int PageFrame::getId(void) {
	return id;
}

int PageFrame::getPriority(void) {
	return priority;
}
