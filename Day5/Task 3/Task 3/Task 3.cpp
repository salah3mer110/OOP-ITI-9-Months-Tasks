// Task 5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <conio.h>
#include <span>
#include <vector>
using namespace std;

struct emp {
    string name, dept;
    int id, age;
};

int  takeChoices(int, vector<emp>&, int&);
void displayMenu();
emp addEmployee(int&);
void display(int, span<emp>);
void displayAll(span<emp>);
void returnMenu();

int main()
{
    displayMenu();
}

//show Menu
void displayMenu() {
    array<string, 4> arr = { "New", "Display", "Display all", "Exit" };
    vector<emp> employees;
    static int empCount = 0;
    int choice = 0;
    while (true) {
        cout << "\033[0;15HEmployee Form\n";
        cout << "------------------------------------------------\n";
        //print
        for (int i = 0; i < arr.size(); i++) {
            if (i == choice)
                cout << "\033[" << i + 4 << ";7H\033[31m" << i + 1 << ". " << arr[i] << "\033[0m\n";
            else
                cout << "\033[" << i + 4 << ";7H" << i + 1 << ". " << arr[i] << "\n";
        }
        choice = takeChoices(choice, employees, empCount);
    }
}
//take keyboard inputs
int  takeChoices(int choice, vector<emp> &employees, int &Empcount) {
    int key = _getch();
    if (key == 27) {//exit
        system("cls");
        cout << "bye bye :)\n";
        return choice;
    }

    switch (key) {
    case 80://down 
        if (choice < 3) {
            choice++;
            system("cls");
        }
        break;
    case 72: //up
        if (choice > 0) {
            choice--;
            system("cls");
        }
        break;
    case 13: //enter
        if (choice == 3) {//exit
            system("cls");
            cout << "bye bye :)\n";
            exit(0);
        }
        if (choice == 0) {
            system("cls");
            employees.push_back(addEmployee(Empcount));
            Empcount++;
            returnMenu();
        }
        if (choice == 1) {
            if (employees.size() != 0) {
                system("cls");
                cout << "Enter Employee ID to show: \n";
                int empNum;
                cin >> empNum;
                while (empNum > employees.size() || empNum < 0) {
                    cout << "Please enter a correct Employee ID to show: \n";
                    cin >> empNum;
                }
                system("cls");
                display(empNum, employees);
                returnMenu();
            }
        }
        if (choice == 2) {
            system("cls");
            displayAll(employees);
            returnMenu();
        }
    }
    return choice;
}

//add new emp
emp addEmployee(int &empCount) {
    emp employee;
    cout << "\033[0;15H" << "Enter Employee data" << endl;
    cout << "----------------------------------------------\n";
    employee.id = empCount + 1;
    cout << "Emp NO." << employee.id << endl;
    cout << "\033[5;5H" << "Name: ";
    cout << "\033[5;30H" << "age: ";
    cout << "\033[8;5H" << "department: ";
    cout << "\033[5;10H";
    cin >> employee.name;
    cout << "\033[5;35H";
    cin >> employee.age;
    cout << "\033[8;17H";
    cin >> employee.dept;
    cout << "----------------------------------------------\n";
    cout << "Employee added successfully" << endl;
    return employee;
}

//display by id
void display(int id, span<emp> employees) {
    if (employees.size() > 0) {
        emp employee = employees[id - 1];
        cout << "Emp No." << employee.id << endl;
        cout << "Emp Name: " << employee.name << endl;
        cout << "Emp age: " << employee.age << endl;
        cout << "Emp Dept: " << employee.dept << endl;
        cout << "---------------------------------------\n";
        return;
    }
    cout << "There are no Employees to Show...\n";
}

//display all Emp
void displayAll(span<emp> employees) {
    if (employees.size() >= 1) {
        for (int i = 0;i < employees.size();i++) {
            if (employees[i].name != "") {
                cout << "Emp No." << employees[i].id << endl;
                cout << "Emp Name: " << employees[i].name << endl;
                cout << "Emp age: " << employees[i].age << endl;
                cout << "Emp Dept: " << employees[i].dept << endl;
                cout << "---------------------------------------\n";
            }
            continue;
        }
    }
    else
        cout << "There are no Employees to Show...\n";
}

//dry code refactor
void returnMenu() {
    cout << "Press any Key to return to the Menu...\n";
    _getch();
    system("cls");
}