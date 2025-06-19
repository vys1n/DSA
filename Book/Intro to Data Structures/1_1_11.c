#include <stdio.h>
#include <stdbool.h>

int countWords(const char* str) {
    int count = 0;
    bool inWord = false;

    // Iterate through each character in string
    for (int i = 0; str[i] != '\0'; ++i) {
        // Check if the current charater is tab newline or spcae
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
            // If the previous word part of a word, increment the word count
            if (inWord) {
                count++;
                inWord = false; // Reset the flag
            }
        }

        else {
            // If the current character is not a space, tab or newline, set the inWord flag
            inWord = true;
        }
    }

    // Check for the last word in case the string doesn't end with a space
    if (inWord) {
        count++;
    }

    return count;
}

int main() {
    char inputString[100];

    printf("Enter a string : ");
    fgets(inputString, sizeof(inputString) ,stdin);

    int wordCount = countWords(inputString);

    printf("Number of words: %d\n", wordCount);

    return 0;
}