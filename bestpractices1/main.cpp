#include "ChoiceLogic.h"
#include "InputValidation.h"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
	//Show menu
	while (true) {
		std::cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - -\n";
		cout << "1 - Encrypt text" << endl;
		cout << "2 - Decrypt text" << endl;
		cout << "3 - View encryption key" << endl;
		cout << "4 - Generate new encryption key" << endl;
		cout << "5 - Change current encryption key" << endl;
		cout << "6 - Quit" << endl;

		int menuChoice{ getNumInput() };

		switch (menuChoice) {
		case 1:
			cout << encrypt(getStringInput());
			break;
		case 2:
			cout << decrypt(getStringInput());
			break;
		case 3:
			displayKey();
			break;
		case 4:
			generateNewKey();
			break;
		case 5:
			changeCurrentKey();
			break;
		case 6:
			std::cout << "\nExiting...\n";
			system("pause");
			break;
		}

		break;
	}

	return 0;
}