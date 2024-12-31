#include "classes.h"

string formatAuthors(const vector<string>& authors) {
    stringstream ss;
    for (size_t i = 0; i < authors.size(); ++i) {
        ss << authors[i];
        if (i != authors.size() - 1) {
            ss << ", ";
        }
    }
    return ss.str();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    map<string, vector<string>> library;
    string command;

    while (true) {
        cout << "Оберіть дію:\n1. Додати книгу\n2. Знайти авторів за назвою книги\n3. Вивести усі книги\n4. Вийти\nВаш вибір: ";
        getline(cin, command);

        if (command == "1") {
            string bookName;
            cout << "Введіть назву книги: ";
            getline(cin, bookName);

            string authorsInput;
            cout << "Введіть авторів (розділених комами): ";
            getline(cin, authorsInput);

            stringstream ss(authorsInput);
            string author;
            vector<string> authors;

            while (getline(ss, author, ',')) {
                authors.push_back(author);
            }

            library[bookName] = authors;
            cout << "Книга успішно додана!" << endl;

        }
        else if (command == "2") { 
            string bookName;
            cout << "Введіть назву книги: ";
            getline(cin, bookName);

            if (library.find(bookName) != library.end()) {
                cout << "Автори книги \"" << bookName << "\": " << formatAuthors(library[bookName]) << endl;
            }
            else {
                cout << "Книга не знайдена." << endl;
            }

        }
        else if (command == "3") { 
            if (library.empty()) {
                cout << "Бібліотека порожня." << endl;
            }
            else {
                cout << "Список книг у бібліотеці:\n";
                for (const auto& [bookName, authors] : library) {
                    cout << bookName << " — " << formatAuthors(authors) << endl;
                }
            }

        }
        else if (command == "4") { 
            cout << "До побачення!" << endl;
            break;

        }
        else {
            cout << "Невірний вибір. Спробуйте ще раз." << endl;
        }
    }

    return 0;
}