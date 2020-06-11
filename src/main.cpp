#include "Classes.h"

//declares function below main()
void adminSession(School&, int);
void teacherSession(School&, int);

int main() {

    School sc(10, 5, 1, 3); //initially creates a school with ten teachers, five students, one administrator, and three courses

    //initializing variables
    bool cancel = false, signedIn = false, programKill = false;
    string u_name = "", pass = "";
    int in = 0, userNumber = 0;

    while(!programKill) { //master program loop starts
        userNumber = -1;

        while (!signedIn && !programKill) { //signing in loop starts
            cout << "Sign in: Are you an administrator (1) or a teacher (2): (Yype \"0\" to kill the program)" << endl;
            cin >> in;
            cout << endl;

            if(in == 0){ //checks if user wanted to cancel
                programKill = true;
            }

            if (in == 1 || in == 2) { //if user did not want to cancel
                cin.ignore();

                while (userNumber < 0 && !cancel) { //credential input loop starts
                    u_name = "", pass = "";
                    cout << "Enter your credentials. (Type \"0\" in both fields to cancel):" << endl;
                    cout << "Username: ";
                    getline(cin, u_name);
                    cout << "Password: ";
                    getline(cin, pass);
                    if (u_name == "0" && pass == "0") { //if the user chooses to cancel the sign in process, they will return back to the top of the signing in loop
                        cancel = true;
                    } else {
                        //statements check the credentials depending on the chosen user type
                        if(in == 1){ //if user is an administrator
                            userNumber = sc.adminLogin(u_name, pass); //calls function to see if credentials are correct
                            if (userNumber != -1) { //if login is successful
                                signedIn = true; //variable changed so the signing in loop ends
                            }
                        }
                        else { //if user is a teacher
                            userNumber = sc.teacherLogin(u_name, pass); //calls function to see if credentials are correct
                            if (userNumber != -1) { //if login is successful
                                signedIn = true;
                            }
                        }
                    }
                } //credential input loop ends
            }
            cancel = false;
        } //signing in loop ends

        if(in == 1){ //if user has logged in an an administrator
            adminSession(sc, userNumber); //calls function below to show aministrator actions
        }
        else if (in == 2){ //if user has logged in as a teacher
            teacherSession(sc, userNumber); //calls function below to show teacher actions
        }

        //resets variables for signin process
        in = 0;
        u_name = "", pass = "";
        signedIn = false;
    } //master program loop ends


    cout << "Thank you for using this database." << endl;
    return 0;
}

void adminSession(School &sc, int userNumber){

    //initializing variables
    bool done = false; //this variable used when the user wants to stop updating the classes
    string confirmation = "", input = "";
    int object, choice, action;

    /*
     * (for people [administrators, teachers, and students])
     * object = 1 means teacher. object = 2 means student
     * action = 1 means view. action = 2 means edit. action = 3 means delete. action = 4 means mark student late.
     * action  = 5 means mark student absent.
     *
     * (for courses)
     * action = 1 means view. action = 2 means delete.
     * action = 3 means add student(s) to course. action = 4 means remove student from course.
     * action = 5 means change teacher of course.
     */

    while(!done) { //admin session loop starts
        //Following output displays the actions that the user can do
        cout << endl;
        cout << "Select an action:" << endl;
        cout << "Actions for people:" << endl;
        cout << "1. View a teacher's information (Type \"1\")" << endl;
        cout << "2. View a student's information (Type \"2\")" << endl;
        cout << "3. Edit a teacher's information (Type \"3\")" << endl;
        cout << "4. Edit a student's information (Type \"4\")" << endl;
        cout << "5. Create a teacher (Type \"5\")" << endl;
        cout << "6. Create a student (Type \"6\")" << endl;
        cout << "7. Delete a teacher (Type \"7\")" << endl;
        cout << "8. Delete a student (Type \"8\")" << endl;
        cout << "9. Create an administrator (Type \"9\")" << endl;
        cout << "10. Delete an administrator (Type \"10\")" << endl;
        cout << "11. Mark a student late (Type \"11\")" << endl;
        cout << "12. Mark a student absent (Type \"12\")" << endl;
        cout << "Actions for your account: " << endl;
        cout << "13. View your account information (Type \"13\")" << endl;
        cout << "14. Edit your account information (Type \"14\")" << endl;
        cout << "Actions for courses:" << endl;
        cout << "15. View a course's information (Type \"15\")" << endl;
        cout << "16. Edit a course's information (Type \"16\")" << endl;
        cout << "17. Create a course (Type \"17\")" << endl;
        cout << "18. Delete a course (Type \"18\")" << endl;
        cout << endl;
        cout << "Log out (Type \"100\")" << endl;
        cin >> choice; //user selects an option
        cout << endl;
        cout << endl;

        input = "";

        if (choice == 1) { //view teacher's information
            cout << "Which teacher would you like to view (search for teacher by entering their name): ";
            cin.ignore();
            getline(cin, input); //gets search input that will be used to find desired person
            object = 1;
            action = 1;
            userNumber = sc.findPeople(input, object, action, userNumber); //method called to find desired person
        } else if (choice == 2) { //view student's information
            cout << "Which student would you like to view (search for student by entering their name): ";
            cin.ignore();
            getline(cin, input);
            object = 2;
            action = 1;
            userNumber = sc.findPeople(input, object, action, userNumber); //method called to find desired person
        } else if (choice == 3) { //edit teacher's information
            cout << "Which teacher would you like to edit (search for teacher by entering their name): ";
            cin.ignore();
            getline(cin, input); //gets search input that will be used to find desired person
            object = 1;
            action = 2;
            userNumber = sc.findPeople(input, object, action, userNumber); //method called to find desired person
        } else if (choice == 4) { //edit student's information
            cout << "Which student would you like to edit (search for student by entering their name): ";
            cin.ignore();
            getline(cin, input); //gets search input that will be used to find desired person
            object = 2;
            action = 2;
            userNumber = sc.findPeople(input, object, action, userNumber); //method called to find desired person
        } else if (choice == 5) { //create a teacher
            cout << "Creating a teacher:" << endl;
            object = 1;
            sc.createPerson(object); //calls method to create person
        } else if (choice == 6) { //create a student
            cout << "Creating a student:" << endl;
            object = 2;
            sc.createPerson(object); //calls method to create person
        } else if (choice == 7) { //delete a teacher
            cout << "Which teacher would you like to delete (search for teacher by entering their name): ";
            cin.ignore();
            getline(cin, input); //gets search input that will be used to find desired person
            object = 1;
            action = 3;
            userNumber = sc.findPeople(input, object, action, userNumber); //method called to find desired person
        } else if (choice == 8) { //delete a student
            cout << "Which student would you like to delete (search for student by entering their name): ";
            cin.ignore();
            getline(cin, input); //gets search input that will be used to find desired person
            object = 2;
            action = 3;
            userNumber = sc.findPeople(input, object, action, userNumber); //method called to find desired person
        } else if(choice == 9){ //create an administrator
            cout << "Creating an administrator:" << endl;
            object = 3;
            sc.createPerson(object); //calls method to create person
        } else if(choice == 10){ //delete administrator
            cout << "Which administrator would you like to edit (search for teacher by entering their name): ";
            cin.ignore();
            getline(cin, input); //gets search input that will be used to find desired person
            object = 3;
            action = 3;
            sc.findPeople(input, object, action, userNumber); //method called to find desired person
        } else if(choice == 11){ //mark student late
            cout << "Which student would you like to mark late (search for student by entering their name): ";
            cin.ignore();
            getline(cin, input); //gets search input that will be used to find desired person
            object = 2;
            action = 4;
            userNumber = sc.findPeople(input, object, action, userNumber); //method called to find desired person
        } else if(choice == 12){ //mark student absent
            cout << "Which student would you like to mark absent (search for student by entering their name): ";
            cin.ignore();
            getline(cin, input); //gets search input that will be used to find desired person
            object = 2;
            action = 5;
            userNumber = sc.findPeople(input, object, action, userNumber); //method called to find desired person
        } else if(choice == 13){ //view current user account
            object = 3;
            sc.displayPerson(userNumber, object); //calls method to display user account
        } else if (choice == 14){ //edit current user account
            object = 3;
            sc.editPerson(userNumber, object); //calls method to edit user account
        } else if(choice == 15){ //view course
            cout << "Which course would you like to view (search for course by entering course code): ";
            cin.ignore();
            getline(cin, input); //gets search input that will be used to find desired course
            action = 1;
            sc.findCourse(input, action); //calls method to find desired course
        } else if(choice == 16){ //edit course
            choice = 0;
            cout << "Would you like to:\n1. Add a student to a course (Type \"1\") \n2. Remove a student from a course (Type \"2\") \n3. Change the teacher of a course (Type \"3\")" << endl;
            cin >> choice;
            cout << "Which course would you like to edit (search for course by entering course code): ";
            cin.ignore(); //gets search input that will be used to find desired course
            getline(cin, input);
            if(choice == 1){ //add a student to course
                action = 3;
            } else if(choice == 2){ //remove a student
                action = 4;
            } else if(choice == 3){ //change the teacher
                action = 5;
            }
            sc.findCourse(input, action); //calls method to find desired course
        } else if(choice == 17){ //create course
            cout << "Creating a course:" << endl;
            sc.createCourse(); //calls method to create course
        } else if(choice == 18){ //delete course
            cout << "Which course would you like to delete (search for course by entering course code): ";
            cin.ignore();
            getline(cin, input); //gets search input that will be used to find desired course
            action = 2;
            sc.findCourse(input, action); //calls method to find desired course
        } else { //log out
            done = true;
        }
    } //admin session loop ends
}

void teacherSession(School &sc, int userNumber){
    bool done = false; //this variable used when the user wants to stop updating the classes
    string confirmation = "", input = "";
    int object, choice, action;

    while(!done){ //teacher session loop starts
        cout << endl;
        cout << "Select an action:" << endl;
        cout << "Actions for students:" << endl;
        cout << "1. View a student's information (Type \"1\")" << endl;
        cout << "2. Mark a student late (Type \"2\")" << endl;
        cout << "3. Mark a student absent (Type \"3\")" << endl;
        cout << "Your account:" << endl;
        cout << "4. View your course's information (Type \"4\")" << endl;
        cout << "5. View your account information (Type \"5\")" << endl;
        cout << "6. Edit your account information (Type \"6\")" << endl;
        cout << endl;
        cout << "Log out (Type \"100\")" << endl;
        cin >> choice;
        cout << endl;
        cout << endl;

        input = "";

        if (choice == 1) { //view a student's information
            cout << "Which student would you like to view (search for student by entering their name): ";
            cin.ignore();
            getline(cin, input); //gets search input that will be used to find desired person
            object = 2;
            action = 1;
            userNumber = sc.findPeople(input, object, action, userNumber); //method called to find desired person
        } else if(choice == 2){ //mark student late
            cout << "Which student would you like to mark late (search for student by entering their name): ";
            cin.ignore();
            getline(cin, input); //gets search input that will be used to find desired person
            object = 2;
            action = 4;
            userNumber = sc.findPeople(input, object, action, userNumber); //method called to find desired person
        } else if(choice == 3){ //mark student absent
            cout << "Which student would you like to mark absent (search for student by entering their name): ";
            cin.ignore();
            getline(cin, input); //gets search input that will be used to find desired person
            object = 2;
            action = 5;
            userNumber = sc.findPeople(input, object, action, userNumber); //method called to find desired person
        } else if(choice == 4){ //view course information
            sc.displayTeacherCourses(userNumber);
        } else if(choice == 5){ //display curernt user information
            object = 1;
            sc.displayPerson(userNumber, object); //calls method to display user information
        } else if(choice == 6){ //edit current user information
            object = 1;
            sc.editPerson(userNumber, object); //calls method to edit user information
        } else { //log out
            done = true;
        }
    } //teacher session loop ends
}
