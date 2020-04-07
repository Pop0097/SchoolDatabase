//
// Created by Dhruv Rawat on 2020-03-10.
//

#include "Classes.h"

Student::Student() : Person::Person(){
    grade = 0;
    studentId = "";
    numLates = 0;
    numAbsences = 0;
}

Student::Student(string first, string last) : Person::Person(first, last){
    grade = 0;
    studentId = "";
    numLates = 0;
    numAbsences = 0;
}

//in next two methods, add the isValid() function to test the student id.
Student::Student(string first, string last, string add, int g, string id) : Person::Person(first, last, add){
    grade = g;
    numLates = 0;
    numAbsences = 0;
    bool valid = isValidId(id); //checks if the given ID is valid
    if(valid){
        studentId = id;
    }
    else{
        cout << "Not a valid Id, please set a new id using \"obejctName\".setStudentId(\"studentID\")" << endl;
        studentId = "";
    }
}

Student::Student(string first, string last, int g, string id) : Person::Person(first, last){
    grade = g;
    numLates = 0;
    numAbsences = 0;
    bool valid = isValidId(id); //checks if the given ID is valid
    if(valid){
        studentId = id;
    }
    else{
        cout << "Not a valid Id, please set a new id using \"obejctName\".setStudentId(\"studentID\")" << endl;
        studentId = "";
    }
}

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

void Student::setGrade(int n){
    grade = n;
}

void Student::setStudentId(string id){ //this needs the isValid method
    bool valid = isValidId(id); //checks if the given ID is valid
    if(valid){
        studentId = id;
    }
    else{
        cout << "Not a valid ID \n" << endl;
    }
}

void Student::addLate(){ //this is added via the Teacher class
    numLates++;
}

void Student::addAbsence() { //this is added via the Teacher class
    numAbsences++;
}

string Student::toString() const{
    cout << "Student:" << endl;
    cout << "Name: " <<  firstName << " " << lastName << endl;
    cout << "Address: " << address << endl;
    cout << "Grade: " << grade << endl;
    cout << "Student ID: " << studentId << endl;
    cout << "Number of Lates: " << numLates << endl;
    cout << "Number of Absences: " << numAbsences << endl;
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
