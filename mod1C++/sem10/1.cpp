#include <iostream>
#include <vector>
#include <string>
#include <cmath>


enum class ShapeType {
    CIRCLE,
    RECTANGLE,
    TRIANGLE,
};

union ShapeData {
    struct { float radius; } circle;
    struct  { float width, height; } rectangle;
    struct  { float a, b, c;} triangle;

};

struct Shape {
    ShapeType type;
    ShapeData data;
};

float area(const Shape& sh) {
    switch (sh.type) {
        case ShapeType::CIRCLE:
            return std::numbers::pi * sh.data.circle.radius * sh.data.circle.radius;
        case ShapeType::RECTANGLE:
            return sh.data.rectangle.width * sh.data.rectangle.height;
        default:
            float a = sh.data.triangle.a;
            float b = sh.data.triangle.b;
            float c = sh.data.triangle.c;
            float p = (a + b + c) / 2.0;
            return std::sqrt(p* (p-a)*(p-b)*(p-c));
    }
}



void printShape(const Shape& sh) {
    switch (sh.type) {
        case ShapeType::CIRCLE:
            std::cout << "Circle: radius = " << sh.data.circle.radius << '\n';
            break;
        case ShapeType::RECTANGLE:
            std::cout << "Rectangle: width = " << sh.data.rectangle.width
                    << " height = " << sh.data.rectangle.height << '\n';
            break;
        case ShapeType::TRIANGLE:
            std::cout << "Triangle: sides " << sh.data.triangle.a << " " << sh.data.triangle.b << " " << sh.data.triangle.c << '\n';
            break;
            
    }
    std::cout << "Area = " << area(sh) << std::endl;
}

int main() {
    Shape s1;
    s1.type = ShapeType::CIRCLE;
    s1.data.circle.radius = 10.0f;

    Shape s2;
    s2.type = ShapeType::RECTANGLE;
    s2.data.rectangle.width = 4.0f;
    s2.data.rectangle.height = 6.0f;

    Shape s3;
    s3.type = ShapeType::TRIANGLE;
    s3.data.triangle.a = 3.0f;
    s3.data.triangle.b = 4.0f;
    s3.data.triangle.c = 5.0f;

    std::vector<Shape> shapes = {s1, s2, s3};

    for (const auto& s : shapes) {
        printShape(s);
    }

    float total = 0.0f;
    for (const auto& s : shapes) {
        total += area(s);
    }
    std::cout << "Total area = " << total << "\n";
}