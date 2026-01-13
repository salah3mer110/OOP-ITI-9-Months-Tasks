// Simple Inherit Task 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class Person {
    static int counter;
    int id;
protected:
    string name;
    int age;
public:
    Person() {
        name = "";
        age = 0;
        id = ++counter;
        cout << "default Person constructor is called" << endl;
    }
    Person(string name, int age) {
        this->name = name;
        this->age = age;
        id = ++counter;
        cout << "Person constructor called" << endl;
    }
    void display() {
        cout << "ID: " << id << "\nPerson :" << name << "\nAge" << age << endl;
    }
    ~Person() {
        cout << "Parent destructor is called" << endl;
    }
};
int Person::counter = 0;
class Employee :public Person {
    string position;
    int salary;
public:
    Employee() :Person() {
        position = "";
        salary = 0;
        cout << "Employee default constructor is called" << endl;
    }
    Employee(string name, int age, string position, int salary) :Person(name, age) {
        this->position = position;
        this->salary = salary;
        cout << "Employee constructor is called" << endl;
    }
    void display() {
        cout << "Employee Name: " << name << "\nAge: " << age << "\nPosition: " << position << "\nSalary: " << salary << endl;
    }
    ~Employee() {
        cout << "Child destructor is called" << endl;

    }
};
int main()
{
    Employee emp("Salah", 22, "SWE", 50000);
    Employee emp2;
    emp.display();
    emp2.display();
}
