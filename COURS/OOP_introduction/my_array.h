#pragma once
#include <stdlib.h>

/*A partir du squelette ci-dessous programmer l�impl�mentation d�une interface permettant l'impl�mentation d�un tableau dont la taille
peut �voluer en fonction des �l�ments qui y sont ajout�s. Pour cela, la structure a deux champs : la taille et sa capacit�. La taille est le
nombre d��l�ments dans le tableau et la capacit� est le nombre d��l�ments que peut contenir le tableau. La taille est n�cessairement
inf�rieure ou �gale � la capacit�. Quand la taille est �gale � la capacit�, la zone de stockage initialement allou�e avec une taille de
_SIZE_INIT_ doit �tre agrandie de _SIZE_TO_ADD_.*/

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