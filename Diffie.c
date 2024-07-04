#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int q, a; // q and alpha value

int mod_exp(int base, int exp, int modulus) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exp /= 2;
    }
    return result;
}

void diffie_hellman(int private_key, int *public_key) {
    *public_key = mod_exp(a, private_key, q);
}

int main() {
    int Xa, Xb; // private keys
    int Ya, Yb; // public keys
    int Ka, Kb; // session keys
    
    printf("\nEnter q value (prime number): ");
    scanf("%d", &q);
    
    printf("\nEnter alpha value (primitive root of q): ");
    scanf("%d", &a);
    
    printf("\nEnter private key of A: ");
    scanf("%d", &Xa);
    
    printf("\nEnter private key of B: ");
    scanf("%d", &Xb);
    
    diffie_hellman(Xa, &Ya);
    diffie_hellman(Xb, &Yb);
    
    printf("\nPublic Key of A: %d", Ya);
    printf("\nPublic Key of B: %d", Yb);
    
    Ka = mod_exp(Yb, Xa, q);
    Kb = mod_exp(Ya, Xb, q);
    
    printf("\nKey of A: %d", Ka);
    printf("\nKey of B: %d", Kb);
    
    return 0;
}

