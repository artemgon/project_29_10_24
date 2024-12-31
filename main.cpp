#include "classes.h"

float calcAverage(const vector<int>& grades)
{
    if (grades.empty()) {
        return 0.0;
    }
    int sum = 0;
    for (int grade : grades) {
        sum += grade;
    }
    return static_cast<float>(sum) / grades.size();
}

int main()
{
	map<string, vector<int>> studentGrades;
	string studentName, input;
	int grade;
    while (true) {
        cout << "Enter student's name (or 'done' to finish): ";
        getline(cin, studentName);
        if (studentName == "done") break;
        cout << "Enter grades (separated by spaces): ";
        getline(cin, input);
        istringstream iss(input);
        vector<int> grades;
        while (iss >> grade) {
            if (grade < 0) {
                cout << "Invalid grade: " << grade << ". Grades should be greater than 0.\n";
                continue;
            }
            grades.push_back(grade);
        }
        studentGrades[studentName] = grades;
    }
    cout << "\nStudent Averages:\n";
    for (const auto& [name, grades] : studentGrades) {
        if (grades.empty()) {
            cout << name << ": No grades entered.\n";
			cout << calcAverage(grades) << endl;
        }
        else {
            float average = calcAverage(grades);
            cout << name << ": Average = " << fixed << setprecision(2) << average << endl;
        }
    }
    return 0;
}