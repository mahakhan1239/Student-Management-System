#include <iostream>
#include <iomanip>
#include <vector>
#include <windows.h>
#include <limits>
#include "Student.h"
#include "StudentManager.h"

using namespace std; 

// Function to set console text color
void setConsoleColor(int textColor, int bgColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}

// Function to display a colored title
void displayTitle(const string& title) {
    setConsoleColor(9, 0); // Bold blue text
    cout << setw(169) << setfill('=') << "\n";
    cout << setw(90) << setfill(' ') << title << "\n";
    cout << setw(169) << setfill('=') << "\n";
    setConsoleColor(7, 0); // Reset to default color
}

// Function to display the main menu
void displayMenu()
 {
    setConsoleColor(10, 0); // Bold green text
    cout << setw(80) << setfill(' ') << "1. Add Student\n";
    cout << setw(83) << setfill(' ') << "2. Delete Student\n";
    cout << setw(91) << setfill(' ') << "3. Update Student Details\n";
    cout << setw(89) << setfill(' ') << "4. Display All Students\n";
    cout << setw(96) << setfill(' ') << "5. Find Student by Roll Number\n";
    cout << setw(92) << setfill(' ') << "6. Save to File (optional)\n";
    cout << setw(94) << setfill(' ') << "7. Load from File (optional)\n";
    cout << setw(90) << setfill(' ') << "8. Sort Students by Name\n";
    cout << setw(91) << setfill(' ') << "9. Sort Students by Marks\n";
    cout << setw(85) << setfill(' ') << "10. Generate Report\n";
    cout << setw(74) << setfill(' ') << "11. Exit\n";
    setConsoleColor(7, 0); // Reset to default color
    cout << setw(84) << setfill(' ') << "Enter your choice: ";
}

int main() {
    StudentManager manager;
    int choice;

    do {
        displayTitle("Student Management System");
        displayMenu();
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 11) //cin.fail=no input
		{
            cout << "\nInvalid input! Please enter a number between 1 and 11." << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                // Add Student
                string name;
                int rollNumber, age;
                string classGrade;
                float marks;

                cout << "\nEnter Student Name: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, name); // Use getline to allow spaces in names
                cout << "Enter Roll Number: ";
                cin >> rollNumber;
                cout << "Enter Age: ";
                cin >> age;
                cout << "Enter Class: ";
                cin.ignore();
                getline(cin, classGrade);
                cout << "Enter Marks: ";
                cin >> marks;

                manager.addStudent(Student(name, rollNumber, age, classGrade, marks));
                break;
            }
            case 2: {
                // Delete Student
                int rollNumber;
                cout << "\nEnter Roll Number to delete: ";
                cin >> rollNumber;
                manager.deleteStudent(rollNumber);
                break;
            }
            case 3: {
                // Update Student Details
                int rollNumber;
                string name;
                int age;
                string classGrade;
                float marks;

                cout << "\nEnter Roll Number of the student to update: ";
                cin >> rollNumber;
                cout << "Enter New Name: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, name);
                cout << "Enter New Age: ";
                cin >> age;
                cout << "Enter New Class: ";
                cin.ignore();
                getline(cin, classGrade);
                cout << "Enter New Marks: ";
                cin >> marks;

                manager.updateStudentDetails(rollNumber, name, age, classGrade, marks);
                break;
            }
            case 4:
                manager.displayAllStudents();
                break;
            case 5: {
                int rollNumber;
                cout << "\nEnter Roll Number to find: ";
                cin >> rollNumber;
                manager.findStudentByRollNumber(rollNumber);
                break;
            }
            case 6:
                manager.saveToFile("students.txt");
                break;
            case 7:
                manager.loadFromFile("students.txt");
                break;
            case 8:
                manager.sortByName();
                cout << "\nStudents sorted by name." << endl;
                break;
            case 9:
                manager.sortByMarks();
                cout << "\nStudents sorted by marks." << endl;
                break;
            case 10:
                manager.generateReport();
                break;
            case 11:
                cout << "\nExiting the program. Goodbye!" << endl;
                break;
        }
        cout << "\nPress Enter to go back to the menu...";
        cin.ignore();
        cin.get(); // Wait for user input to continue

    } while (choice != 11);

    return 0;
}
