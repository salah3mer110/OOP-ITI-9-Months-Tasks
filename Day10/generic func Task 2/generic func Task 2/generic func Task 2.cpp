#include <iostream>
using namespace std;

template <class T>
T sum(const T& a, const T& b) {
    return a + b;
}

class Complex {
    float real, imag;
    static int counter;
public:
    Complex(): real(0), imag(0) {};

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

    Complex operator+(const Complex& s) const {
        return Complex(real + s.real, imag + s.imag);
    }

    Complex operator-(Complex& s) {
        return Complex(real - s.real, imag - s.imag);
    }

    Complex operator*(Complex& s) {
        return Complex(real * s.real - imag * s.imag, real * s.imag + imag * s.real);
    }

    Complex operator/(Complex& s) {
        float denomorator = s.real * s.real + s.imag * s.imag;
        return Complex((real * s.real + imag * s.imag) / denomorator, (imag * s.real - real * s.imag) / denomorator);
    }

    //less than
    bool operator <(Complex& s) {
        if (real < s.real) return true;
        (real == s.real) ? imag < s.imag : false;
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

    friend ostream& operator <<(ostream& out,const Complex& s);
    friend istream& operator>>(istream& in, Complex& s);

    static int showCounter() {
        return counter;
    }
    ~Complex() {
        cout << "destructor is Called" << endl;
        counter--;
    }
};
ostream& operator <<(ostream& out,const Complex& s) {
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

int main() {
    cout << sum(5, 10) << endl;
    cout << sum(2.5, 3.7) << endl;
    cout << sum(1.1, 2.2) << endl;

    Complex c1(1, 2), c2(3, 4);
    cout << sum(c1, c2) << endl;
    return 0;
}
