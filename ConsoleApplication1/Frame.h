#ifndef FRAME_H
#define FRAME_H

#include <vector>

class Frame {
public:
	Frame();
	~Frame();

	int getFrameSize();
	int getRefStringSize();
	std::vector<int> getFrame();
	std::vector<int> getHistory();
	std::vector<int> getReferenceString();

	void setFrame(int*, int, int);
	void setReferenceString(int*);
	void fillFrame(int*, int);
	
private:
	int frameSize;
	int referenceStringSize;
	std::vector<int> frame;
	std::vector<int> history;
	std::vector<int> referenceString;
};

#endif