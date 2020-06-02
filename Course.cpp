//
// Created by Dhruv Rawat on 2020-06-02.
//

#include "Classes.h"

Course::Course(){ //makes a course with ten students and one teacher
    studentNumber = 10;
    students = new Student*[10];
    for(int i = 0; i < 10; i++){
        students[i] = new Student();
    }
    instructor = new Teacher();
    courseBlock = 0;
    subject = "Default";
    courseCode = "Default";
    roomNumber = 0;
}

Course::Course(int block, string sub, string code, int room){
    studentNumber = 10;
    students = new Student*[10];
    for(int i = 0; i < 10; i++){
        students[i] = new Student();
    }
    instructor = new Teacher();
    courseBlock = block;
    subject = sub;
    courseCode = code;
    roomNumber = room;
}

Course::Course(int studentsNumber, int block, string sub, string code, int room){
    studentNumber = studentsNumber;
    students = new Student*[studentsNumber];
    for(int i = 0; i < studentsNumber; i++){
        students[i] = new Student();
    }
    instructor = new Teacher();
    courseBlock = block;
    subject = sub;
    courseCode = code;
    roomNumber = room;
}

Course::Course(int studentsNumber, int block, string sub, string code, int room, Teacher& teach){
    studentNumber = studentsNumber;
    students = new Student*[studentsNumber];
    for(int i = 0; i < studentsNumber; i++){
        students[i] = new Student();
    }
    instructor = &teach;
    courseBlock = block;
    subject = sub;
    courseCode = code;
    roomNumber = room;
}

Course::~Course(){}

string Course::getCourseSubject(){
    return subject;
}

string Course::getCourseCode(){
    return courseCode;
}

int Course::getCourseBlock(){
    return courseBlock;
}

string Course::getCourseTeacher(){
    cout << instructor->getFirstName() << " " << instructor->getLastName();
    return "";
}

int Course::getRoomNumber(){
    return roomNumber;
}




string Course::toString(){
    cout << "Course: " << subject << " (" << courseCode << ")" <<  endl;
    cout << "Block: " << courseBlock << endl;
    cout << "Room: " << roomNumber << endl;
    cout << "Teacher: " << instructor->getFirstName() << " " << instructor->getLastName() << "; (Employee ID: " << instructor->getEmployeeId() << ")" << endl;
    cout << "Students: " << endl;
    int counter = 1;
    for(int i = 0; i < studentNumber; i++){
        cout << counter << ". " << students[i]->getFirstName() << " " << students[i]->getLastName() << endl;
        counter++;
    }
    cout << endl;
    return "";
}
