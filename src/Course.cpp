//
// Created by Dhruv Rawat on 2020-06-02.
//

#include "Classes.h"

Course::Course(){ //all constructors add 2 default students to the class upon creation. These students can be removed later.
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
    if(block >= 1 && block <= 8){
        courseBlock = block;
    } else {
        courseBlock = 1;
    }
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
    if(block >= 1 && block <= 8){
        courseBlock = block;
    } else {
        courseBlock = 1;
    }
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
    cout << instructor->getFirstName() << " " << instructor->getLastName() << ".";
    return "";
}

int Course::getRoomNumber(){
    return roomNumber;
}

string Course::getInstructorFirstName() {
    return instructor->getFirstName();
}

string Course::getInstructorLastName() {
    return instructor->getLastName();
}

string Course::getInstructorId() {
    return instructor->getEmployeeId();
}

void Course::setCourseTeacher(Teacher& teach){
    instructor = &teach;
}

void Course::removeInstructorCourse(){
    int block = this->getCourseBlock();
    instructor->removeCourse(block);
}

void Course::removeStudent(int stu, int block){
    students[stu]->removeCourse(block); //removes the course from the student's schedule
    Student ** tempArray = students;
    studentNumber--;
    students = new Student * [studentNumber]; //re-declares the students array
    for(int i = 0; i < studentNumber; i++){ //re-initializes the elements in the students array, excluding the removed student
        if(i < stu){
            students[i] = tempArray[i];
        } else {
            students[i] = tempArray[i+1];
        }
    }
}

void Course::removeAllStudents() {
    for(int i = 0; i < studentNumber; i++){ //removes the course from the student's schedule
        students[i]->removeCourse(this->getCourseBlock());
    }
}

void Course::addStudent(Student& stu){
    Student ** tempArray = students;
    studentNumber++;
    students = new Student * [studentNumber]; //re-declares the students array
    for(int i = 0; i < studentNumber; i++){ //re-initializes the elements in the students array, including the added student
        if(i < studentNumber - 1){
            students[i] = tempArray[i];
        } else {
            students[i] = &stu;
        }
    }
}

int Course::isStudentInCourse(string fname, string lname) {
    string studentFirstName = "", studentLastName = "";
    int found1 = 0, found2 = 0;
    int result = -1;
    for (int i = 0; i < studentNumber; i++) { //checks if student is in course
        studentFirstName = students[i]->getFirstName();
        studentLastName = students[i]->getLastName();
        found1 = studentFirstName.find(fname);
        found2 = studentLastName.find(lname);
        if (found1 != -1 && found2 != -1) {
            result = i;
        }
    }
    return result;
}

void Course::displayStudents(){ //displays all students in the course
    for(int i = 0; i < studentNumber; i++){
        cout << (i+1) << ". " << students[i]->getFirstName() << " " << students[i]->getLastName() << "." << endl;
    }
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
