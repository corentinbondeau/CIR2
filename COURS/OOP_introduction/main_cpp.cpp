#include <stdlib.h>
#include <stdio.h>
#include "shape_cpp.hpp"


int main()
{
    const int const_size = 5;
    Rectangle rectangle(5.f, 10.f); // length_ = 5.f, width_ = 10.f;
    printf("area Shape : %f...\n", rectangle.get_area());
    rectangle.print_data();

    auto p_rectangle = &rectangle; // Rectangle *p_rectangle = &rectangle;
    printf("area Shape : %f...\n", p_rectangle->get_area());
    p_rectangle->print_data();

    Shape_cpp *p_shape = &rectangle;
    printf("area Shape : %f...\n", p_shape->get_area());
    p_shape->print_data();

    auto tab_shape = new Shape_cpp *[const_size]; 
    // C++ equivalent to Shape_cpp **tab_shape  = (Shape_cpp **) malloc(_SIZE_ * sizeof(Shape_cpp*)) with some additions

    tab_shape[0] = new Rectangle(5, 10);
    tab_shape[1] = new Triangle(5, 12, 15);
    tab_shape[2] = new Circle(20);
    tab_shape[3] = new Square_as_shape(20);
    tab_shape[4] = new Square_as_rectangle(20);

    for (int i = 0; i < const_size; ++i)
    {
        printf("area Shape n° %d : %f...\n", i + 1, tab_shape[i]->get_area());
        tab_shape[i]->print_data();
    }

    for (int i = 0; i < const_size; ++i)
    {
        delete tab_shape[i];
    }
    delete [] tab_shape;
   
    return EXIT_SUCCESS;
}
