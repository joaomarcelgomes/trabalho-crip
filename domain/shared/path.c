#include <stdio.h>
#include <stdlib.h>

#include "path.h"

#ifdef _WIN32
#include <windows.h>
#elif __linux__
    #include <unistd.h>
    #include <limits.h>
#endif

char* dirname(const char* path) {

    static char fullPath[PATH_MAX];

    #ifdef _WIN32
        if (!GetFullPathNameA(path, PATH_MAX, fullPath, NULL)) {
            printf("Error getting full path\n");
            return NULL;
        }
    #elif __linux__
        if (realpath(path, fullPath) == NULL) {
            perror("Error getting full path");
            return NULL;
        }
    #else
        #error "Unsupported platform"
    #endif

    return fullPath;
}