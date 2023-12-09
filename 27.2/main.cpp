#include <iostream>
#include <string>
#include <math.h>

class BoundingRectangle {
    double upperLeftX;
    double upperLeftY;
    double width;
    double height;

public:
    BoundingRectangle(double x, double y, double w, double h)
            : upperLeftX(x), upperLeftY(y), width(w), height(h) {}

    double getUpperLeftX() const {
        return upperLeftX;
    }

    double getUpperLeftY() const {
        return upperLeftY;
    }

    double getWidth() const {
        return width;
    }

    double getHeight() const {
        return height;
    }
};

class Shape {
    double centerX;
    double centerY;
    std::string color;

public:
    Shape(double x = 0.0, double y = 0.0, const std::string &color_user = "") : centerX(x), centerY(y), color(color_user) {}

    double getCenterX() const {
        return centerX;
    }

    double getCenterY() const {
        return centerY;
    }

    std::string getColor() const {
        return color;
    }

    void setCenterX(double x) {
        centerX = x;
    }

    void setCenterY(double y) {
        centerY = y;
    }

    void setColor(const std::string &color_user) {
        color = color_user;
    }

    double getArea() const {
        return 0.0;
    }

    virtual void printDetails() const {
        std::cout << "Center: (" << getCenterX() << ", " << getCenterY() << "), Color: " << getColor() << ", ";
    }

    virtual BoundingRectangle getBoundingRectangle() const = 0;
};

class Circle : public Shape {
    double radius;

public:
    Circle(double r = 0.0) : radius(r) {}

    double getRadius() const {
        return radius;
    }

    double getArea() const {
        return atan(1) * 4 * getRadius() * getRadius();
    }

    void printDetails() const {
        Shape::printDetails();
        std::cout << "Radius: " << getRadius() << ", Area: " << getArea() << std::endl;
    }

    BoundingRectangle getBoundingRectangle() const override {
        double side = 2 * getRadius();
        return BoundingRectangle(getCenterX() - getRadius(), getCenterY() - getRadius(), side, side);
    }
};

class Square : public Shape {
    double sideLength;

public:
    Square(double len = 0.0) : sideLength(len) {}

    double getSideLength() const {
        return sideLength;
    }

    double getArea() const {
        return getSideLength() * getSideLength();
    }

    void printDetails() const {
        Shape::printDetails();
        std::cout << "Side Length: " << getSideLength() << ", Area: " << getArea() << std::endl;
    }

    BoundingRectangle getBoundingRectangle() const override {
        return BoundingRectangle(getCenterX() - getSideLength() / 2, getCenterY() - getSideLength() / 2, getSideLength(), getSideLength());
    }
};

class Triangle : public Shape {
    double sideLength;

public:
    Triangle(double len = 0.0) : sideLength(len) {}

    double getSideLength() const {
        return sideLength;
    }

    double getArea() const {
        return (getSideLength() * getSideLength() * std::sqrt(3)) / 4;
    }

    void printDetails() const {
        Shape::printDetails();
        std::cout << "Side Length: " << getSideLength() << ", Area: " << getArea() << std::endl;
    }

    BoundingRectangle getBoundingRectangle() const override {
        return BoundingRectangle(getCenterX() - getSideLength() / 2, getCenterY() - (getSideLength() * std::sqrt(3)) / 2, getSideLength(), getSideLength() * std::sqrt(3) / 2);
    }
};

class Rectangle : public Shape {
    double width;
    double height;

public:
    Rectangle(double w = 0.0, double h = 0.0) : width(w), height(h) {}

    double getWidth() const {
        return width;
    }
    double getHeight() const {
        return height;
    };

    double getArea() const {
        return getWidth() * getHeight();
    }

    void printDetails() const {
        Shape::printDetails();
        std::cout << "Width: " << getWidth() << ", Height: " << getHeight() << ", Area: " << getArea() << std::endl;
    }

    BoundingRectangle getBoundingRectangle() const override {
        return BoundingRectangle(getCenterX() - getWidth() / 2, getCenterY() - getHeight() / 2, getWidth(), getHeight());
    }
};

int main() {
        std::string command;
        std::cout << "Enter a command (circle, square, triangle, rectangle):  ";
        std::cin >> command;

        Shape *shape = nullptr;

        if (command == "circle") {
            double centerX, centerY, radius;
            std::string color;

            std::cout << "Enter center X coordinate: ";
            std::cin >> centerX;

            std::cout << "Enter center Y coordinate: ";
            std::cin >> centerY;

            std::cout << "Enter color (Red, Blue, Green): ";
            std::cin >> color;

            std::cout << "Enter radius: ";
            std::cin >> radius;

            shape = new Circle(radius);
            shape->setCenterX(centerX);
            shape->setCenterY(centerY);
            shape->setColor(color);
        } else if (command == "square") {
            double centerX, centerY, sideLength;
            std::string color;

            std::cout << "Enter center X coordinate: ";
            std::cin >> centerX;

            std::cout << "Enter center Y coordinate: ";
            std::cin >> centerY;

            std::cout << "Enter color (Red, Blue, Green): ";
            std::cin >> color;

            std::cout << "Enter side length: ";
            std::cin >> sideLength;

            shape = new Square(sideLength);
            shape->setCenterX(centerX);
            shape->setCenterY(centerY);
            shape->setColor(color);
        } else if (command == "triangle") {
            double centerX, centerY, sideLength;
            std::string color;

            std::cout << "Enter center X coordinate: ";
            std::cin >> centerX;

            std::cout << "Enter center Y coordinate: ";
            std::cin >> centerY;

            std::cout << "Enter color (Red, Blue, Green): ";
            std::cin >> color;

            std::cout << "Enter side length: ";
            std::cin >> sideLength;

            shape = new Triangle(sideLength);
            shape->setCenterX(centerX);
            shape->setCenterY(centerY);
            shape->setColor(color);
        } else if (command == "rectangle") {
            double centerX, centerY, width, height;
            std::string color;

            std::cout << "Enter center X coordinate: ";
            std::cin >> centerX;

            std::cout << "Enter center Y coordinate: ";
            std::cin >> centerY;

            std::cout << "Enter color (Red, Blue, Green): ";
            std::cin >> color;

            std::cout << "Enter width: ";
            std::cin >> width;

            std::cout << "Enter height: ";
            std::cin >> height;

            shape = new Rectangle(width, height);
            shape->setCenterX(centerX);
            shape->setCenterY(centerY);
            shape->setColor(color);
        } else {
            std::cout << "Unknown command. Please enter a valid shape command." << std::endl;
        }

    if (shape != nullptr) {
        shape->printDetails();
        BoundingRectangle rect = shape->getBoundingRectangle();
        std::cout << "Bounding Rectangle: Upper Left Corner (" << rect.getUpperLeftX() << ", " << rect.getUpperLeftY() << "), Width: " << rect.getWidth() << ", Height: " << rect.getHeight() << std::endl;
        delete shape;
    }
}
