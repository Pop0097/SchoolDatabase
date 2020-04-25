#include "Classes.h"

int main() {
    School sc(2, 2); //initially creates a school with two teachers and two students

    bool done = false; //this variable used when the user wants to stop updating the classes
    int choice, object;
    string confirmation = "";

    while(!done){
        //user chooses what they would like to do
        cout << endl;
        cout << "What would you like to do?:" << endl;
        cout << "View a teacher's information (Type \"1\")" << endl;
        cout << "View a student's information (Type \"2\")" << endl;
        cout << "Edit a teacher's information (Type \"3\")" << endl;
        cout << "Edit a student's information (Type \"4\")" << endl;
        cout << "Create a teacher (Type \"5\")" << endl;
        cout << "Create a student (Type \"6\")" << endl;
        cout << "Delete a teacher (Type \"7\")" << endl;
        cout << "Delete a student (Type \"8\")" << endl;
        cout << "See all teachers and students (Type \"9\")" << endl;
        cout << "Cancel your session (Type anything other than \"1\", \"2\", \"3\", \"4\", \"5\", \"6\", \"7\", or \"8\")" << endl;
        cin >> choice;

        if(choice == 1){
            object = 1; //user wishes to see teachers
            sc.displayPeople(object);
            cout << "Choose which teacher you would like to view (enter the number beside the name or press 0 to cancel): ";
            cin >> choice;
            if(choice != 0){
                sc.displayPerson(choice, object);
            }
        }
        else if(choice == 2){
            object = 2; //user wishes to see students
            sc.displayPeople(object);
            cout << "Choose which student you would like to view (enter the number beside the name or press 0 to cancel): ";
            cin >> choice;
            if(choice != 0){
                sc.displayPerson(choice, object);
            }
        }
        else if(choice == 3){
            object = 1;
            sc.displayPeople(object);
            cout << "Choose which teacher you would like to edit (enter the number beside the name or press 0 to cancel): ";
            cin >> choice;
            cout << endl;
            if(choice != 0){
                sc.editPerson(choice, object);
            }
        }
        else if(choice == 4){
            object = 2;
            sc.displayPeople(object);
            cout << "Choose which student you would like to edit (enter the number beside the name or press 0 to cancel): ";
            cin >> choice;
            cout << endl;
            if(choice != 0){
                sc.editPerson(choice, object);
            }
        }
        else if(choice == 5){
            cout << "Creating a teacher:" << endl;
            object = 1;
            sc.createPerson(object);
        }
        else if(choice == 6){
            cout << "Creating a student:" << endl;
            object = 2;
            sc.createPerson(object);
        }
        else if(choice == 7){
            object = 1;
            sc.displayPeople(object);
            cout << "Choose which teacher you would like to delete (enter the number beside the name or press 0 to cancel): ";
            cin >> choice;
            if(choice != 0){
                cout << "Are you sure? (\"y\" or \"n\")? " << endl;
                cin.ignore();
                getline(cin, confirmation);
                if(confirmation == "y"){
                    sc.deletePerson(choice, object);
                }
            }
        }
        else if(choice == 8){
            object = 2;
            sc.displayPeople(object);
            cout << "Choose which student you would like to delete (enter the number beside the name or press 0 to cancel): ";
            cin.ignore();
            cin >> choice;
            if(choice != 0){
                cout << "Are you sure? (\"y\" or \"n\")? " << endl;
                cin.ignore();
                getline(cin, confirmation);
                if(confirmation == "y"){
                    sc.deletePerson(choice, object);
                }
            }
        }
        else if(choice == 9){
            sc.toString();
        }
        else{
            done = true;
        }
    }
    cout << "Thank you for using this database" << endl;
    return 0;
}
