#include "classes.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    map<string, int> wordCount;
    string text, word;
    cout << "Enter text: ";
    getline(cin, text);
    istringstream iss(text);
    while (iss >> word) {
        wordCount[word]++;
    }
    cout << "\nWord Frequency:\n";
    for (const auto& [key, value] : wordCount) {
        cout << key << " – " << value << endl;
    }
    return 0;
}


