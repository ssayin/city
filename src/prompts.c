#include "include/city.h"
#include "include/citysearchlist.h"
#include "include/citysearch.h"
#include "include/cityutil.h"

#include <stdio.h>
#include <stdlib.h>


void city_add_prompt(City** head) {
    int license;
    char name[NAME_SIZE];
    char region[REGION_SIZE];

    printf("License: ");
    scanf("%d", &license);
    getchar();

    printf("Name: ");
    fgets_wrapper(name, NAME_SIZE);

    printf("Region: ");
    fgets_wrapper(region, REGION_SIZE);

    printf("\n");

    city_add(head, license, name, region);
}


void city_print_prompt(City* head) {
    int decision;

    if (!head) {
        printf("Error: No elements in the list\n\n");
        return;
    }

    printf("Print Menu\n1. Use next pointers\n2. Use next next pointers\n");
    decision = get_input_between(1, 2, "Decision: ");

    print_header();

    switch (decision) {
        case 1:
            city_print_all(head, city_print_step_next);
        break;
        case 2:
            city_print_all(head, city_print_step_nextnext);
        break;
    }

    print_footer();
}


void city_search_prompt(City** head, int remove) {
    CityList* match;
    City* rmv;
    char buf[NAME_SIZE];
    int decision;
    int size;

    city_search_by_string_cb_t callbacks[] = {
        city_search_by_name,
        city_search_by_region,
    };

    if (*head == NULL) {
        printf("Error: The list is empty!\n\n");
        return;
    }

    printf("%s Menu\n", remove ? "Remove" : "Search");
    printf("1. By Plate Code\n");
    printf("2. By Name\n");
    printf("3. By Region\n");

    decision = get_input_between(1, 3, "Decision: ");

    getchar();

    switch (decision) {
        case 1:
            printf("License: ");
            scanf("%d", &decision);
            printf("\n");
            match = city_search_by_license(*head, decision);
        break;

        case 2:
        case 3:
            printf("Begins with: ");
            fgets_wrapper(buf, NAME_SIZE); /* See city.h */
            printf("\n");
            match = city_search_by_string(*head, buf, callbacks[decision - 2]);
        break;
    }

    /* Something went awry :( */
    if (match == NULL) {
        printf("An error occured!\n\n");
        return;
    }

    city_list_print(match);

    if ((size = city_list_size(match)) > 0) {
        if (remove) {
            decision = get_input_between(1, size, "Index of the city you want"
                " to remove (1-%d): ", size);

            rmv = city_list_get(match, decision - 1);
            city_remove(head, rmv);
        }
    }

    if (match) {
        city_list_free(match);
    }
}
