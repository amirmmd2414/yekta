//
// Created by Asus on 3/18/2024.
//

#ifndef YEKTA_USER_H
#define YEKTA_USER_H
#include <iostream>
using namespace std;
    class Users{
    public:
        string Username;
    ~Users();
};
class student : public Users{
    int ShowingGreades();
};
class teachers : public Users{
public:
    int AddLeason(string class_name);
    int EnterGrades();
    int AddStudent(string str,string sad);
    int DeleteStudent();
};
class admin : public Users{
    //
};
void wait();
int login(string username,string role);
void menu();
#endif //YEKTA_USER_H
