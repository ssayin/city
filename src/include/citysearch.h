#ifndef __CITYSEARCH_H__
#define __CITYSEARCH_H__

#include "citysearchlist.h"

/*! \typedef city_search_by_string_cb_t
    \brief Aliasing function_ptr type for city_search_by_string()

    @see city_search_by_string()
    @see city_search_by_name()
    @see city_search_by_region()
*/
typedef int (*city_search_by_string_cb_t) (City* ptr, const char* str);

/**
 * Search cities by string
 * @param head a pointer to the head of the list
 * @param str
 * @param cb search criterion
 * @see city_search_by_string_cb_t
 * @return the list of matches
 */
CityList* city_search_by_string(City* head, const char* str,
    city_search_by_string_cb_t cb);

/**
 * Search cities by plate code
 * @param head a pointer to the head of the list
 * @param license plate code
 * @return the list of matches
 */
CityList* city_search_by_license(City* head, int license);

#endif
