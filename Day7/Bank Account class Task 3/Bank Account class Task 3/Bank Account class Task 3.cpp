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
	BankAccount(string accountHolder,float balance) {
		while(balance < 0){
			cout << "Please re-enter balance" << endl;
			cin >> balance;
		}
		counter++;
		this->accountHolder =accountHolder;
		accountNumber = counter;
		this->balance = balance;
		cout << "param constructor called" << endl;
	}
	BankAccount& deposit(float amount) {
		balance += amount;
		cout << "Your balance after deposit is: " <<balance << endl;
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
		cout << "balance: " << balance<< endl;
	}
	static int showCounter() {
		return counter;
	}
	~BankAccount() {
		cout << "Destructor called\n";
	}

};
int BankAccount::counter = 0;

int main()
{
	BankAccount b;
	BankAccount b1("Salah", -3000);
	b.deposit(1000).withdraw(500);
	b1.deposit(1000).withdraw(500).showAccount();
	cout << "Account 2 balance = " << b1.getBalance() << endl;
	cout << "count= " << b.showCounter() << endl;

}
