//
// Created by Asus on 3/18/2024.
//

#ifndef YEKTA_USER_H
#define YEKTA_USER_H
#include <iostream>
using namespace std;
    class Users{
        friend  void menu();
        friend int complete_profile();
        friend int update();
            protected:
        string Username;
        string firstname;
        string lastname;
        string phonenumber;
        string password;
    public:
    ~Users();
    string getusername();
    void setusername(string username);
    string getfirstname();
    string getlastname();
    void setfirstname(string First);
    void serlastname(string last);
    string getphonenumber();
};
class student : public Users{
public:
    string ShowingGreades(string student_name,string class_name);
    int sendassignment(string assignment,string username,string classname);
    ~student();
};
class teachers : public Users{
public:
    int AddLeason(string class_name);
    int EnterGrades(string student_name,string class_name,string grade);
    int AddStudent(string str,string sad);
    int seeassignment(string student_username,string classname);
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
int login(string username,string role,string password);
void menu();
#endif //YEKTA_USER_H
