//
// Created by Dhruv Rawat on 2020-03-10.
//

#include "Classes.h"

Person::Person(){
    firstName = "Default First Name";
    lastName = "Default Last Name";
    address = "Default Address";
}

Person::Person(string first, string last, string add){
    if(first != "0"){
        firstName = first;
    }
    else{
        firstName = "Default First Name";
    }

    if(last != "0"){
        lastName = last;
    }
    else{
        lastName = "Default last Name";
    }

    if(add != "0"){
        address = add;
    }
    else{
        address = "Default Address";
    }
}

Person::~Person(){}

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
