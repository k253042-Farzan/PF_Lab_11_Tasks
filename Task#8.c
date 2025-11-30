#include <stdio.h>

#define M_TO_KM 0.001  // constant for meter to kilometer conversion

double convertToKilometer(double meters) {
    static int callCount = 0;  
    callCount++;

    printf("Function called %d times\n", callCount);
    return meters * M_TO_KM;
}

int main() {
    double meters, km;
    char choice;

    do {
        printf("Enter distance in meters: ");
        scanf("%lf", &meters);

        km = convertToKilometer(meters);
        printf("%.2lf meters = %.3lf kilometers\n", meters, km);

        printf("Do you want to convert another value? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

