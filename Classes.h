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
    string adminEncrypt(string, string);
    string adminDecrypt(string, string);
    string getName();
    string getUsername();
    string getPassword();
    string toString();
    void setName(string);
    void setUsername(string);
    void setPassword(string);
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
public:
    Person();
    Person(string, string, string);
    virtual ~Person(); //a virtual function is used for destructors so function overriding can take place. The destructors in the child classes are also virtual
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
public:
    Student();
    Student(string, string, string, string, string); //no need for other constructors as user is forced to initialize all values
    virtual ~Student();
    int getGrade();
    string getStudentId();
    int getNumLates();
    int getNumAbsences();
    void setGrade(string);
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
    string t_username;
    string t_encrypted_password;
public:
    Teacher();
    Teacher(string, string);
    Teacher(string, string, string, string, string);
    Teacher(string, string, string, string, string, string, string);
    virtual ~Teacher();
    string getTeachables();
    string getEmployeeId();
    void setTeachables(string);
    void setEmployeeId(string);
    void markStudentLate(Student&);
    void markStudentAbsent(Student&);
    bool isValidId(string) const;
    string toString() const;
    string teacherEncrypt(string, string);
    string teacherDecrypt(string, string);
    string getUsername();
    string getPassword();
    void setUsername(string);
    void setPassword(string);
};

#endif

#ifndef SCHOOL_H
#define SCHOOL_H

class School{
private:
    Person ** people;
    Admin ** adminArray;
    int teachers;
    int students;
    int administrators;
    int totalPeople;
public:
    School(int, int, int);
    int findPeople(string, int, int, int);
    void editPerson(int, int);
    void displayPerson(int, int);
    void createPerson(int);
    int deletePerson(int, int, int);


    string toString();
    int adminLogin(string, string);
    int teacherLogin(string, string);
};

#endif
