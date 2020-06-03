//
// Created by Dhruv Rawat on 2020-03-13.
//

#import "Classes.h"

School::School(int t, int s, int a, int c){
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
    classNumber = c;
    classes = new Course*[classNumber];
    for(int i = 0; i < classNumber; i++){
        classes[i] = new Course();
    }
}

/* Methods for signing in */

int School::adminLogin(string uname, string password){
    bool valid = false;
    int userNumber = 0;
    Admin * tempAdmin = new Admin(uname, password);
    string encrypt_pass = tempAdmin->getPassword();
    //cout << "yee: " << encrypt_pass << endl;
    delete tempAdmin;
    // cout << "here1" << endl;

    Admin ** temporaryArray = adminArray;
    string tempName = "";
    for(int i = 0; i < administrators; i++){
        //cout << "AAA: " << temporaryArray[i]->getPassword() << endl;
        if(temporaryArray[i]->getUsername() == uname && temporaryArray[i]->getPassword() == encrypt_pass){
            //cout << temporaryArray[i]->getUsername() << " " << temporaryArray[i]->getPassword() << " ; " << encrypt_pass << endl;
            tempName = temporaryArray[i]->getName();
            userNumber = i+1;
            valid = true;
        }
    }

    // cout << "here2" << endl;

    if(valid){
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "You're logged in. Welcome!" << endl;
        cout << endl;
        cout << endl;
        return userNumber;
    }
    else{
        cout << "Credentials are incorrect. Please try again" << endl;
        cout << endl;
        return -1;
    }
}

int School::teacherLogin(string uname, string password){
    bool valid = false;
    int userNumber = 0;
    Teacher * tempTeach = new Teacher(uname, password);
    string encrypt_pass = tempTeach->getPassword();
    //cout << "yee: " << encrypt_pass << endl;
    delete tempTeach;

    for(int i = 0; i < teachers; i++){
        Teacher * tempTeach = dynamic_cast<Teacher*>(people[i]);
        //cout << "AAA: " << tempTeach->getPassword() << endl;

        if(tempTeach->getUsername() == uname && tempTeach->getPassword() == encrypt_pass) {
            //cout << tempTeach->getUsername() << " " << tempTeach->getPassword() << " ; " << encrypt_pass << endl;
            valid = true;
            userNumber = i+1;
        }
    }

    if(valid){
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "You're logged in. Welcome!" << endl;
        cout << endl;
        cout << endl;
        return userNumber;
    }
    else{
        cout << "Credentials are incorrect. Please try again" << endl;
        cout << endl;
        return -1;
    }
}

/* Methods for CRUD operations for people */

int School::findPeople(string n, int object, int action, int userNumber){ //function searches whole people array and only gives results that have the user's input within
    int searchType = 0;
    string fName = "", lName = "";
    int found = n.find(" ");
    //cout << "Found: " << found << endl;
    if(found != -1 && object != 3){ //in case the user put in both the first and last name
        searchType = 1;
        fName = n.substr(0, found);
        lName = n.substr(found+1);
        //cout << "Names:" << fName << " " << lName << endl;
    }
    int counter = 1;
    bool anyFound = false;
    if(object == 1){ //searching for teachers
        for(int i = 0; i < teachers; i++){
            if(searchType == 0){
                int found1 = people[i]->getFirstName().find(n);
                int found2 = people[i]->getLastName().find(n);
                //cout << "Found1: " << found1 << " " << "Found2: " << found2 << endl;
                if(found1 != -1 || found2 != -1){
                    cout << counter << ". " << people[i]->getFirstName() << " " << people[i]->getLastName() << " (enter \""  << (i+1) << "\")" << endl;
                    anyFound = true;
                    counter++;
                }
            } else{
                int found1 = people[i]->getFirstName().find(fName);
                int found2 = people[i]->getLastName().find(lName);
                //cout << "Found1: " << found1 << " " << "Found2: " << found2 << endl;
                if(found1 != -1 || found2 != -1){
                    cout << counter << ". " << people[i]->getFirstName() << " " << people[i]->getLastName() << " (enter \""  << (i+1) << "\")" << endl;
                    anyFound = true;
                    counter++;
                }
            }
        }
    }
    else if (object == 2){ //searching for students
        for(int i = teachers; i < totalPeople; i++){
            if(searchType == 0){
                int found1 = people[i]->getFirstName().find(n);
                int found2 = people[i]->getLastName().find(n);
                //cout << "Found1: " << found1 << " " << "Found2: " << found2 << endl;
                if(found1 != -1 || found2 != -1){
                    cout << counter << ". " << people[i]->getFirstName() << " " << people[i]->getLastName() << " (enter \""  << (i-teachers+1) << "\")" << endl;
                    anyFound = true;
                    counter++;
                }
            } else{
                int found1 = people[i]->getFirstName().find(fName);
                int found2 = people[i]->getLastName().find(lName);
                //cout << "Found1: " << found1 << " " << "Found2: " << found2 << endl;
                if(found1 != -1 || found2 != -1){
                    cout << counter << ". " << people[i]->getFirstName() << " " << people[i]->getLastName() << " (enter \""  << (i-teachers+1) << "\")" << endl;
                    anyFound = true;
                    counter++;
                }
            }
        }
    } else { //searching for administrators
        for(int i = 0; i < administrators; i++){
            int found = adminArray[i]->getName().find(n);
            //cout << "Found: " << found << endl;
            if(found != -1){
                cout << counter << ". " << adminArray[i]->getName() << " (Type \""  << (i+1) << "\")" << endl;
                anyFound = true;
                counter++;
            }
        }
    }

    if(anyFound) {
        int decision = 0;
        cout << "Please select one of the above (or Type \"0\" to cancel)" << endl;
        cin >> decision;
        if(decision != 0 && action == 1){ //view
            this->displayPerson(decision, object);
        } else if (decision != 0 && action == 2){ //edit
            this->editPerson(decision, object);
        } else if (decision != 0 && action == 3) { //delete
            userNumber = this->deletePerson(decision, object, userNumber);
        } else if(decision != 0 && action == 4) { //mark student late
            Student * tempStudent = dynamic_cast<Student*>(people[decision-1+teachers]);
            tempStudent->addLate();
        } else if(decision != 0 && action == 5) { //mark student absent
            Student * tempStudent = dynamic_cast<Student*>(people[decision-1+teachers]);
            tempStudent->addAbsence();
        }
    } else {
        cout << "No entries matched your search." << endl;
        cout  << endl;
    }
    return userNumber;
}

void School::displayPerson(int personNumber, int object) {
    if(object == 1){
        personNumber--; //increments the value down by one so it can be used to navigate the "people" array
        people[personNumber]->toString();
    }
    else if (object == 2){
        personNumber = teachers + personNumber - 1;
        people[personNumber]->toString();
    }
    else{
        personNumber--;
        adminArray[personNumber]->toString();
    }
}

void School::editPerson(int personNumber, int object) {
    if(object == 1 || object == 2){
        if(object == 1){
            personNumber--; //increments the value down by one so it can be used to navigate the "people" array
        }
        else{
            personNumber = teachers + personNumber - 1;
        }
        cout << "Current Information:" << endl;
        people[personNumber]->toString();
        //gets new values from the user
        string firstName = "", lastName = "", address = "";
        cout << "Set new values. If you do not want to change a field, submit 0" << endl;
        cout << "First name: ";
        cin >> firstName;
        cout << "Last name: ";
        cin >> lastName;
        cout << "Address: ";
        cin.ignore();
        getline(cin, address);

        if(object == 1){ //Teacher specific actions done here
            string teachables = "", employeeId = "", username = "", password = "";
            cout << "Teachables: ";
            getline(cin, teachables);
            cout << "Employee ID: ";
            getline(cin, employeeId);
            cout << "Username: ";
            getline(cin, username);
            cout << "Password: ";
            getline(cin, password);

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
                if(username != "0"){
                    temporary->setUsername(username);
                }
                if(password != "0"){
                    temporary->setPassword(password);
                }
                people[personNumber] = temporary; //updates the Teacher object
            }
        }
        else if (object == 2){
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
    } else {
        personNumber--;
        cout << "Current Information:" << endl;
        adminArray[personNumber]->toString();
        //gets new values from the user
        string name = "", username = "", password = "";
        cout << "Set new values. If you do not want to change a field, submit 0" << endl;
        cout << "Name (first and last): ";
        cin.ignore();
        getline(cin, name);
        cout << "Username: ";
        getline(cin, username);
        cout << "Password: ";
        getline(cin, password);

        if(name != "0"){
            adminArray[personNumber]->setName(name);
        }
        if(username != "0"){
            adminArray[personNumber]->setUsername(username);
        }
        if(password != "0"){
            adminArray[personNumber]->setPassword(password);
        }
        cout << endl;
        cout << "Updated Information:" << endl;
        adminArray[personNumber]->toString();
    }
}

void School::createPerson(int object) {
    cout << "Set new values. If you do not want to change a field, submit 0. To cancel this process, input 0 into all fields" << endl;
    if(object == 1 || object == 2){
        totalPeople++;
        Person ** temporaryArray = people; //creates a temporary array to store the previous "people" array

        //gets new values from the user
        string firstName = "", lastName = "", address;
        cout << "First name: ";
        cin >> firstName;
        cout << "Last name: ";
        cin >> lastName;
        cout << "Address: ";
        cin.ignore();
        getline(cin, address);
        //sets values in methods that are unique to Teacher
        if (object == 1) {
            string teachables = "", employeeId = "", username = "", password = "";
            cout << "Teachables: ";
            getline(cin, teachables);
            cout << "Employee ID: ";
            cin >> employeeId;
            cout << "Username: ";
            cin.ignore();
            getline(cin, username);
            cout << "Password: ";
            getline(cin, password);
            if (firstName == "0" && lastName == "0" && address == "0" && teachables == "0" && employeeId == "0" && username == "0" && password == "0") {//checks if user wishes to cancel the process
                totalPeople--;
                cout << "Creation process canceled" << endl;
            }
            else {
                teachers++;
                Teacher * tempPerson = new Teacher(firstName, lastName, address, teachables, employeeId, username, password); //creates new Teacher object with inputted information
                people = new Person *[totalPeople]; //resets the people array to include the new individual
                for (int i = 0; i < totalPeople; i++) {
                    if (i < teachers - 1) {
                        people[i] = temporaryArray[i];
                    } else if (i == teachers - 1) {
                        people[i] = tempPerson;
                    } else {
                        people[i] = temporaryArray[i - 1];
                    }
                }
                cout << endl;
                cout << "New Teacher: " << endl;
                people[teachers - 1]->toString();
            }
        }
        else if (object == 2) {
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
                Student * tempPerson = new Student(firstName, lastName, address, grade, studentId); //creates new Student object with inputted information
                people = new Person *[totalPeople]; //resets the people array to include the new individual
                for (int i = 0; i < totalPeople; i++) {
                    if (i < teachers) {
                        people[i] = temporaryArray[i];
                    } else if (i >= teachers && i < teachers + students - 1) {
                        people[i] = temporaryArray[i];
                    } else {
                        people[i] = tempPerson;
                    }
                }
                cout << endl;
                cout << "New Student:" << endl;
                people[totalPeople - 1]->toString();
                delete tempPerson;
            }
        }
        delete[] temporaryArray;

    } else {
        cin.ignore();
        string name = "", username = "", password = "";
        cout << "Name (first and last): ";
        getline(cin, name);
        cout << "Username: ";
        getline(cin, username);
        cout << "Password: ";
        getline(cin, password);
        cout << "Inputs: " << name << " " << username << " " << password << endl;

        if(name == "0" && username == "0" && password == "0"){
            cout << "Process canceled." << endl;
            cout << endl;
        }
        else{
            administrators++;
            Admin * newAdmin = new Admin(name, username, password);
            //sets new and arrays
            Admin ** tempAdminArray = adminArray;
            adminArray = new Admin * [administrators];
            for(int i = 0; i < administrators; i++){
                if(i < administrators-1){
                    adminArray[i] = tempAdminArray[i];
                }
                else{
                    adminArray[i] = newAdmin;
                }
            }
            cout << endl;
            cout << "New Administrator:" << endl;
            adminArray[administrators - 1]->toString();
            delete [] tempAdminArray;
            delete newAdmin;
        }
    }

}

int School::deletePerson(int personNumber, int object, int userNumber) {
    string confirmation = "";
    cout << "Are you sure? (Type \"y\" or \"n\")" << endl;
    cin.ignore();
    getline(cin, confirmation);
    if(confirmation == "y"){
        if(personNumber < userNumber){ //if the user being deleted comes before the current user in the array, the current user's array is shifted so the functions still work
            userNumber--;
        }
        if(object == 1 || object == 2){
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
            else if (object == 2){
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
        } else {
            Admin ** temporaryArray = adminArray;
            personNumber--;
            administrators--;
            adminArray = new Admin * [administrators];
            for(int i = 0; i < administrators; i++){
                if(i < personNumber){
                    adminArray[i] = temporaryArray[i];
                }
                else{
                    adminArray[i] = temporaryArray[i+1];
                }
            }
            cout << "Administrator deleted" << endl;
            delete[] temporaryArray;
        }
    }
    return userNumber;
}

/* Methods for courses (CRUD operations) */

void School::findCourse(string in, int action){ //find courses based on the course code
    int counter = 1;
    int found = 0;
    bool anyFound = false;
    for(int i = 0; i < classNumber; i++){
        found = classes[i]->getCourseCode().find(in);
        if(found != -1){
            anyFound = true;
            cout << counter << ". " << classes[i]->getCourseSubject() << " (Code: " << classes[i]->getCourseCode() << "); Block: " << classes[i]->getCourseBlock() << "; Room #: " << classes[i]->getRoomNumber() << "; Teacher: " << classes[i]->getCourseTeacher() << " (Type \"" << (i+1) << "\")" << endl;
            counter++;
        }
    }
    if(anyFound) {
        int decision = 0;
        cout << "Please select one of the above (or type \"0\" to cancel)" << endl;
        cin >> decision;
        if(decision != 0 && action == 1){ //view
            cout << endl;
            classes[decision-1]->toString(); //directly calls toString() function for course
        } else if (decision != 0 && action == 2){ //delete
            this->deleteCourse(decision);
        } else if (decision != 0 && action == 3) { //add student(s) to course
            this->addStudents(decision);
        } else if (decision != 0 && action == 4) { //remove student from course
            this->removeStudent(decision);
        } else if (decision != 0 && action == 5) { //change teacher of course
            this->changeTeacher(decision);
        } else if (decision != 0 && action == 6) { //change block/room of course
            this->changeCourseTime(decision);
        }
    } else {
        cout << "No entries matched your search." << endl;
        cout  << endl;
    }
}

void School::createCourse(){
    bool done = false;
    bool cancel = false;
    int block = 0, room = 0;
    string subject = "", code = "";
    cout << "Course information:" << endl;
    cout << "Course subject: ";
    cin.ignore();
    getline(cin, subject);
    cout << "Course code: ";
    getline(cin, code);
    cout << endl;

    Teacher * tempTeach;
    while(!done){ //select course time and teacher loop starts
        cout << "Selecting Time: (Type \"0\" in the next 2 fields to cancel)" << endl;
        bool success = true;
        do{ //select time loop starts
            success = true;
            cout << "Room Number: ";
            cin >> room;
            cout << "Course block: ";
            cin >> block;
            if(room == 0 && block == 0){ //in case user wants to cancel the process during this step
                cancel = true;
                done = true;
            } else {
                for(int i = 0; i < classNumber; i++){ //ensures that the seclected room is free duirng the specified time
                    if(classes[i]->getCourseBlock() == block && classes[i]->getRoomNumber() == room){
                        cout << "Room " << room << " is not free during block " << block << "." << endl;
                        success = false;
                    }
                }
            }
        } while(!success); //select time loop ends

        if(!cancel){ //If user wants to cancel, these steps are skipped
            cout << "Room " << room << " is free during block " << block << "." << endl;
            cout << endl;
            done = this->findTeachers(block, 1);
        }
    } //select course time and teacher loop ends

    if(!cancel){ //if user wants to cancel, these steps are skipped
        classNumber++;
        Course ** tempArray = classes;
        classes = new Course*[classNumber];

        int decision = 0;
        cout << "Choose a teacher (Type \"0\" to cancel): ";
        cin >> decision;
        if(decision != 0){ //if user did not cancel the process
            tempTeach = dynamic_cast<Teacher*>(people[decision-1]);
            people[decision-1]->changeAvailability(block);

            Course * tempCourse = new Course(block, subject, code, room, *tempTeach);

            cout << "Here" << endl;

            for(int i = 0; i < classNumber; i++){
                if(i < classNumber - 1){
                    classes[i] = tempArray[i];
                } else{
                    classes[i] = tempCourse;
                    string courseInfo = tempCourse->getCourseSubject() + " (" + tempCourse->getCourseCode() + ")\nRoom: " + to_string(tempCourse->getRoomNumber());
                    tempTeach->addCourse(courseInfo, block);
                }
            }
            cout << "Course created. " << endl;
            //classes[classNumber-1]->toString();
            cout << endl;
        }
        delete [] tempArray;
    }
}

void School::addStudents(int course){
    course--;
}

void School::removeStudent(int course){
    course--;
}

void School::changeTeacher(int course){
    course--;
    cout << "Current teacher: ";
    classes[course]->displayTeacher();
    cout << endl;
    bool found = this->findTeachers(classes[course]->getCourseBlock(), 2);
    if(found) {
        int decision;
        cout << "Choose a teacher (Type \"0\" to cancel): ";
        cin >> decision;
        if (decision != 0) { //if user did not cancel the process
            Teacher *tempTeach = dynamic_cast<Teacher *>(people[decision - 1]);
            people[decision - 1]->changeAvailability(classes[course]->getCourseBlock());
            classes[course]->setCourseTeacher(*tempTeach);
            string courseInfo = classes[course]->getCourseSubject() + " (" + classes[course]->getCourseCode() + ")\nRoom: " + to_string(classes[course]->getRoomNumber());
            tempTeach->addCourse(courseInfo, classes[course]->getCourseBlock());

            cout << endl;
            cout << "Course updated" << endl;
            cout << endl;
            classes[course]->toString();
        }
    }

}

void School::changeCourseTime(int course){
    course--;
    cout << "Current information: " << endl;
    cout << "Block: " << classes[course]->getCourseBlock() << endl;
    cout << "Room Number: " << classes[course]->getRoomNumber() << endl;
    cout << endl;
    cout << "Selecting Time: (Type \"0\" in the next 2 fields to cancel)" << endl;
    bool success = true, done = false;
    int room, block;
    do{ //select time loop starts
        success = true;
        cout << "Room Number: ";
        cin >> room;
        cout << "Course block: ";
        cin >> block;
        if(room == 0 && block == 0){ //in case user wants to cancel the process during this step
            done = true;
            success = false;
        } else {
            for(int i = 0; i < classNumber; i++){ //ensures that the seclected room is free duirng the specified time
                if(classes[i]->getCourseBlock() == block && classes[i]->getRoomNumber() == room){
                    cout << "Room " << room << " is not free during block " << block << "." << endl;
                    success = false;
                }
            }
        }
    } while(!success && !done); //select time loop ends

    if(success){
        cout << "Room " << room << " is free during block " << block << "." << endl;
        classes[course]->setCourseBlock(block);
        classes[course]->setRoomNumber(room);
        cout << endl;
        cout << "Course updated" << endl;
        cout << endl;
    }
}








void School::deleteCourse(int index){
    string confirmation = "";
    cout << "Are you sure? (Type \"y\" or \"n\")" << endl;
    cin.ignore();
    getline(cin, confirmation);
    if(confirmation == "y"){
        index--;
        classNumber--;
        Course ** tempArray = classes;
        classes = new Course*[classNumber];
        for(int i = 0; i < classNumber; i++){
            if(i < index){
                classes[i] = tempArray[i];
            }
            else{
                classes[i] = tempArray[i+1];
            }
        }
        delete [] tempArray;
        cout << "Course deleted" << endl;
    }
}

bool School::findTeachers(int block, int caller){
    string desiredTeachable = "";
    cout << "Selecting teacher:" << endl;
    int counter = 1, d = 0;
    bool anyFound = false, done = false;
    Teacher * tempTeach;

    do{ //select teacher loop starts
        cout << "Enter the desired teachable (only one)" << endl;
        cout << "Acceptable inputs: Math, CompSci, Physics, Chem, Bio, Eng, French, Spanish, Geo, History, Business, Tech, PhysEd, Music, VisualArt, Drama" << endl;
        cin.ignore();
        getline(cin, desiredTeachable);
        for(int i = 0; i < teachers; i++){
            tempTeach = dynamic_cast<Teacher*>(people[i]);
            if(tempTeach->getTeachables().find(desiredTeachable) != -1 && people[i]->checkAvailability(block) == true){
                anyFound = true;
                cout << counter << ". " << tempTeach->getFirstName() << " " << tempTeach->getLastName() << " (Employee ID: " << tempTeach->getEmployeeId() << "); Teachables: " << tempTeach->getTeachables() << " (Type \"" << (i+1) << "\")" <<  endl;
                counter++;
                done = true;
            }
        }
        if(!anyFound){
            cout << "No teachers who have the desired teachable are available during that block." << endl;
            if(caller == 1){ //if the createCourse() method called this method.
                cout << "Do you want to select a new block? (if yes, enter \"0\". If no (search a different teachable), enter \"1\").";
                cin >> d;
                if(d == 0){
                    anyFound = true; //to get out of
                }
                cout << endl;
            }
            if(caller == 2){ //if the changeTeacher() method called this method
                cout << "Do you wish to cancel the process? (if yes, enter \"0\". If no (search a different teachable), enter \"1\").";
                cin >> d;
                if(d == 0){
                    anyFound = true; //to get out of
                }
                cout << endl;
            }
        }
    } while (!anyFound); //select teacher loop ends
    return done;
}















string School::toString(){
    int counter = 0; //this makes sure the elements for schoolStudents[] starts at zero
    for(int i = 0; i < totalPeople; i++){
        people[i] -> toString();
        cout << endl;
    }
    return "";
}
