#include <stdio.h>
#include <string.h>

#define MAX_PLAYERS 100

struct Player {
    char name[50];
    int age;
    char position[30];
};

struct Team {
    char teamName[50];
    char sport[30];
    struct Player players[MAX_PLAYERS];
    int playerCount;
};

void addPlayer(struct Team *t) {
    int i = t->playerCount;

    printf("Enter player name: ");
    scanf(" %[^\n]", t->players[i].name);

    printf("Enter age: ");
    scanf("%d", &t->players[i].age);

    printf("Enter position: ");
    scanf(" %[^\n]", t->players[i].position);

    t->playerCount++;

    printf("Player added successfully!\n");
}

void searchByPosition(struct Team t) {
    char searchPos[30];
    int found = 0;
    int i;

    printf("Enter position to search: ");
    scanf(" %[^\n]", searchPos);

    printf("\nPlayers with position '%s':\n", searchPos);

    for (i = 0; i < t.playerCount; i++) {
        if (strcmp(t.players[i].position, searchPos) == 0) {
            printf("\nName: %s\n", t.players[i].name);
            printf("Age: %d\n", t.players[i].age);
            found = 1;
        }
    }

    if (!found)
        printf("No players found with this position.\n");
}

void displayTeam(struct Team t) {
    int i;

    printf("\n--- Team Details ---\n");
    printf("Team Name: %s\n", t.teamName);
    printf("Sport: %s\n", t.sport);
    printf("Total Players: %d\n", t.playerCount);

    for (i = 0; i < t.playerCount; i++) {
        printf("\nPlayer %d:\n", i + 1);
        printf("Name: %s\n", t.players[i].name);
        printf("Age: %d\n", t.players[i].age);
        printf("Position: %s\n", t.players[i].position);
    }
}

int main() {
    struct Team team;
    int choice;

    team.playerCount = 0;

    printf("Enter team name: ");
    scanf(" %[^\n]", team.teamName);

    printf("Enter sport: ");
    scanf(" %[^\n]", team.sport);

    do {
        printf("\n--- Team Menu ---\n");
        printf("1. Add Player\n");
        printf("2. Search Player by Position\n");
        printf("3. Display Team Details\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPlayer(&team);
                break;
            case 2:
                searchByPosition(team);
                break;
            case 3:
                displayTeam(team);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 4);

    return 0;
}

