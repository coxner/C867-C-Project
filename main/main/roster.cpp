#include "roster.hpp"
#include "student.hpp"
using namespace std;

// lhs stands for left hand side and right hand side stand for

// Start of Roster::parse method
void Roster::parse(string studentdata) {
    //DegreeProgram degreeProgram = SECURITY;
    
    // extract studentID
    int rhs = studentdata.find(",");
    string sID = studentdata.substr(0, rhs);
    
    // move past previous comma
    int lhs = rhs + 1;
    // , is the end lhs is the start
    rhs = studentdata.find(",", lhs);
    // lhs is the start rhs-lhs gives us the number of indexs to move
    string fName = studentdata.substr(lhs, rhs - lhs);
    
    // Last name
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    string lName = studentdata.substr(lhs, rhs-lhs);
    
    // Email address
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    string eAdd = studentdata.substr(lhs, rhs-lhs);
    
    // Age
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int age = stoi(studentdata.substr(lhs, rhs-lhs));
    
    //Days in course
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int dic1 = stod(studentdata.substr(lhs, rhs-lhs));
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int dic2 = stod(studentdata.substr(lhs, rhs-lhs));
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    int dic3 = stod(studentdata.substr(lhs, rhs-lhs));
    
    // Determine degree program
    lhs = rhs + 1;
    rhs = studentdata.find(",", lhs);
    DegreeProgram dp = SOFTWARE;
    if (studentdata.at(lhs) == 'N') dp = NETWORK;
    else if (studentdata.at(lhs) == 'S' && studentdata.at(lhs + 1) == 'E') dp = SECURITY;
    
    // Takes all temporary variables and adds it to add method to to create student objects.
    add(sID, fName, lName, eAdd, age, dic1, dic2, dic3, dp);
} // End of Roster::parse()

// Start of Roster::add method
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2,
                 int daysInCourse3, DegreeProgram degreeProgram) {
    // Puts elements into array to add to the student constructor below
    int parr[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    // Creates student objects and adds them to an array lastIndex is -1 first array index will be 0
    studentRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, parr, degreeProgram);
} // End Roster::add method
//Start of printAll() method
void Roster::printAll() {
    Student::printHeader();
    // loop through array and call student print mehtod to display results
    for (int i = 0; i <= Roster::lastIndex; i++ ) {
        Roster::studentRosterArray[i]->print();
    }
} // end ot printAll()
// Start of printByDegreeProgram method
void Roster::printByDegreeProgram(DegreeProgram dp)
{
    cout << "Printing students with degree program " << degreeProgramType[dp] << std::endl;
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) {
        // loop through studentRosterArray if degreeProgram is == to input field dp print student information
        if (Roster::studentRosterArray[i]->getDegreeProgram() == dp) studentRosterArray[i]->print();
    } // end of for loop
    cout << std::endl;
} // end of printByDegreeProgram
// Start of printInvalidEmailAddress
void Roster::printInvalidEmailAddress()
{
    bool any = false; // by default set boolean to false
    for(int i = 0; i <= Roster::lastIndex; i++)
    {
        string email = (studentRosterArray[i]->getEmailAddress());
        // if email doesnt contain @ or . or if it does contain ' ' then we have found invalid email
        if(email.find('@') == string::npos || (email.find('.') == string::npos) || !(email.find(' ') == string::npos)) {
            any = true; // found invalid email so change boolean and display invalid email
            cout << email << ':' << studentRosterArray[i]->getStudentID() << std::endl;
        }
    }
} // end of invalid EmailAddress
// Start of printAverageDaysInCourse
void Roster::printAverageDaysInCourse(string studentID) {
    for(int i = 0; i <= Roster::lastIndex; i++) {
        if(studentRosterArray[i]->getStudentID() == studentID){
            cout << studentRosterArray[i]->getStudentID() << ": ";
            cout << (studentRosterArray[i]->getDaysToCompleteCourse()[0]
                     + studentRosterArray[i]->getDaysToCompleteCourse()[1]
                     + studentRosterArray[i]->getDaysToCompleteCourse()[2]) / 3 << std::endl;
        }
    }
    cout << std::endl;
} // End of printAverageDaysInCourse
// Start of remove method
void Roster::remove(string studentID) {
    bool success = false;
    // Using Roster::lastindex keeps the input dynamic and not constant in case array grows or shrinks
    for(int i = 0; i <= Roster::lastIndex; i++) {
        if(studentRosterArray[i]->getStudentID() == studentID) {
            success = true;
            if (i < numStudents - 1) {
                Student* tempData = studentRosterArray[i];
                // re assign pointer locations
                studentRosterArray[i] = studentRosterArray[numStudents - 1];
                //stores data from array position being removed to index -1
                studentRosterArray[numStudents -1] = tempData;
            }
            Roster::lastIndex--; // Takes values at -1 and -- indexs them removes access to it
        }
    }
    if(success)
    {
        cout << studentID << " removed from database." << std::endl << std::endl;
        this->printAll(); // Displays book with removed one gone
    } else cout << studentID << " not found." << std::endl << std::endl;
} // End of remove method
// start fo deconstructor
Roster::~Roster()
{
    cout << "Destructor Called" << std::endl << std::endl;
    for(int i = 0; i <= numStudents; i++) {
        cout << "Destroying student #" << i + 1 << std::endl;
        delete studentRosterArray[i];
        studentRosterArray[i] = nullptr;
    }
} // end of deconstructor


