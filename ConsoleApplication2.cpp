#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	string abc = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string key = "xjqnmhklcbydogfretiupaswvzXJQNMHKLCBYDOGFRETIUPASWVZ";
	string s1{};
	string s1_locked{};
	string s1_unlocked{};
	int choice{};

	do {
		system("cls");
		cout << "- - - - - - - - - - - - - - -" << endl;
		cout << "1 - Encrypt text" << endl;
		cout << "2 - Decrypt text" << endl;
		cout << "3 - Show encryption key" << endl;
		cout << "4 - Generate new encryption key" << endl;
		cout << "5 - Change current encryption key" << endl;
		cout << "6 - Quit" << endl;
		cout << "\nEnter your selection: ";
		cin >> choice;
		cin.clear();
		cin.ignore();

		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			system("cls");
			cout << "Invalid choice, please try again." << endl;
		}
		else {
			switch (choice) {

			case 1: {
				system("cls");
				cout << "- - - - - - - - - - - - - - -" << endl;
				cout << " - Encrypt message - " << endl << endl;
				cout << "Enter the message to be encrypted: ";
				getline(cin, s1);
				system("cls");

				for (char c : s1) {
					size_t position{ abc.find(c) };
					if (position != string::npos) {
						char new_char{ key.at(position) };
						s1_locked += new_char;
					}
					else {
						s1_locked += c;
					}
				}

				system("cls");
				cout << "- - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
				cout << "The encrypted message is: " << endl << endl
					<< s1_locked << endl << endl;
				cout << "\nDon't forget to copy the message." << endl;
				cout << "- - - - - - - - - - - - - - - - - - - - - - - - -" << endl;

				break;
			}
			case 2: {
				system("cls");
				cout << "- - - - - - - - - - - - - - -" << endl;
				cout << " - Decrypt message - " << endl << endl;
				cout << "Enter the message to be decrypted: ";
				getline(cin, s1);
				system("cls");

				for (char c : s1) {
					size_t position{ key.find(c) };
					if (position != string::npos) {
						char new_char{ abc.at(position) };
						s1_unlocked += new_char;
					}
					else {
						s1_unlocked += c;
					}
				}

				system("cls");
				cout << "- - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
				cout << "The decrypted message is: " << endl << endl
					<< s1_unlocked << endl << endl;
				cout << "\nTry sending a message to the sender, too!" << endl;
				cout << "- - - - - - - - - - - - - - - - - - - - - - - - -" << endl;

				break;
			}
			case 3: {
				system("cls");
				cout << "- - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
				cout << " - Show encryption key -" << endl << endl;
				cout << "The encryption key is: " << endl;
				cout << "' " << key << " '" << endl << endl;
				cout << "Changing the encryption key is recommended" << endl << endl
					<< "every app usage to avoid others from deciphering" << endl << endl
					<< "your previous messages, etc";

				break;
			}
			case 6: {
				system("cls");
				cout << "Goodbye!" << endl;
				break;
			}
			default:
				cin.clear();
				system("cls");
				cout << "Hello from default case" << endl;
				break;

			}
		}
		do {
			system("pause");
			break;
		} while (choice != 6);

		s1.clear();
		s1_locked.clear();
		s1_unlocked.clear();

	} while (choice != 6);

	s1.clear();
	s1_locked.clear();
	s1_unlocked.clear();

	return 0;
}