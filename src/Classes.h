//
// Created by Dhruv Rawat on 2020-03-10.
//

#include <iostream>
#include <string.h>

using namespace std;

#ifndef ADMIN_H
#define ADMIN_H

class Admin
{
private:
    string name;
    string username;
    string encrypted_password;
public:
    Admin();
    Admin(string, string);
    Admin(string, string, string);
    ~Admin();
    /* Code used for password entry */
    string adminEncrypt(string, string);
    string adminDecrypt(string, string);
    /* Getters and setters */
    string getName();
    string getUsername();
    string getPassword();
    void setName(string);
    void setUsername(string);
    void setPassword(string);
    /* Display */
    string toString();
};

#endif


#ifndef PERSON_H
#define PERSON_H

class Person //this is the base class for Student and Teacher. It is an abstract base class.
{
protected:
    string firstName;
    string lastName;
    string address;
    bool free[8]; //used to see if person is free during a block
public:
    Person();
    Person(string, string, string);
    virtual ~Person(); //a virtual function is used for destructors so function overriding can take place. The destructors in the child classes are also virtual
    /* Getters and setters */
    string getFirstName();
    string getLastName();
    string getAddress();
    void setFirstName(string);
    void setLastName(string);
    void setAddress(string);
    /* Methods used to set schedule for people */
    bool checkAvailability(int);
    void changeAvailability(int);
    //pure virtual functions are declared in base class and will be overridden via function overriding in the child classes
    virtual string toString() const = 0;
    virtual bool isValidId(string) const = 0; //this method checks if the student ID or teacher ID is valid.
    /*
      For a student ID to be valid, it must begin with a 'S' followed by exactly 9 digits
      For a teacher ID to be valid, it must begin with a 'C' followed by exactly 5 digits
    */
};

#endif


#ifndef STUDENT_H
#define STUDENT_H

//child class of Person
class Student : public Person
{
private:
    int grade;
    string studentId;
    int numLates;
    int numAbsences;
    string schedule[8]; //contains student's schedule
public:
    Student();
    Student(string, string, string, string, string); //no need for other constructors as user is forced to initialize all values
    virtual ~Student();
    /* Getters and setters */
    int getGrade();
    string getStudentId();
    int getNumLates();
    int getNumAbsences();
    void setGrade(string);
    void setStudentId(string);
    void addLate();
    void addAbsence();
    bool isValidId(string) const;
    /* Used to modify schedule */
    void removeCourse(int);
    void addCourse(string, int);
    /* Display */
    string toString() const;
};

#endif


#ifndef TEACHER_H
#define TEACHER_H

//Child class of Person
class Teacher : public Person
{
private:
    string teachables; //possible courses that the teachers can teach (ex. "math and computer science)
    string employeeId;
    int teacherNumber;
    string t_username;
    string t_encrypted_password;
    string schedule[8]; //contains teacher's schedule
public:
    Teacher();
    Teacher(string, string);
    Teacher(string, string, string, string, string);
    Teacher(string, string, string, string, string, string, string);
    virtual ~Teacher();
    /* Getters and setters */
    string getTeachables();
    string getEmployeeId();
    string getUsername();
    string getPassword();
    void setUsername(string);
    void setPassword(string);
    void setTeachables(string);
    void setEmployeeId(string);
    bool isValidId(string) const;
    /* Code used for password entry */
    string teacherEncrypt(string, string);
    string teacherDecrypt(string, string);
    /* Used to modify schedule */
    void addCourse(string, int);
    void removeCourse(int);
    /* Display */
    string toString() const;
};

#endif


#ifndef COURSE_H
#define COURSE_H

class Course{
private:
    Student ** students; //array of all students in the course
    Teacher * instructor; //teacher of the course
    int courseBlock; //1 = 1A; 2 = 1B; 3 = 1C; 4 = 1D; 5 = 2A; 6 = 2B; 7= 2C; 8 = 2D
    string subject;
    string courseCode;
    int roomNumber;
    int studentNumber; //number of students in the course
public:
    Course();
    Course(int, string, string, int);
    Course(int, string, string, int, Teacher&);
    ~Course();
    /* Getters and setters */
    string getCourseSubject();
    string getCourseCode();
    int getCourseBlock();
    string getCourseTeacher();
    int getRoomNumber();
    string getInstructorFirstName();
    string getInstructorLastName();
    string getInstructorId();
    void setCourseTeacher(Teacher&);
    void removeInstructorCourse(); //removes the instructor of the course
    void removeStudent(int, int);
    void addStudent(Student&);
    /* Display */
    void displayTeacher();
    void displayStudents();
    string toString();
};

#endif


#ifndef SCHOOL_H
#define SCHOOL_H

//Class that is used to perform all operations (CRUD) for all classes.
class School{
private:
    Person ** people; //array stores all teachers and students in the school
    Admin ** adminArray; //array stores all administrators
    Course ** classes; //array stores all courses in school
    int classNumber; //number of course objects in school
    int teachers; //number of teachers in school
    int students; //number of students in school
    int administrators; //number of administrators for school
    int totalPeople; //total number of People (teachers + students) in school
public:
    School(int, int, int, int);
    //Methods for signing in
    int adminLogin(string, string);
    int teacherLogin(string, string);
    //CRUD methods for people
    int findPeople(string, int, int, int);
    void editPerson(int, int);
    void displayPerson(int, int);
    void createPerson(int);
    int deletePerson(int, int, int);
    //CRUD methods for courses
    void findCourse(string, int);
    void createCourse();
    void deleteCourse(int);
    void addStudents(int);
    void removeStudent(int);
    void changeTeacher(int);
    bool findTeachers(int, int);
    bool findStudents(int);
    void displayTeacherCourses(int);
    /* Display */
    string toString();
};

#endif
