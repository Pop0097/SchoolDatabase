#include "Classes.h"

int main() {

    int initialTeachers, initialStudents;
    cout << "First create your school:" << endl;
    cout << "How many teachers are there?: ";
    cin >> initialTeachers;
    cout << "How many students are there?: ";
    cin >> initialStudents;
    cout << endl;

    School sc(initialTeachers, initialStudents); //creates school

    bool done = false; //this variable used when the user wants to stop updating the classes
    int choice, object;

    while(!done){
        //user chooses what they would like to do
        cout << "What would you like to do?:" << endl;
        cout << "View a teacher's information (Type \"1\")" << endl;
        cout << "View a student's information (Type \"2\")" << endl;
        cout << "Edit a teacher's information (Type \"3\")" << endl;
        cout << "Edit a student's information (Type \"4\")" << endl;
        cout << "Create a teacher (Type \"5\")" << endl;
        cout << "Create a student (Type \"6\")" << endl;
        cout << "Delete a teacher (Type \"7\")" << endl;
        cout << "Delete a student (Type \"8\")" << endl;
        cout << "Cancel your session (Type anything other than \"1\", \"2\", \"3\", \"4\", \"5\", \"6\", \"7\", or \"8\")" << endl;
        cin >> choice;

        if(choice == 1){
            object = 1; //user wishes to see teachers
            sc.displayPeople(object);
            cout << "Choose which teacher you would like to view (enter the number beside the name): ";
            cin >> choice;
            sc.displayPerson(choice);
        }
        else if(choice == 2){
            object = 2; //user wishes to see students
            sc.displayPeople(object);
            cout << "Choose which student you would like to view (enter the number beside the name): ";
            cin >> choice;
            sc.displayPerson(choice);
        }
        else if(choice == 3){
            object = 1;
            sc.displayPeople(object);
            cout << "Choose which teacher you would like to edit (enter the number beside the name): ";
            cin >> choice;
            cout << endl;
            sc.editPerson(choice, object);
        }
        else if(choice == 4){
            object = 2;
            sc.displayPeople(object);
            cout << "Choose which student you would like to edit (enter the number beside the name): ";
            cin >> choice;
            cout << endl;
            sc.editPerson(choice, object);
        }
        else if(choice == 5){

        }
        else if(choice == 6){

        }
        else if(choice == 7){

        }
        else if(choice == 8){

        }
        else{
            done = true;
        }
    }
    cout << "Hello World!" << endl;
    return 0;
}
