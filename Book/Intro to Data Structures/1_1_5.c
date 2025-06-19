#include <stdio.h>
#include <string.h>

void add(const char* binary1, const char* binary2) {
    int len1 = strlen(binary1);
    int len2 = strlen(binary2);
    int maxLen = (len1 > len2) ? len1 : len2;

    char result[maxLen + 2];    // +1 sum for and +1 for '\0'
    result[maxLen + 1] = '\0';

    int carry = 0;

    for (int i = 0; i < maxLen; ++i) {
        int bit1 = (i < len1) ? (binary1[len1 - 1 -i] - '0') : 0;
        int bit2 = (i < len2) ? (binary2[len2 - 1 -i] - '0') : 0;

        int sum = bit1 + bit2 + carry;
        result[maxLen - i] = (sum % 2) + '0';
        carry = sum / 2;
    }

    result[0] = carry + '0';

    printf("Sum : %s\n", result + (result[0] == '0' ? 1 : 0));
}


void subtract(const char* binary1, const char* binary2) {
    int len1 = strlen(binary1);
    int len2 = strlen(binary2);
    int maxLen = (len1 > len2) ? len1 : len2;

    char result[maxLen + 1];    // +1 for '\0'
    result[maxLen] = '\0';

    int borrow = 0;

    for (int i = 0; i < maxLen; ++i) {
        int bit1 = (i < len1) ? (binary1[len1 - 1 - i] - '0') : 0;
        int bit2 = (i < len2) ? (binary2[len2 - 1 - i] - '0') : 0;

        int diff = bit1 - bit2 - borrow;

        if (diff < 0) {
            diff += 2;
            borrow = 1;
        }

        else {
            borrow = 0;
        }

        result[maxLen - 1 - i] = diff + '0';
    }

    printf("Subtraction: %s\n", result + (result[0] == '0' ? 1 : 0));
}


void multiply(const char* binary1, const char* binary2) {
    int len1 = strlen(binary1);
    int len2 = strlen(binary2);
    int resultLen = len1 + len2;

    int result[resultLen];
    for (int i = 0; i < resultLen; ++i) {
        result[i] = 0;
    }

    for (int i = 0; i < len1; ++i) {
        int bit1 = binary1[len1 - 1 - i] - '0';

        for (int j = 0; j < len2; ++j) {
            int bit2 = binary2[len2 - 1 - j] - '0';

            result[i + j] += bit1 * bit2;

            if (result[i + j] >= 2) {
                result[i + j + 1] += result[i + j] / 2;
                result[i + j] %= 2;
            }
        }
    }

    // Find the most significant bit position
    int msb = resultLen - 1;
    while (msb > 0 && result[msb] == 0) {
        msb--;
    }

    // Print the result
    printf("Multiplication: ");
    for (int i = msb; i >= 0; --i) {
        printf("%d", result[i]);
    }
    printf("\n");
}


int main() {
    const char* binary1 = "1101";
    const char* binary2 = "101";

    add(binary1, binary2);
    subtract(binary1, binary2);
    multiply(binary1, binary2);

    return 0;
}