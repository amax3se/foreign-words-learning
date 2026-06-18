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
    cout << "/show - show your dictionary" << endl;
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

            string fooler;
            getline(cin, fooler, '\n');
            for (int i=0; i<wordsAm; i++) {
                cout << "Enter the " << i+1 << " word: ";
                getline(cin, word, '\n');
                cout << "Enter the translation: ";
                getline(cin, translation, '\n');

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
            int count=0;

            cout << "Fine! Type \"Word\" if you want me to write words in your language and \"Translation\" if you want me to write a translation. " << endl;
            cin >> mode;

            if (mode == "Word") {
                clearScreen();
                cout << "I'll write foreign words and you have to guess the translation. Let's begin. ";

                for (const auto& pair : words) {
                    cout << pair.first << endl;

                    while (userWord != pair.second) {
                        getline(cin, userWord, ' ');
                        if (userWord != pair.second) { cout << "Nope! Try again. "; }
                    }
                    
                    count++;
                    if (count == words.size()) {
                        cout << "Right! You guessed all the words. " << endl;
                    } else {
                        cout << "Right! Next word: " << endl;
                    }
                }
                count = 0;
            } else if (mode == "Translation") {
                clearScreen();
                cout << "I'll write foreign words and you have to guess the translation. Let's begin. ";

                for (const auto& pair : words) {
                    cout << pair.second << endl;

                    while (userWord != pair.first) {
                        getline(cin, userWord, ' ');
                        if (userWord != pair.first) { cout << "Nope! Try again. "; }
                    }
                    
                    count++;
                    if (count == words.size()) {
                        cout << "Right! You guessed all the words. " << endl;
                    } else {
                        cout << "Right! Next word: " << endl;
                    }
                }
                count = 0;
            } 
        } else { 
            clearScreen();
            if (command == "/exit") { break; }

            cout << "I don't have such a command yet. " << endl; 
            commandShowing();
            cout << endl;
        }
    }

    return 0;
}