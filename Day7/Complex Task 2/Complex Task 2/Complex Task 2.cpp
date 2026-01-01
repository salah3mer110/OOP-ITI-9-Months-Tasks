// Complex Task 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Complex {
    float real, imag;
    static int counter;
public:
    Complex() = default;

    Complex(float x) {
        real = imag = x;
        counter++;
    }
    Complex(float x, float y) {
        real = x;
        imag = y;
        counter++;
    }
    void printComplex() {
        if (real == 0 && imag == 0) {
            cout << "0" << endl;
        }
        else if (imag == 0) {
            cout << real << endl;
        }
        else if (real == 0) {
            cout << imag << "i" << endl;
        }
        else {
            cout << real<<(imag > 0 ? " + " : " - ")<< abs(imag) << "i" << endl;
        }
    }

    static int showCounter() {
        return counter;
    }
    ~Complex() {
        cout << "destructor is Called" << endl;
    }
};
int Complex::counter = 0;
int main()
{
    Complex s;
    Complex s1(0);
    Complex s2(0,-3);
    s.printComplex();
    s1.printComplex();
    s2.printComplex();
    cout << "count= " << s.showCounter() << endl;

}
