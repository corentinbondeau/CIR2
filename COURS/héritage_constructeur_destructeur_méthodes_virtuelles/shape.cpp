#define _USE_MATH_DEFINES // for C with VS
#include <math.h>
#include <utility>

#include "shape.hpp"

#include "shape.hpp"

unsigned Shape::global_count_ = 0;

Shape::Shape(const Color &color) : color_(color)
{
    count_ = global_count_++;
}

Shape_pure_virtual::Shape_pure_virtual(const Color &color) : Shape(color) {}

Shape_virtual::Shape_virtual(const Color &color) : Shape(color) {}

Rectangle_pure_virtual::Rectangle_pure_virtual(const float &length, const float &width, const Color &color) : Shape_pure_virtual(color), length_(length), width_(width)
{
}

Rectangle::Rectangle(const float &length, const float &width, const Color &color) : Shape(color), length_(length), width_(width)
{
}

void Shape_virtual::print_data()
{
    cout << "Shape type : Shape_virtual"<< " with color : " << color_  << endl;
}

void Rectangle_pure_virtual::print_data()
{
    cout << "Shape type : Rectangle_pure_virtual with sides : " << length_ << " " << width_ << " with color : " << color_ << endl;
}

Rectangle_virtual::Rectangle_virtual(const float &length, const float &width, const Color &color) : Shape_virtual(color), length_(length), width_(width)
{
}

void Rectangle_virtual::print_data()
{
    cout << "Shape type : Rectangle_virtual with sides : " << length_ << " " << width_ << " with color : " << color_ << endl;
}

void Rectangle::print_data()
{
    cout << "Shape type : Rectangle with sides : " << length_ << " " << width_ << " with color : " << color_ << endl;
}

void Shape::print_data()
{
    cout << "Shape type : Base"<< " with color : " << color_ << endl;
}

std::ostream &operator<<(std::ostream &os, const Color &color)
{
    os << static_cast<int>(std::to_underlying(color));
    return os;
}

