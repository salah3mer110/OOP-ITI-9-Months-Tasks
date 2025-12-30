// Task 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Stack {
	int top, size;
	int* ptr;
	static int counter;
public:
	Stack() {
		top = -1;
		size = 5;
		ptr = new int[size];
		cout << "default constructor called" << endl;
		counter++;
	}
	Stack(int size) {
		top = -1;
		this->size = size;
		ptr = new int[size];
		cout << "param constructor called"<<endl;
		counter++;
	}
	Stack & pop() {
		if (top == -1) {
			cout << "Stack is empty" << endl;
			return *this;
		}
		 ptr[top--];
		return *this;
	}
	Stack& push(int value) {
		if (top == size-1) {
			cout << "Stack is Full" << endl;
			return *this;
		}
		ptr[++top] = value;
		return *this;
	}

	void showElements() {
		if (top != -1) {
			cout << "values in stack are: ";
			for (int i = 0; i <= top; i++)
			{
				cout << *(ptr + i) << " ";
			}
			cout << "\n";
		}
		else
			cout << "No elements to show\n";
	}
	
	static int showCounter() {
		return counter;
	}

	~Stack() {
		cout << "Destructor called" << endl;
	}

};
int Stack::counter = 0;

int main()
{
	Stack s;
	Stack s2(5);
	s.push(10).push(20).push(30).pop().showElements();
	s2.push(10).push(20).push(30).push(40).pop().pop().pop().pop().pop().showElements();
	cout << "count = " << s.showCounter()<<endl;
}
