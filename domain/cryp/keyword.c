#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include <stdlib.h>

#define ALPHABET_SIZE 26

#include "keyword.h"

char* new_alphabet(const char *keyword) {
    char *alphabet = (char*) malloc(ALPHABET_SIZE * sizeof(char));

    strcpy(alphabet, keyword);

    for(int i = 0; i < strlen(keyword); i++) {
        if (isalpha(keyword[i])) {
            char c = toupper(keyword[i]);
            if (strchr(alphabet, c) == NULL) {
                strncat(alphabet, &c, 1);
            }
        }
    }

    for(char c = 'A'; c <= 'Z'; c++) {
        if (strchr(alphabet, c) == NULL) {
            strncat(alphabet, &c, 1);
        }
    }

    return alphabet;
}

char* encrypt(const char *message, const char *keyword) {
    char *encrypted_message = (char*) malloc((strlen(message) + 1) * sizeof(char));

    char *alphabet = new_alphabet(keyword);

    for(int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            int index = toupper(message[i]) - 'A';
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

    char *alphabet = new_alphabet(keyword);

    for(int i = 0; i < strlen(encrypted_message); i++) {
        if (isalpha(encrypted_message[i])) {
            int index = strchr(alphabet, toupper(encrypted_message[i])) - alphabet;
            decrypted_message[i] = 'A' + index;
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }

    decrypted_message[strlen(encrypted_message)] = '\0';

    return decrypted_message;
}