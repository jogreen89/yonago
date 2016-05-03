#ifndef REFSTRING_H
#define REFSTRING_H
#include <iostream>
#include <string>

void helloRefString(void);

void helloRefString(void) {
	std::string refString;
	char *str;
	int i;
	std::cout << "Please provide the length of the reference string: ";
	std::cin >> refString;

	for (i = 0; i < refString.size(); i++) {
		std::cout << refString[i] << "\t";
		
	}

	std::cout << std::endl << "You entered a reference string of length "
		<< refString.size() << std::endl;
}

#endif // !REFSTRING_H