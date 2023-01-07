#pragma once
#include "student.hpp"

class Roster
{
public:
    // Start index at -1 so when we ++index array will start at 0
    int lastIndex = -1;
    const static int numStudents = 5;
    //recheck not declaring a dynamic array
    Student* studentRosterArray[numStudents];
    
public:
    // extracts data from each comma
    void parse(string row);
    
    void add(string studentID,
             string firstName,
             string lastName,
             string emailAddress,
             int age,
             int daysInCourse1,
             int daysInCourse2,
             int daysInCourse3,
             DegreeProgram degreeProgram);
    
    void printAll(); // Call print method in Student class for each student
    void printByDegreeProgram(DegreeProgram degreeProgram); // Prints students by degree program
    void printInvalidEmailAddress(); // Prints invalid email address
    void remove(string studentID); // Removes a student id
    void printAverageDaysInCourse(string studentID); // Prints the
    ~Roster();
    
    
    
    
};
