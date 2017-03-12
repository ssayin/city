#ifndef __CITYUTIL_H__
#define __CITYUTIL_H__

/**
 *  Loops continually until the user enters an acceptable input
 *  @param min minimum number (inclusive)
 *  @param max maximum number (inclusive)
 *  @param format format of the string to be printed when prompting the user
 *  @param variadic
 *  @return returns if the input is in between min and max
 */
int get_input_between(int min, int max, const char* format, ...);

/**
 *  Removes the trailing '\n' character after calling fgets(...)
 *  @param s read input to s
 *  @param n number of chars to be read, consider the '\0' at the end
 *  @return varies depending on the output from fgets, NULL if nothing is read
 */
char* fgets_wrapper(char* s, int n);

#endif
