// Task 1 Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
template <class T>
class Stack {
    int top, size;
    T* ptr;
    static int counter;

public:
    Stack() = delete;

    Stack(int size = 5) {
        this->size = size;
        top = -1;
        ptr = new T[size];
        counter++;
    }

    Stack(const Stack& s) {
        top = s.top;
        size = s.size;
        ptr = new T[size];
        for (int i = 0; i <= top; i++)
            ptr[i] = s.ptr[i];
        counter++;
    }

    Stack(Stack&& s) noexcept {
        top = s.top;
        size = s.size;
        ptr = s.ptr;
        s.ptr = nullptr;
        s.top = -1;
        s.size = 0;
        counter++;
    }

    Stack& operator=(const Stack& s) {
        if (this != &s) {
            delete[] ptr;
            top = s.top;
            size = s.size;
            ptr = new T[size];
            for (int i = 0; i <= top; i++)
                ptr[i] = s.ptr[i];
        }
        return *this;
    }

    Stack& operator=(Stack&& s) noexcept {
        if (this != &s) {
            delete[] ptr;
            top = s.top;
            size = s.size;
            ptr = s.ptr;
            s.ptr = nullptr;
            s.top = -1;
            s.size = 0;
        }
        return *this;
    }

    T& operator[](int index) {
        if (index < 0 || index > top)
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
    void showElements() const {
        if (top == -1) {
            cout << "Empty\n";
            return;
        }
        cout << "Stack: ";
        for (int i = 0; i <= top; i++)
            cout << ptr[i] << " ";
        cout << "\n";
    }

    static int showCounter() { return counter; }

    ~Stack() {
        delete[] ptr;
        counter--;
    }
};

template <class T>
int Stack<T>::counter = 0;

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

    Complex operator+(Complex& s) {
        return Complex(this->real + s.real, this->imag + s.imag);
    }

    Complex operator-(Complex& s) {
        return Complex(this->real - s.real, this->imag - s.imag);
    }

    Complex operator*(Complex& s) {
        return Complex(this->real * s.real - imag * s.imag, this->real * s.imag + imag * s.real);
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
ostream& operator <<(ostream& out, Complex& s) {
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
    Stack<int> s1(3);
    s1.push(10).push(20).push(30);
    s1.showElements();

    Stack<float> s2(3);
    s2.push(1.1f).push(2.2f).push(3.3f);
    s2.showElements();

    Stack<char> s3(3);
    s3.push('A').push('B').push('C');
    s3.showElements();

    Stack<Complex> s4(3);
    s4.push(Complex(1, 2)).push(Complex(3, 4)).push(Complex(5, 6));
    s4.showElements();

    Stack<int> s5 = s1;
    s5.showElements();

    Stack<int> s6 = move(s1);
    s6.showElements();

    cout << "Total active stacks: " << Stack<int>::showCounter() << endl;

}

