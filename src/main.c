#include "include/city.h"
#include "include/citysearchlist.h"
#include "include/citysearch.h"
#include "include/cityutil.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


static int menu() {
    int ret;
    printf("Main Menu\n");
    printf("1. Add to the list\n");
    printf("2. Remove from the list\n");
    printf("3. Print from the list\n");
    printf("4. Search\n");
    printf("5. Exit\n");

    ret = get_input_between(1, 5, "Decision: ");

    printf("\n");

    return ret;
}


int main(int argc, char** argv) {
    City* head = NULL;
    City* tail = NULL;

    int decision;
    do {
        switch (decision = menu()) {
            case 1:
                city_add_prompt(&head);
                if (tail == NULL) { /* Not sure about this */
                    tail = head;
                }
                if (head == NULL) {
                    tail = NULL;
                }
                break;
            case 2:
                city_search_prompt(&head, 1);
                break;
            case 3:
                city_print_prompt(head);
                break;
            case 4:
                city_search_prompt(&head, 0);
                break;
            case 5:
                /* Free heap block */
                city_free_all(head);
                break;
        }
    } while (decision != 5);
}
