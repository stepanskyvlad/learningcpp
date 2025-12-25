// Section 16
// Pure virtual functions and abstract base classes
/**
 * Abstract Class
An Abstract Class is a conceptual blueprint that cannot be 
 instantiated (you cannot create a physical object from it).
Its primary purpose is to define a common interface and shared
 logic for a family of related classes.

Role: It acts as a "contract." It tells all derived classes:
"You must have these specific behaviors, but how you perform them is up to you."

Defining Feature: In C++, it is defined by the presence of
 at least one pure virtual function (a function declared with = 0).

Usage: Used to represent broad, generic categories (e.g., Shape, Animal, or Document).

We can use pointers and references to dynamically refer tp concrete classes dereived from them:
Example:
```
void get_square(Shape &shape);
```
 * Concrete Class
A Concrete Class is a complete, "finished" class that can be used to
 create real objects in memory.
It provides specific implementations for
 every action it is capable of performing.

Role: It is the functional realization of an idea.

Requirement: It must implement (fill in the logic for) 
all the abstract/pure virtual functions it inherited from its parent classes.

Usage: Used to represent specific, well-defined entities (e.g., Circle, Dog, or PDF_File).
 */
#include <iostream>
#include <vector>

class Shape {			// Abstract Base class
private:
       // attributes common to all shapes
public:
      virtual void draw() = 0;	 // pure virtual function
      virtual void rotate() = 0;   // pure virtual function
      virtual ~Shape() { }
};

class Open_Shape: public Shape {    // Abstract class
public:
    virtual ~Open_Shape() { }
};

class Closed_Shape : public Shape {  // Abstract class
public:
    virtual ~Closed_Shape() { };
};

class Line: public Open_Shape {     // Concrete class
public:
    virtual void draw() override {
        std::cout << "Drawing a line" << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotating a line" << std::endl;
    }
    virtual ~Line() {}
};

class Circle: public Closed_Shape {     // Concrete class
public:
    virtual void draw() override {
        std::cout << "Drawing a circle" << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotating a circle" << std::endl;
    }
    virtual ~Circle() {}
};

class Square: public Closed_Shape {     // Concrete class
public:
    virtual void draw() override {
        std::cout << "Drawing a square" << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotating a square" << std::endl;
    }
    virtual ~Square() {}
};


void screen_refresh(const std::vector<Shape *> &shapes) {
    std::cout << "Refreshing" << std::endl;
    for (const auto p: shapes) 
        p->draw();
}

int main() {
//    Shape s;
//    Shape *p = new Shape();

//        Circle c;
//        c.draw();

//    Shape *ptr = new Circle();
//    ptr->draw();
//    ptr->rotate();

    Shape *s1 = new Circle();
    Shape *s2 = new Line();
    Shape *s3 = new Square();
    
    std::vector<Shape *> shapes {s1,s2,s3};
    
//    for (const auto p: shapes) 
//        p->draw();
        
    screen_refresh(shapes);
    
    delete s1;
    delete s2;
    delete s3;
    
    return 0;
}
