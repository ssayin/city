#ifndef __CITYSEARCHLIST_H__
#define __CITYSEARCHLIST_H__

/* Standard library */
#include <stdlib.h>

/*! \typedef CityList
    \brief Encapsulating _CityList variables
*/
typedef struct _CityList CityList;

/* Forward declaration */
typedef struct city City;

/**
 *  Allocates mem & returns a pointer to the list
 *  @return pointer to CityList struct
 */
CityList* city_list_create();

/**
 *  Prints the elements of the list in table format
 *  @param ptr address of the struct
 *  @see city_print(...)
 *  @see print_header()
 *  @see print_footer()
 */
void city_list_print(CityList* ptr);

/**
 *  Adds a city by its ptr to the list
 *  @param list address of the struct
 *  @param ptrC city pointer
 */
void city_list_add(CityList* list, City* ptrC);

/**
 *  Size of the given list
 *  @param list address of the struct
 *  @return size of the dynamic array CityList
 */
int city_list_size(CityList* list);

/**
 *  The city at given index
 *  Return value is NULL if the given index is out of range
 *
 *  @param list address of the struct
 *  @param index index of the city
 *  @return the city at given index
 */
City* city_list_get(CityList* list, size_t index);

/**
 *  Free heap block
 *  @param list address of the struct
 */
void city_list_free(CityList* list);

#endif
