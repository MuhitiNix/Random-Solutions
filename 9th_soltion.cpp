#include<iostream>
using namespace std;

struct Student {
    string name;
    int roll;
    int marks;

};

int main(){
    Student s;
    cout<<"Please fill in the information: ";

    getline(cin , s.name);
    cin>>s.roll>>s.marks;
    cout<<"Name: " <<s.name<<endl;
     cout<<"Roll: " <<s.roll<<endl;
     cout<<"Marks: " <<s.marks<<endl;
     return 0;
    
}