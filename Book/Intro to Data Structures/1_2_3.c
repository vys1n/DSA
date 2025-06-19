#include <stdio.h>

#define NUM_BRANCHES 20
#define NUM_ITEMS 10

int main() {
    int sales[NUM_BRANCHES][NUM_ITEMS];  // 2D array to store sales figures
    int branch, item, salesFigure;

    // Initialize sales array to zero
    for (int i = 0; i < NUM_BRANCHES; i++) {
        for (int j = 0; j < NUM_ITEMS; j++) {
            sales[i][j] = 0;
        }
    }

    // Read data cards
    while (1) {
        printf("Enter branch number, item number, and sales figure (or enter -1 to end): ");
        scanf("%d", &branch);

        // Check for termination condition
        if (branch == -1) {
            break;
        }

        scanf("%d %d", &item, &salesFigure);

        // Validate input
        if (branch < 1 || branch > NUM_BRANCHES || item < 1 || item > NUM_ITEMS || salesFigure < 0 || salesFigure >= 100000) {
            printf("Invalid input. Please enter valid data.\n");
            continue;
        }

        // Update sales array
        sales[branch - 1][item - 1] += salesFigure;
    }

    // Print table headers
    printf("%-10s", "Branch");
    for (int j = 0; j < NUM_ITEMS; j++) {
        printf("%-10s", "Item");
    }
    printf("%-10s\n", "Total");

    // Print table data
    for (int i = 0; i < NUM_BRANCHES; i++) {
        int branchTotal = 0;
        printf("%-10d", i + 1);

        for (int j = 0; j < NUM_ITEMS; j++) {
            printf("%-10d", sales[i][j]);
            branchTotal += sales[i][j];
        }

        printf("%-10d\n", branchTotal);
    }

    // Print total sales for each item
    printf("%-10s", "TOTAL");
    for (int j = 0; j < NUM_ITEMS; j++) {
        int itemTotal = 0;

        for (int i = 0; i < NUM_BRANCHES; i++) {
            itemTotal += sales[i][j];
        }

        printf("%-10d", itemTotal);
    }

    // Print grand total sales for the chain
    int grandTotal = 0;
    for (int i = 0; i < NUM_BRANCHES; i++) {
        for (int j = 0; j < NUM_ITEMS; j++) {
            grandTotal += sales[i][j];
        }
    }
    printf("%-10d\n", grandTotal);

    return 0;
}
