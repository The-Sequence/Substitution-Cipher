#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void clearConsole() {
    std::cout << "\033[2J\033[1;1H"; // ANSI escape codes to clear the screen
}

int main() {
    string abc = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string key = "xjqnmhklcbydogfretiupaswvzXJQNMHKLCBYDOGFRETIUPASWVZ";
    string s1{};
    string locked{};
    string unlocked{};
    char choice{};
    bool actionDone{};
    
    do {
            cout << " ---------------------------------" << endl;
            cout << "             Welcome" << endl;
            cout << " ---------------------------------" << endl;
            cout << " 1. Encode a message" << endl;
            cout << " 2. Decode a message" << endl;
            cout << " 3. View current cipher key" << endl;
            cout << " 4. Generate a new cipher key" << endl;
            cout << " 5. Change the cipher key" << endl;
            cout << " 6. Quit" << endl;
            cout << "\n Enter your selection: ";

            cin >> choice;
            cin.ignore(); // Clear the input buffer including the newline character.

        //Implement the switch statement here...

            switch (choice) {

            case '1': {
                clearConsole();
                cout << "     - Encode a message -" << endl;
                cout << "---------------------------------" << endl;
                cout << "\nEnter your message: ";
                getline(cin, s1);

                for (auto c : s1) {
                    size_t position{ abc.find(c) };
                    if (position != string::npos) {
                        char new_char{ key.at(position) };
                        locked += new_char;
                    }
                    else {
                        locked += c;
                    }
                }
                clearConsole();
                cout << "--------------------------------------------------------------------" << endl;
                cout << "- Encrypted message -";
                cout << "" << endl;
                cout << "--------------------------------------------------------------------" << endl;
                cout << "\n' " << locked << " '" << endl;
                cout << "\n--------------------------------------------------------------------" << endl;
                cout << "\nDon't forget to copy this text if you want to"
                    << "\nsend it to your friend or if you want to decrypt it!" << endl;
                break;
            }
            case '2':
                clearConsole();
                cout << "     - Decode a message -" << endl;
                cout << "---------------------------------" << endl;
                cout << "\nEnter the encrypted message: ";
                getline(cin, s1);

                for (auto c : s1) {
                    size_t position{ key.find(c) };
                    if (position != string::npos) {
                        char new_char{ abc.at(position) };
                        unlocked += new_char;
                    }
                    else {
                        unlocked += c;
                    }
                }
                clearConsole();
                cout.width(56);
                cout << "--------------------------------------------------------------------" << endl;
                cout << "- Decoded message -";
                cout << "" << endl;
                cout << "--------------------------------------------------------------------" << endl;
                cout << "\n'" << unlocked << "'" << endl;
                cout << "\n--------------------------------------------------------------------" << endl;
                cout << "\nAwesome!"
                    << "\nSend another message back by Pressing Any Key"
                    << "\nand Pressing 1 on the menu!" << endl;
                break;

            case '3':
                clearConsole();
                cout << "------------------------------------------------------------------------------" << endl << endl;
                cout << "- Cipher Key -";
                cout << "" << endl;
                cout << "' " << key << " '" << endl << endl << endl;
                cout << "About the Cipher Key:" << endl << endl;
                cout << "" << "Share this text if you want to communicate with your friend!" << endl;
                cout << "" << "If you lose this key, you wouldn't be able to encrypt and decipher text!" << endl;
                cout << "\n------------------------------------------------------------------------------" << endl;
                cout << "\nIf you want to change this key, Press Any Key,"
                    << "\nenter number 5 in the menu and hit enter!" << endl;

                break;
            case '4':
                clearConsole();
                cout << "------------------------------------------------------------------------------" << endl;
                cout << "You have selected: 'Generate new cipher key' " << endl;
                cout << "Oops, the feature is yet to be worked on!" << endl
                    << "\nOptions 1 to 3 are available as of now, please check it out!" << endl
                    << "\nPress any key to go back to the menu!" << endl;
                cout << "------------------------------------------------------------------------------" << endl << endl;
                break;

            case '5': {
                clearConsole();
                cout << "--------------------------------------------------------------------" << endl;
                cout << "- Change Cipher Key -";
                cout << "" << endl;
                cout << "--------------------------------------------------------------------" << endl << endl;
                cout << "NOTE!" << endl << endl;
                cout << "A valid cipher key is required for this application" << endl;
                cout << "to work correctly!" << endl << endl << endl;
                cout << "It is recommended that you change the cipher key every" << endl;
                cout << "once in a while!" << endl << endl;
                cout << "\n--------------------------------------------------------------------" << endl;
                cout << "Type '0' and press enter if you're sure about this" << endl;
                cout << "otherwise type '1' and press enter." << endl;

                cout << "Change the key?: ";
                int confirm{};
                cin >> confirm;

                if (cin.fail()) {
                    clearConsole();
                    do {
                        cin.clear();
                        cout << "This is shown when the user enters a choice that's not" << endl
                            << "between 0 and 1." << endl
                            << "\nThis effectively prompts the user to type in a valid choice." << endl
                            << "This feature is yet to be implemented." << endl << endl
                            << "Press any key to return to the menu." << endl;
                        break;
                    } while (!cin.fail());
                }
                else if (confirm == 0) {
                    clearConsole();
                    cout << "This is displayed when the user wants to change the current" << endl
                        << "cipher key." << endl
                        << "This feature is yet to be implemented." << endl;
                    break;

                }
                else if (confirm == 1) {
                    clearConsole();
                    cout << "This is executed when the user does not want to change the current" << endl
                        << "cipher key." << endl
                        << "This feature is yet to be implemented." << endl;
                    break;
                }
                break;
            }
                    break;

            case '6': {
                clearConsole();
                cout << "Bye-bye!" << endl;
                system("pause");
                return 0;
            }

            default: {
                clearConsole(); // Clear the screen
                cout << "Invalid selection" << endl;
                break;
            }
            }

            s1.clear();
            unlocked.clear();
            locked.clear();

        cout << endl;
        system("pause"); // Pause the program so that the user can read what we just printed to the screen
        clearConsole();

    } while (choice != '6');

}