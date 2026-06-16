#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, string> words;
    string word, translation;
    int wordsAm;

    // Greatings
    cout << "Hello! I will help you learn some foriegn words. My commands: " << endl;
    cout << "/newWords - add new words" << endl;
    cout << "/show - show your words" << endl;
    cout << "/cards - begin learning" << endl;

    
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

    cout << endl;
    cout << "Great! There are your words: " << endl;
    for (const auto& pair : words) {
        cout << pair.first << " - " << pair.second << endl;
    }

    return 0;
}