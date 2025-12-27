// Task 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
using namespace std;

class Employee {
	string name;
	int id, age, salary;
public:
	void setId(int id) {
		this->id = id;

	}
	void setName(string name) {
		this->name = name;
	}
	void setAge(int age) {
		this->age = age;
	}
	void setSalary(int salary) {
		this->salary = salary;
	}
	void display() {
		system("cls");
		cout << "Emp No:" <<id << endl;
		cout << "Emp Name: " << name << endl;
		cout << "Emp age: " << age << endl;
		cout << "Emp salary: " << salary << endl;
	}
};


int main()
{
	Employee s1;
	int id, age, salary;
	string name;
	cout << "\033[0;15H" << "Enter Employee data" << endl;
	cout << "----------------------------------------------\n";
	cout << "\033[5;5H" << "ID: ";
	cout << "\033[5;30H" << "Name: ";
	cout << "\033[8;5H" << "Age: ";
	cout <<"\033[8;30H" << "Salary: ";
	cout << "\033[5;8H";
	cin >> id;
	s1.setId(id);
	cout << "\033[5;35H";
	cin >> name;
	s1.setName(name);
	cout << "\033[8;9H";
	cin >> age;
	s1.setAge(age);
	cout << "\033[8;37H";
	cin >> salary;
	s1.setSalary(salary);
	cout << "----------------------------------------------\n";
	cout << "Press any key to display Employee" << endl;
	_getch();
	s1.display();
}
