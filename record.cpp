#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
public:
    string name;
    vector<pair<string, double>> subjects;

    Student(string studentName) {
        name = studentName;
    }

    void addGrade(string subject, double grade) {
        subjects.push_back(make_pair(subject, grade));
    }

    double calculateAverage() {
        double sum = 0;
        for (auto &subject : subjects) {
            sum += subject.second;
        }
        return sum / subjects.size();
    }

    void displayReportCard() {
        cout << "Report Card for " << name << ":\n";
        for (auto &subject : subjects) {
            cout << subject.first << ": " << subject.second << endl;
        }
        cout << "Average Grade: " << calculateAverage() << endl;
    }
};

int main() {
    vector<Student> students;
    int choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Student\n";
        cout << "2. Add Grades\n";
        cout << "3. Display Report Card\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            cout << "Enter student name: ";
            cin >> name;
            students.push_back(Student(name));
        } else if (choice == 2) {
            string name, subject;
            double grade;
            cout << "Enter student name: ";
            cin >> name;
            cout << "Enter subject name: ";
            cin >> subject;
            cout << "Enter grade: ";
            cin >> grade;

            for (auto &student : students) {
                if (student.name == name) {
                    student.addGrade(subject, grade);
                }
            }
        } else if (choice == 3) {
            string name;
            cout << "Enter student name: ";
            cin >> name;

            for (auto &student : students) {
                if (student.name == name) {
                    student.displayReportCard();
                }
            }
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}

