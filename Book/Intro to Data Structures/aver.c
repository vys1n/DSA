#include <stdio.h>
#define NUMELTS 10

void aver()
{
    int num[NUMELTS];
    int i;
    int total;
    int avg;
    int diff;
    
    // number and the average
    total = 0;
    for (i = 0; i < NUMELTS; i++) {
        scanf("%d", &num[i]);
        total += num[i];
    }
    avg = total / NUMELTS;
    
    printf("\n number difference");
    // print each numbers and its difference
    for (i = 0; i < NUMELTS; i++) {
        diff = num[i] - avg;
        printf("\n %d %d", num[i], diff);
    }
    printf("\n average is: %d", avg);
}

int main() {
    aver();
    return 0;
}