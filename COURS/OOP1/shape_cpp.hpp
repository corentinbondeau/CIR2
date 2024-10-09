#pragma once

enum struct Color : unsigned char
{
   blue = 0,
   green = 1,
   orange = 2,
   brown = 3
};

struct Shape_cpp
{
    virtual float get_area() = 0;
    virtual void print_data() = 0;
};

struct Rectangle : Shape_cpp
{
    float length_;
    float width_;
    float get_area();
    void print_data();
    Rectangle(const float &length, const float &width);
};

struct Triangle : Shape_cpp
{
    float length_side1_;
    float length_side2_;
    float length_side3_;
    float get_area();
    void print_data();
    Triangle(const float &length_side1, const float &length_side2,
             const float &length_side3);
};

struct Circle : Shape_cpp
{
    float radius_;
    float get_area();
    virtual void print_data();
    Circle(const float &radius);
};

struct Square : Shape_cpp
{
	float length_;
	float get_area();
	void print_data();
	Square(const float& lenght);
};
