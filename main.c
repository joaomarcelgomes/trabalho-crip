#include <stdio.h>
#include "domain/shared/path.h"
#include "domain/shared/file.h"
#include "domain/cryp/keyword.h"

int main() {
    const char* pathKeyword = dirname("alphabet.txt");
    char* keyword = readFile(pathKeyword);

    const char* pathMessage = dirname("message.txt");
    char* message = readFile(pathMessage);

    char *encrypted = encrypt(message, keyword);
    printf("encrypt: %s\n", encrypted);

    char *decrypted = decrypt(encrypted, keyword);
    printf("decrypt: %s\n", decrypted);

    return 0;
}
