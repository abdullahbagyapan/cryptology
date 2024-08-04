/*
 @module:   CAESAR CIPHER
 @author:   Abdullah Bagyapan
 @date:     07/31/2024
*/


/*================================== Libraries ==================================*/


// Module's own header
#include "cipher.h"


/*================================== Definitions ==================================*/


// Based on ASCII table
#define MINCAP  65   // letter 'A'
#define MAXCAP  90   // letter 'Z'

#define MINLOW  97   // letter 'a'
#define MAXLOW  122  // letter 'z'

#define TOTAL_LETTER_NUMBER_IN_ALPHABET     (int) sizeof(__alphabet_low)  // For English Alphabet, there is 26 letter in it


/*================================== Variables ==================================*/


static uint8_t  __shift_key = 5; // default caesar cipher uses 2 alphabets shifter.

static char     __alphabet_cap[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
static char     __alphabet_low[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};


/*================================== Private Functions ==================================*/


/*
 @brief     Encrypt given a plain text byte data with caesar cipher

 @author    Abdullah Bagyapan

 @date      08/2/2024

 @param     data    The plain text data(a byte)

 @return    The encrypted data
*/
char __caesar_cipher_encrypt_byte(char data) {

    static char *alphabet = NULL; // To choose low or cap letter from alphabet

    int ascii_data = data + __shift_key;
    int first_letter;

    if (data >= MINCAP && data <= MAXCAP) { // the letter is between A...Z
        first_letter = MINCAP;
        alphabet = __alphabet_cap;
    }
    else if (data >= MINLOW && data <= MAXLOW) { // the letter is between a...z 
        first_letter = MINLOW;
        alphabet = __alphabet_low;
    }
    else { // if given character is not in alphabet
        return data;
    }


    ascii_data -= first_letter; // Reassign value between [0...TOTAL_LETTER_NUMBER_IN_ALPHABET]

    // To fix side channels attacks such as Power Analysis or Timing Attack, i know this is over-engineering.
    ascii_data += TOTAL_LETTER_NUMBER_IN_ALPHABET;

    uint8_t index = ascii_data % TOTAL_LETTER_NUMBER_IN_ALPHABET; // Index for alphabet

    return alphabet[index];
}

/*
 @brief     Decrypt given a encrypted text byte data with caesar cipher

 @author    Abdullah Bagyapan

 @date      08/2/2024

 @param     data    The encrypted text data(a byte)

 @return    The decrypted data
*/
char __caesar_cipher_decrypt_byte(char encrypted_data) {

    static char *alphabet = NULL; // To choose low or cap letter from alphabet

    int ascii_data = encrypted_data - __shift_key;
    int first_letter;

    if (encrypted_data >= MINCAP && encrypted_data <= MAXCAP) { // the letter is between A...Z
        first_letter = MINCAP;
        alphabet = __alphabet_cap;
    }
    else if (encrypted_data >= MINLOW && encrypted_data <= MAXLOW) { // the letter is between a...z 
        first_letter = MINLOW;
        alphabet = __alphabet_low;
    }
    else { // if given character is not in alphabet
        return encrypted_data;
    }

    ascii_data -= first_letter; // Reassign value between [0...TOTAL_LETTER_NUMBER_IN_ALPHABET]

    // In ANSI C, negative modulo operation is not returns positive result (for more info, google it: negative modulo in c)
    ascii_data += TOTAL_LETTER_NUMBER_IN_ALPHABET; // to fix underflow

    uint8_t index = ascii_data % TOTAL_LETTER_NUMBER_IN_ALPHABET; // Index for alphabet

    return alphabet[index];
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