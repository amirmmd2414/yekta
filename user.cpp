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
void makeallfalse(bool& b1,bool& b2, bool& b3){
    b1 = false;
    b2 = false;
    b3 = false;
}
void wait(){
    for(int i = 0;i<3;i++) {
        cout << ". ";
        Sleep(1000);
    }
}

int teachers:: AddLeason(string class_name){
    ofstream file(class_name+".txt");
    file.close();
    return 1;
}
void write_users(string person){
    fstream Users;
    Users.open("users.txt", ios::app);
    Users << person << endl;
    Users.close();

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
        file.close();
        write_users(username);
    } else if (str == "-a") {
        ofstream file(username+".txt");
        file << "admin" << endl;
        write_users(username);
        file.close();
    } else if (str == "-t") {
        ofstream file(username+".txt");
        file << "teacher" << endl;
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
        cout << endl << "logged in Seccesfully" << endl;
        if(role == "student"){
            return 2;        }
        else if(role == "teacher"){
            return 3;
        }
        else{
            return 4;
        }
    }
}
int teachers ::DeleteStudent(string student_name,string class_name){
    ifstream file(class_name + ".txt");
    string temp[100]; //100 is the maximum student in a class
    int i = 0;
    while(file >> temp[i]){
        if(temp[i] == student_name){
            continue;
        }
        i++;
    }
    file.close();
    ofstream mnewfile(class_name + ".txt");
    file.close();
    fstream mynewfile(class_name+".txt",ios::app);
    for(int j = 0;j<i;j++){
        mynewfile << temp[j] << endl;
    }
    mynewfile.close();
    cout << "Student " << student_name <<
    " has been deleted from the class " <<
    class_name << endl;
    return 1;

}
int teachers ::AddStudent(std::string str, std::string sad) {
    fstream file;
    file.open(str+".txt",ios::app);
    file << sad << endl;
    file.close();
    cout << "Student " << sad <<
         " is now on the class " << str << endl;
    return 1;
}
string student :: ShowingGreades(string student_name,string class_name){
    string temp;
    ifstream file(student_name+".txt");
    while(file >> temp){
     if(temp == class_name){
         file >> temp;
         return temp;
     }

    }
    return "notfound";

}
int teachers ::EnterGrades(std::string student_name, std::string class_name,string grade) {
    fstream finalfileopeningfortoday(student_name+".txt",ios::app);
    finalfileopeningfortoday << class_name << endl << grade << endl;
    cout << "the grade has been entered " << endl;
    return 1;
}
void helper(){
    cout << "make an account : mkacc -s/-a/-t <username>"
         << endl << endl
         << "login : login -s/-a/-t <username>"
         << endl << endl
         << "make a class : tch add <classname>" <<
         endl << endl <<
         "add student to class : tch <student name> <class name>"
         << endl << endl <<
         "delete Student from a class :dlt <student name> <class name>" <<
         endl << endl
         << "Enter Grades : grd <student name> <class name> <grade>" <<
         endl << endl
         << "Show Grades : shw <class name>" <<
         endl << endl;
}
void menu() {
    bool Tlogin,Alogin,Slogin = false;
    string operation;
    string username;
    string log_in_username;
    string sad;
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
                int answer= login(username,str) ;
                if(answer== 1){
                    continue;
                }
                makeallfalse(Alogin,Tlogin,Slogin);
                log_in_username = username;
                if(answer == 2){
                    Slogin = true;
                }
                else if(answer == 3){
                    Tlogin = true;
                }
                else{
                    Alogin = true;
                }
            }
        }
        else if(operation == "shw" && Slogin == true){
            cin >> str;
            student guy;
            guy.Username = log_in_username;
           if(guy.ShowingGreades(guy.Username,str) == "notfound"){
               cout << "You have no grade for class " << str << endl;
               continue;
           }
           cout << "your grade for " << str << " is :" <<guy.ShowingGreades(guy.Username,str)
            << endl;
        }
        else if(operation == "tch" && Tlogin == true){
            cin >> str >> sad;
            teachers guy;
            guy.Username = log_in_username;
            if(str == "add"){
                // sad is the name of the class
                string temp;
                int j = 0;
                ifstream file(log_in_username+".txt");
                while(file >> temp){
                    if(temp == sad){
                        j = 1;
                        break;
                    }
                }
                if(j == 1){
                    cout << "This class is already exist " << endl;
                    continue;
                }
                file.close();
                fstream myfile;
                myfile.open(log_in_username+".txt",ios::app);
            myfile << sad;
           myfile.close();
            guy.AddLeason(sad);
            }
            else{
                ifstream file(str+".txt");
                int i =0;
                string temp;
                file >> temp;
                if(temp != "student"){
                    cout << "This user is not a student" << endl;
                    continue;
                }
                file.close();
                ifstream myfile(guy.Username+".txt");
                while(myfile >> temp){
                    if(temp == sad){
                         i = 1;
                        break;
                    }
                }
                myfile.close();
                if(i!=1){
                    cout << "This class does not exist" << endl;
                    continue;
                }
                else if(check(str) == true){
                    cout << "This student does not exist" << endl;
                    continue;
                }
                else{
                    guy.AddStudent(sad,str);
                }
            }
        }
        else if(operation == "dlt" && Tlogin == true){



            cin >> str >> sad;
            //str = name of the student    sad = name of the class
            string temp;
            teachers guy;
            guy.Username = log_in_username;
            int j = 0;
            ifstream file(log_in_username+".txt");
            while(file >> temp){
                if(temp == sad){
                    j = 1;
                    break;
                }
            }
            if(j != 1){
                cout << "This class does not exist " << endl;
                continue;
            }
            file.close();
             if(check(str) == true){
                cout << "This student does not exist" << endl;
                continue;
            }
             int q = 0;
             ifstream classname(sad+".txt");
             while(classname >> temp){
                 if(temp == str){
                     q = 1;
                     break;
                 }
             }
             if(q == 0){
                 cout << "This student is not in this class" << endl;
                 continue;
             }
             guy.DeleteStudent(str,sad);
        }
        else if(operation == "grd" && Tlogin == true){
            string temp;
            string grade;
            cin >> str >> sad >> grade;
            int q = 0;
            ifstream classnamee(sad+".txt");
            while(classnamee >> temp){
                if(temp == str){
                    q = 1;
                    break;
                }
            }
            if(q == 0){
                cout << "This student is not in this class" << endl;
                continue;
            }
            classnamee.close();
            teachers guy;
            guy.Username = log_in_username;
            guy.EnterGrades(str,sad,grade);
        }
        else if(operation == "/help"){
            helper();
        }
        else {
            cout <<
                 "This Command does not exits"
                 << endl << "Use /help to See list of the commands"
                 << endl;
        }
    }
}