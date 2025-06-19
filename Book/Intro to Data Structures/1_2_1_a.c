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

void Median(int a[], int size)
{
    float median;
    if ((size % 2) == 0) {
        median = (a[(size/2) - 1] + a[(size/2)])/2.0;
        printf("\nmedian is : %.2f", median);
    }

    else {
        median = a[(size/2)];
        printf("\nmedian is : %.2f", median);
    }
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

    Median(a, size);

    return 0;
}