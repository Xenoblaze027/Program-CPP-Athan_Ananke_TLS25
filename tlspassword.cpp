#include <iostream>
#include <string>
using namespace std;

string removeVowels(const string& word) {
    string noVowels;

    for (char c : word) {
        if (c != 'a' && c != 'i' && c != 'u' && c != 'e' && c != 'o' && c != 'A' && c != 'I' && c != 'U' && c != 'E' && c != 'O') {
            noVowels.push_back(c);
        }
    }

    return noVowels;
}

string passwordGenerate(const string& word) {
    if (word.empty()) return "";

    string noVowels = removeVowels(word);

    char tempChar;
    for (int i = 0; i < (noVowels.size()/2); i++) {
        tempChar = noVowels[i];
        noVowels[i] = noVowels[noVowels.size() - 1 - i];
        noVowels[noVowels.size() - 1 - i] = tempChar;
    }

    int ASCII_code = word[0];
    string ASCII_str = to_string(ASCII_code);

    int middle;
    if (noVowels.size() % 2 == 0) {
        middle = noVowels.size()/2;
    } else {
        middle = noVowels.size()/2 + 1;
    }

    string password = noVowels.substr(0, middle) + ASCII_str + noVowels.substr(middle);

    return password;
}

int main() {
    string word;
    cin >> word;

    string password = passwordGenerate(word);
    cout << password;
    
    return 0;
}