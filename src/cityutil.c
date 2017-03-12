#include "include/cityutil.h"


#include <stdio.h>
#include <string.h>
#include <stdarg.h>


int get_input_between(int min, int max, const char* format, ...) {
    va_list args;
    int input;

    do {
        va_start(args, format);
        vprintf(format, args);
        va_end(args);

        scanf("%d", &input);
    } while(input < min || input > max);

    return input;
}


char* fgets_wrapper(char* s, int n) {
    size_t len;

    if (fgets(s, n, stdin) == NULL)
        return NULL;

    len = strlen(s);

    if (s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }

    return s;
}
