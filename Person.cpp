//
// Created by Dhruv Rawat on 2020-03-10.
//

#include "Classes.h"

Person::Person(){
    firstName = "";
    lastName = "";
    address = "";
}

Person::Person(string first, string last){
    firstName = first;
    lastName = last;
    address = "";
}

Person::Person(string first, string last, string add){
    firstName = first;
    lastName = last;
    address = add;
}

string Person::getFirstName(){
    return firstName;
}

string Person::getLastName(){
    return lastName;
}

string Person::getAddress(){
    return address;
}

void Person::setFirstName(string n){
    firstName = n;
}

void Person::setLastName(string n){
   lastName = n;
}

void Person::setAddress(string a){
    address = a;
}

string Person::toString() const{
    return "";
}

bool Person::isValidId(string n) const{
    return false;
}
