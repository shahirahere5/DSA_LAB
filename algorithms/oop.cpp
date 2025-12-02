#include <iostream>
using namespace std;

// Encapsulation + Abstraction
class Person {
private:
    string name;
    int age;
public:
    void setData(string n, int a) { name = n; age = a; }
    void display() { cout << "Name: " << name << ", Age: " << age << endl; }
};

// Inheritance
class Student : public Person {
private:
    int rollNo;
public:
    void setRollNo(int r) { rollNo = r; }
    void show() { display(); cout << "Roll No: " << rollNo << endl; }
};

// Polymorphism
class Shape {
public:
    virtual void area() { cout << "Area of shape" << endl; }
};

class Rectangle : public Shape {
private:
    int width, height;
public:
    Rectangle(int w, int h) : width(w), height(h) {}
    void area() { cout << "Rectangle area: " << width*height << endl; }
};

int main() {
    Person p;
    p.setData("Alice", 20);
    p.display();
    cout << "-------------" << endl;

    Student s;
    s.setData("Bob", 18);
    s.setRollNo(101);
    s.show();
    cout << "-------------" << endl;

    Shape* sh = new Rectangle(5, 10);
    sh->area();
    delete sh;
}
