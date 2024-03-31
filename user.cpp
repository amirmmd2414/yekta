//
// Created by Asus on 3/18/2024.
//
#include "user.h"
#include "windows.h"
#include <iostream>
#include <fstream>
#include "new.h"
#include <string>
#include <shellapi.h>
using namespace std;
Users::~Users(){

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
teachers :: ~teachers(){

}
student :: ~student(){

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
int student :: sendassignment(string assignment,string username,string classname){
    fstream file;
    file.open(username + ".txt" , ios :: app);
    file << "//" + classname + '-' + assignment << endl;
    file.close();
    cout << "The assignment has been sent" << endl;
    return 1;
}
void make_something(string str, string username,string password){
    if (str == "-s") {
        ofstream file(username+".txt");
        file << "student" << endl
                << "+++"+password+"+++" << endl;
        file.close();
        write_users(username);
    } else if (str == "-a") {
        ofstream file(username+".txt");
        file << "admin" << endl
                << "+++"+password+"+++" << endl;
        write_users(username);
        file.close();
    } else if (str == "-t") {
        ofstream file(username+".txt");
        file << "teacher" << endl
                << "+++"+password+"+++" << endl;
        write_users(username);
        file.close();
    } else {
        cout << "This Role does not exist" << endl;
    }
}
int login(string username,string role,string password){
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
    string p;
    file >> temp >>p;
    if(temp != role){
        cout << "This user is not " << role << "!" << endl;
        return 1;
    }
    else if("+++"+password+"+++" != p){
        cout << "wrong password" << endl;
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
bool CheckIfIsDeleted(string username){
    ifstream file("soft_delete.txt");
    string temp;
    while(file >> temp){
        if(temp == username){
            return false;
        }
    }
    return true;
}
int admin::softdelete(string username) {
    ifstream isitadmin(username + ".txt");
    string role;
    isitadmin >> role;
    if(role == "admin"){
        cout <<"admins can not be deleted" << endl;
        return 1;
    }
    fstream file;
    file.open("soft_delete.txt",ios ::app);
    file << username << endl;
    file.close();
    cout << "User " << username << " is deleted" << endl;
    return 1;
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
int admin ::read(std::string username) {
    ifstream file(username+".txt");
    string temp;
    while(file >> temp){
        if(temp[0] == '*'){
            cout << endl << "First name : " << temp.substr(1,temp.length()) << endl;
            file >> temp;
            cout << "Last name : " << temp << endl;
            file >> temp;
            cout << "Phone number : " << temp << endl << endl;
            break;
        }
    }
    file.close();

    return 1;

}
int teachers :: seeassignment(string student_username,string classname){
    ifstream file(student_username + ".txt");
    string temp;
    int i = 0;
    int length = classname.length();
    while(file >> temp){
        if(temp[0] == '/' && temp[1] == '/'&& temp.substr(2,length) == classname){
            i = 1;
            break;
        }
    }
    if(i == 0){
        cout << "This student has no assignment" << endl;
        return 1;
    }
    file >> temp;
    cout << student_username << " assignment :" <<
    endl << endl << temp << endl << endl;
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
    cout << "make an account : mkacc -s/-a/-t <username> <password>"
         << endl << endl
         << "login : login -s/-a/-t <username> <password>"
         << endl << endl
         << "make a class : tch add <classname>" <<
         endl << endl <<
         "add student to class : tch <student name> <class name>"
         << endl << endl <<
         "delete Student from a class :dlt <student name> <class name>" <<
         endl << endl
         << "Send assignment : send <class name> <assignment>" //
         << endl << endl
         << "See assignment : see <student username> <class name>"
         << endl << endl
         << "Enter Grades : grd <student name> <class name> <grade>" <<
         endl << endl
         << "Show Grades : shw <class name>" <<
         endl << endl
         << "delete user : delete <username>" <<
         endl << endl
         << "restore user : restore <username>"<<
         endl << endl
         << "complete profile : complete <username> <first name> <last name> <phone number>"
         << endl << endl
         << "update profile : update <username> <first name> <last name > <phone number>"
         << endl << endl
         << "show profile : show <username>"
         << endl << endl
         << "show class members : show_cl <class name>"
         << endl << endl
         << "go to real site : real"
         << endl << endl;
}
int admin ::restore(std::string username){

    ifstream file("soft_delete.txt");
    string temp[100]; //100 is the maximum users in  soft delete
    int i = 0;
    while(file >> temp[i]){
        if(temp[i] == username){
            continue;
        }
        i++;
    }
    file.close();
    ofstream mnewfile("soft_delete.txt");
    file.close();
    fstream mynewfile("soft_delete.txt",ios::app);
    for(int j = 0;j<i;j++){
        mynewfile << temp[j] << endl;
    }
    mynewfile.close();
    cout << "User " << username <<
         " has been restored "<< endl;


    return 1;
}
void menu() {
    bool Tlogin,Alogin,Slogin = false;
    string operation;
    string username;
    string log_in_username;
    string sad;
    string str;
    string password;
    while(1) {
        cin >> operation;
        if (operation == "mkacc" && Alogin == true) {
            cin >> str
                >> username >> password;
            if(check(username) == false){
                cout << "this username does exist" << endl;
                continue;
            }
            else if(checkifisenglish(username) == false){
                cout << "username should be in english" << endl;
                continue;
            }
            else if(passwordcheckk(password,username) == false){
                cout << "Weak Password" << endl;
            }
            make_something(str,username,password);
            cout << "new account hsa been created " << endl;
        }
        else if (operation == "login") {
            cin >> str
                >> username >> password;
            if(str=="-s"||str=="-a"||str=="-t"){
                if(CheckIfIsDeleted(username) == false){
                    cout << "This user does not exist" << endl;
                    continue;
                }
                int answer= login(username,str,password) ;
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
        else if(operation == "see" && Tlogin == true){
            string usernameusername;
            string classnameclassname;
            cin >> usernameusername >> classnameclassname;
            if(CheckIfIsDeleted(usernameusername) == false || check(usernameusername) == true){
                cout << "This user does not exist" << endl;
                continue;
            }
            teachers userrr;
            userrr.seeassignment(usernameusername,classnameclassname);
            continue;
        }
        else if(operation == "real"){
            ShellExecuteA(NULL,"open","https://webauth.iut.ac.ir/cas/login?service=https%3A%2F%2Flogin.iut.ac.ir%2Flogin%2Fcas",NULL,NULL,SW_SHOWNORMAL);
            cout << "You entered the real site of YEKTA" << endl;
            continue;
        }
        else if(operation == "delete" && Alogin == true){
            string ss;
            cin >> ss;
            if(CheckIfIsDeleted(ss) == false || check(ss) == true){
                cout << "This user does not exist" << endl;
                continue;
            }
            admin guy;
            guy.Username = log_in_username;
            guy.softdelete(ss);
            continue;
        }
        else if(operation == "restore" && Alogin == true){
            string ss;
            cin >> ss;
            admin guy;
            guy.Username = log_in_username;
            if(CheckIfIsDeleted(ss) == true){
                cout << "This User Can not be restored" << endl;
                continue;
            }
            guy.restore(ss);
            continue;
        }
        else if(operation == "show_cl" && Tlogin == true){
            string classname;
            string temp;
            cin >> classname;
            ifstream file(log_in_username+".txt");
            int doesThisClassExist = 0;
            while(file >> temp){
                if(temp == classname){
                    doesThisClassExist = 1;
                    break;
                }
            }
            if(doesThisClassExist == 0){
                cout << "This class does not exist" << endl;
                continue;
            }
            show_class(classname);
            continue;
        }
        else if(operation == "update" && Alogin == true){
            string user_name;
            cin >> user_name;
            if(isprofilecomplete(user_name) == false){
                cout << "This user does not have a profile yet" << endl;
                continue;
            }
            else if(check(user_name) || CheckIfIsDeleted(user_name) == false){
                cout << "This user does not exist" << endl;
                continue;
            }
            string temp;
            ifstream file(user_name + ".txt");
            file >> temp;

            if(temp == "student"){
                student someone;
                someone.Username = user_name;
                cin >> someone.firstname >> someone.lastname >> someone.phonenumber;
                update(someone);
                cout << "This file updated successfully" << endl;
                continue;
            }
            else if(temp == "teacher"){
                teachers someone;
                someone.Username = user_name;
                cin >> someone.firstname >> someone.lastname >> someone.phonenumber;
                update(someone);
                cout << "This file updated successfully" << endl;

                continue;
            }
            else{
                cout << "This username is a admin!!!" << endl;
                continue;
            }
        }
        else if(operation == "show" && Alogin == true){

            string temp;
            cin >> temp;
            if(isprofilecomplete(temp) == false){
                cout << "The profile for this user in not complete " << endl;
                continue;
            }
            else if(check(temp) == true || CheckIfIsDeleted(temp) == false){
                cout << "This user does not exist" << endl;
                continue;
            }
             ifstream file(temp+".txt");
            string temp2;
            file >> temp2;
            file.close();
            if(temp2 == "admin"){
                cout << "This user is an admin!!!" << endl;
                continue;
            }
            else{
                admin Admin;
                Admin.read(temp);
                continue;
            }
        }
        else if(operation == "send" && Slogin == true){
            string class__name;
            string assignment;
            cin >> class__name;
            getline(cin,assignment);
            ifstream file(class__name+".txt");
            string temp;
            int wtf = 0;
            while(file >> temp){
                if(temp == log_in_username){
                    wtf = 1;
                    break;
                }
            }
            if(wtf == 0){
                cout << "This class does not exist" << endl;
                continue;
            }
            student someone;
            someone.Username = log_in_username;
            someone.sendassignment(assignment,log_in_username,class__name);
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
        else if(operation == "tch" &&   Tlogin == true){
            cin  >> str >> sad;
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
            myfile << sad << endl;
           myfile.close();
            guy.AddLeason(sad);
            }
            else{
                ifstream file(str+".txt");
                int i =0;
                string temp;
                file >> temp;
                if(CheckIfIsDeleted(str) == false){
                    cout <<"This user does not exist anymore" << endl;
                    continue;
                }
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
                ifstream khasteshodam(sad+".txt");
                int jj = 0;
                while(khasteshodam>>temp){
                    if(temp == str){
                        jj = 1;
                    }
                }
                if(jj==1){
                    cout << "This student is in this class" << endl;
                    continue;
                }
                    guy.AddStudent(sad,str);

            }
        }
        else if(operation == "complete" && Alogin == true){
            cin >> str;
            if(check(str) == true || CheckIfIsDeleted(str) == false){
                cout << "This user does not exist" << endl;
                continue;
            }
            else if(isprofilecomplete(str)){
                cout << "This user has a complete profile" << endl;
                continue;
            }
            ifstream file(str+".txt");
            string temp;
            file >> temp;
            if(temp == "student"){
                student user;
                user.Username = str;
                cin >> user.firstname >>
                user.lastname >> user.phonenumber;
                complete_profile(user);
                continue;
            }
            else if(temp == "teacher"){
                teachers user;
                user.Username = str;
                cin >> user.firstname >>
                    user.lastname >> user.phonenumber;
                    complete_profile(user);
                continue;
            }
            else{
                cout << "This user is an admin!!!" << endl;
                continue;
            }
        }
        else if(operation == "dlt" && Tlogin == true){



            cin >> str >> sad;
            //str = name of the student    sad = name of the classo 
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
            if(q == 0 || CheckIfIsDeleted(str) == false){
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
        else if(operation == "exit"){
            break;
        }
        else {
            cout <<
                 "This Command does not exits"
                 << endl << "Use /help to See list of the commands"
                 << endl;
        }
    }
    return ;
}