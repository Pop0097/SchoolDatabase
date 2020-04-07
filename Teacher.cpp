//
// Created by Dhruv Rawat on 2020-03-10.
//

#include "Classes.h"

Teacher::Teacher() : Person::Person(){
    teachables = "";
    employeeId = "";
}

Teacher::Teacher(string f, string l) : Person::Person(f, l){
    teachables = "";
    employeeId = "";
}

Teacher::Teacher(string f, string l, string a, string t, string id) : Person::Person(f, l, a) {
    teachables = t;
    bool valid = isValidId(id); //checks if the given ID is valid
    if (valid) {
        employeeId = id;
    } else {
        cout << "Not a valid Id, please set a new id using \"obejctName\".setStudentId(\"studentID\")" << endl;
        employeeId = "";
    }
}

Teacher::Teacher(string f, string l, string a, string id) : Person::Person(f, l, a){
    teachables = "";
    bool valid = isValidId(id); //checks if the given ID is valid
    if (valid) {
        employeeId = id;
    } else {
        cout << "Not a valid Id, please set a new id using \"obejctName\".setStudentId(\"studentID\")" << endl;
        employeeId = "";
    }
}

string Teacher::getTeachables() {
    return teachables;
}

string Teacher::getEmployeeId(){
    return employeeId;
}

void Teacher::setTeachables(string t) {
    teachables = t;
}

void Teacher::setEmployeeId(string id) {
    bool valid = isValidId(id); //checks if the given ID is valid
    if(valid){
        employeeId = id;
    }
    else{
        cout << "Not a valid ID \n" << endl;
    }
}

void Teacher::markStudentLate(Student &s) { //this is used to mark students late
    s.addLate();
}

void Teacher::markStudentAbsent(Student &s){//this is used to mark students as absent
    s.addAbsence();
}

string Teacher::toString() const{
    cout << "Teacher:" << endl;
    cout << "Name: " << firstName << " " << lastName << endl;
    cout << "Address: " << address << endl;
    cout << "Teachables: " << teachables << endl;
    cout << "Employee ID: " << employeeId << endl;
    cout << endl;
    return "";
}

bool Teacher::isValidId(string n) const {
    bool valid = false;
    if(n.length() == 6){
        char firstCharacter = n.at(0);
        int digit[5];
        for(int i = 0; i < 5; i++){
            digit[i] = (int) n.at(i+1); //48 57
        }
        if(firstCharacter == 'C' && n.length() == 6 && (48 <= digit[0] && 57 >= digit[0]) && (48 <= digit[1] && 57 >= digit[1]) && (48 <= digit[2] && 57 >= digit[2]) && (48 <= digit[3] && 57 >= digit[3]) && (48 <= digit[4] && 57 >= digit[04]) ) {
            valid = true;
        }
    }
    return valid;
}
