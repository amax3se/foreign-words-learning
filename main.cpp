#include <iostream>
#include <map>
#include <string>
using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void commandShowing() { // showing commands
    cout << "My commands are: " << endl;
    cout << "/newWords - add new words" << endl;
    cout << "/show - show your words" << endl;
    cout << "/cards - begin learning" << endl;
    cout << "/exit - stop programm" << endl;
}

int main() {
    map<string, string> words;
    string command;

    // greetings
    cout << "Hello! I will help you learn some foriegn words. ";
    cout << endl;

    // commands 
    while (command != "/exit") {
        commandShowing();
        cout << "Enter command: ";
        cin >> command;
        if (command == "/newWords") {  // add new words
            clearScreen();
            int wordsAm;
            string word, translation;
            cout << endl;
            cout << "How much words do you want to add? ";
            cin >> wordsAm;
            cout << endl;
            cout << "Please, enter the words" << endl;
            
            for (int i=0; i<wordsAm; i++) {
                cout << "Enter the word: ";
                cin >> word;
                cout << "Enter the translation: ";
                cin >> translation;

                words[word] = translation;
                cout << endl;
            }
        } else if (command == "/show") {  // show your words
            clearScreen();
            cout << "Great! There are your words: " << endl;
            for (const auto& pair : words) {
                cout << pair.first << " - " << pair.second << endl;
            }
            cout << endl;
        } else if (command == "/cards") { // learning new words with cards
            clearScreen();
            string mode, userWord;
            cout << "Fine! Write \"Word\" if you want me to write words in your language and \"Translation\" if translation. " << endl;
            cin >> mode;

            if (mode == "Word") {
                clearScreen();
                cout << "I will write the word in your language and you need to answer me the foreign word. Let's begin. ";

                for (const auto& pair : words) {
                    cout << pair.first << endl;

                    while (userWord != pair.second) {
                        cin >> userWord;
                        if (userWord != pair.second) { cout << "No! Try again. "; }
                    }
                    cout << "Yes! Next word: " << endl; 
                }
            } else if (mode == "Translation") {
                clearScreen();
                cout << "I will write the foreign word and you need to answer me the in your language. Let's begin. ";

                for (const auto& pair : words) {
                    cout << pair.second << endl;

                    while (userWord != pair.first) {
                        cin >> userWord;
                        if (userWord != pair.first) { cout << "No! Try again. "; }
                    }
                    cout << "Yes! Next word: " << endl; 
                }
            } //! don't get words with space (" ")
        } else if (command == "/exit") { // stop programm
            break;
        } else { 
            clearScreen();
            cout << "I havn't got that command yet. " << endl; 
            commandShowing();
            cout << endl;
        }
    }

    return 0;
}