#pragma once
#include <stdlib.h>

#define _SIZE_INIT_ 10
#define _SIZE_TO_ADD_ _SIZE_INIT_

class My_array_in_cpp{
    private:
    int *tab_;
    size_t capacity_;
    size_t size_;
    public:
    My_array_in_cpp();
    size_t get_size();
    size_t get_capacity();
    void set_an_element(int elem);
    int get_an_element(size_t nb);
};