#ifndef REFSTRING_H
#define REFSTRING_H
#include <iostream>
#include <string>

void helloRefString(void);

void helloRefString(void) {
	std::string refString;
	char *str;
	int i, count = 0;
	std::cout << "Please provide the length of the reference string: ";
	std::cin >> refString;

	for (i = 0; i < refString.size(); i++) {
		std::cout << refString[i] << "\t";
		count++;
	}

	std::cout << std::endl << "You entered a reference string of length "
		<< count << std::endl;
}

#endif // !REFSTRING_H