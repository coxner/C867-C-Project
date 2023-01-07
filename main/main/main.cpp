//
//  main.cpp
//  main
//
//  Created by Christian Oxner
//  C867 Assignment
//  Assignment Notes : Left comments in that I felt helpful to me, and allow me to return to project at a
//  later date and understand. Enjoyed assignment found some methods used to do things very informative and
//  will always use this assignment as a reference guide when creating projects in the future. One problem I had
//  that I wasn't able to solve was EXC_BAD_ACCESS on Student de constructor. 

#include <iostream>
#include "roster.hpp"
using namespace std;
//using std::endl;
int main()
{
    const string studentData[] =
    
    {   "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Chris,Oxner,coxner5@wgu.edu,26,30,31,32,SOFTWARE"
    };
    
    const int numOfStudents = 5;
    Roster classRoster;
    
    // Program information screen user must press enter to continue
    cout << "\n\n\n\n\n\n\n" << endl;
    cout << "\t\t\tScripting and Programming - Applications - C867" << endl;
    cout << "\t\t\tChristian Oxner || Student ID: 009554482" << endl;
    cout << "\t\t\tProgram designed with C++ in Xcode \n\n\n\n\n" << endl;
    cout << "\t\t\tPress Enter to continue" << std::endl;
    cin.ignore();
    
    // Parses all students into student data array and calls printall
    for (int i = 0; i < numOfStudents; i++) classRoster.parse(studentData[i]);
    cout << "Displaying all students: " << std::endl;
    classRoster.printAll();
    cout << std::endl;
    // Displays students with invalid email addresses
    cout << "Displaying stduents with invalid email addresses" << std::endl;
    classRoster.printInvalidEmailAddress();
    cout << std::endl;
    
    // Displays average days per class for each student
    cout << "Displaying average days per class: " << std::endl;
    for (int i = 0; i < 5; i++) {
        classRoster.printAverageDaysInCourse(classRoster.studentRosterArray[i]->getStudentID());
    }
    cout << std::endl;
    
    // Prints by degree program software
    classRoster.printByDegreeProgram(SOFTWARE);
    
    // Removes student with the ID A3
    cout << "Removing student with ID A3" << std::endl;
    classRoster.remove("A3");
    cout << std::endl;
    // To prove student was removed
    classRoster.remove("A3");
    
    return 0;
}
