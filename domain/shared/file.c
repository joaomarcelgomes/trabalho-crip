#include <stdio.h>
#include <stdlib.h>

#include "file.h"

char* readFile(const char* filename) {

    FILE* file = fopen(filename, "r");

    if (!file) {
        fprintf(stderr, "Unable to open file %s", filename);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    unsigned long fileLen = ftell(file);
    rewind(file);

    char* buffer = (char*) malloc((fileLen + 1) * sizeof(char));

    if (!buffer) {
        fprintf(stderr, "Memory error!");
        fclose(file);
        return NULL;
    }

    fread(buffer, fileLen, 1, file);

    buffer[fileLen] = '\0';

    fclose(file);

    return buffer;
}