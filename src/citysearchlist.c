#include "include/citysearchlist.h"
#include "include/city.h"


#include <stdlib.h>


struct _CityList {
   City** ptrs;
   size_t size;
   size_t size_max;
};


void city_list_print(CityList* list) {
    if (list == NULL) return;

    print_header();
    for (int i = 0; i < list->size; ++i) {
        city_print(list->ptrs[i]);
    }
    print_footer();
}


void city_list_add(CityList* list, City* ptrC) {
    if (list == NULL) return;

    if (list->size >= list->size_max) {
        list->size_max *= 3;
        list->ptrs = realloc(list->ptrs, sizeof(City*) * list->size_max);
    }

    list->ptrs[list->size++] = ptrC;
}


CityList* city_list_create() {
    CityList* cl = malloc(sizeof(CityList));
    cl->size = 0;
    cl->size_max = 20;
    cl->ptrs = malloc(sizeof(City*) * 20);
    return cl;
}


int city_list_size(CityList* list) {
    if (list) {
        return list->size;
    } else return -1;
}


City* city_list_get(CityList* list, size_t index) {
    if (!list || !(index < list->size)) return NULL;
    return list->ptrs[index];
}


void city_list_free(CityList* list) {
    free(list->ptrs);
    free(list);
}
