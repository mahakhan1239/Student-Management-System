#include "StudentManager.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <windows.h> // Include Windows header

void setConsoleColor(int textColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, textColor);
}

void StudentManager::addStudent(const Student& student) {
    students.push_back(student);
    setConsoleColor(9); // Blue
    std::cout << "Student added successfully.\n"; 
    setConsoleColor(7); // Reset to default color
}

void StudentManager::deleteStudent(int rollNumber) {
    auto it = std::remove_if(students.begin(), students.end(),
        [rollNumber](const Student& s) { return s.getRollNumber() == rollNumber; });

    if (it != students.end()) {
        students.erase(it, students.end());
        setConsoleColor(14); // Yellow
        std::cout << "Student's record deleted successfully.\n"; 
        setConsoleColor(7); // Reset to default color
    } else {
        setConsoleColor(12); // Red
        std::cout << "Student with roll number " << rollNumber << " not found.\n"; 
        setConsoleColor(7); // Reset to default color
    }
}

void StudentManager::updateStudentDetails(int rollNumber, const std::string& name, int age, const std::string& classGrade, float marks) {
    for (auto& student : students) {
        if (student.getRollNumber() == rollNumber) {
            student = Student(name, rollNumber, age, classGrade, marks);
            setConsoleColor(9); // Blue
            std::cout << "Student's details updated successfully.\n"; 
            setConsoleColor(7); // Reset to default color
            return;
        }
    }
    setConsoleColor(12); // Red
    std::cout << "Student with roll number " << rollNumber << " not found.\n"; 
    setConsoleColor(7); // Reset to default color
}

void StudentManager::displayAllStudents() const {
    for (const auto& student : students) {
        student.displayStudentDetails();
    }
}

void StudentManager::findStudentByRollNumber(int rollNumber) const {
    for (const auto& student : students) {
        if (student.getRollNumber() == rollNumber) {
            student.displayStudentDetails();
            return;
        }
    }
    setConsoleColor(12); // Red
    std::cout << "Student with roll number " << rollNumber << " not found.\n"; 
    setConsoleColor(7); // Reset to default color
}

void StudentManager::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    for (const auto& student : students) {
        file << student.getName() << "," 
             << student.getRollNumber() << ","
             << student.getAge() << ","
             << student.getClassGrade() << ","
             << student.getMarks() << std::endl;
    }
    file.close();
}

void StudentManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string name, classGrade;
        int rollNumber, age;
        float marks;
        if (std::getline(iss, name, ',') && 
            (iss >> rollNumber) && 
            (iss.ignore()) &&
            (iss >> age) && 
            (iss.ignore()) &&
            (std::getline(iss, classGrade, ',')) && 
            (iss >> marks)) {
            Student student(name, rollNumber, age, classGrade, marks);
            addStudent(student);
        }
    }
    file.close();
}

void StudentManager::sortByName() {
    std::sort(students.begin(), students.end(),
        [](const Student& a, const Student& b) { return a.getName() < b.getName(); });
}

void StudentManager::sortByMarks() {
    std::sort(students.begin(), students.end(),
        [](const Student& a, const Student& b) { return a.getMarks() > b.getMarks(); });
}

void StudentManager::generateReport() const {
    std::cout << std::setw(20) << "Name" 
              << std::setw(15) << "Roll Number" 
              << std::setw(10) << "Age" 
              << std::setw(15) << "Class" 
              << std::setw(10) << "Marks" << std::endl;
    for (const auto& student : students) {
        std::cout << std::setw(20) << student.getName() 
                  << std::setw(15) << student.getRollNumber() 
                  << std::setw(10) << student.getAge() 
                  << std::setw(15) << student.getClassGrade() 
                  << std::setw(10) << student.getMarks() << std::endl;
    }
}
