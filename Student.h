#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    int age;
    string classGrade;
    float marks;

public:
    Student(string n, int r, int a, string c, float m);
    string getName() const;
    int getRollNumber() const;
    int getAge() const;
    string getClassGrade() const;
    float getMarks() const;
    void displayStudentDetails() const;
};

#endif
