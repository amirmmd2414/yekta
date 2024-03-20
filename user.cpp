//
// Created by Asus on 3/18/2024.
//
#include "user.h"
#include "windows.h"
#include <iostream>
#include <fstream>
using namespace std;
Users::~Users(){
    ;
}
void wait(){
        for(int i = 0;i<3;i++) {
            cout << ". ";
            Sleep(1000);
        }
}
void write_users(string person){
    ofstream Users("users.txt");
    Users << person << endl;
}
bool check(string username){
    string temp;
    ifstream Users("users.txt");
    while(Users >> temp){
        if(temp == username){
            Users.close();
            return false;
        }
    }
    Users.close();
    return true;
}
void make_something(string str, string username){
    if (str == "-s") {
        ofstream file(username+".txt");
        file << "student" << endl;
        file << username;
        file.close();
        write_users(username);
    } else if (str == "-a") {
        ofstream file(username+".txt");
        file << "admin" << endl;
        file << username;
        write_users(username);
        file.close();
    } else if (str == "-t") {
        ofstream file(username+".txt");
        file << "teacher" << endl;
        file << username;
        write_users(username);
        file.close();
    } else {
        cout << "This Role does not exist" << endl;
    }
}
int login(string username,string role){
    if(role == "-s"){
        role = "student";
    }
    else if(role == "-a"){
        role = "admin";
    }
    else{
        role = "teacher";
    }
    if(check(username) == true){
        cout << "This Username does not exit" << endl;
        return 1;
    }
    string temp;
    ifstream file(username+".txt");
    file >> temp;
    if(temp != role){
        cout << "This user is not " << role << "!" << endl;
        return 1;
    }
    else{
        wait();
        cout << endl << "logged in Seccesfully";
        return 0;
    }
}
void helper(){
    cout << "make and account : mkacc -s/-a/-t <username>"
    << endl << "login : login -s/-a/-t <username>"
    << endl << "";
}
void menu() {
    string operation;
    string username;
    string str;
    while(1) {
        cin >> operation;
        if (operation == "mkacc") {
            cin >> str
                >> username;
            if(check(username) == false){
                cout << "this username does exist" << endl;
                continue;
            }
            make_something(str,username);
        } else if (operation == "login") {
            cin >> str
                >> username;
            if(str=="-s"||str=="-a"||str=="-t"){
                if(login(username,str) == 1){
                    continue;
                }
            }
        } else {
            cout <<
                 "This Command does not exits"
                 << endl << "Use /help to See list of the commands"
                 << endl;
        }
    }
}