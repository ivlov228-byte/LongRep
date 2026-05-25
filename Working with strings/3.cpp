#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
using namespace std;

int main() {
    string sentence, p_word;
    cout << "Enter string: ";
    getline(cin, sentence);

    cout << "Enter word: ";
    getline(cin, p_word);

    string p_word_prov;
    for (char c : p_word) {
        if (isalpha(c)) {
            p_word_prov += tolower(c);
        }
    }

    std::vector<std::string> words;
    std::stringstream ss(sentence);
    std::string word;

    while (ss >> word) {
        words.push_back(word);
    }

    std::vector<std::string> result;

    for (const std::string& w : words) {
        std::string wordProv;
        for (char c : w) {
            if (isalpha(c)) {
                wordProv += tolower(c);
            }
        }

        bool containsAll = true;
        for (char p : p_word_prov) {
            bool found = false;
            for (char wc : wordProv) {
                if (wc == p) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                containsAll = false;
                break;
            }
        }

        if (!containsAll || wordProv.empty()) {
            result.push_back(w);
        }
    }

    std::cout << "\nResult: ";
    for (size_t i = 0; i < result.size(); i++) {
        std::cout << result[i];
        if (i != result.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}