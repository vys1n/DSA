#include <stdio.h>

void hanoi(int n, char so[], char des[], char aux[]){
    if (n == 1){
        printf("move 1 disk from %s to %s\n", so, des);
        return;
    }

    hanoi(n-1, so, aux, des);
    printf("move 1 disk from %s to %s\n", so, des);
    hanoi(n-1, aux, des, so);
}

int main(){
    
    int n;
    printf("Enter the number of towers: ");
    scanf("%d", &n);

    char so[] = "source";
    char des[] = "destination";
    char aux[] = "auxilary";

    hanoi(n, so, des, aux);
    
    return 0;
}