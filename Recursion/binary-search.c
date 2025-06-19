#include <stdio.h>

int BinarySearch(int arr[], int i, int j, int x) {
    
    if (i == j) {
        if (arr[i] == x){
            return i;
        }
        
        else{
            return -1;
        }
    }
    
    else{
        
        int mid = (i + j) / 2;

        if (arr[mid] == x) {
            return mid;
        }
        
        else{
            
            if (x < arr[mid]){
                return BinarySearch(arr, i, mid - 1, x);
            }
            
            else {
                return BinarySearch(arr, mid + 1, j, x);
            }
        }
    }
}

int main() {
    
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    
    int result = BinarySearch(arr, 0, n - 1, x);
    
    if (result == -1){
        printf("Element not found.\n");
    }
    
    else{
        printf("Element found at position %d\n", result + 1);
    }
    return 0;
}

