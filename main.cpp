#include <iostream>
#include <map>
#include <string>
using namespace std;

void commandShowing() { // showing commands
    cout << "My commands are: " << endl;
    cout << "/newWords - add new words" << endl;
    cout << "/show - show your words" << endl;
    cout << "/cards - begin learning" << endl;
}

int main() {
    map<string, string> words;
    string command;

    // greetings
    cout << "Hello! I will help you learn some foriegn words. ";
    commandShowing();

    // commands 
    while (true) {
        cout << "Enter command: ";
        cin >> command;
        if (command == "/newWords") {  // add new words
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
            continue;
        } else if (command == "/show") {  // show your words
            cout << "Great! There are your words: " << endl;
            for (const auto& pair : words) {
                cout << pair.first << " - " << pair.second << endl;
            }
            continue;
        } else if (command == "/cards") { // learning neew words with cards
            /* There will be cards func */ 
            continue;
        } else { 
            cout << "I havn't got that command yet. " << endl; 
            commandShowing();
            continue;
        }
    }

    return 0;
}