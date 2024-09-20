#pragma once
#include <stdlib.h>

/*A partir du squelette ci-dessous programmer l’implémentation d’une interface permettant l'implémentation d’un tableau dont la taille
peut évoluer en fonction des éléments qui y sont ajoutés. Pour cela, la structure a deux champs : la taille et sa capacité. La taille est le
nombre d’éléments dans le tableau et la capacité est le nombre d’éléments que peut contenir le tableau. La taille est nécessairement
inférieure ou égale à la capacité. Quand la taille est égale à la capacité, la zone de stockage initialement allouée avec une taille de
_SIZE_INIT_ doit être agrandie de _SIZE_TO_ADD_.*/

#define _SIZE_INIT_ 10
#define _SIZE_TO_ADD_ _SIZE_INIT_

#ifdef __cplusplus
extern "C"{
#endif

typedef struct My_array_in_C{
    int *tab;
    size_t size;
    size_t capacity;
} My_array_in_C;

My_array_in_C allocate_my_array();
void set_an_element(My_array_in_C *my_array,int elem);

#ifdef __cplusplus
}
#endif