#include <stdlib.h>
#include <stdio.h>
#include "my_array.h"


My_array_in_C allocate_my_array()
{
    My_array_in_C array;
    array.size = 0;
    array.capacity = _SIZE_INIT_;
    array.tab = (int *)malloc(array.capacity * sizeof(int));
    return array;
}

void set_an_element(My_array_in_C *my_array, int elem){
    if (my_array->size == my_array->capacity){
        my_array->capacity += _SIZE_TO_ADD_;
        my_array->tab = (int*) realloc(my_array->tab, my_array->capacity * sizeof(int));
        if (my_array->tab == NULL){
            printf("Cannot allocate memory\n");
            exit(EXIT_SUCCESS);
        }
    }
    my_array->tab[my_array->size++] = elem;
}
