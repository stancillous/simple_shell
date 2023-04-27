#include "shell.h"


char* _strtok(char* str, const char* delim) {
    static char* ptr = NULL;
    char* start;
  
    if (str == NULL) {
        if (ptr == NULL) {
            return NULL;
        }
        str = ptr;
    }
    
    start = str;
    while (*str != '\0') {
        const char* d = delim;
        while (*d != '\0') {
            if (*str == *d) {
                *str = '\0';
                ptr = str + 1;
                if (*ptr == '\0') {
                    ptr = NULL;
                }
                return start;
            }
            d++;
        }
        str++;
    }
    
    ptr = NULL;
    return start;
}

