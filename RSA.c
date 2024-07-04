#include <stdio.h>
#include <math.h>
int gcd(int a, int h){
	int temp;
	while (1){
		temp = a % h;
		if (temp == 0)
			return h;
		a = h;
		h = temp;
	}
}
int powmod(int a,int b,int n)
{
	int x=1,y=a;
	while(b>0){
		if(b % 2 ==1)
		{
			x=(x * y) % n;
		}
		y=(y * y) % n;
		b /=2;
	}
	return x % n;
}

int stringToNumber(char *str) {
    int number = 0,i;
    for (i = 0; i < strlen(str); i++) {
        number = number * 10 + (str[i] - 'A' + 1);
    }
    return number;
}

// Function to convert number back to string
void numberToString(int number, char *str) {
    int i = 0,j;
    while (number > 0) {
        str[i++] = (number % 10) + 'A' - 1;
        number /= 10;
    }
    str[i] = '\0';

    // Reverse the string
    int len = strlen(str);
    for (j = 0; j < len / 2; j++) {
        char temp = str[j];
        str[j] = str[len - j - 1];
        str[len - j - 1] = temp;
    }
}

int main()
{
	int p,q;
	printf("Enter the first prime number:\n");
	scanf("%d",&p);
	printf("Enter the second prime number:\n");
	scanf("%d",&q);
	int n= p * q;
	int phi=(p - 1) * (q - 1);
	int e=2;
	while (e < phi){
		if (gcd(e, phi) == 1)
			break;
		else
			e++;
	}
	printf("Public key is = <%d,%d>\n",e,n);
	int d=0;
	//int k=((d*e)%(phi));
	for(d = e + 1;d<=10000;d++)
	{
		if(((d*e) % phi)==1)
			break;
	}
	//int k = 2;
	//int d = (1 + (k * phi)) / e;
	printf("Private key = <%d,%d>\n",d,n);
	
	char input[256];
    printf("Enter the data:\n");
    scanf(" %[^\n]%*c",input);
	
	int data = stringToNumber(input);
    printf("Numeric representation of the input string is: %d\n", data);
    
	int cipher=powmod(data,e,n);
	printf("The cipher text is: %d\n",cipher);
	
	int decrypt=powmod(cipher,d,n);
	printf("The decsrypted text is: %d\n",decrypt);
	
	char decryptedString[256];
    numberToString(decrypt, decryptedString);
    printf("The decrypted text is: %s\n", decryptedString);
	return 0;
}
