#include <stdlib.h>
#include <stdio.h>
#include "my_array.hpp"


My_array_in_cpp::My_array_in_cpp() : tab_(new int[_SIZE_INIT_])
{
}

void My_array_in_cpp::set_an_element(int elem){
        if (size_ == capacity_){
        capacity_ += _SIZE_TO_ADD_;
        tab_ = (int*) realloc(tab_,capacity_ * sizeof(int));
        if (tab_ == NULL){
            printf("Cannot allocate memory\n");
            exit(EXIT_SUCCESS);
        }
    }
    tab_[size_++] = elem;
}

int My_array_in_cpp::get_an_element(size_t nb){
    if (nb<size_) {
        return tab_[nb];
    }
            printf("Cannot get element\n");
            exit(EXIT_SUCCESS);
}

size_t My_array_in_cpp::get_size(){
    return size_;
}

size_t My_array_in_cpp::get_capacity(){
    return capacity_;
}