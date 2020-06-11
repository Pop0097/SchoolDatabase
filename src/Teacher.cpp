//
// Created by Dhruv Rawat on 2020-03-10.
//

#include "Classes.h"

Teacher::Teacher() : Person::Person(){
    teachables = "Default Teachables";
    employeeId = "Default Employee ID";
    t_username = "d_uname";
    t_encrypted_password = teacherEncrypt("pass", "Slf64kf321daC");
    for(int i = 0; i < 8; i++){ //initializes the schedule class to show that the teacher is free all periods
        schedule[i] = "Break";
    }
}

Teacher::Teacher(string u, string pass) : Person::Person(){
    teachables = "Default Teachables";
    employeeId = "Default Employee ID";
    t_username = u;
    t_encrypted_password = teacherEncrypt(pass, "Slf64kf321daC"); //encrypts password
    for(int i = 0; i < 8; i++){
        schedule[i] = "Break";
    }
}

Teacher::Teacher(string f, string l, string a, string t, string id) : Person::Person(f, l, a) {
    //for all fields it checks if the attribute is 0 (Used in UI to signal "cancel"). If it is, then the default is used.
    if(t != "0"){
        teachables = t;
    }
    else{
        teachables = "Default Teachables";
    }
    bool valid = isValidId(id); //checks if the given ID is valid
    //does action depending if id is valid
    if (valid) {
        employeeId = id;
    } else {
        cout << "Not a valid Id, please set a new id using \"obejctName\".setStudentId(\"studentID\")" << endl;
        employeeId = "Default Employee ID";
    }
    t_username = "d_uname";
    t_encrypted_password = teacherEncrypt("pass", "Slf64kf321daC"); //encrypts password
    for(int i = 0; i < 8; i++){
        schedule[i] = "Break";
    }
}

Teacher::Teacher(string f, string l, string a, string t, string id, string u, string pass) : Person::Person(f, l, a) {
    if(t != "0"){
        teachables = t;
    }
    else{
        teachables = "Default Teachables";
    }
    bool valid = isValidId(id); //checks if the given ID is valid
    if (valid) {
        employeeId = id;
    } else {
        cout << "Not a valid Id, please set a new id using \"obejctName\".setStudentId(\"studentID\")" << endl;
        employeeId = "Default Employee ID";
    }
    t_username = u;
    t_encrypted_password = teacherEncrypt(pass, "Slf64kf321daC"); //encrypts password
    for(int i = 0; i < 8; i++){
        schedule[i] = "Break";
    }
}

Teacher::~Teacher(){}

string Teacher::getTeachables() {
    return teachables;
}

string Teacher::getEmployeeId(){
    return employeeId;
}

string Teacher::getUsername(){
    return t_username;
}

string Teacher::getPassword(){
    return t_encrypted_password;
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
        cout << "Not a valid Employee ID \n" << endl;
    }
}

void Teacher::setUsername(string uname){
    t_username = uname;
}

void Teacher::setPassword(string pass){
    t_encrypted_password = teacherEncrypt(pass, "Slf64kf321daC"); //encrypts password
}

bool Teacher::isValidId(string n) const {
    bool valid = false;
    if(n.length() == 6){
        char firstCharacter = n.at(0);
        int digit[5];
        for(int i = 0; i < 5; i++){
            digit[i] = (int) n.at(i+1);
        }
        if(firstCharacter == 'C' && n.length() == 6 && (48 <= digit[0] && 57 >= digit[0]) && (48 <= digit[1] && 57 >= digit[1]) && (48 <= digit[2] && 57 >= digit[2]) && (48 <= digit[3] && 57 >= digit[3]) && (48 <= digit[4] && 57 >= digit[4]) ) {
            valid = true;
        }
    }
    return valid;
}

string Teacher::teacherEncrypt(string password, string key){ //method encrypts the teacher's password
    //ensures the key is (at a minimum) as long as the message
    string tmp(key);
    while(key.size() < password.size()){
        key += tmp;
    }

    for(int i = 0; i < password.size(); ++i){
        password[i] ^= key[i];
    }
    //cout << password;
    return password;
}

string Teacher::teacherDecrypt(string entry, string key){ //method used to decrypt the teacher's password
    return teacherEncrypt(entry, key);
}

void Teacher::addCourse(string c, int block){ //modifies teacher schedule to add course
    schedule[block-1] = c;
}

void Teacher::removeCourse(int block){ //modifies teacher schedule to remove course
    schedule[block-1] = "Break";
    free[block-1] = true;
}

string Teacher::toString() const{
    cout << "Name: " << firstName << " " << lastName << endl;
    cout << "Address: " << address << endl;
    cout << "Teachables: " << teachables << endl;
    cout << "Employee ID: " << employeeId << endl;
    cout << "Schedule: " << endl;
    for(int i = 0; i < 8; i++){ //prints teacher's schedule
        cout << "-----------------------------" << endl;
        cout << "Block " << (i+1) << endl;
        cout << schedule[i] << endl;
    }
    cout << endl;
    return "";
}
