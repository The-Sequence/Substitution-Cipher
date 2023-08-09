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
            cout << "              Welcome" << endl;
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
                cout.width(43);
                cout << "- Encrypted message -";
                cout << "" << endl;
                cout.width(56);
                cout << "--------------------------------------------------------------------" << endl;
                cout << "\n' " << locked << " '" << endl;
                cout.width(56);
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

                cout.width(43);
                cout << "- Decoded message -";
                cout << "" << endl;
                cout.width(56);
                cout << "--------------------------------------------------------------------" << endl;
                cout<<"\n'" << unlocked << "'" << endl;
                cout.width(56);
                cout << "\n--------------------------------------------------------------------" << endl;
                cout << "\nAwesome!"
                    << "\nSend another message back by Pressing Any Key"
                    << "\nand Pressing 1 on the menu!" << endl;
                break;

            case '3':
                clearConsole();
                cout.width(56);
                cout << "------------------------------------------------------------------------------" << endl << endl;
                cout.width(46);
                cout << "- Cipher Key -";
                cout << "" << endl;
                cout.width(13);
                cout << "' " << key << " '" << endl << endl << endl;
                cout.width(50);
                cout << "About the Cipher Key:" << endl << endl;
                cout.width(10);
                cout <<"" << "Share this text if you want to communicate with your friend!" << endl;
                cout.width(4);
                cout << "" << "If you lose this key, you wouldn't be able to encrypt and decipher text!" << endl;
                cout.width(55);
                cout << "\n------------------------------------------------------------------------------" << endl;
                cout << "\nIf you want to change this key, Press Any Key,"
                    << "\nenter number 5 in the menu and hit enter!" << endl;
                break;
            case '4':
                clearConsole();
                cout << "------------------------------------------------------------------------------" << endl;
                cout << "You have selected: 'Generate new cipher key' " << endl;
                cout << "Oops, the feature is yet to be worked on!" <<endl
                     << "\nOptions 1 to 3 are available as of now, please check it out!" <<endl
                     << "\nPress any key to go back to the menu!" << endl;
                cout << "------------------------------------------------------------------------------" << endl << endl;
                break;
            
            case '5':
                clearConsole();
                cout << "------------------------------------------------------------------------------" << endl;
                cout << "You have selected: 'Change the cipher key' " << endl;
                cout << "Oops, the feature is yet to be worked on!" << endl
                    << "\nFor the mean time, options 1 to 3 are available. Please check them out!" << endl
                    << "\nPress any key to go back to the menu!" << endl;
                cout << "------------------------------------------------------------------------------" << endl << endl;
                break;
            case '6':
                clearConsole();
                cout << "Bye-bye!" << endl;
                system("pause");
                return 0;

            default:
                clearConsole(); // Clear the screen
                cout << "Invalid selection" << endl;
                break;
            }

            s1.clear();
            unlocked.clear();
            locked.clear();

        cout << endl;
        system("pause"); // Pause the program so that the user can read what we just printed to the screen
        clearConsole();

    } while (choice != '6');

}