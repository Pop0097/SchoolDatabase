//
// Created by Dhruv Rawat on 2020-03-10.
//

#include <iostream>
#include <string.h>

using namespace std;

#ifndef PERSON_H
#define PERSON_H

class Person //this is the base class for Student and Teacher. It is an abstract base class.
{
protected:
    string firstName;
    string lastName;
    string address;
public:
    Person();
    Person(string, string);
    Person(string, string, string);
    string getFirstName();
    string getLastName();
    string getAddress();
    void setFirstName(string);
    void setLastName(string);
    void setAddress(string);
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

class Student : public Person
{
private:
    int grade;
    string studentId;
    int numLates;
    int numAbsences;
    int studentNumber;
public:
    Student();
    Student(string, string);
    Student(string, string, string, int, string);
    Student(string, string, int, string);
    int getGrade();
    string getStudentId();
    int getNumLates();
    int getNumAbsences();
    void setGrade(int);
    void setStudentId(string);
    void addLate();
    void addAbsence();
    bool isValidId(string) const;
    string toString() const;
};

#endif

#ifndef TEACHER_H
#define TEACHER_H

class Teacher : public Person
{
private:
    string teachables; //possible courses that the teachers can teach (ex. "math and computer science)
    string employeeId;
    int teacherNumber;
public:
    Teacher();
    Teacher(string, string);
    Teacher(string, string, string, string, string);
    Teacher(string, string, string, string);
    string getTeachables();
    string getEmployeeId();
    void setTeachables(string);
    void setEmployeeId(string);
    void markStudentLate(Student&);
    void markStudentAbsent(Student&);
    bool isValidId(string) const;
    string toString() const;
};

#endif

#ifndef SCHOOL_H
#define SCHOOL_H

class School{
private:
    Person ** people;
    int teachers;
    int students;
    int totalPeople;
public:
    School(int, int);
    void displayPeople(int); //gives a list of all available teachers
    void editPerson(int, int);
    string displayPerson(int);



    string toString();
};

#endif
