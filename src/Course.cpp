//
// Created by Dhruv Rawat on 2020-06-02.
//

#include "Classes.h"

Course::Course(){ //makes a course with ten students and one teacher
    studentNumber = 2;
    students = new Student*[2];
    for(int i = 0; i < 2; i++){
        students[i] = new Student();
    }
    instructor = new Teacher();
    courseBlock = 1;
    subject = "Default";
    courseCode = "Default";
    roomNumber = 0;
}

Course::Course(int block, string sub, string code, int room){
    studentNumber = 2;
    students = new Student*[2];
    for(int i = 0; i < 2; i++){
        students[i] = new Student();
    }
    instructor = new Teacher();
    courseBlock = block;
    subject = sub;
    courseCode = code;
    roomNumber = room;
}

Course::Course(int block, string sub, string code, int room, Teacher& teach){
    studentNumber = 2;
    students = new Student*[2];
    for(int i = 0; i < 2; i++){
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

void Course::displayTeacher() {
    cout << instructor->getFirstName() << " " << instructor->getLastName();
}

void Course::setCourseBlock(int block){
    courseBlock = block;
}

void Course::setCourseTeacher(Teacher& teach){
    instructor = &teach;
}

void Course::setRoomNumber(int num){
    roomNumber = num;
}
void Course::displayStudents(){
    for(int i = 0; i < studentNumber; i++){
        cout << (i+1) << ". " << students[i]->getFirstName() << " " << students[i]->getLastName()  << endl;
    }
}

void Course::removeInstructorCourse(){
    int block = this->getCourseBlock();
    instructor->removeCourse(block);
}

void Course::removeStudent(int stu, int block){
    students[stu]->removeCourse(block);
    Student ** tempArray = students;
    studentNumber--;
    students = new Student * [studentNumber];
    for(int i = 0; i < studentNumber; i++){
        if(i < stu){
            students[i] = tempArray[i];
        } else if(i > stu){
            students[i] = tempArray[i+1];
        } else{
            cout << i << " Student removed" << endl;
        }
    }
    this->toString();
}

void Course::addStudent(Student& stu){
    Student ** tempArray = students;
    studentNumber++;
    students = new Student * [studentNumber];
    for(int i = 0; i < studentNumber; i++){
        if(i < studentNumber - 1){
            students[i] = tempArray[i];
        } else {
            students[i] = &stu;
        }
    }
    this->toString();
}

string Course::toString(){
    cout << "Course: " << subject << " (" << courseCode << ")" <<  endl;
    cout << "Block: " << courseBlock << endl;
    cout << "Room: " << roomNumber << endl;
    cout << "Teacher: " << instructor->getFirstName() << " " << instructor->getLastName() << "; (Employee ID: " << instructor->getEmployeeId() << ")" << endl;
    cout << "Students: " << studentNumber << endl;
    int counter = 1;
    for(int i = 0; i < studentNumber; i++){
        cout << counter << ". " << students[i]->getFirstName() << " " << students[i]->getLastName() << endl;
        counter++;
    }
    cout << endl;
    return "";
}
