#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main() {
	int Size, Mat[10][10], i, j;
	char message[1000];
	printf("Enter the size of the key matrix (max 10): ");
	scanf("%d", &Size);
	printf("Enter the elements of the key matrix:\n");
	for (i = 0; i < Size; i++) {
		for (j = 0; j < Size; j++) {
			scanf("%d", &Mat[i][j]);
		}
	}
	
	if (determinant(Mat[0][0], Mat[0][1], Mat[1][0], Mat[1][1]) == 0) {
		printf("The key matrix is not invertible. Please enter a valid key matrix.\n");
		return 1;
	}
	
	printf("Enter the message to be encrypted (uppercase letters only): ");
	scanf("%s", message);
	
	encrypt(message, Mat, Size);
	return 0;
}

int determinant(int a, int b, int c, int d) {
	return (a * d - b * c);
}

void encrypt(char message[], int keyMatrix[][10], int keySize) {
	int mlen = strlen(message);
	int paddedLength = (int) ceil(mlen / (float) keySize) * keySize;
	int paddedMessage[paddedLength];
	int encrypted[paddedLength];
	int i, j, k, sum;
	
	for (i = 0; i < mlen; i++) {
		paddedMessage[i] = message[i] - 'A';
	}
	for (; i < paddedLength; i++) {
		paddedMessage[i] = 23;
	}
	
	for (i = 0; i < paddedLength; i += keySize) {
		for (j = 0; j < keySize; j++) {
			sum = 0;
			for (k = 0; k < keySize; k++) {
				sum += keyMatrix[j][k] * paddedMessage[i + k];
			}
			encrypted[i + j] = sum % 26;
		}
	}
	
	printf("Encrypted message: ");
	for (i = 0; i < paddedLength; i++) {
		printf("%c", (char) (encrypted[i] + 'A'));
	}
	printf("\n");
}

int moduloInverse(int a, int m) {
	int i;
	for (i = 1; i < m; i++) {
		if ((a * i) % m == 1) {
			return i;
		}
	}
	return -1;
}
