#ifndef FRAME_H
#define FRAME_H

#include <vector>

class Frame {
public:
	Frame();
	~Frame();

	int getSize();
	std::vector<int> getFrame();
	void setFrame(int*, int);
	
private:
	int size;
	std::vector<int> frameCell;
	std::vector<int> history;
};

#endif
