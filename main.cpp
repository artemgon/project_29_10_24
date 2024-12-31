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
        cout << "������ ��:\n1. ������ �������� �� �����\n2. �������� ��������\n3. �������� �������� �����\n4. �����\n��� ����: ";
        getline(cin, command);

        if (command == "1") { 
            string groupName, studentsInput;
            cout << "������ ����� �����: ";
            getline(cin, groupName);

            cout << "������ �������� (��������� ������): ";
            getline(cin, studentsInput);

            stringstream ss(studentsInput);
            string student;
            while (getline(ss, student, ',')) {
                studentGroups[groupName].push_back(student);
            }

            cout << "�������� ������ ����� �� ����� " << groupName << "!" << endl;

        }
        else if (command == "2") { 
            string groupName, studentToRemove;
            cout << "������ ����� �����: ";
            getline(cin, groupName);

            if (studentGroups.find(groupName) == studentGroups.end()) {
                cout << "����� " << groupName << " �� ��������." << endl;
                continue;
            }

            cout << "������ ��'� �������� ��� ���������: ";
            getline(cin, studentToRemove);

            auto& students = studentGroups[groupName];
            auto it = find(students.begin(), students.end(), studentToRemove);

            if (it != students.end()) {
                students.erase(it);
                cout << "�������� " << studentToRemove << " �������� � ����� " << groupName << "." << endl;
            }
            else {
                cout << "�������� " << studentToRemove << " �� �������� � ���� " << groupName << "." << endl;
            }

        }
        else if (command == "3") { 
            string groupName;
            cout << "������ ����� �����: ";
            getline(cin, groupName);

            if (studentGroups.find(groupName) != studentGroups.end()) {
                cout << "����� " << groupName << ": " << formatStudents(studentGroups[groupName]) << endl;
            }
            else {
                cout << "����� " << groupName << " �� ��������." << endl;
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