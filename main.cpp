/*
  this file is mainly used to test the functionality of the classes
*/

#include "Classes.h"

int main() {

    //Following code tests the functionality of all methods in the Teacher and Student classes
    Student s("Bill" , "james", "wertyu", 10, "S987654321");
    s.toString();

    cout << "Now Teachers" << endl;

    Teacher t("Debra", "James", "46", "Compsci", "C45678");
    t.toString();
    t.setEmployeeId("555");
    t.markStudentLate(s);
    t.markStudentAbsent(s);
    t.markStudentAbsent(s);
    t.toString();

    cout << endl;

    s.toString();

}
