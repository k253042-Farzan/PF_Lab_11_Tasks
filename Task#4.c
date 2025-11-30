#include <stdio.h>
#include <string.h>

#define MAX 100

struct Movie {
    char title[50];
    char genre[30];
    char director[50];
    int year;
    float rating;
};

void addMovie(struct Movie movies[], int *count) {
    printf("Enter movie title: ");
    scanf(" %[^\n]", movies[*count].title);

    printf("Enter genre: ");
    scanf(" %[^\n]", movies[*count].genre);

    printf("Enter director: ");
    scanf(" %[^\n]", movies[*count].director);

    printf("Enter release year: ");
    scanf("%d", &movies[*count].year);

    printf("Enter rating: ");
    scanf("%f", &movies[*count].rating);

    (*count)++;
    printf("Movie added successfully!\n");
}

void searchByGenre(struct Movie movies[], int count) {
    char searchGenre[30];
    int found = 0;
    int i;

    printf("Enter genre to search: ");
    scanf(" %[^\n]", searchGenre);

    printf("\nMovies in genre '%s':\n", searchGenre);

    for (i = 0; i < count; i++) {
        if (strcmp(movies[i].genre, searchGenre) == 0) {
            printf("\nTitle: %s\n", movies[i].title);
            printf("Director: %s\n", movies[i].director);
            printf("Year: %d\n", movies[i].year);
            printf("Rating: %.1f\n", movies[i].rating);
            found = 1;
        }
    }

    if (!found) {
        printf("No movies found in this genre.\n");
    }
}

void displayMovies(struct Movie movies[], int count) {
    int i;

    if (count == 0) {
        printf("No movies added yet.\n");
        return;
    }

    printf("\nAll Movie Details:\n");
    for (i = 0; i < count; i++) {
        printf("\nMovie %d:\n", i + 1);
        printf("Title: %s\n", movies[i].title);
        printf("Genre: %s\n", movies[i].genre);
        printf("Director: %s\n", movies[i].director);
        printf("Year: %d\n", movies[i].year);
        printf("Rating: %.1f\n", movies[i].rating);
    }
}

int main() {
    struct Movie movies[MAX];
    int count = 0;
    int choice;

    do {
        printf("\n--- Movie Management System ---\n");
        printf("1. Add New Movie\n");
        printf("2. Search Movies by Genre\n");
        printf("3. Display All Movies\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &count);
                break;
            case 2:
                searchByGenre(movies, count);
                break;
            case 3:
                displayMovies(movies, count);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}

