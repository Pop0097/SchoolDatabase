#include "Classes.h"

void adminSession(School&);
void teacherSession(School&);

int main() {

    School sc(10, 100, 5); //initially creates a school with two teachers and two students

    bool cancel = false, loginSuccess = false, signedIn = false, programKill = false;
    string u_name = "", pass = "";
    int in = 0, userType = 0;

    while(!programKill) { //master program loop starts

        while (!signedIn && !programKill) { //signing in loop starts
            cout << "Sign in: Are you an administrator (1) or a teacher (2): (type \"0\" to kill the program)" << endl;
            cin >> in;
            if(in == 0){
               programKill = true;
            }
            if (in == 1 || in == 2) {
                cin.ignore();

                while (!loginSuccess && !cancel) { //credential input loop starts
                    u_name = "", pass = "";
                    cout << "Enter your credentials. (Type 0 in both fields to cancel):" << endl;
                    cout << "Username: ";
                    getline(cin, u_name);
                    //cout << u_name << endl;
                    cout << "Password: ";
                    getline(cin, pass);
                    //cout << pass << endl;
                    if (u_name == "0" && pass == "0") { //if the user chooses to cancel the sign in process, they will return back to the top of the signing in loop
                        cancel = true;
                    } else {
                        //statements check the credentials depending on the chosen user type
                        if(in == 1){
                            loginSuccess = sc.adminLogin(u_name, pass);
                            if (loginSuccess) {
                                signedIn = true; //variable changed so the signing in loop ends
                                userType = 1;
                            }
                        }
                        else{
                            loginSuccess = sc.teacherLogin(u_name, pass);
                            if (loginSuccess) {
                                signedIn = true;
                                userType = 2;
                            }
                        }
                    }
                } //credential input loop ends
            }
            cancel = false, loginSuccess = false;
        } //signing in loop ends

        in = 0;
        u_name = "", pass = "";

        //depending on the type of user signed in, a different session is called
        if(userType == 1){
            adminSession(sc);
        }
        else if (userType == 2){
            teacherSession(sc);
        }

        signedIn = false;
        userType = 0;
    } //master program loop ends

    cout << "Thank you for using this database" << endl;
    return 0;
}

void adminSession(School &sc){

    bool done = false; //this variable used when the user wants to stop updating the classes
    string confirmation = "";
    int object, choice;

    while(!done) { //admin session loop starts
        cout << endl;
        cout << "Select an action:" << endl;
        cout << "1. View a teacher's information (Type \"1\")" << endl;
        cout << "2. View a student's information (Type \"2\")" << endl; //Instead, make the admin enter the person's name. The program will search for the person and then output the desired one. (reduces need to list so many!!!)
        cout << "3. Edit a teacher's information (Type \"3\")" << endl;
        cout << "4. Edit a student's information (Type \"4\")" << endl; //Instead, make the admin enter the person's name. The program will search for the person and then output the desired one. (reduces need to list so many!!!)
        cout << "5. Create a teacher (Type \"5\")" << endl;
        cout << "6. Create a student (Type \"6\")" << endl;
        cout << "7. Delete a teacher (Type \"7\")" << endl;
        cout << "8. Delete a student (Type \"8\")" << endl;
        cout << "9. Create a class (Type \"9\")" << endl;
        cout << "10. Edit a class (Type \"10\")" << endl;
        cout << "11. Create an administrator (Type \"11\")" << endl;
        cout << "12. Delete an administrator (Type \"12\")" << endl;
        cout << "13. View your account information (Type \"13\")" << endl;
        cout << "14. Edit your account information (Type \"14\")" << endl;
        cout << endl;
        cout << "Log out (Type \"100\")" << endl;
        cin >> choice;
        cout << endl;
        cout << endl;


        if (choice == 1) {
            object = 1; //user wishes to see teachers
            sc.displayPeople(object);
            cout
                    << "Choose which teacher you would like to view (enter the number beside the name or press 0 to cancel): ";
            cin >> choice;
            if (choice != 0) {
                cout << endl;
                sc.displayPerson(choice, object);
            }
        } else if (choice == 2) {
            object = 2; //user wishes to see students
            sc.displayPeople(object);
            cout
                    << "Choose which student you would like to view (enter the number beside the name or press 0 to cancel): ";
            cin >> choice;
            if (choice != 0) {
                cout << endl;
                sc.displayPerson(choice, object);
            }
        } else if (choice == 3) {
            object = 1;
            sc.displayPeople(object);
            cout
                    << "Choose which teacher you would like to edit (enter the number beside the name or press 0 to cancel): ";
            cin >> choice;
            cout << endl;
            if (choice != 0) {
                sc.editPerson(choice, object);
            }
        } else if (choice == 4) {
            object = 2;
            sc.displayPeople(object);
            cout
                    << "Choose which student you would like to edit (enter the number beside the name or press 0 to cancel): ";
            cin >> choice;
            cout << endl;
            if (choice != 0) {
                sc.editPerson(choice, object);
            }
        } else if (choice == 5) {
            cout << "Creating a teacher:" << endl;
            object = 1;
            sc.createPerson(object);
        } else if (choice == 6) {
            cout << "Creating a student:" << endl;
            object = 2;
            sc.createPerson(object);
        } else if (choice == 7) {
            object = 1;
            sc.displayPeople(object);
            cout
                    << "Choose which teacher you would like to delete (enter the number beside the name or press 0 to cancel): ";
            cin >> choice;
            if (choice != 0) {
                cout << "Are you sure? (\"y\" or \"n\")? "
                     << endl; //confirms that the user really wants to destroy the Teacher object
                cin.ignore();
                getline(cin, confirmation);
                if (confirmation == "y") {
                    sc.deletePerson(choice, object);
                }
            }
        } else if (choice == 8) {
            object = 2;
            sc.displayPeople(object);
            cout
                    << "Choose which student you would like to delete (enter the number beside the name or press 0 to cancel): ";
            cin.ignore();
            cin >> choice;
            if (choice != 0) {
                cout << "Are you sure? (\"y\" or \"n\")? "
                     << endl; //confirms that the user really wants to destroy the Student object
                cin.ignore();
                getline(cin, confirmation);
                if (confirmation == "y") {
                    sc.deletePerson(choice, object);
                }
            }
        } else if(choice == 9){

        } else if(choice == 10){

        } else if(choice == 11){

        } else if(choice == 12){

        } else if(choice == 13){

        } else {
            done = true;
        }
    } //admin session loop ends
}

void teacherSession(School &sc){
    bool done = false; //this variable used when the user wants to stop updating the classes
    string confirmation = "";
    int object, choice;

    while(!done){ //teacher session loop starts
        cout << endl;
        cout << "Select an action:" << endl;
        cout << "1. View a student's information (Type \"1\")" << endl; //Instead, make the admin enter the person's name. The program will search for the person and then output the desired one. (reduces need to list so many!!!)
        cout << "2. View your account information (Type \"2\")" << endl;
        cout << "3. Edit your account information (Type \"3\")" << endl;
        cout << endl;
        cout << "Log out (Type \"100\")" << endl;
        cin >> choice;
        cout << endl;
        cout << endl;

        if (choice == 1) {
            object = 2; //user wishes to see students
            sc.displayPeople(object);
            cout
                    << "Choose which student you would like to view (enter the number beside the name or press 0 to cancel): ";
            cin >> choice;
            if (choice != 0) {
                cout << endl;
                sc.displayPerson(choice, object);
            }
        } else if(choice == 2){

        } else if(choice == 3){

        } else {
            done = true;
        }
    } //admin session loop ends
}
