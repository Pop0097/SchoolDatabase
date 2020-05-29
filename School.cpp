//
// Created by Dhruv Rawat on 2020-03-13.
//

#import "Classes.h"

School::School(int t, int s, int a){
    teachers = t;
    students = s;
    totalPeople = t+s;
    people = new Person*[totalPeople];
    for(int i = 0; i < totalPeople; i++){ //instatiates all objects in people array
        if(i < t){ //firsts makes teachers
            people[i] = new Teacher();
        }
        else{ //makes students
            people[i] = new Student();
        }
    }
    administrators = a;
    adminArray = new Admin*[a];
    for(int i = 0; i < a; i++){
        adminArray[i] = new Admin();
    }
}

void School::displayPeople(int object) {
    if(object == 1){
        if(teachers == 0){//checks if there are teachers present in the array
            cout << "There are no teachers in the system" << endl;
        }
        else{
            for (int i = 0; i < teachers; i++) {
                cout << i + 1 << ": " << people[i]->getFirstName() << " " << people[i]->getLastName() << endl;
            }
        }
    }
    else{
        if(students == 0){ //checks if there are students present in the array
            cout << "There are no students in the system" << endl;
        }
        else{
            int counter = 1;
            for(int i = teachers; i < totalPeople; i++){
                cout << counter << ": " << people[i]->getFirstName() << " " << people[i]->getLastName() << endl;
                counter++;
            }
        }
    }
}

void School::editPerson(int personNumber, int object) {
    if(object == 1){
        personNumber--; //increments the value down by one so it can be used to navigate the "people" array
    }
    else{
        personNumber = teachers + personNumber - 1;
    }
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
        getline(cin, teachables);
        cout << "Employee ID: ";
        getline(cin, employeeId);

        //sets values in methods that are unique to Teacher
        //I need to access methods that are in the Teacher class that are not accessible by the Person class. I used downcasting here to access the methods
        Teacher * temporary = dynamic_cast <Teacher*>(people[personNumber]);
        if(temporary){
            if(teachables != "0"){
                temporary->setTeachables(teachables);
            }
            if(employeeId != "0"){
                temporary->setEmployeeId(employeeId);
            }
            people[personNumber] = temporary; //updates the Teacher object
        }
    }
    else{
        string grade = "", studentId = "";
        cout << "Grade: ";
        getline(cin, grade); //takes in input as a string so the program does not crash if the user inputs a string
        cout << "Student ID: ";
        getline(cin, studentId);

        //sets values in methods that are unique to Student
        //I need to access methods that are in the Student class that are not accessible by the Person class. I used downcasting here to access the methods
        Student * temporary = dynamic_cast <Student*>(people[personNumber]);
        if(temporary){ //checks if pointer is defined
            if(grade != "0"){
                temporary->setGrade(grade);
            }
            if(studentId != "0"){
                temporary->setStudentId(studentId);
            }
            people[personNumber] = temporary; //updates the Student object
        }
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
    cout << "Updated Information:" << endl;
    people[personNumber]->toString();
}

string School::displayPerson(int personNumber, int object) {
    if(object == 1){
        personNumber--; //increments the value down by one so it can be used to navigate the "people" array
    }
    else{
        personNumber = teachers + personNumber - 1;
    }
    people[personNumber]->toString();
    return "";
}

void School::createPerson(int object) {
    totalPeople++;
    Person ** temporaryArray = people; //creates a temporary array to store the previous "people" array

    //gets new values from the user
    string firstName = "", lastName = "", address;
    cout << "Set new values. If you do not want to change a field, submit 0. To cancel this process, input 0 into all fields" << endl;
    cout << "First name: ";
    cin >> firstName;
    cout << "Last name: ";
    cin >> lastName;
    cout << "Address: ";
    cin.ignore();
    getline(cin, address);

    //sets values in methods that are unique to Teacher
    if (object == 1) {
        string teachables = "", employeeId = "";
        cout << "Teachables: ";
        getline(cin, teachables);
        cout << "Employee ID: ";
        cin >> employeeId;
        if (firstName == "0" && lastName == "0" && address == "0" && teachables == "0" && employeeId == "0") {//checks if user wishes to cancel the process
            totalPeople--;
            cout << "Creation process canceled" << endl;
        }
        else {
            teachers++;
            Teacher *newTeacher = new Teacher(firstName, lastName, address, teachables, employeeId); //creates new Teacher object with inputted information
            people = new Person *[totalPeople]; //resets the people array to include the new individual
            for (int i = 0; i < totalPeople; i++) {
                if (i < teachers - 1) {
                    people[i] = temporaryArray[i];
                } else if (i == teachers - 1) {
                    people[i] = newTeacher;
                } else {
                    people[i] = temporaryArray[i - 1];
                }
            }
            cout << endl;
            cout << "New Teacher: " << endl;
            people[teachers - 1]->toString();
        }
    }
    else {
        string grade = "", studentId = "";
        cout << "Grade: ";
        cin >> grade;
        cout << "Student ID: ";
        cin >> studentId;
        if (firstName == "0" && lastName == "0" && address == "0" && grade == "0" && studentId == "0") {//checks if user wishes to cancel the process
            totalPeople--;
            cout << "Creation process canceled" << endl;
        }
        else {
            students++;
            Student * newStudent = new Student(firstName, lastName, address, grade, studentId); //creates new Student object with inputted information
            people = new Person *[totalPeople]; //resets the people array to include the new individual
            for (int i = 0; i < totalPeople; i++) {
                if (i < teachers) {
                    people[i] = temporaryArray[i];
                } else if (i >= teachers && i < teachers + students - 1) {
                    people[i] = temporaryArray[i];
                } else {
                    people[i] = newStudent;
                }
            }
            cout << endl;
            cout << "New Student" << endl;
            people[totalPeople - 1]->toString();
        }
    }
    delete[] temporaryArray;
}

void School::deletePerson(int personNumber, int object) {
    totalPeople--;
    Person ** temporaryArray = people; //creates a temporary array to store the previous "people" array

    if(object == 1){
        personNumber--; //increments the value down by one so it can be used to navigate the "people" array
        teachers--;
        people = new Person *[totalPeople];
        for(int i = 0; i < totalPeople; i++){
            if(i < personNumber){
                people[i] = temporaryArray[i];
            }
            else{
                people[i] = temporaryArray[i+1];
            }
        }
        cout << "Teacher deleted" << endl;
    }
    else{
        personNumber = teachers + personNumber - 1;
        students--;
        people = new Person *[totalPeople];
        for(int i = 0; i < totalPeople; i++){
            if(i < personNumber){
                people[i] = temporaryArray[i];
            }
            else{
                people[i] = temporaryArray[i+1];
            }
        }
        cout << "Student deleted" << endl;
    }
    delete[] temporaryArray;
}

string School::toString(){
    int counter = 0; //this makes sure the elements for schoolStudents[] starts at zero
    for(int i = 0; i < totalPeople; i++){
        people[i] -> toString();
        cout << endl;
    }
    return "";
}

bool School::adminLogin(string uname, string password){
    bool valid = false;
    Admin * tempAdmin = new Admin(uname, password);
    string encrypt_pass = tempAdmin->adminEncrypt(password, "Axc4RDx3osYg");
    delete tempAdmin;
    //cout << "here1" << endl;

    Admin ** temporaryArray = adminArray;
    string tempName = "";
    for(int i = 0; i < administrators; i++){
        if(temporaryArray[i]->getUsername() == uname && temporaryArray[i]->getPassword() == encrypt_pass){
            tempName = temporaryArray[i]->getName();
            valid = true;
        }
    }

    //cout << "here2" << endl;

    if(valid){
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "You're logged in. Welcome!" << endl;
        cout << endl;
        cout << endl;
        return true;
    }
    else{
        cout << "Credentials are incorrect. Please try again" << endl;
        cout << endl;
        return false;
    }
}

bool School::teacherLogin(string uname, string password){
    bool valid = false;
    Teacher * tempTeach = new Teacher(uname, password);
    string encrypt_pass = tempTeach->teacherEncrypt(password, "Slf64kf321daC");
    delete tempTeach;

    for(int i = 0; i < teachers; i++){
        Teacher * tempTeach = dynamic_cast<Teacher*>(people[i]);

        if(tempTeach->getUsername() == uname && tempTeach->getPassword() == encrypt_pass) {
            valid = true;
        }
    }

    if(valid){
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "You're logged in. Welcome!" << endl;
        cout << endl;
        cout << endl;
        return true;
    }
    else{
        cout << "Credentials are incorrect. Please try again" << endl;
        cout << endl;
        return false;
    }
}
