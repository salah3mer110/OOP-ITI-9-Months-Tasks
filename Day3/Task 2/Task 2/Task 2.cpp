// oop task 2 lab 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
using namespace std;
struct subject {
    string subjName="Math";
    int grade=90;
};
struct student{
    int id;
    string name="Salah";
    array<subject, 2> subjects ;
};

int main()
{
    array<student, 2> s;
    for (int i = 0;i < 2;i++) {
        s.at(i).id=i;
        cout << "Enter student " << i + 1 << " Name: ";
        cin >> s.at(i).name;
        for (int j = 0;j < 2;j++) {
            cout << "Enter subject "<<j+1<< " Name: ";
           cin>>s.at(i).subjects.at(j).subjName;
           cout << "Enter subject  " << j + 1 << " grade: ";
            cin >> s.at(i).subjects.at(j).grade;
        }
    }

    array<array<int, 2>, 2> results = {0};

    for (int i = 0; i < 2; i++) {
        int total = 0;
        for (int j = 0; j < 2; j++) {
           total += s.at(i).subjects.at(j).grade;
        }
        results.at(i).at(0) = total;
        results.at(i).at(1) = total / s.at(i).subjects.size();
    }
    system("cls");
    for (int i = 0; i < 2; i++) {
        cout << "Student " << s.at(i).name << ": ";
        cout << "Sum of grades = " << results.at(i).at(0) << ", ";
        cout << "Avg of grades = " << results.at(i).at(1) << endl;
    }
}
