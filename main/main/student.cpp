#include "student.hpp"

using namespace std;

// Student default constructor
Student::Student()
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    for (int i = 0; i < coursesArraySize; i++) this->daysToCompleteCourse[i] = 0;
    // setting security as a default value
    this->degreeProgram = DegreeProgram::SECURITY;
} // End of default constructor
// Full student constructor
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age,
                 int daysToCompleteCourse[], DegreeProgram degreeProgram)
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < coursesArraySize; i++) this->daysToCompleteCourse[i] = daysToCompleteCourse[i];
    // setting security as a default value
    this->degreeProgram = degreeProgram;
} // end of student constructor

// Student deconstructor
Student::~Student() {
    
}
// All student getter methods
string Student::getStudentID() { return this->studentID;}
string Student::getFirstName() { return this->firstName;}
string Student::getLastName() { return this->lastName;}
string Student::getEmailAddress() { return this->emailAddress;}
int Student::getAge() {return this->age;}
// Array name acts as a pointer
int* Student::getDaysToCompleteCourse() {return this->daysToCompleteCourse;}
DegreeProgram Student::getDegreeProgram() {return this->degreeProgram;}
// All student setter methods
void Student::setStudentID(string studentID) {this->studentID = studentID;}
void Student::setFirstName(string firstName) {this->firstName = firstName;}
void Student::setLastName(string lastName) {this->lastName = lastName;}
void Student::setEmailAddress(string emailAddress) {this->emailAddress = emailAddress;}
void Student::setAge(int age) {this->age = age;}
// Set each course day on its own
void Student::setDaysToCompleteCourse(int daysToCompleteCourse[])
{
    for (int i = 0; i < coursesArraySize; i++) this->daysToCompleteCourse[i] = daysToCompleteCourse[i];
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {this->degreeProgram = degreeProgram;}

// Print header for displaying data
void Student::printHeader()
{
    cout << "Student ID| First Name | Last Name | Email \t\t\t\t| Age | Days in Course | Degree Program \n";
}
// Method to display a singlular student
void Student::print()
{
    cout << this->getStudentID() << '\t' << '\t' << '\t';
    cout << this->getFirstName() << '\t' << '\t';
    cout << this->getLastName() << '\t' << '\t' ;
    cout << this->getEmailAddress() << '\t' ;
    cout << this->getAge() << '\t' << '\t';
    cout << this->getDaysToCompleteCourse()[0] << ',';
    cout << this->getDaysToCompleteCourse()[1] << ',';
    cout << this->getDaysToCompleteCourse()[2] << '\t' ;
    // Converts degreeProgram from integer to string value
    cout << degreeProgramType[this->getDegreeProgram()] << '\n' ;
}


