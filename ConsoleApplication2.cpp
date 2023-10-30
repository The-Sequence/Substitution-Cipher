#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <random>

using namespace std;

int main() {
	string abc = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string key = "xjqnmhklcbydogfretiupaswvzXJQNMHKLCBYDOGFRETIUPASWVZ";
	string default_key = "xjqnmhklcbydogfretiupaswvzXJQNMHKLCBYDOGFRETIUPASWVZ";
	string s1{};
	string s1_locked{};
	string s1_unlocked{};
	string newKey{};
	int choice{};

	do {
		system("cls");
		cout << "- - - - - - - - - - - - - - -" << endl;
		cout << "1 - Encrypt text" << endl;
		cout << "2 - Decrypt text" << endl;
		cout << "3 - View encryption key" << endl;
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

				if (s1.length() <= 1) {
					do {
						system("cls");
						cout << "- - - - - - - - - - - - - - -" << endl;
						cout << " - Encrypt message - " << endl << endl;
						cout << "You returned a blank space/single character."
							<< "\nEnter the message to be encrypted: ";
						getline(cin, s1);
					} while (s1.length() <= 2);
				}

				if (s1.length() >= 1) {
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
					cout << "\nDon't forget to copy the encrypted message." << endl;
					cout << "- - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
				}
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
				cout << "\nTry sending a message back too." << endl;
				cout << "- - - - - - - - - - - - - - - - - - - - - - - - -" << endl;

				break;
			}
			case 3: {
				system("cls");
				cout << "- - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
				cout << " - View encryption key -" << endl << endl;
				cout << "The encryption key is: " << endl;
				cout << "' " << key << " '" << endl << endl;
				cout << "Changing the encryption key is recommended once every" << endl
					<< "session to avoid others from deciphering your" << endl
					<< "previous mesages. " << endl << endl
					<< "You can generate one from the app." << endl << endl;
				cout << "- - - - - - - - - - - - - - - - - - - - - - - - -" << endl;

				break;
			}
			case 4: {
				string confirm{};
				srand(time(0));
				system("cls");
				cout << "- - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
				cout << " - Generate a new encryption key -" << endl << endl;
				cout << "New key: " << endl;

				string shuffledKey{ default_key };
				
				for (int i = key.length() - 1; i > 0; i--) {
					int j = rand() % (i + 1);
					swap(shuffledKey[i], shuffledKey[j]);

					key = shuffledKey;
				}
				cout << key;
				
				cout << "\n\nDon't forget to copy this key.";
				cout << "\n- - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
				cout << "\nSet this as the default key for this current session?"
					<< "\n(Y / N): ";
				getline(cin, confirm);

				if (confirm == "y" || confirm == "Y") {
					cin.clear();
					system("cls");
					cout << "- - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
					cout << " - Generate a new encryption key -" << endl << endl;
					cout << "Key has been set." << endl;
					key.clear();
					key = shuffledKey;
					break;
				}
				else {
					cin.clear();
					break;
				}

				break;
			}
			case 5: {
				system("cls");
				string user_key;
				cout << "- - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
				cout << " - Change current encryption key -" << endl << endl;
				cout << "\nEnter your new encryption key here: ";
				getline(cin, user_key);

				
				do {
					if (user_key.length() == 0) {
						system("cls");
						cin.clear();
						cout << "- - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
						cout << " - Change current encryption key -" << endl;
						cout << "\nYou returned a blank space.";
						cout << "\n\nYou can use the default key by typing 'quit'"
							<< "\nor proceed entering a valid key.";

						cout << "\n\nPlease enter a valid encryption key: ";
						getline(cin, user_key);

						if (user_key == "quit") {
							cout << "\nReturning to the menu...";
							cin.clear();
							break;
						}
					}
					else if (user_key.length() < 52 || user_key.length() > 52) {
						cin.clear();
						system("cls");
						cout << "- - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
						cout << " - Change current encryption key -" << endl;
						cout << "\nThe key you entered is invalid.";
						cout << "\n\nYou can generate one here in the app, or";
						cout << "\nYou can type 'quit' to go back to the menu and use"
							<< "\nthe default key to encrypt your messages.";

						cout << "\n\nPlease enter a valid encryption key: ";
						getline(cin, user_key);
					}

					if (user_key == "quit") {
						cout << "\nReturning to the menu...";
						break;
					}
					else if (user_key.length() == 52 && user_key != "quit") {
						system("cls");
						cout << "- - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
						cout << " - Change current encryption key -" << endl << endl;
						key = user_key;
						cout << "New key has been set!";
						break;
					}

				} while (user_key.length() != 52 || user_key != "quit");
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
	return 0;
}