// Bank Account class Task 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class BankAccount {
	string accountHolder;
	int accountNumber;
	float balance;
	static int counter;
public:
	BankAccount() {
		counter++;
		accountHolder = "";
		accountNumber = counter;
		balance = 0;
		cout << "default constructor called" << endl;
	}
	BankAccount(string accountHolder, float balance) {
		while (balance < 0) {
			cout << "Please re-enter balance" << endl;
			cin >> balance;
		}
		counter++;
		this->accountHolder = accountHolder;
		accountNumber = counter;
		this->balance = balance;
		cout << "param constructor called" << endl;
	}
	BankAccount(BankAccount& s) {
		accountHolder = s.accountHolder;
		balance = s.balance;
		accountNumber = s.accountNumber;
		counter++;
		cout << "copy constructor called" << endl;
	}
	BankAccount(BankAccount&& s) {
		accountHolder = s.accountHolder;
		balance = s.balance;
		accountNumber = s.accountNumber;
		cout << "move constructor called" << endl;
	}
	BankAccount operator = (BankAccount& s) = delete;
	BankAccount operator = (BankAccount&& s) {
		if (this != &s) {
		accountHolder = s.accountHolder;
		balance = s.balance;
		accountNumber = s.accountNumber;
		cout << "move operator called" << endl;
		}
		return *this;
	}
	BankAccount& deposit(float amount) {
		balance += amount;
		cout << "Your balance after deposit is: " << balance << endl;
		return *this;
	}
	BankAccount& withdraw(float amount) {
		if (balance < amount) {
			cout << "Insufficient funds to withdraw\n";
			return *this;
		}
		balance -= amount;
		cout << "Your balance after withdraw is: " << balance << endl;
		return *this;
	}

	float getBalance() {
		return balance;
	}
	void showAccount() {
		cout << "ID: " << accountNumber << endl;
		cout << "Name: " << accountHolder << endl;
		cout << "balance: " << balance << endl;
	}
	friend ostream& operator<<(ostream& out, BankAccount& b);
	friend istream& operator>>(istream& in, BankAccount& b);

	static int showCounter() {
		return counter;
	}
	~BankAccount() {
		cout << "Destructor called\n";
		counter--;
	}

};
ostream& operator<<(ostream& out, BankAccount& b) {
	out << b.accountNumber<<"\n";
	out << b.accountHolder<<"\n";
	out << b.balance<<"\n";
	return out;
}
istream& operator>>(istream& in, BankAccount& b) {
b.accountNumber=b.counter;
	cout << "Enter Name:\n";
	in >> b.accountHolder;
	cout << "Enter Balance:\n";
	in >> b.balance;
	return in;
}
int BankAccount::counter = 0;

int main() {
	BankAccount b1;
	cout << "Enter details for account 1:" << endl;
	cin >> b1;

	BankAccount b2("Salah", -3000); 

	b1.deposit(1000).withdraw(500);
	b2.deposit(1000).withdraw(500);

	cout << "\nAccount 1 details:" << endl;
	b1.showAccount();

	cout << "\nAccount 2 details:" << endl;
	b2.showAccount();

	cout << "\nUsing << operator to show accounts:" << endl;
	cout << b1 << endl;
	cout << b2 << endl;

	cout << "\nBalance of account 2: " << b2.getBalance() << endl;
	cout << "Total accounts created: " << b2.showCounter() << endl;

	BankAccount b3 = move(b2); // Move constructor
	cout << "\nAfter moving account 2 to account 3:" << endl;
	cout << b3 << endl;

	BankAccount b4;
	b4 = move(b1); // Move assignment
	cout << "\nAfter moving account 1 to account 4:" << endl;
	cout << b4 << endl;

	cout << "Current total accounts: " << BankAccount::showCounter() << endl;

	return 0;
}
