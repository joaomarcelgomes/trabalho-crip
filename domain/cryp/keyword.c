#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include <stdlib.h>

#define ALPHABET_SIZE 80

#include "keyword.h"

char* encrypt(const char *message, const char *keyword) {
    char *encrypted_message = (char*) malloc((strlen(message) + 1) * sizeof(char));

    char alphabet[ALPHABET_SIZE];
    strcpy(alphabet, keyword);

    for(int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            int index = tolower(message[i]) - 'a';
            encrypted_message[i] = alphabet[index];
        } else {
            encrypted_message[i] = message[i];
        }
    }

    encrypted_message[strlen(message)] = '\0';

    return encrypted_message;
}

char* decrypt(const char *encrypted_message, const char *keyword) {
    char *decrypted_message = (char*) malloc((strlen(encrypted_message) + 1) * sizeof(char));

    char alphabet[ALPHABET_SIZE];
    strcpy(alphabet, keyword);

    for(int i = 0; i < strlen(encrypted_message); i++) {
        if (isalpha(encrypted_message[i])) {
            int index = strchr(alphabet, encrypted_message[i]) - alphabet;
            decrypted_message[i] = 'a' + index;
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }

    decrypted_message[strlen(encrypted_message)] = '\0';

    return decrypted_message;
}