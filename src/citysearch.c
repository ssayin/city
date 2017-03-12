#include "include/citysearch.h"
#include "include/city.h"


CityList* city_search_by_string(City* head, const char* str,
    city_search_by_string_cb_t cb) {
    CityList* cl = city_list_create();

    City* ptr = head;

    while (ptr != NULL) {
        if (cb(ptr, str)) {
            city_list_add(cl, ptr);
        }

        ptr = ptr->next;
    }

    return cl;
}


CityList* city_search_by_license(City* head, int license) {
    CityList* cl = city_list_create();

    City* ptr = head;

    while (ptr != NULL) {
        if (ptr->license == license) {
            city_list_add(cl, ptr);
        }

        ptr = ptr->next;
    }

    return cl;
}
