// Complex Task 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
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
            cout << real << (imag > 0 ? " + " : " - ") << abs(imag) << "i" << endl;
        }
    }

    Complex operator+(Complex &s) {
        return Complex(this->real + s.real, this->imag + s.imag);
    }

    Complex operator-(Complex& s) {
        return Complex(this->real - s.real, this->imag - s.imag);
    }

    Complex operator*(Complex& s) {
        return Complex(this->real * s.real- imag * s.imag, this->real * s.imag+imag*s.real);
    }

    Complex operator/(Complex& s) {
        float denomorator = s.real * s.real + s.imag * s.imag;
        return Complex((real * s.real + imag * s.imag)/denomorator, (imag * s.real - real * s.imag) /denomorator);
    }

    //less than
    bool operator <(Complex& s) {
        if (real < s.real) return true;
         (real == s.real)? imag < s.imag:false;
    }
    
    //greater than
    bool operator >(Complex& s) {
        if (real > s.real) return true;
        (real == s.real) ? imag > s.imag : false;
    }

    //increment
    Complex& operator ++() { 
        real++;
        imag++;
        return *this;
    }
    Complex operator ++(int) {
        Complex temp = *this;
        real++;
        imag++;
        return temp;
    }

    //decrement
    Complex& operator --() {
        real--;
        imag--;
        return *this;
    }
    Complex operator --(int) {
        Complex temp = *this;
        real--;
        imag--;
        return temp;
    }
   operator double() {
        return static_cast<double>(real);
   }

   friend ostream& operator <<(ostream& out, Complex& s);
   friend istream& operator>>(istream& in, Complex& s);

    static int showCounter() {
        return counter;
    }
    ~Complex() {
        cout << "destructor is Called" << endl;
        counter--;
    }
};
ostream& operator <<(ostream& out,Complex& s) {
    if (s.imag >= 0)
        out << s.real << " + " << s.imag << "i";
    else
        out << s.real << s.imag << "i";
    return out;
}
istream& operator>>(istream& in, Complex& s) {
    cout << "Enter Real Num:\n";
    in >> s.real;
    cout << "Enter Imag Num:\n";
    in >> s.imag;
    return in;
}
int Complex::counter = 0;
int main()
{
    Complex c1(3, 4), c2(3, -2);

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex prod = c1 * c2;
    Complex div = c1 / c2;

    cout << "\nSum: " << sum << endl;
    cout << "Difference: " << diff << endl;
    cout << "Product: " << prod << endl;
    cout << "division: " << div << endl;

    cout << "\nComparisons:\n";
    cout << "c1 < c2 ? " << (c1 < c2) << endl;
    cout << "c1 > c2 ? " << (c1 > c2) << endl;

    cout << "\nIncrement/Decrement:\n";
    cout << "++c1 = " << ++c1 << endl;
    cout << "c1++ = " << c1++ << endl;
    cout << "--c2 = " << --c2 << endl;
    cout << "c2-- = " << c2-- << endl;

    cout << "\nType casting to double:\n";
    double castC1 = c1;
    cout << "c1 = " << castC1 << endl;

    cout << "\nEnter a new complex number:\n";
    Complex c3;
    cin >> c3;
    cout << "You entered: " << c3 << endl;

    cout << "\nNumber of Complex objects created: " << Complex::showCounter() << endl;

    return 0;
}
