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
        } else{ //makes students
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
    string encrypt_pass = tempAdmin->getPassword(); //gets encrypted password

    delete tempAdmin;

    string tempName = "";
    for(int i = 0; i < administrators; i++){ //checks all administrators
        if(adminArray[i]->getUsername() == uname && adminArray[i]->getPassword() == encrypt_pass){ //checks if inputted credentials match that of one admin
            tempName = adminArray[i]->getName(); //gets admin name
            userNumber = i+1;
            valid = true;
        }
    }

    if(valid){ //if login is valid
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "You're logged in. Welcome!" << endl;
        cout << endl;
        cout << endl;
        return userNumber;
    } else{
        cout << endl;
        cout << "Credentials are incorrect. Please try again." << endl;
        cout << endl;
        return -1;
    }
}

int School::teacherLogin(string uname, string password){
    bool valid = false;
    int userNumber = 0;
    Teacher * tempTeach = new Teacher(uname, password);
    string encrypt_pass = tempTeach->getPassword(); //gets encrypted password
    delete tempTeach;

    for(int i = 0; i < teachers; i++){ //Looks through all teachers
        Teacher * tempTeach = dynamic_cast<Teacher*>(people[i]); //downcasts people array element to access Teacher methods
        if(tempTeach){ //checks if downcasting worked so program does not crash
            if(tempTeach->getUsername() == uname && tempTeach->getPassword() == encrypt_pass) { //checks if inputted credentials match that of one teacher
                valid = true;
                userNumber = i+1;
            }
        }
    }

    if(valid){ //if login is valid
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "You're logged in. Welcome!" << endl;
        cout << endl;
        cout << endl;
        return userNumber;
    } else{
        cout << endl;
        cout << "Credentials are incorrect. Please try again." << endl;
        cout << endl;
        return -1;
    }
}

/* Methods for CRUD operations for people */

int School::findPeople(string n, int object, int action, int userNumber){ //function searches whole people array and only gives results that have the user's input within
    int searchType = 0;
    string fName = "", lName = "";
    int found = n.find(" ");
    if(found != -1 && object != 3){ //in case the user put in both the first and last name
        searchType = 1;
        fName = n.substr(0, found);
        lName = n.substr(found+1);
    }

    int counter = 1;
    bool anyFound = false;
    if(object == 1){ //searching for teachers
        for(int i = 0; i < teachers; i++){ //goes through all teachers and prints out teachers that match search results
            if(searchType == 0){ //if either first or last name was entered
                int found1 = people[i]->getFirstName().find(n);
                int found2 = people[i]->getLastName().find(n);
                if(found1 != -1 || found2 != -1){ //if match is found
                    cout << "(Type \""  << (i+1) << "\") | " << counter << ". " << people[i]->getFirstName() << " " << people[i]->getLastName() << endl;
                    anyFound = true;
                    counter++;
                }
            } else { //if both first and last name was entered
                int found1 = people[i]->getFirstName().find(fName);
                int found2 = people[i]->getLastName().find(lName);
                if(found1 != -1 || found2 != -1){ //if match is found
                    cout << "(Type \""  << (i+1) << "\") | " << counter << ". " << people[i]->getFirstName() << " " << people[i]->getLastName() << endl;
                    anyFound = true;
                    counter++;
                }
            }
        }
    } else if (object == 2){ //searching for students
        for(int i = teachers; i < totalPeople; i++){ //goes through all students and prints out teachers that match search results
            if(searchType == 0){ //if either first or last name was entered
                int found1 = people[i]->getFirstName().find(n);
                int found2 = people[i]->getLastName().find(n);
                if(found1 != -1 || found2 != -1){ //if match is found
                    cout << "(Type \""  << (i-teachers+1) << "\") | " << counter << ". " << people[i]->getFirstName() << " " << people[i]->getLastName() <<  endl;
                    anyFound = true;
                    counter++;
                }
            } else { //if both first and last name was entered
                int found1 = people[i]->getFirstName().find(fName);
                int found2 = people[i]->getLastName().find(lName);
                if(found1 != -1 || found2 != -1){ //if match is found
                    cout << "(Type \""  << (i-teachers+1) << "\") | " << counter << ". " << people[i]->getFirstName() << " " << people[i]->getLastName() <<  endl;
                    anyFound = true;
                    counter++;
                }
            }
        }
    } else { //searching for administrators
        for(int i = 0; i < administrators; i++){ //goes through all administrators and prints out teachers that match search results
            int found = adminArray[i]->getName().find(n);
            if(found != -1){ //if match is found
                cout << "(Type \""  << (i+1) << "\") | " << counter << ". " << adminArray[i]->getName() << endl;
                anyFound = true;
                counter++;
            }
        }
    }

    if(anyFound) { //if the search yielded results
        int decision = 0;
        cout << "Please select one of the above (Type \"0\" to cancel): ";
        cin >> decision; //user chooses a person

        //based on desired action (decided in main.cpp), a different CRUD method is called
        if(decision != 0 && action == 1){ //view
            this->displayPerson(decision, object);
        } else if (decision != 0 && action == 2){ //edit
            this->editPerson(decision, object);
        } else if (decision != 0 && action == 3) { //delete
            userNumber = this->deletePerson(decision, object, userNumber);
        } else if(decision != 0 && action == 4) { //mark student late
            Student * tempStudent = dynamic_cast<Student*>(people[decision-1+teachers]);
            if(tempStudent){ //checks if downcasting worked so program does not crash
                tempStudent->addLate();
            }
        } else if(decision != 0 && action == 5) { //mark student absent
            Student * tempStudent = dynamic_cast<Student*>(people[decision-1+teachers]);
            if(tempStudent){ //checks if downcasting worked so program does not crash
                tempStudent->addAbsence();
            }
        }
    } else { //if no results were found
        cout << endl;
        cout << "No entries matched your search." << endl;
        cout  << endl;
    }
    return userNumber;
}

void School::displayPerson(int personNumber, int object) { //method displays the person: "Read" in CRUD
    if(object == 1){ //teacher
        personNumber--; //changes value so it can be used to navigate people array
        people[personNumber]->toString();
    } else if (object == 2){ //student
        personNumber = teachers + personNumber - 1; //changes value so it can be used to navigate people array
        people[personNumber]->toString();
    } else{ //administrator
        personNumber--; //changes value so it can be used to navigate adminArray array
        adminArray[personNumber]->toString();
    }
}

void School::editPerson(int personNumber, int object) { //method edits person: "Update" in CRUD
    if(object == 1 || object == 2){ //if action is being done on a teacher or a student
        if(object == 1){ //teacher
            personNumber--; //changes value so it can be used to navigate people array
        } else{ //student
            personNumber = teachers + personNumber - 1; //changes value so it can be used to navigate people array
        }

        //displays current information on person
        cout << "Current Information:" << endl;
        people[personNumber]->toString();

        //gets new values from the user
        string firstName = "", lastName = "", address = "";
        cout << "Set new values (Type \"0\" if you don't want to change a field. Enter \"0\" into all fields to cancel edit process): " << endl;
        cout << "First name: ";
        cin >> firstName;
        cout << "Last name: ";
        cin >> lastName;
        cout << "Address: ";
        cin.ignore();
        getline(cin, address);

        if(object == 1){ //Teacher specific actions done here
            string teachables = "", employeeId = "", username = "", password = "";
            cout << "Teachables (Acceptable inputs: Math, CompSci, Physics, Chem, Bio, Eng, French, Spanish, Geo, History, Business, Tech, PhysEd, Music, VisualArt, Drama): ";
            getline(cin, teachables);
            cout << "Employee ID (\"C\" followed by 5 digits): ";
            getline(cin, employeeId);
            cout << "Username: ";
            getline(cin, username);
            cout << "Password: ";
            getline(cin, password);

            //sets values in methods that are unique to Teacher
            Teacher * temporary = dynamic_cast <Teacher*>(people[personNumber]); //downcasting used on Person pointer to access Teacher methods
            if(temporary){ //checks if downcasting worked so program does not crash
                // checks if values are 0 since it is used in this program to signify "no change"
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
        } else if (object == 2){ //Student specific actions done here
            string grade = "", studentId = "";
            cout << "Grade (Number between 1 and 12 inclusive): ";
            getline(cin, grade);
            cout << "Student ID (\"S\" followed by 9 digits): ";
            getline(cin, studentId);

            //sets values in methods that are unique to Student
            Student * temporary = dynamic_cast <Student*>(people[personNumber]); //downcasting used on Person pointer to access Student methods
            if(temporary){ //checks if downcasting worked so program does not crash
                // checks if values are 0 since it is used in this program to signify "no change"
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

        //displays updated person
        cout << endl;
        cout << "Updated Information:" << endl;
        people[personNumber]->toString();
    } else { //if action is being done on an administrator
        personNumber--; //changes value so it can be used to navigate people array

        //displays current information
        cout << "Current Information:" << endl;
        adminArray[personNumber]->toString();

        //gets new values from the user
        string name = "", username = "", password = "";
        cout << "Set new values (Type \"0\" if you don't want to change a field. Enter \"0\" into all fields to cancel edit process): " << endl;
        cout << "Name (first and last): ";
        cin.ignore();
        getline(cin, name);
        cout << "Username: ";
        getline(cin, username);
        cout << "Password: ";
        getline(cin, password);

        //checks if values are 0 since it is used in this program to signify "no change"
        if(name != "0"){
            adminArray[personNumber]->setName(name);
        }
        if(username != "0"){
            adminArray[personNumber]->setUsername(username);
        }
        if(password != "0"){
            adminArray[personNumber]->setPassword(password);
        }

        //displays updated administrator
        cout << endl;
        cout << "Updated Information:" << endl;
        adminArray[personNumber]->toString();
    }
}

void School::createPerson(int object) { //method creates person: "Create" in CRUD
    cout << "Set new values (Type \"0\" if you don't want to set a field. Enter \"0\" into all fields to cancel creation process): " << endl;
    if(object == 1 || object == 2){ //if action is being done on a student or a teacher
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

        if (object == 1) { //sets values in methods that are unique to Teacher
            string teachables = "", employeeId = "", username = "", password = "";
            cout << "Teachables (Acceptable inputs: Math, CompSci, Physics, Chem, Bio, Eng, French, Spanish, Geo, History, Business, Tech, PhysEd, Music, VisualArt, Drama): ";
            cout << "" << endl;
            getline(cin, teachables);
            cout << "Employee ID (\"C\" followed by 5 digits): ";
            cin >> employeeId;
            cout << "Username: ";
            cin.ignore();
            getline(cin, username);
            cout << "Password: ";
            getline(cin, password);
            if (firstName == "0" && lastName == "0" && address == "0" && teachables == "0" && employeeId == "0" && username == "0" && password == "0") {//checks if user wishes to cancel the process
                totalPeople--;
                cout << endl;
                cout << "Process canceled." << endl;
                cout << endl;
            } else {
                teachers++;
                Teacher * tempPerson = new Teacher(firstName, lastName, address, teachables, employeeId, username, password); //creates new Teacher object with inputted information
                people = new Person *[totalPeople]; //re-declares the people array to include the new teacher
                for (int i = 0; i < totalPeople; i++) { //re-initializes the people array to include new teacher
                    if (i < teachers - 1) {
                        people[i] = temporaryArray[i];
                    } else if (i == teachers - 1) {
                        people[i] = tempPerson;
                    } else {
                        people[i] = temporaryArray[i - 1];
                    }
                }
                //displays new teacher
                cout << endl;
                cout << "New Teacher: " << endl;
                people[teachers - 1]->toString();
            }
        } else if (object == 2) { //sets values in methods that are unique to Student
            string grade = "", studentId = "";
            cout << "Grade (Number between 1 and 12 inclusive): ";
            cin >> grade;
            cout << "Student ID (\"S\" followed by 9 digits): ";
            cin >> studentId;
            if (firstName == "0" && lastName == "0" && address == "0" && grade == "0" && studentId == "0") {//checks if user wishes to cancel the process
                totalPeople--;
                cout << endl;
                cout << "Process canceled." << endl;
                cout << endl;
            } else {
                students++;
                Student * tempPerson = new Student(firstName, lastName, address, grade, studentId); //creates new Student object with inputted information
                people = new Person *[totalPeople]; //re-declares the people array to include the new student
                for (int i = 0; i < totalPeople; i++) { //re-initializes the people array to include new student
                    if (i < teachers) {
                        people[i] = temporaryArray[i];
                    } else if (i >= teachers && i < teachers + students - 1) {
                        people[i] = temporaryArray[i];
                    } else {
                        people[i] = tempPerson;
                    }
                }
                //displays new student
                cout << endl;
                cout << "New Student:" << endl;
                people[totalPeople - 1]->toString();
            }
        }
        delete[] temporaryArray;
    } else { //if action is being done on an administrator
        cin.ignore();

        //gets values
        string name = "", username = "", password = "";
        cout << "Name (first and last): ";
        getline(cin, name);
        cout << "Username: ";
        getline(cin, username);
        cout << "Password: ";
        getline(cin, password);
        cout << "Inputs: " << name << " " << username << " " << password << endl;

        if(name == "0" && username == "0" && password == "0"){ //checks if user canceled the process
            cout << "Process canceled." << endl;
            cout << endl;
        } else{
            administrators++;
            Admin * newAdmin = new Admin(name, username, password);
            //sets new and arrays
            Admin ** tempAdminArray = adminArray;
            adminArray = new Admin * [administrators]; //re-declares the adminArray array
            for(int i = 0; i < administrators; i++){ //re-initializes array to include new admin
                if(i < administrators-1){
                    adminArray[i] = tempAdminArray[i];
                }
                else{
                    adminArray[i] = newAdmin;
                }
            }
            //displays new admin
            cout << endl;
            cout << "New Administrator:" << endl;
            adminArray[administrators - 1]->toString();
            delete [] tempAdminArray;
        }
    }
}

int School::deletePerson(int personNumber, int object, int userNumber) { //method deletes person: "Delete" in CRUD
    string confirmation = "";
    cout << "Are you sure (Type \"y\" or \"n\"): ";
    cin.ignore();
    getline(cin, confirmation); //confirms that user actually wants to delete person
    if(confirmation == "y"){ //if user confirms
        if(personNumber < userNumber){
            //if the user being deleted comes before the current user in the array, the current user's array is shifted so the functions still work
            userNumber--;
        }
        if(object == 1 || object == 2){ //if action is conducted on teacher or student
            totalPeople--;
            Person ** temporaryArray = people; //creates a temporary array to store the previous "people" array

            if(object == 1){ //if teacher
                personNumber--; //increments the value down by one so it can be used to navigate the "people" array
                string teacherFirstName = "", teacherLastName = "";
                int found1 = 0, found2 = 0;
                Teacher * newTeach = new Teacher();
                for(int i = 0; i < classNumber; i++) { //goes through all courses and finds ones where deleted teacher is present
                    teacherFirstName = classes[i]->getInstructorFirstName();
                    teacherLastName = classes[i]->getInstructorLastName();
                    found1 = teacherFirstName.find(people[personNumber]->getFirstName());
                    found2 = teacherLastName.find(people[personNumber]->getLastName());
                    if(found1 != -1 && found2 != -1){ //sets teacher to default if teacher is found
                        classes[i]->setCourseTeacher(*newTeach);
                    }
                }
                teachers--;
                people = new Person *[totalPeople]; //re-declares people array
                for(int i = 0; i < totalPeople; i++){ //re-initializes people array to exclude deleted teacher
                    if(i < personNumber){
                        people[i] = temporaryArray[i];
                    } else {
                        people[i] = temporaryArray[i+1];
                    }
                }
                cout << endl;
                cout << "Teacher deleted." << endl;
                cout << endl;
            }
            else if (object == 2){ //if student
                personNumber = teachers + personNumber - 1;
                int indexNum = 0, blockNum = 0;
                for(int i = 0; i < classNumber; i++){
                    //checks if student is in the class. If student is present, method also removes student
                    indexNum = classes[i]->isStudentInCourse(people[personNumber]->getFirstName(), people[personNumber]->getLastName());
                    if(indexNum != -1){
                        blockNum = classes[i]->getCourseBlock();
                        classes[i]->removeStudent(indexNum, blockNum);
                    }
                }
                students--;
                people = new Person *[totalPeople]; //re-declares people array
                for(int i = 0; i < totalPeople; i++){ //re-initializes people array to exclude deleted student
                    if(i < personNumber){
                        people[i] = temporaryArray[i];
                    } else{
                        people[i] = temporaryArray[i+1];
                    }
                }
                cout << endl;
                cout << "Student deleted." << endl;
                cout << endl;
            }
            delete[] temporaryArray;
        } else { //if action is being done on admin
            Admin ** temporaryArray = adminArray;
            personNumber--;
            administrators--;
            adminArray = new Admin * [administrators]; //re-declares AdminArray array
            for(int i = 0; i < administrators; i++){ //re-initializes people array to exclude deleted admin
                if(i < personNumber){
                    adminArray[i] = temporaryArray[i];
                } else{
                    adminArray[i] = temporaryArray[i+1];
                }
            }
            cout << endl;
            cout << "Administrator deleted." << endl;
            cout << endl;
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
    for(int i = 0; i < classNumber; i++){ //displays all courses in school that match input
        found = classes[i]->getCourseCode().find(in);
        if(found != -1){ //if course code matches input
            anyFound = true;
            cout << "(Type \"" << (i+1) << "\") | " << counter << ". " << classes[i]->getCourseSubject() << " (Code: " << classes[i]->getCourseCode()
                << "); Block: " << classes[i]->getCourseBlock() << "; Room #: " << classes[i]->getRoomNumber() << "; Teacher: "
                << classes[i]->getCourseTeacher() << endl;
            counter++;
        }
    }

    if(anyFound) { //if any results found
        int decision = 0;
        cout << "Please select one of the above (Type \"0\" to cancel): ";
        cin >> decision; //user chooses a course to act on
        if(decision != 0 && action == 1){ //view
            cout << endl;
            classes[decision-1]->toString(); //directly calls toString() function for course
        } else if (decision != 0 && action == 2){ //delete
            this->deleteCourse(decision);
        } else if (decision != 0 && action == 3) { //add a student to course
            this->addStudents(decision);
        } else if (decision != 0 && action == 4) { //remove student from course
            this->removeStudent(decision);
        } else if (decision != 0 && action == 5) { //change teacher of course
            this->changeTeacher(decision);
        }
    } else { //if no results found
        cout << endl;
        cout << "No entries matched your search." << endl;
        cout  << endl;
    }
}

void School::createCourse(){ //method creates course: "Create" in CRUD
    bool done = false;
    bool cancel = false;
    int block = 0, room = 0;
    string subject = "", code = "";
    //gets values from user
    cout << "Course information:" << endl;
    cout << "Course subject: ";
    cin.ignore();
    getline(cin, subject);
    cout << "Course code: ";
    getline(cin, code);
    cout << endl;

    Teacher * tempTeach;
    while(!done){ //select course time and teacher loop starts
        cout << "Selecting Time (Enter \"0\" in the next 2 fields to cancel): " << endl;
        bool success = true;
        do{ //select time loop starts
            success = true;
            cout << "Room Number: ";
            cin >> room;
            cout << "Course block (Number between 1 and 8 inclusive): ";
            cin >> block;
            if(room == 0 && block == 0){ //in case user wants to cancel the process during this step
                cancel = true;
                done = true;
            } else {
                for(int i = 0; i < classNumber; i++){ //ensures that the seclected room is free duirng the specified time
                    if(classes[i]->getCourseBlock() == block && classes[i]->getRoomNumber() == room){ //if free
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
        int decision = 0;
        cout << "Choose a teacher (Type \"0\" to cancel): ";
        cin >> decision;
        if(decision != 0){ //if user did not cancel the process
            classNumber++;
            Course ** tempArray = classes;
            classes = new Course*[classNumber]; //re-declares classes array

            tempTeach = dynamic_cast<Teacher*>(people[decision-1]); //downcasts Person pointer to teacher
            if(tempTeach){ //checks if downcasting was successful so program does not crash
                people[decision-1]->changeAvailability(block); //checks if teacher is available during block

                Course * tempCourse = new Course(block, subject, code, room, *tempTeach); //creates new course

                for(int i = 0; i < classNumber; i++){ //re-initializes classes array to include new course
                    if(i < classNumber - 1){
                        classes[i] = tempArray[i];
                    } else{
                        classes[i] = tempCourse;
                        //adds course to teacher's schedule
                        string courseInfo = tempCourse->getCourseSubject() + " (" + tempCourse->getCourseCode() + ")\nRoom: " + to_string(tempCourse->getRoomNumber());
                        tempTeach->addCourse(courseInfo, block);
                    }
                }
                cout << endl;
                cout << "Course created. " << endl;
                cout << endl;
            }
            delete [] tempArray;
        }
    }
}

/* Following methods edit courses: "Update" in CRUD */

void School::addStudents(int course){ //adds students to course
    course--;
    bool found = this->findStudents(classes[course]->getCourseBlock()); //calls method to search for student to add
    if(found){ //if students are found
        int personNum = 0;
        cout << "Select a student (Type \"0\" to cancel): ";
        cin >> personNum; //user selects a student
        Student * tempStudent = dynamic_cast<Student*>(people[personNum - 1 + teachers]);
        if(tempStudent){ //checks if downcasting worked so program does not crash
            //updates student information to reflect schedule change
            classes[course]->addStudent(*tempStudent);
            people[personNum - 1 + teachers]->changeAvailability(classes[course]->getCourseBlock());
            string courseInfo = classes[course]->getCourseSubject() + " (" + classes[course]->getCourseCode() + ")\nRoom: " + to_string(classes[course]->getRoomNumber());
            tempStudent->addCourse(courseInfo, classes[course]->getCourseBlock());
            cout << endl;
            cout << "Student added." << endl;
            cout << endl;
        }
    }
}

void School::removeStudent(int course){ //removes students from course
    course--;
    classes[course]->displayStudents(); //dispalys students in clas
    int stu = 0;
    cout << "Select a student (Type \"0\" to cancel): ";
    cin >> stu; //user chooses student to remove
    if(stu > 0) {
        stu--;
        int block = classes[course]->getCourseBlock();
        classes[course]->removeStudent(stu, block); //calls method to remove student
        cout << endl;
        cout << "Student removed." << endl;
        cout << endl;
    }
}

void School::changeTeacher(int course){ //changes teacher of course
    course--;
    //displays current teacher
    cout << "Current teacher: ";
    classes[course]->getCourseTeacher();
    cout << endl;
    bool found = this->findTeachers(classes[course]->getCourseBlock(), 2); //calls method to search for new teacher
    if(found) { //if teacher is found
        classes[course]->removeInstructorCourse();
        int decision;
        cout << "Choose a teacher (Type \"0\" to cancel): ";
        cin >> decision; //user chooses teacher
        if (decision != 0) { //if user did not cancel the process
            //program updates teachers' schedule
            Teacher * tempTeach = dynamic_cast<Teacher *>(people[decision - 1]);
            if(tempTeach){ //checks if downcasting worked so program does not crash
                people[decision - 1]->changeAvailability(classes[course]->getCourseBlock());
                classes[course]->setCourseTeacher(*tempTeach);
                string courseInfo = classes[course]->getCourseSubject() + " (" + classes[course]->getCourseCode() + ")\nRoom: " + to_string(classes[course]->getRoomNumber());
                tempTeach->addCourse(courseInfo, classes[course]->getCourseBlock());

                cout << endl;
                cout << "Course updated." << endl;
                cout << endl;
                classes[course]->toString();
            }
        }
    }
}

void School::deleteCourse(int index){ //method deletes course: "Delete" in CRUD
    string confirmation = "";
    cout << "Are you sure (Type \"y\" or \"n\"): "; //gets confirmation
    cin.ignore();
    getline(cin, confirmation);
    if(confirmation == "y"){ //if confirmed
        index--;
        classes[index]->removeInstructorCourse(); //removes course from Teacher's schedule
        classes[index]->removeAllStudents(); //removes course from all Students' schedules
        classNumber--;
        Course ** tempArray = classes;
        classes = new Course*[classNumber]; //re-declares classes array
        for(int i = 0; i < classNumber; i++){ //re-initializes classes array without deleted course
            if(i < index){
                classes[i] = tempArray[i];
            }
            else{
                classes[i] = tempArray[i+1];
            }
        }
        delete [] tempArray;
        cout << endl;
        cout << "Course deleted." << endl;
        cout << endl;
    }
}

/* Following find people methods are different from the School::findPeople method since it also takes into account the person's schedule */

bool School::findTeachers(int block, int caller){ //finds teacher
    string desiredTeachable = "";
    cout << "Selecting teacher:" << endl;
    int counter = 1, d = 0;
    bool anyFound = false, done = false;
    Teacher * tempTeach;

    do{ //select teacher loop starts
        cout << "Enter the desired teachable (only one):" << endl;
        cout << "Acceptable inputs: Math, CompSci, Physics, Chem, Bio, Eng, French, Spanish, Geo, History, Business, Tech, PhysEd, Music, VisualArt, Drama" << endl;
        cin.ignore();
        getline(cin, desiredTeachable);
        for(int i = 0; i < teachers; i++){ //lists teachers that match search results
            tempTeach = dynamic_cast<Teacher*>(people[i]);
            if(tempTeach){ //checks if downcasting was successful so program does not crash
                if(tempTeach->getTeachables().find(desiredTeachable) != -1 && people[i]->checkAvailability(block) == true){ //if found and teacher is free in  block
                    anyFound = true;
                    cout << "(Type \"" << (i+1) << "\") | " << counter << ". " << tempTeach->getFirstName() << " " << tempTeach->getLastName() << " (Employee ID: " << tempTeach->getEmployeeId()
                    << "); Teachables: " << tempTeach->getTeachables() << endl;
                    counter++;
                    done = true;
                }
            }
        }
        if(!anyFound){ //if none found
            cout << endl;
            cout << "No teachers who have the desired teachable are available during that block." << endl;
            if(caller == 1){ //if the createCourse() method called this method.
                cout << "Do you want to select a new block? (if yes, type \"0\". If no (search a different teachable), type \"1\"): ";
                cin >> d;
                if(d == 0){
                    anyFound = true; //to get out of this loop
                }
            }
            if(caller == 2){ //if the changeTeacher() method called this method
                cout << "Do you wish to cancel the process? (if yes, type \"0\". If no (search a different teachable), type \"1\"): ";
                cin >> d;
                if(d == 0){
                    anyFound = true; //to get out of this loop
                }
            }
        }
        cout << endl;
    } while (!anyFound); //select teacher loop ends
    return done;
}

bool School::findStudents(int block){ //finds student
    string name = "";
    bool anyFound = false, done  = false;
    int searchType = 0;
    string fName = "", lName = "";
    int counter = 1;
    do { //find student loop starts
        cout << "Search for a student (Enter their first or last name. Type \"0\" to cancel): ";
        cin.ignore();
        getline(cin, name);
        if (name != "0") { //if not canceled
            int found = name.find(" ");

            if (found != -1) { //in case the user put in both the first and last name
                searchType = 1;
                fName = name.substr(0, found);
                lName = name.substr(found + 1);
            }

            for (int i = teachers; i < totalPeople; i++) { //print students that match search input
                if (searchType == 0) { //if either first or last name entered
                    int found1 = people[i]->getFirstName().find(name);
                    int found2 = people[i]->getLastName().find(name);
                    if ((found1 != -1 || found2 != -1) && people[i]->checkAvailability(block)) { //if found and student free in block
                        cout << "(Type \"" << (i - teachers + 1) << "\") | " << counter << ". " << people[i]->getFirstName() << " " << people[i]->getLastName() << endl;
                        anyFound = true;
                        done = true;
                        counter++;
                    }
                } else { //if both first and last name entered
                    int found1 = people[i]->getFirstName().find(fName);
                    int found2 = people[i]->getLastName().find(lName);
                    if ((found1 != -1 || found2 != -1) && people[i]->checkAvailability(block)) { //if found and student free in block
                        cout << "(Type \"" << (i - teachers + 1) << "\") | " << counter << ". " << people[i]->getFirstName() << " " << people[i]->getLastName() << endl;
                        anyFound = true;
                        done = true;
                        counter++;
                    }
                }
            }

            if(!anyFound){ //if none found
                cout << endl;
                cout << "No students who are free during this block match your search." << endl;
            }
            cout << endl;
        } else { //if user canceled process
            anyFound = true;
        }
    } while (!anyFound); //find student loop ends
    return done;
}

void School::displayTeacherCourses(int userNumber) { //Displays courses for a specific teacher (when teacher session is running)
    userNumber--; //changes value so array can be navigated
    Teacher * tempTeach = dynamic_cast<Teacher*>(people[userNumber]);
    if(tempTeach) { //checks if downcasting was successful to prevent program from crashing
        cout << "Your courses:" << endl;
        string fname = people[userNumber]->getFirstName();
        string lname = people[userNumber]->getLastName();
        string instructorId = tempTeach->getEmployeeId();
        for(int i = 0; i < classNumber; i++){ //program checks all courses that have teacher as instructor
            //checks three attributes for accurate results
            if(classes[i]->getInstructorFirstName() == fname && classes[i]->getInstructorLastName() == lname && classes[i]->getInstructorId() == instructorId){
                cout << "---------------------------------------------------------------------------------------------" << endl;
                cout << "(Type " << (i+1) << ")" << endl;
                cout << "Block " << classes[i]->getCourseBlock() << endl;
                cout << classes[i]->getCourseSubject() + " (" + classes[i]->getCourseCode() + ")\nRoom: " + to_string(classes[i]->getRoomNumber()) << endl;
            }
        }
        int decision = 0;
        cout << endl;
        cout << "Choose a course to view: ";
        cin >> decision; //user chooses a course to view

        //displays course
        cout << endl;
        cout << "Your course:" << endl;
        classes[decision-1]->toString();
    }
}

string School::toString(){
    int counter = 0; //this makes sure the elements for schoolStudents[] starts at zero
    for(int i = teachers; i < totalPeople; i++){
        cout << people[i]->getFirstName() << " " << people[i]->getLastName() << endl;
        cout << endl;
    }
    return "";
}
