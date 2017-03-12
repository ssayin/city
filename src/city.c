#include "include/city.h"
#include "include/cityutil.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <memory.h>
#include <string.h>


void city_add(City** head, int license, const char* name, const char* region) {
    City* temp = *head;
    *head = malloc(sizeof(City));

    /* Memory allocation failed */
    if (!(*head)) {
        printf("Error: Not enough ram!\n\n");
        *head = temp; /* Set it back to head as if nothing happened :D */
        return;
    }

    /* Initialize our data values */
    (*head)->license = license;
    strcpy((*head)->name, name);
    strcpy((*head)->region, region);

    if (temp) { /* Head was not NULL */
        (*head)->next = temp;
        (*head)->nextnext = temp->next;
    } else { /* Head was NULL */
        (*head)->next = NULL;
        (*head)->nextnext = NULL;
    }
}


void city_remove(City** head, City* ptr) {
    City* prev = NULL;
    City* prevprev = NULL;
    City* curr = NULL;

    /* The list is empty */
    if (*head == NULL) {
        printf("Error: No element to remove!\n\n");
        return;
    }

    /**
     *  If the ptr we are looking for is found at the head,
     *  what we need to do is to basically free head
     *  and set head to the next item accordingly.
     */
    if (*head == ptr) {
        curr = (*head)->next;

        if (curr == NULL) {
            printf("Removing %d %s %s\n\n", (*head)->license, (*head)->name,
                (*head)->region);

            free(*head);
            *head = NULL;
            return;
        }

        free(*head);
        *head = curr;
        return;
    }

    /* It is not possible to get here if everything goes right */
    if ((*head)->next == NULL) {
        printf("Error!\n\n");
        return;
    }

    prev = (*head)->next;
    curr = prev->next;

    if (prev == ptr) {

        /**
         *  The list has 2 items, user is trying to remove the first inserted item
         *  which is the next item after the head, therefore free that item,
         *  set (*head)->next to NULL
         */
        if (curr == NULL) {
            printf("Removing %d %s %s\n\n", (*head)->next->license,
                (*head)->next->name, (*head)->next->region);

            free((*head)->next);
            (*head)->next = NULL;
            (*head)->nextnext = NULL;
            return;
        }

        /**
         *  The list has more than 2 items
         */
        (*head)->next = curr;
        (*head)->nextnext = curr->next;


        printf("Removing %d %s %s\n\n", prev->license, prev->name, prev->region);

        free(prev);
        prev = NULL;

        return;
    }

    /* Find the ptr */
    while ((prevprev = prev) && (prev = curr) && ((curr = curr->next) != ptr)) {
        /**
         *  The list has more than 3 items, prev holds our ptr,
         *  prevprev points to the element before prev,
         *  *head points to the element before prevprev
         */
        if (prev == ptr) {
            prevprev->next = prev->next;
            (*head)->nextnext = prev->next;
            prevprev->nextnext = prev->nextnext;

            printf("Removing %d %s %s\n\n", prev->license, prev->name, prev->region);

            free(prev);
            prev = NULL;

            return;
        }

        /**
         *  If it gets here, that means there is no such ptr
         *  in the list, since that is impossible, check if someone
         *  got into your system (he must be an uber-hacker though)
         */
        if (curr == NULL) {
            printf("Error: Someone is exploiting your system\n\n");
            return;
        }
    }

    /* Got the ptr in curr, no need to explain the operations below */
    prev->next = curr->next;
    prevprev->nextnext = curr->next;
    prev->nextnext = curr->nextnext;

    printf("Removing %d %s %s\n\n", curr->license, curr->name, curr->region);

    free(curr);
    curr = NULL;
}


void city_free_all(City* head) {
    City* c = head;
    City* next = NULL;

    while (c != NULL) {
        next = c->next;
        free(c);
        c = next;
    }
}


void city_print(City* ptr) {
    printf("| %7d | %16s | %16s |\n", ptr->license, ptr->name, ptr->region);
}


void city_print_all(City* head, city_print_step_cb_t cb) {
    City* a;
    a = head;
    while (a != NULL) {
        city_print(a);
        a = cb(a);
    }
}


void print_header() {
    printf("\n+---------+------------------+------------------+\n");
    printf("| %7s | %16s | %16s |\n", "License", "City Name", "Region");
    printf("+---------+------------------+------------------+\n");
}


void print_footer() {
    printf("+---------+------------------+------------------+\n\n");
}
