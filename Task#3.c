#include <stdio.h>
#include <string.h>

struct Flight {
    int flightNumber;
    char departure[50];
    char destination[50];
    char date[20];
    int seats;
};

void displayFlight(struct Flight f) {
    printf("\nFlight Details:\n");
    printf("Flight Number: %d\n", f.flightNumber);
    printf("Departure: %s\n", f.departure);
    printf("Destination: %s\n", f.destination);
    printf("Date: %s\n", f.date);
    printf("Available Seats: %d\n", f.seats);
}

void bookSeat(struct Flight *f) {
    if (f->seats > 0) {
        f->seats--;
        printf("\nSeat booked successfully!\n");
    } else {
        printf("\nNo seats available!\n");
    }
}

int main() {
    struct Flight f;

    printf("Enter flight number: ");
    scanf("%d", &f.flightNumber);

    printf("Enter departure city: ");
    scanf("%s", f.departure);

    printf("Enter destination city: ");
    scanf("%s", f.destination);

    printf("Enter date: ");
    scanf("%s", f.date);

    printf("Enter available seats: ");
    scanf("%d", &f.seats);

    int choice;

    do {
        printf("\n1. Book Seat\n2. Display Flight Details\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bookSeat(&f);
                break;
            case 2:
                displayFlight(f);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 3);

    return 0;
}

