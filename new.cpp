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
    if(checkifisenglish(user.firstname)==false|| checkifisenglish(user.lastname) == false){
        cout << "Your first and last name should be in english format" << endl;
        return 275;
    }
    fstream file;
    file.open(user.Username + ".txt",ios :: app);
    file << "*"+user.firstname << endl
    << user.lastname << endl <<
    user.phonenumber << endl <<
    "++true++" << endl;
    cout << "your profile is complete now " << endl;
    file.close();
    return 1;

}
int complete_profile(teachers user){
    if(checkifisenglish(user.firstname)==false|| checkifisenglish(user.lastname) == false){
        cout << "Your first and last name should be in english format" << endl;
        return 275;
    }
    fstream file;
    file.open(user.Username + ".txt",ios :: app);
    file << "*"+user.firstname << endl
         << user.lastname << endl <<
         user.phonenumber << endl <<
         "++true++" << endl;
    cout << "your profile is complete now " << endl;
    file.close();
    return 1;

}
int update(student user){
    ifstream file(user.Username + ".txt");
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
            temp[i] = "*"+user.firstname;
            file >> more;
            temp[i+1] = user.lastname;
            file >> more;
            temp[i+2] = user.phonenumber;
            i+=2;
        }
        i++;
    j = i;
    }
    file.close();
    ofstream myfile(user.Username+".txt");
    for(int i = 0;i<=j;i++){
        myfile << temp[i] << endl;
    }
    cout << "Your profile is updated" << endl;
    return 1;
}
int update(teachers user){
    ifstream file(user.Username + ".txt");
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
            temp[i] = "*"+user.firstname;
            file >> more;
            temp[i+1] = user.lastname;
            file >> more;
            temp[i+2] = user.phonenumber;
            i+=2;
        }
        i++;
        j = i;
    }
    file.close();
    ofstream myfile(user.Username+".txt");
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
