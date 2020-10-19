#include <iostream>

using namespace std;

class Rectangle {
private:
    int length;
    int breadth;
public:
    Rectangle();
    Rectangle(int length, int breadth);
    Rectangle(const Rectangle& r);
    int getLength() { return length; };
    int getBreadth() { return breadth; };
    void setLength(int length) { this->length = length; };
    void setBreadth(int breadth) { this->breadth = breadth; };
    int area();
    int perimeter();
    bool isSquare();
    ~Rectangle();
};

Rectangle::Rectangle() : length(10), breadth(10) {};
Rectangle::Rectangle(int length, int breadth) : length(length), breadth(breadth) {};
Rectangle::Rectangle(const Rectangle& r) : length(r.length), breadth(r.breadth) {};
int Rectangle::area() { return length * breadth; }
int Rectangle::perimeter() { return length * 2 + breadth * 2; }
bool Rectangle::isSquare() { return length == breadth ? true : false; }
Rectangle::~Rectangle() {};

int main()
{
    Rectangle r2(20, 20);
    Rectangle r1 = r2;

    cout << "Area: " << r1.area() << endl;
    if (r1.isSquare()) cout << "Yes" << endl;

    return EXIT_SUCCESS;
}