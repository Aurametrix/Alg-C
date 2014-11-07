#include <iostream.h>
class Rectangle 
{ 
private: 
    int width; 
    int length; 
    int area; 
public: 
    Rectangle(): 
    width(0), 
    length(0), 
    area(0) {}

Rectangle(int w, int l): 
    width(w), 
    length(l), 
    area(w*l) {}

Rectangle& operator = (Rectangle const& rectangle) 
{ 
    if(this != &rectangle) 
    { 
        width = rectangle.width; 
        length = rectangle.length; 
        area = rectangle.area; 
    } 
    return *this; 
}

// Simplifying the routine parameter list by using structured variables.

int CombinedArea(Rectangle a) 
{ 
    return area + a.area; 
}

void Display() 
{ 
    cout<<"Width of rectangle: "<<width<<endl; 
    cout<<"Length of rectangle: "<<length<<endl; 
    cout<<"Area of rectangle: "<<area<<endl<<endl; 
} 
};

main() 
{ 
    Rectangle first(5, 6); 
    Rectangle second(0, 0);

    second = first;

    first.Display(); 
    second.Display();

    cout<<"Combined area of both rectangles: "<<first.CombinedArea(second)<<endl; 
}
