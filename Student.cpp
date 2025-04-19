#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(string n, int r, int a, string c, float m)
    : name(n), rollNumber(r), age(a), classGrade(c), marks(m) {}

string Student::getName() const { return name; }
int Student::getRollNumber() const { return rollNumber; }
int Student::getAge() const { return age; }
string Student::getClassGrade() const { return classGrade; }
float Student::getMarks() const { return marks; }

void Student::displayStudentDetails() const {
    cout << "Name: " << name << ", Roll Number: " << rollNumber
         << ", Age: " << age << ", Class: " << classGrade
         << ", Marks: " << marks << endl;
}
