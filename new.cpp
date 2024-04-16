//
// Created by Asus on 3/27/2024.
//

#include "new.h"
#include <iostream>
#include <fstream>
bool isprofilecomplete(string username){
    ifstream file(username + ".txt");
    string temp;
    while(file >> temp){
        if(temp == "++true++"){
            return true;
        }
    }
    return false;
}
bool checkifisenglish(string word){
    for(int i = 0;i<word.length();i++){
        if((int)word[i]<=122 && (int)word[i]>=65){
            continue;
        }
        return false;
    }
    return true;
}
int complete_profile(student user){
    if(checkifisenglish(user.getfirstname())==false|| checkifisenglish(user.getlastname()) == false){
        cout << "Your first and last name should be in english format" << endl;
        return 275;
    }
    fstream file;
    file.open(user.getusername()+ ".txt",ios :: app);
    file << "*"+user.getfirstname() << endl
    << user.getlastname() << endl <<
    user.getphonenumber() << endl <<
    "++true++" << endl;
    cout << "your profile is complete now " << endl;
    file.close();
    return 1;

}
int complete_profile(teachers user){
    if(checkifisenglish(user.getfirstname())==false|| checkifisenglish(user.getlastname()) == false){
        cout << "Your first and last name should be in english format" << endl;
        return 275;
    }
    fstream file;
    file.open(user.getusername() + ".txt",ios :: app);
    file << "*"+user.getfirstname() << endl
         << user.getlastname() << endl <<
         user.getphonenumber() << endl <<
         "++true++" << endl;
    cout << "your profile is complete now " << endl;
    file.close();
    return 1;

}
int update(student user){
    ifstream file(user.getusername() + ".txt");
    string temp[100];
    int j;
    string more;
    for(int i = 0;;){
        if(file >> temp[i]){
            ;
        }
        else{
            break;
        }
         if(temp[i][0] == '*'){
            temp[i] = "*"+user.getfirstname();
            file >> more;
            temp[i+1] = user.getlastname();
            file >> more;
            temp[i+2] = user.getphonenumber();
            i+=2;
        }
        i++;
    j = i;
    }
    file.close();
    ofstream myfile(user.getusername()+".txt");
    for(int i = 0;i<=j;i++){
        myfile << temp[i] << endl;
    }
    cout << "Your profile is updated" << endl;
    return 1;
}
int update(teachers user){
    ifstream file(user.getusername() + ".txt");
    string temp[100];
    int j;
    string more;
    for(int i = 0;;){
        if(file >> temp[i]){
            ;
        }
        else{
            break;
        }
        if(temp[i][0] == '*'){
            temp[i] = "*"+user.getfirstname();
            file >> more;
            temp[i+1] = user.getlastname();
            file >> more;
            temp[i+2] = user.getphonenumber();
            i+=2;
        }
        i++;
        j = i;
    }
    file.close();
    ofstream myfile(user.getusername()+".txt");
    for(int i = 0;i<=j;i++){
        myfile << temp[i] << endl;
    }
    cout << "Your profile is updated" << endl;
    return 1;

    }
void show_class(string ClassName){
    ifstream file(ClassName+".txt");
    string temp;
    cout << "members of class : " << endl;
    while(file >> temp){
        cout << temp << endl;
    }
    return;
}
bool passwordcheckk(string str,string name) {
    if (str.length() <= 6 || str.length() >= 21) {
        return false;
    }
    for (int i = 0; i < name.length() - 2; i++) {
        for (int j = 4; j < name.length() - i; i++) {
            if (str.find(name.substr(i, j)) != string::npos) {
                return false;
            }
        }
    }
    return true;
}