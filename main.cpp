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
        cout << "������ ��:\n1. ������ �����\n2. ������ ������ �� ������ �����\n3. ������� �� �����\n4. �����\n��� ����: ";
        getline(cin, command);

        if (command == "1") {
            string bookName;
            cout << "������ ����� �����: ";
            getline(cin, bookName);

            string authorsInput;
            cout << "������ ������ (��������� ������): ";
            getline(cin, authorsInput);

            stringstream ss(authorsInput);
            string author;
            vector<string> authors;

            while (getline(ss, author, ',')) {
                authors.push_back(author);
            }

            library[bookName] = authors;
            cout << "����� ������ ������!" << endl;

        }
        else if (command == "2") { 
            string bookName;
            cout << "������ ����� �����: ";
            getline(cin, bookName);

            if (library.find(bookName) != library.end()) {
                cout << "������ ����� \"" << bookName << "\": " << formatAuthors(library[bookName]) << endl;
            }
            else {
                cout << "����� �� ��������." << endl;
            }

        }
        else if (command == "3") { 
            if (library.empty()) {
                cout << "��������� �������." << endl;
            }
            else {
                cout << "������ ���� � ��������:\n";
                for (const auto& [bookName, authors] : library) {
                    cout << bookName << " � " << formatAuthors(authors) << endl;
                }
            }

        }
        else if (command == "4") { 
            cout << "�� ���������!" << endl;
            break;

        }
        else {
            cout << "������� ����. ��������� �� ���." << endl;
        }
    }

    return 0;
}