//
// Created by Dhruv Rawat on 2020-03-13.
//

#import "Classes.h"

School::School(int t, int s){
    teachers = t;
    students = s;
    totalPeople = t+s;
    people = new Person*[t+s];
    for(int i = 0; i < totalPeople; i++){
        if(i < t){ //firsts makes teachers
            people[i] = new Teacher();
        }
        else{ //makes students
            people[i] = new Student();
        }
    }
}

void School::displayPeople(int object) {
    if(object == 1){
        for (int i = 0; i < teachers; i++) {
            cout << i + 1 << ": " << people[i]->getFirstName() << " " << people[i]->getLastName() << endl;
        }
    }
    else{
        int counter = 1;
        for(int i = teachers; i < totalPeople; i++){
            cout << counter << ": " << people[i]->getFirstName() << " " << people[i]->getLastName() << endl;
            counter++;
        }
    }
}

void School::editPerson(int personNumber, int object) {
    personNumber--; //increments the value down by one so it can be used to navigate the "people" array
    cout << "Current Information:" << endl;
    people[personNumber]->toString();
    //gets new values from the user
    string firstName = "", lastName = "", address;
    cout << "Set new values. If you do not want to change a field, submit 0" << endl;
    cout << "First name: ";
    cin >> firstName;
    cout << "Last name: ";
    cin >> lastName;
    cout << "Address: ";
    cin.ignore();
    getline(cin, address);

    if(object == 1){ //Teacher specific actions done here
        string teachables = "", employeeId = "";
        cout << "Teachables: ";
        cin >> teachables;
        cout << "Employee ID: ";
        cin >> employeeId;

        //sets values in methods that are unique to Teacher
        //I need to access methods that are in the Teacher class that are not accessible by the Person class. I used downcasting here to access the methods
        auto temporary = dynamic_cast <Teacher*>(people[personNumber]);
        if(teachables != "0"){
            temporary->setTeachables(teachables);
        }
        if(employeeId != "0"){
            temporary->setEmployeeId(teachables);
        }
        people[personNumber] = temporary; //updates the Teacher object
    }
    else{
        int grade;
        string studentId = "";
        cout << "Grade: ";
        cin >> grade;
        cout << "Student ID: ";
        cin >> studentId;

        //sets values in methods that are unique to Student
        //I need to access methods that are in the Student class that are not accessible by the Person class. I used downcasting here to access the methods
        auto temporary = dynamic_cast <Student*>(people[personNumber]);
        if(grade != 0){
            temporary->setGrade(grade);
        }
        if(studentId != "0"){
            temporary->setStudentId(studentId);
        }
        people[personNumber] = temporary; //updates the Student object
    }
    //calls functions shared by Teacher and Student here
    if(firstName != "0"){
        people[personNumber]->setFirstName(firstName);
    }
    if(lastName != "0"){
        people[personNumber]->setLastName(lastName);
    }
    if(address != "0") {
        people[personNumber]->setAddress(address);
    }

    cout << endl;
    cout << "Updated Information:";
    people[personNumber]->toString();
}

string School::displayPerson(int personNumber) {
    personNumber--; //increments the value down by one so it can be used to navigate the "people" array
    people[personNumber]->toString();
    return "";
}



string School::toString(){
    int counter = 0; //this makes sure the elements for schoolStudents[] starts at zero
    for(int i = 0; i < totalPeople; i++){
        people[i] -> toString();
        cout << endl;
    }
    return "";
}
