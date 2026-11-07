
#include <iostream>
using namespace std;

struct Student
{
    string name;
    int rollNo;
    float marks;
};

int main()
{
    Student s1;

    cout << "Enter student name: ";
    cin >> s1.name;

    cout << "Enter roll number: ";
    cin >> s1.rollNo;

    cout << "Enter marks: ";
    cin >> s1.marks;

    cout << "\n===== STUDENT RESULT =====" << endl;

    cout << "Name: " << s1.name << endl;
    cout << "Roll Number: " << s1.rollNo << endl;
    cout << "Marks: " << s1.marks << endl;

    if(s1.marks >= 50)
    {
        cout << "Result: PASS" << endl;
    }
    else
    {
        cout << "Result: FAIL" << endl;
    }

    return 0;
}
