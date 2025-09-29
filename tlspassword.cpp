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

string reversePassword(const string& password) {
    string word;
    string ASCII_str;

    for (char c : password) {
        if (c >= '0' && c <= '9') {
            ASCII_str.push_back(c);
        } else {
            word.push_back(c);
        }
    }

    int ASCII_code = stoi(ASCII_str);
    char firstChar = ASCII_code;

    char tempChar;
    for (int i = 0; i < (word.size()/2); i++) {
        tempChar = word[i];
        word[i] = word[word.size() - 1 - i];
        word[word.size() - 1 - i] = tempChar;
    }

    if (firstChar == word[0]) {
        word = word;
    } else {
        word = firstChar + word;
    }

    return word;
}

int main() {
    char choice;
    cout << "Generate(G) or Crack(C) password? [G/C]" << endl;
    cin >> choice;
    
    if (choice == 'G' || choice == 'g') {
        string word;
        cin >> word;

        string password = passwordGenerate(word);
        cout << "Password: " << password;
    } else if (choice == 'C' || choice == 'c') {
        string password;
        cin >> password;

        string word = reversePassword(password);
        cout << "Word with no vowels: " << word;
    }
    
    return 0;
}