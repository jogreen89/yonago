#ifndef FRAME_H
#define FRAME_H

#include <iostream>

class Frame {
public:
	Frame();
	~Frame();

	void setData(int);
	void setNext(Frame*);

private:
	int data;
	Frame *next;

};

#endif
