#include <iostream>
#include <array>
#include <string>
using namespace std;


struct Course {
    string name;
    float grade;
};
struct Student {
    string name;
    array<Course, 3> courses;
};
int main() {
    const int numStudents = 4;
    const int numCourses = 3;
    array<Student, numStudents> students = {{
        {"Farida", { {{"CS", 95}, {"OR", 90}, {"SWE", 93}} }},
        {"Malak",  { {{"CS", 88}, {"OR", 85}, {"SWE", 90}} }},
        {"Fadwa",  { {{"CS", 92}, {"OR", 94}, {"SWE", 91}} }},
        {"Nour",   { {{"CS", 85}, {"OR", 87}, {"SWE", 89}} }}
    }};
    cout << "Average grade per course:\n";
    for (int j = 0; j < numCourses; j++) {
        float sum = 0;
        for (int i = 0; i < numStudents; i++) {
            sum += students.at(i).courses.at(j).grade;
        }
        float avg = sum / numStudents;
        cout << students.at(0).courses.at(j).name << " average = " << avg << endl;
    }
    cout << "\n\n";
    cout << "Total grades per student:\n";
    for (int i = 0; i < numStudents; i++) {
        float total = 0;
        for (int j = 0; j < numCourses; j++) {
            total += students.at(i).courses.at(j).grade;
        }
        cout << students.at(i).name << " total = " << total << endl;
    }
    return 0 ;}
