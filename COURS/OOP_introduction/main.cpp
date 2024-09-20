#include <stdio.h>
#include "my_array.h"
#include "my_array.hpp"

int main()
{
    My_array_in_C my_array = allocate_my_array();
    for (size_t i = 0; i < my_array.size; ++i)
    {
        set_an_element(&my_array, (int)i);
    }

    for (long long unsigned i = 0; i < my_array.size; ++i)
    {
        printf("Element n° %llu = %i\n", i, my_array.tab[i]);
    }
}