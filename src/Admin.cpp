//
// Created by Dhruv Rawat on 2020-05-27.
//

#include "Classes.h"

Admin::Admin(){
    name = "d_name";
    username = "d_uname";
    encrypted_password = adminEncrypt("pass", "Axc4RDx3osYg");
}

Admin::Admin(string u, string password){
    name = "d_name";
    username = u;
    encrypted_password = adminEncrypt(password, "Axc4RDx3osYg");
}

Admin::Admin(string n, string u, string password){
    name = n;
    username = u;
    encrypted_password = adminEncrypt(password, "Axc4RDx3osYg");
}

Admin::~Admin(){
    //cout << "deleted" << endl;
}

string Admin::adminEncrypt(string password, string key){
    //ensures the key is (at a minimum) as long as the message
    //cout << "called" << endl;
    string tmp(key);
    while(key.size() < password.size()){
        key += tmp;
    }

    for(int i = 0; i < password.size(); ++i){
        password[i] ^= key[i];
    }
    //cout << password;
    return password;
}

string Admin::adminDecrypt(string entry, string key){
    return adminEncrypt(entry, key);
}

string Admin::getName(){
    return name;
}

string Admin::getUsername(){
    return username;
}

string Admin::getPassword(){
    return encrypted_password;
}

string Admin::toString(){
    cout << "Administrator account information:" << endl;
    cout << "Name: " <<  name << endl;
    cout << "Username: " << username << endl;
    cout << endl;
    return "";
}

void Admin::setName(string n){
    name = n;
}

void Admin::setUsername(string u){
    username = u;
}

void Admin::setPassword(string pass){
    encrypted_password = adminEncrypt(pass, "Axc4RDx3osYg");
}
