// Prevents multiple includes
#pragma once
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include "degree.hpp"
using std::string;
using std::cout;
//using std::cout;

class Student {
public:
    const static int coursesArraySize = 3;
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    // array must be a constant
    int daysToCompleteCourse[coursesArraySize];
    //
    DegreeProgram degreeProgram;
public:
    Student();
    Student(string studentID, string firstName, string lastName, string emailAddress,
            int age, int dayToCompleteCourse[], DegreeProgram degreeProgram);
    ~Student();
    
    // getter methods
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getDaysToCompleteCourse();
    DegreeProgram getDegreeProgram();
    
    
    //setter methods
    void setStudentID(string ID);
    void setFirstName(string firstName);
    void setLastName(string lastNAme);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setDaysToCompleteCourse(int daysToComplete[]);
    void setDegreeProgram(DegreeProgram degree);
    
    // header that data folows
    static void printHeader();
    
    // to print a student
    void print();
};
