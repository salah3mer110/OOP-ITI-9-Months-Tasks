// Task Library.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Member {
    string name;
public:
    Member() : name("") { cout << "def Member constructor called\n"; }
    Member(string n) : name(n) { cout << "Memeber constructor called\n"; }
    string getName() { return name; }
};

class Author {
    string name;
    string nation;
public:
    Author() : name(""), nation("") { cout << "def Author constructor called\n"; }
    Author(string name, string nation) : name(name), nation(nation) { cout << "Author constructor called\n"; }
    Author(Author& a) { name = a.name; nation = a.nation; }
    void isMember(Member& m) { cout << "Author " << m.getName() << "is a member" << endl; }
    Author& operator=(Author& a) {
        if (this != &a) {
            name = a.name;
            nation = a.nation;
        }
        return *this;
    }
    string getAuthorName() { return name; }
};

class Book {
    string title;
    int year;
    Author author;
public:
    Book() : title(""), year(0), author("", "") {
        cout << "def Book constructor called\n";
    }
    Book(string title, int year, Author auth) : title(title), year(year), author(auth) {
        cout << "Book constructor called\n";
    }
    Book(Book& b) : title(b.title), year(b.year), author(b.author) {
        cout << "copy Book constructor called\n";
    }
    Book& operator=(Book& b) {
        if (this != &b) {
            title = b.title;
            year = b.year;
            author = b.author;
        }
        return *this;
    }
    string getTitle() { return title; }
    int getYear() { return year; }
    Author getAuthor() { return author; }
};

//dynamic
/*
class Book {
    string title;
    int year;
    Author* author;
public:
    Book() : title(""), year(0), author(nullptr) {}
    Book(string title, int year, Author* auth) : title(title), year(year) {
        author = new Author(*auth);
    }
    Book(const Book& b) : title(b.title), year(b.year) {
        author = new Author(*(b.author));
    }
    Book& operator=(const Book& b) {
        if (this != &b) {
            title = b.title;
            year = b.year;
            delete author;
            author = new Author(*(b.author));
        }
        return *this;
    }
    string getTitle() { return title; }
    int getYear() { return year; }
    Author* getAuthor() { return author; }
    ~Book() {
        delete author;
    }
};
*/

class Library {
    vector<Book*> books;
public:
    Library() = default;
    Library(vector<Book*>& b) : books(b) {
        cout << "Library Constructor called\n";
    }
    Library& addBooks(Book* b) {
        books.push_back(b); return *this;
    }
    void showLibraryBooks() {
        for (auto b : books) {
            cout << "Book Name: " << b->getTitle();
            cout << "\nBook Year: " << b->getYear();
            cout << "\nAuthor Name: " << b->getAuthor().getAuthorName();
            cout << "\n" << endl;
        }
    }
};

int main()
{
    /*Author* aPtr = new Author("Agatha Christie", "UK");
    Book b1("Murder on the Orient Express", 1934, aPtr);
    Book b2("Death on the Nile", 1937, aPtr);*/
    Author a("Agatha Christie", "UK");
    Book b1("Murder on the Orient Express", 1934, a);
    Book b2("Death on the Nile", 1937, a);
    Book b3 = b1;
    b3 = b2;

    vector<Book*> books;
    Library lib(books);
    lib.addBooks(&b1);
    lib.addBooks(&b2);
    lib.addBooks(&b3);
    lib.showLibraryBooks();

    //delete aPtr;
    //aPtr = nullptr;
}
