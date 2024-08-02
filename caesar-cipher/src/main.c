/*
 @file:     main.c
 @author:   Abdullah Bagyapan
 @date:     07/31/2024
*/


/*================================== Libraries ==================================*/

// Standard Libraries
#include <stdio.h>

// Other Libraries
// CAESAR CIPHER module
#include "cipher.h"

/*================================== Variables ==================================*/

static char data[] = "THISISAPLAINTEXTDATA";

/*================================== Functions ==================================*/


int main() {

    // Encryption
    char encrypted_data[sizeof(data)];

    if (caesar_cipher_encrypt(data, sizeof(data), encrypted_data)) {

        printf("There is a error occured while encrypting data");
        return 1;
    }

    printf("The plain text data is: %s \n", data);
    printf("The encrypted data is: %s \n", encrypted_data);


    // Decryption
    char data[sizeof(encrypted_data)];

    if (caesar_cipher_decrypt(encrypted_data, sizeof(encrypted_data), data)) {

        printf("There is a error occured while decrypting data");
        return 1;
    }

    printf("The encrypted data is: %s \n", encrypted_data);
    printf("The plain text data is: %s \n", data);

    return 0;
}