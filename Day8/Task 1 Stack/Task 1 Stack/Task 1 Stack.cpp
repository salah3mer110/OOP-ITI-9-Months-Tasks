// Task 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Stack {
	int top, size;
	int* ptr;
	static int counter;
public:
	Stack() = delete;
	Stack(int size=5) {
		top = -1;
		this->size = size;
		ptr = new int[size];
		cout << "param constructor called" << endl;
		counter++;
	}
	Stack(Stack& s) {
		cout << "copy constructor called" << endl;
		top = s.top;
		size = s.size;
		ptr = new int[size];
		for (int i = 0; i <= top; i++)
			ptr[i] = s.ptr[i];
		counter++;
	}

	Stack(Stack&& s) {
		cout << "Move constructor called" << endl;
		top = s.top;
		size = s.size;
		ptr = new int[size];
		ptr = s.ptr;
		s.ptr = nullptr;
		counter++;
	}

	Stack &operator=(Stack & s){
		if (this != &s) {
			delete []ptr;
			top = s.top;
			size = s.size;
			ptr = new int[size];
			for (int i = 0; i <= top; i++)
				ptr[i] = s.ptr[i];
			counter++;
		}
		return *this;
	}

	Stack& operator=(Stack&& s) {
		if (this != &s) {
			delete[]ptr;
			top = s.top;
			size = s.size;
			ptr = new int[size];
			ptr = s.ptr;
			s.ptr = nullptr;
			counter++;
		}
		return *this;
	}

	int &operator[](int index) {
		
		if (index<0 || index>top)
			throw out_of_range("Index out of range");
		return ptr[index];
	}

	Stack& pop() {
		if (top == -1) {
			cout << "Stack is empty" << endl;
			return *this;
		}
		ptr[top--];
		return *this;
	}
	Stack& push(int value) {
		if (top == size - 1) {
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
		delete []ptr;
		ptr = nullptr;
		counter--;
	}

};

int Stack::counter = 0;

int main()
{
	cout << "Creating stack s1" << endl;
	Stack s1(5);
	s1.push(10).push(20).push(30).showElements();

	cout << "Copying s1 to s2" << endl;
	Stack s2 = s1;
	s2.showElements();

	cout << "Modifying s2" << endl;
	s2[1] = 50;
	s2.showElements();

	cout << "Moving s2 to s3" << endl;
	Stack s3 =move(s2);
	s3.showElements();

	cout << "Popping elements from s3" << endl;
	s3.pop().pop().pop().pop();
	s3.showElements();

	cout << "Pushing elements to s3" << endl;
	s3.push(100).push(200);
	s3.showElements();

	cout << "Current stack count: " << Stack::showCounter() << endl;

	return 0;
}
