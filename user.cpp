//
// Created by Asus on 3/18/2024.
//
#include "user.h"
#include "windows.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;
Users::~Users(){
    ;
}
void menu() {
    string operation;
    string username;
    student personS;
    teachers personT;
    admin personA;
    string str;
    while(1) {
        cin >> operation;
        if (operation == "mkacc") {
            cin >> str  //
                >> username;
            if (str == "-s") {
                personS.Username = username;
            } else if (str == "-a") {
                personA.Username = username;
            } else if (str == "-t") {
                personT.Username = username;
            } else {
                cout << "This Role does not exist" << endl;
            }
        } else if (operation == "clr") {
            system("cls");
        } else if (operation == "login") {

        } else {
            cout <<
                 "This Command does not exits" << endl;
        }
    }
}