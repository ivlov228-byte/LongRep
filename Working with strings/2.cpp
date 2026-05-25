#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string sentence;
    cout << "Enter string: ";
    getline(cin, sentence);

    vector<string> words;
    string word;

    for (char c : sentence) {
        if (c == ' ' || c == ',' || c == '.' || c == '!' || c == '?') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        else {
            word += c;
        }
    }

    if (!word.empty()) {
        words.push_back(word);
    }
    int dlinoe = 0;
    int korotkoe = 0;

    for (int i = 0; i < words.size(); i++) {
        if (words[i].length() > words[dlinoe].length()) {
            dlinoe = i;
        }
        if (words[i].length() < words[dlinoe].length()) {
            korotkoe = i;
        }
    }

    string zamena = words[dlinoe];
    words[dlinoe] = words[korotkoe];
    words[korotkoe] = zamena;
    cout << "\nResult: ";
    for (int i = 0; i < words.size(); i++) {
        cout << words[i];
        if (i != words.size() - 1) {
            cout << " ";
        }
    }
    cout <<endl;

    return 0;
}