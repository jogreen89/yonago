#pragma once
class PageFrame {
public:
	PageFrame();
	~PageFrame();

	void helloPageFrame(void);
	int getId(void);
	int getPriority(void);

private:
	int id;
	int priority;
};

