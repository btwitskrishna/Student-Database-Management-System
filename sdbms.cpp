
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

struct Student {
    string name;
    int rollNumber;
    string course;
};

map<int, Student> studentDatabase;

void addStudent() {
    Student student;
    cout << "Enter name: ";
    cin >> student.name;
    cout << "Enter roll number: ";
    cin >> student.rollNumber;
    cout << "Enter course: ";
    cin >> student.course;
    studentDatabase[student.rollNumber] = student;
    cout << "Student added successfully!" << endl;
}

void displayStudents() {
    for (auto& student : studentDatabase) {
        cout << "Roll Number: " << student.first << endl;
        cout << "Name: " << student.second.name << endl;
        cout << "Course: " << student.second.course << endl;
        cout << endl;
    }
}

void searchStudent() {
    int rollNumber;
    cout << "Enter roll number to search: ";
    cin >> rollNumber;
    if (studentDatabase.find(rollNumber) != studentDatabase.end()) {
        Student student = studentDatabase[rollNumber];
        cout << "Name: " << student.name << endl;
        cout << "Course: " << student.course << endl;
    } else {
        cout << "Student not found!" << endl;
    }
}

void deleteStudent() {
    int rollNumber;
    cout << "Enter roll number to delete: ";
    cin >> rollNumber;
    if (studentDatabase.find(rollNumber) != studentDatabase.end()) {
        studentDatabase.erase(rollNumber);
        cout << "Student deleted successfully!" << endl;
    } else {
        cout << "Student not found!" << endl;
    }
}

int main() {
    int choice;
    while (true) {
        cout << "1. Add Student" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Delete Student" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
