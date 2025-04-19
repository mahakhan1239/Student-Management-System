#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include <vector>
#include "Student.h"
using namespace std;

class StudentManager {
private:
    vector<Student> students;

public:
    void addStudent(const Student& student);
    void deleteStudent(int rollNumber);
    void updateStudentDetails(int rollNumber, const string& name, int age, const string& classGrade, float marks);
    void displayAllStudents() const;
    void findStudentByRollNumber(int rollNumber) const;
    void saveToFile(const string& filename);
    void loadFromFile(const string& filename);
    void sortByName();
    void sortByMarks();
    void generateReport() const;
};

#endif
