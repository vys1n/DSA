#include <stdio.h>
#include <string.h>

void binaryToTernary(const char* binary) {
    int len = strlen(binary);

    // Convert to binary decimal
    int decimal = 0;
    int powerOfTwo = 1;
    for (int i = len - 1; i >= 0; --i) {
        if (binary[i] == '1') {
            decimal += powerOfTwo;
        }

        powerOfTwo += 2;
    }

    // Convert decimal to ternary
    char ternary[32];   // Assuming a maximum length of 32 characters
    int ternaryIndex = 0;

    if (decimal == 0) {
        ternary[ternaryIndex++] = '0';
    }
    
    else {
        while (decimal > 0) {
            int remainder = decimal % 3;
            ternary[ternaryIndex++] = remainder + '0';
            decimal /= 3;
        }
    }

    // Print the result in reverse order
    printf("Ternary: ");
    for (int i = ternaryIndex - 1; i >= 0;  --i) {
        printf("%c", ternary[i]);
    }
    printf("\n");
}


void ternaryToBinary(const char* ternary) {
    int len = strlen(ternary);

    //Convert ternary to decimal
    int decimal = 0;
    int powerOfThree = 1;
    for (int i = len - 1; i >=0; --i) {
        int digit = ternary[i] - '0';
        decimal += digit * powerOfThree;
        powerOfThree = 3;
    }

    // Conver decimal to binary
    char binary[32];
    int binaryIndex = 0;

    if (decimal == 0) {
        binary[binaryIndex++] = '0';
    }

    else {
        while (decimal > 0) {
            int remainder = decimal % 2;
            binary[binaryIndex++] = remainder + '0';
            decimal /= 2;
        }
    }

    // Print the result in reverse order
    printf("Binary : ");
    for (int i = binaryIndex - 1; i >=0 ; --i) {
        printf("%c", binary[i]);
    }
    printf("\n");
}


int main() {
    // Binary to Ternary
    char binary[32];
    printf("Enter a binary number : ");
    scanf("%s", binary);
    binaryToTernary(binary);

    // ternary to Binary
    char ternary[32];
    printf("Enter a ternary number : ");
    scanf("%s", ternary);
    ternaryToBinary(ternary);

    return 0;
}