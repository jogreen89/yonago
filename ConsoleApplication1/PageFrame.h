#ifndef PAGEFRAME_H
#define PAGEFRAME_H

#include <iostream>

class PageFrame {
public:
	PageFrame();
	~PageFrame();

	int getId(void);
	int getPriority(void);

private:
	int id;
	int priority;
};

#endif // !PAGEFRAME_H