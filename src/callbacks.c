#include "include/city.h"

#include <string.h>


static int string_begins_with(const char* str, const char* match) {
    if (strlen(match) > strlen(str))
        return 0;

    for (int i = 0; i < strlen(match); ++i) {
        if (str[i] != match[i]) {
            return 0;
        }
    }

    return 1;
}


int city_search_by_name(City* ptr, const char* name) {
    return string_begins_with(ptr->name, name);
}


int city_search_by_region(City* ptr, const char* region) {
    return string_begins_with(ptr->region, region);
}


City* city_print_step_next(City* ptr) {
    return ptr->next;
}


City* city_print_step_nextnext(City* ptr) {
    return ptr->nextnext;
}
