#ifndef FRAME_H
#define FRAME_H

#include <vector>

class Frame {
public:
	Frame();
	~Frame();

	void setSize(int);
	void setFrameSize(int);
	
private:
	int size;
	std::vector<int> frameCell;

};

#endif
