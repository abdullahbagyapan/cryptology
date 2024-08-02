/*
 @module:   CAESAR CIPHER
 @author:   Abdullah Bagyapan
 @date:     07/31/2024
*/


/*================================== Libraries ==================================*/


// Module's own header
#include "cipher.h"


/*================================== Definitions ==================================*/


// TODO: map from __alphabet array
// Based on ASCII table
#define MINCAP  65   // letter 'A'
#define MAXCAP  90   // letter 'Z'

#define MINLOW  97   // letter 'a'
#define MAXLOW  122  // letter 'z'

#define TOTAL_LETTER_NUMBER_IN_ALPHABET     (int) sizeof(__alphabet)  // For English Alphabet, there is 26 letter in it


/*================================== Variables ==================================*/


static uint8_t  __shift_key = 5; // default caesar cipher uses 2 alphabets shifter.

// TODO: add alphabet for lower case letters
static char     __alphabet[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};


/*================================== Private Functions ==================================*/


/*
 @brief     Encrypt given a plain text byte data with caesar cipher

 @author    Abdullah Bagyapan

 @date      08/2/2024

 @param     data    The plain text data(a byte)

 @return    The encrypted data
*/
char __caesar_cipher_encrypt_byte(char data) {

    int ascii_data = data + __shift_key;
    int first_letter;

    if (data >= MINCAP && data <= MAXCAP) { // the letter is between A...Z
        first_letter = MINCAP;
    }
    else if (data >= MINLOW && data <= MAXLOW) { // the letter is between a...z 
        first_letter = MINLOW;
    }

    ascii_data -= first_letter; // Reassign value between [0...TOTAL_LETTER_NUMBER_IN_ALPHABET]

    // To fix side channels attacks such as Power Analysis, i know this is over-engineering.
    ascii_data += TOTAL_LETTER_NUMBER_IN_ALPHABET;

    int index = ascii_data % TOTAL_LETTER_NUMBER_IN_ALPHABET; // Index for alphabet

    return __alphabet[index];
}

/*
 @brief     Decrypt given a encrypted text byte data with caesar cipher

 @author    Abdullah Bagyapan

 @date      08/2/2024

 @param     data    The encrypted text data(a byte)

 @return    The decrypted data
*/
char __caesar_cipher_decrypt_byte(char encrypted_data) {

    int ascii_data = encrypted_data - __shift_key;
    int first_letter;

    if (encrypted_data >= MINCAP && encrypted_data <= MAXCAP) { // the letter is between A...Z
        first_letter = MINCAP;
    }
    else if (encrypted_data >= MINLOW && encrypted_data <= MAXLOW) { // the letter is between a...z 
        first_letter = MINLOW;
    }

    ascii_data -= first_letter; // Reassign value between [0...TOTAL_LETTER_NUMBER_IN_ALPHABET]

    // In ANSI C, negative modulo operation is not returns positive result (for more info, google it: negative modulo in c)
    ascii_data += TOTAL_LETTER_NUMBER_IN_ALPHABET; // to fix underflow

    int index = ascii_data % TOTAL_LETTER_NUMBER_IN_ALPHABET; // Index for alphabet

    return __alphabet[index];
}


/*================================== Public Functions ==================================*/


uint8_t caesar_cipher_encrypt(char *data, size_t size, char *encrypted_data) {

    int i; // iterator

    for (i = 0; i < size; i++) {

        encrypted_data[i] = __caesar_cipher_encrypt_byte(data[i]);
    }

    return 0; // data succesfully encrypted;
}


uint8_t caesar_cipher_decrypt(char *encrypted_data, size_t size, char *data) {

    int i; // iterator

    for (i = 0; i < size; i++) {

        data[i] = __caesar_cipher_decrypt_byte(encrypted_data[i]);
    }

    return 0; // data succesfully decrypted;
}