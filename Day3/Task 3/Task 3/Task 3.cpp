// Task 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<array>
using namespace std;

struct emp {
	string name="no name", dept="no dept";
	int id=1, age=22;
};

int main()
{
	array<emp, 2>employees;
	int i = 0;
	while(i<employees.size()){
	cout << "\033[0;15H" << "Enter Employee data" << endl;
	cout << "----------------------------------------------\n";
	employees.at(i).id = i + 1;
	cout << "Emp NO." << employees.at(i).id << endl;
	cout << "\033[5;5H" << "Name: ";
	cout << "\033[5;30H" << "age: ";
	cout << "\033[8;5H" << "department: ";
	cout << "\033[5;10H";
	cin >> employees.at(i).name;
	cout << "\033[5;35H";
	cin >> employees.at(i).age;
	cout << "\033[8;17H";
	cin >> employees.at(i).dept;
	cout << "----------------------------------------------\n";
	i++;
	system("cls");
	}

	for (auto emp:employees)
	{
		cout << "Emp No." << emp.id << endl;
		cout << "Emp Name: " << emp.name<< endl;
		cout << "Emp age: " << emp.age << endl;
		cout << "Emp Dept: " << emp.dept << endl;
		cout << "---------------------------------------\n";
	}

}
