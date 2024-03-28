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
        string firstname;
        string lastname;
        string phonenumber;
        string password;
    ~Users();
};
class student : public Users{
public:
    string ShowingGreades(string student_name,string class_name);
    ~student();
};
class teachers : public Users{
public:
    int AddLeason(string class_name);
    int EnterGrades(string student_name,string class_name,string grade);
    int AddStudent(string str,string sad);
    int DeleteStudent(string student_name,string class_name);
    ~teachers();
};
class admin : public Users{
public :
    int softdelete(string username);
    int restore(string username);
    int read(string username);
};
void wait();
int login(string username,string role);
void menu();
string arraying(string NameofTheFile);
#endif //YEKTA_USER_H
