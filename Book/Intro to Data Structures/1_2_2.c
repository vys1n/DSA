#include <stdio.h>

#define MAX_READINGS 181

int main() {
    int latitude, temperature, numReadings;
    int sumLatitudes[181] = {0};     // Array to store the sum of temperatures for each latitude
    int countLatitudes[181] = {0};   // Array to store the sum of count of readings at each latitude

    // Input Readings
    while (numReadings < MAX_READINGS) {
        printf("Enter latitude and temperature (separated by a space, -100 to stop giving more readings): ");
        scanf("%d", &latitude);

        // Check for sentinel value to stop input
        if (latitude == -100) {
            break;
        }

        scanf("%d", &temperature);

        // Validate latitude range
        if (latitude < -90 || latitude > 90) {
            printf("Invalid latitude. Latitude should be between -90 and 90.");
            continue;
        }

        // Update sum and count arrays
        sumLatitudes[latitude + 90] += temperature;
        countLatitudes[latitude + 90]++;
        numReadings++;
    }

    printf("\nLatitude\tAverage Temperature\n");

    // print average temperatures for each latitude
    for (int i = 0; i <= 180; i++) {
        int latitude = i - 90;
        if (countLatitudes[i] > 0) {
            float averageTemperature = (float) sumLatitudes[i] / countLatitudes[i];
            printf("%d\t\t%.2f\n", latitude, averageTemperature);
        }
        else {
            printf("%d\t\tNO DATA\n", latitude);
        }
    }

    // Calculate average temperature in Northern and Sourthern Hemispheres
    float northernAverage = 0, southernAverage = 0;
    int northernCount = 0, southernCount = 0;

    for (int i = 1; i <= 90; i++) {
        northernAverage += sumLatitudes[i + 90];
        northernCount += countLatitudes[i + 90];
    }

    for (int i = -1; i >= -90; i--) {
        southernAverage += sumLatitudes[i + 90];
        southernCount += countLatitudes[i + 90];
    }

    if (northernCount > 0) {
        northernAverage /= northernCount;
    }

    if (southernCount > 0) {
        southernAverage /= southernCount;
    }

    printf("\nNorthern Hemisphere average temperature: %.2f\n", northernAverage);
    printf("Southern Hemisphere average temperature: %.2f\n", southernAverage);

    // Determine which hemisphere is warmer
    if (northernAverage > southernAverage) {
        printf("The Northern Hemisphere is warmer.\n");
    }
    else if (northernAverage < southernAverage) {
        printf("The Southern Hemisphere is warmer.\n");
    }
    else {
        printf("The Northern and Southern Hemisphere are equally warm.\n");
    }

    return 0;
}
