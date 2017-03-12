#ifndef __CITY_H__
#define __CITY_H__

/*
    Make sure the definitions below have the same number unless you want
    change the implementation of city_search_prompt(...) in prompts.c
*/
#define NAME_SIZE 16
#define REGION_SIZE 16

/*! City struct */
typedef struct city {
    int license; /*!< Stores the plate code of the city.  */
    struct city* next; /*!< Points at the next element of the list. */
    struct city* nextnext; /*!< Points at the second next element of the list.*/
    char name[NAME_SIZE]; /*!< Stores the city name. */
    char region[REGION_SIZE]; /*!< Stores the city region. */
} City;

/*! \typedef city_print_step_cb_t
    \brief Aliasing function_ptr type for city_print_all()

    @see city_print_all()
    @see city_print_step_next()
    @see city_print_step_nextnext()
*/
typedef City* (*city_print_step_cb_t) (City* ptr);

/**
 * A small callback function to prevent unnecessary function duplication
 * @param ptr a pointer to City object
 * @return The next element in the list
 */
City* city_print_step_next(City* ptr);

/**
 * A small callback function to prevent unnecessary function duplication
 * @param ptr a pointer to City object
 * @return The second next element in the list
 */
City* city_print_step_nextnext(City* ptr);

/**
 * Search condition
 * @param ptr a pointer to City object
 * @return 1 if there is match, 0 otherwise
 */
int city_search_by_name(City* ptr, const char* name);

/**
 * Search condition
 * @param ptr a pointer to City object
 * @return 1 if there is match, 0 otherwise
 */
int city_search_by_region(City* ptr, const char* region);

/**
 * Linked list Add function implementation
 * @param head a pointer pointer to the head of the list
 * @param license license of the city to be added
 * @param name name of the city to be added
 * @param region region of the city to be added
 */
void city_add(City** head, int license, const char* name, const char* region);

 /**
  * Linked list Remove function implementation
  * @param head a pointer pointer to the head of the list
  * @param ptr pointer to the city to be removed
  */
void city_remove(City** head, City* ptr);

/**
 * Free all heap blocks before exiting
 * @param head a pointer to the head of the list
 */
void city_free_all(City* head);

/**
 * Prompts user
 * @param head a pointer pointer to the head of the list
 */
void city_add_prompt(City** head);

/**
 * Prompts user
 * @param head pointer to the head of the list
 */
void city_print_prompt(City* head);

/**
 * Prompts user
 * @param head pointer pointer to the head of the list
 * @param remove prompts user for which element to remove if given other than 0
 */
void city_search_prompt(City** head, int remove);

/**
 * Prints a single row
 * @param ptr pointer to the element to be printed
 */
void city_print(City* ptr);

/**
 * Prints a table following the rule cb defines
 * @param head pointer to the head of the list
 * @param cb defines whether to step once or twice while printing rows
 * @see city_print_step_cb_t
 */
void city_print_all(City* head, city_print_step_cb_t cb);

/**
 * Prints the table header
 * @see city_print_all()
 */
void print_header();

/**
 * Prints the table footer
 * @see city_print_all()
 */
void print_footer();

#endif
