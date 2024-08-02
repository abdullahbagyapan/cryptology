/*
 @module:   CAESAR CIPHER
 @author:   Abdullah Bagyapan
 @date:     07/31/2024
*/


/*================================== Libraries ==================================*/

// Standart libraries
#include <stddef.h>
#include <stdint.h>

/*================================== Functions ==================================*/


/*
 @brief     Encrypt given plain text data with caesar cipher

 @author    Abdullah Bagyapan

 @date      07/31/2024

 @param     data    The plain text data that is gonna be encrypted
 @param     size    The size of plain text data

 @return    0: successful
            1: fail
*/
uint8_t caesar_cipher_encrypt(char *data, size_t size, char *encrypted_data);


/*
 @brief     Decrypt given plain text data with caesar cipher

 @author    Abdullah Bagyapan

 @date      07/31/2024

 @param     data    The plain text data that is gonna be encrypted
 @param     size    The size of plain text data

 @return    0: successful
            1: fail
*/
uint8_t caesar_cipher_decrypt(char *encrypted_data, size_t size, char *data);