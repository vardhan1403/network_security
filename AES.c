#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

char aes_key[] = "0123456789abcdef";

void aes_encrypt(char *plaintext, char *ciphertext) {
    AES_KEY key;
    AES_set_encrypt_key(aes_key, 128, &key);
    AES_encrypt(plaintext, ciphertext, &key);
}

void aes_decrypt(char *ciphertext, char *decryptedtext) {
    AES_KEY key;
    AES_set_decrypt_key(aes_key, 128, &key);
    AES_decrypt(ciphertext, decryptedtext, &key);
}

int main() {
    char plaintext[] = "welcome to ISE";
    char ciphertext[AES_BLOCK_SIZE];
    char decryptedtext[AES_BLOCK_SIZE];
    aes_encrypt(plaintext, ciphertext);
    aes_decrypt(ciphertext, decryptedtext);
    printf("Original message: %s\n", plaintext);
    printf("Encrypted message: ");
    for (int i = 0; i < AES_BLOCK_SIZE; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");
    printf("Decrypted message: %s\n", decryptedtext);
    return 0;
}

// gcc -o aes aes.c -lssl -lcrypto
// ./aes
