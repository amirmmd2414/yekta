//
// Created by Asus on 3/18/2024.
//

#ifndef YEKTA_USER_H
#define YEKTA_USER_H
#include <iostream>
using namespace std;
    class Users{
    private:
        string firstname;
        string lastname;
        string ID;
    public:
    class teachers{
        int EnterLeason();
        int EnterGrades();
        int AddStudent();
        int DeleteStudent();
    };
    class student{
        int ShowingGreades();
    };
    class admin{
    //
    };
    Users(string fname,string lname,string id);
    ~Users();
};
#endif //YEKTA_USER_H
