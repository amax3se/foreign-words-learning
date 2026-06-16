#include <iostream>
#include <map>
#include <string>
using namespace std;

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
    commandShowing();
    cout << endl;

    // commands 
    while (command != "/exit") {
        cout << "Enter command: ";
        cin >> command;
        if (command == "/newWords") {  // add new words
            cout << endl;
            int wordsAm;
            string word, translation;

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
            cout << endl;
            cout << "Great! There are your words: " << endl;
            for (const auto& pair : words) {
                cout << pair.first << " - " << pair.second << endl;
            }
            cout << endl;
        } else if (command == "/cards") { // learning new words with cards
            cout << endl;
            /* There will be cards func */ 
        } else if (command == "/exit") { // stop programm
            break;
        } else { 
            cout << endl;
            cout << "I havn't got that command yet. " << endl; 
            commandShowing();
            cout << endl;
        }
    }

    return 0;
}