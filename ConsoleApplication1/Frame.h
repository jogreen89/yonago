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

	void setReferenceString(int*, int);
	void fillFrame(int*, int);
	
private:
	int faults;		// number of page faults
	int frameSize;
	int referenceStringSize;
	std::vector<int> frame;
	std::vector<int> history;
	std::vector<int> referenceString;
};

#endif