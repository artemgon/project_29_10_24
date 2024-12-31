#include "classes.h"

string formatStudents(const vector<string>& students) {
    stringstream ss;
    for (size_t i = 0; i < students.size(); ++i) {
        ss << students[i];
        if (i != students.size() - 1) {
            ss << ", ";
        }
    }
    return ss.str();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    map<string, vector<string>> studentGroups;
    string command;

    while (true) {
        cout << "Оберіть дію:\n1. Додати студентів до групи\n2. Видалити студента\n3. Показати студентів групи\n4. Вийти\nВаш вибір: ";
        getline(cin, command);

        if (command == "1") { 
            string groupName, studentsInput;
            cout << "Введіть назву групи: ";
            getline(cin, groupName);

            cout << "Введіть студентів (розділених комами): ";
            getline(cin, studentsInput);

            stringstream ss(studentsInput);
            string student;
            while (getline(ss, student, ',')) {
                studentGroups[groupName].push_back(student);
            }

            cout << "Студенти успішно додані до групи " << groupName << "!" << endl;

        }
        else if (command == "2") { 
            string groupName, studentToRemove;
            cout << "Введіть назву групи: ";
            getline(cin, groupName);

            if (studentGroups.find(groupName) == studentGroups.end()) {
                cout << "Група " << groupName << " не знайдена." << endl;
                continue;
            }

            cout << "Введіть ім'я студента для видалення: ";
            getline(cin, studentToRemove);

            auto& students = studentGroups[groupName];
            auto it = find(students.begin(), students.end(), studentToRemove);

            if (it != students.end()) {
                students.erase(it);
                cout << "Студента " << studentToRemove << " видалено з групи " << groupName << "." << endl;
            }
            else {
                cout << "Студента " << studentToRemove << " не знайдено в групі " << groupName << "." << endl;
            }

        }
        else if (command == "3") { 
            string groupName;
            cout << "Введіть назву групи: ";
            getline(cin, groupName);

            if (studentGroups.find(groupName) != studentGroups.end()) {
                cout << "Група " << groupName << ": " << formatStudents(studentGroups[groupName]) << endl;
            }
            else {
                cout << "Група " << groupName << " не знайдена." << endl;
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