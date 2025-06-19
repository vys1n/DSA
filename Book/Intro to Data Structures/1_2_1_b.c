#include <stdio.h>

void Sort(int a[], int size)
{
    int i, j, temp;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int Mode(int a[], int size)
{
    int i, j;
    int maxValue = 0;
    int maxCount = 0;
    
    for (i = 0; i < size; i++) {
        int count = 0;
        for (j = 0; j < size; j++) {
            if (a[j] == a[i]) {
                count++;
            }
        }

        if (count > maxCount) {
            maxCount = count;
            maxValue = a[i];
        }
    }

    return maxValue;
}

int main() {
    int i, size;

    printf("Enter the size of the array : ");
    scanf("%d", &size);

    int a[size];

    // taking an array from user
    printf("Enter the numbers: \n");
    for (i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }

    Sort(a, size);

    // showing user the array
    printf("This is your sorted array : ");
    for(i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }

    printf("\nMode of the array is : %d", Mode(a, size));

    return 0;
}