#include <iostream>
#include <string>
using namespace std;

struct Students
{   
    int roll;
    string name;
    double marks;
};

void print_student(const Students &s) {
    cout << "Roll: " << s.roll << "\n";
    cout << "Name: " << s.name << "\n";
    cout << "Marks: " << s.marks << "\n";
}

int main()
{
    Students cls[5];
    for(int i = 0; i < 5; i++)
    {
        cout << "Enter roll, name, marks for student " << i+1 << ": ";
        cin >> cls[i].roll;
        cin.ignore(); // to ignore leftover newline
        getline(cin, cls[i].name);
        cin >> cls[i].marks;
    }

    for(int i = 0; i < 5; i++)
    {
        print_student(cls[i]);
        cout << "-----------------\n";
    }

    return 0;
}
