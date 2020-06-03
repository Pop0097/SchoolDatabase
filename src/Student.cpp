//
// Created by Dhruv Rawat on 2020-03-10.
//

#include "Classes.h"

Student::Student() : Person::Person(){
    grade = 0;
    studentId = "Default Student ID";
    numLates = 0;
    numAbsences = 0;
    for(int i = 0; i < 8; i++){
        schedule[i] = "Spare";
    }
}

//in next two methods, add the isValid() function to test the student id.
Student::Student(string first, string last, string add, string g, string id) : Person::Person(first, last, add){
    //sets value for grade
    if(g == "1" || g == "2" || g == "3" || g == "4" || g == "5" || g == "6" || g == "7" || g == "8" || g == "9" || g == "10" || g == "11" || g == "12" ){
        int tempGrade = stoi(g); //converts string to integer
        grade = tempGrade;
    }
    else{
        grade = 0;
        cout << "The inputted grade was not valid. The value must be a number between 1 and 12." << endl;
    }
    numLates = 0;
    numAbsences = 0;
    bool valid = isValidId(id); //checks if the given ID is valid
    if(valid){
        studentId = id;
    }
    else{
        cout << "Not a valid Id, please set a new id using \"obejctName\".setStudentId(\"studentID\")" << endl;
        studentId = "Default Student ID";
    }
    for(int i = 0; i < 8; i++){
        schedule[i] = "Spare";
    }
}

Student::~Student(){}

int Student::getGrade(){
    return grade;
}

string Student::getStudentId(){
    return studentId;
}

int Student::getNumLates(){
    return numLates;
}

int Student::getNumAbsences() {
    return numAbsences;
}

void Student::setGrade(string n){
    //checks if input is valid
    if(n == "1" || n == "2" || n == "3" || n == "4" || n == "5" || n == "6" || n == "7" || n == "8" || n == "9" || n == "10" || n == "11" || n == "12" ){
        int g = stoi(n); //converts string to integer
        grade = g;
    }
    else{
        cout << "The inputted grade was not valid. The value must be a number between 1 and 12." << endl;
    }
}

void Student::setStudentId(string id){ //this needs the isValid method
    bool valid = isValidId(id); //checks if the given ID is valid
    if(valid){
        studentId = id;
    }
    else{
        cout << "Not a valid Student ID \n" << endl;
    }
}

void Student::addLate(){ //this is added via the Teacher class
    numLates++;
    //cout << "done" << endl;
}

void Student::addAbsence() { //this is added via the Teacher class
    numAbsences++;
}

string Student::toString() const{
    cout << "Name: " <<  firstName << " " << lastName << endl;
    cout << "Address: " << address << endl;
    cout << "Grade: " << grade << endl;
    cout << "Student ID: " << studentId << endl;
    cout << "Number of Lates: " << numLates << endl;
    cout << "Number of Absences: " << numAbsences << endl;
    cout << "Schedule" << endl;
    for(int i = 0; i < 8; i++){
        cout << "-----------------------------" << endl;
        cout << "Block " << (i+1) << endl;
        cout << schedule[i] << endl;
    }
    cout << endl;
    return "";
}

bool Student::isValidId(string n) const{
    bool valid = false;
    if(n.length() == 10){
        char firstCharacter = n.at(0);
        int digit[9];
        for(int i = 0; i < 9; i++){
            digit[i] = (int) n.at(i+1);
        }
        if(firstCharacter == 'S' && (48 <= digit[0] && 57 >= digit[0]) && (48 <= digit[1] && 57 >= digit[1]) && (48 <= digit[2] && 57 >= digit[2]) && (48 <= digit[3] && 57 >= digit[3]) && (48 <= digit[4] && 57 >= digit[4]) && (48 <= digit[5] && 57 >= digit[5]) && (48 <= digit[6] && 57 >= digit[6]) && (48 <= digit[7] && 57 >= digit[7]) && (48 <= digit[8] && 57 >= digit[8]) ){
            valid = true;
        }
    }
    return valid;
}
