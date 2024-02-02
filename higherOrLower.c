#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "datafile.h"

// Function to check the winner based on follower counts
int checkWin(struct Person a, struct Person b) {
    if (a.follower_count > b.follower_count) {
        return 1;  // A has more followers
    } else if (b.follower_count > a.follower_count) {
        return 2;  // B has more followers
    } else {
        return 0;  // Draw
    }
}

// Function for a new turn in the game
void new_turn(struct Person *a, struct Person *b) {
    // Copy person B data to person A
    *a = *b;

    // Print an ASCII art header
    printf("   __  ___       __             \n");
    printf("  / / / (_)___ _/ /_  ___  _____\n");
    printf(" / /_/ / / __ `/ __ \\/ _ \\/ ___/\n");
    printf("/ __  / / /_/ / / / /  __/ /    \n");
    printf("\\/ ///_/\\__, /_/ /_/\\___/_/     \n");
    printf("   / /  /____/_      _____  _____\n");
    printf("  / /   / __ \\ | /| / / _ \\/ ___/\n");
    printf(" / /___/ /_/ / |/ |/ /  __/ /    \n");
    printf("/_____/\____/|__/|__/\\___/_/     \n");

    // Generate a new person B randomly
    *b = data[rand() % (sizeof(data) / sizeof(data[0]))];
    printf("Compare B: %s, %s, %s\n", b->name, b->description, b->country);
}

// Main function where the game is played
int main() {
    srand(time(NULL));  // Seed for random number generation

    // Initialize persons A and B with random data
    struct Person a = data[rand() % (sizeof(data) / sizeof(data[0]))];
    struct Person b = data[rand() % (sizeof(data) / sizeof(data[0]))];

    // Print an ASCII art header for persons A and B
    printf("   __  ___       __             \n");
    printf("  / / / (_)___ _/ /_  ___  _____\n");
    printf(" / /_/ / / __ `/ __ \\/ _ \\/ ___/\n");
    printf("/ __  / / /_/ / / / /  __/ /    \n");
    printf("\\/ ///_/\\__, /_/ /_/\\___/_/     \n");
    printf("   / /  /____/_      _____  _____\n");
    printf("  / /   / __ \\ | /| / / _ \\/ ___/\n");
    printf(" / /___/ /_/ / |/ |/ /  __/ /    \n");
    printf("/_____/\____/|__/|__/\\___/_/     \n");

    // Print details of persons A and B
    printf("Compare A: %s, %s, %s\n", a.name, a.description, a.country);
    printf(" _    __    \n");
    printf("| |  / /____\n");
    printf("| | / / ___/\n");
    printf("| |/ (__  ) \n");
    printf("|___/____(_)\n");
    printf("Compare B: %s, %s, %s\n", b.name, b.description, b.country);

    int game_ends = 0;  // Flag to check if the game should end
    int contador = 0;   // Counter for the score

    while (!game_ends) {
        char input[10];
        printf("Who has more followers? Type 'A' or 'B': ");
        scanf("%s", input);

        if (strcmp(input, "a") == 0) {
            // Check the winner and update the score
            int winner = checkWin(a, b);
            if (winner == 1) {
                printf("You win!\n");
                contador += 1;
            } else if (winner == 2) {
                printf("Sorry, that's wrong. Final score: %d\n", contador);
                game_ends = 1;
                break;
            } else {
                printf("Draw!\n");
                game_ends = 1;
                break;
            }
        } else if (strcmp(input, "b") == 0) {
            // Check the winner and update the score
            int winner = checkWin(a, b);
            if (winner == 1) {
                printf("Sorry, that's wrong. Final score: %d\n", contador);
                game_ends = 1;
                break;
            } else if (winner == 2) {
                printf("You win!\n");
                contador += 1;
            } else {
                printf("Draw!\n");
                game_ends = 1;
                break;
            }
        }

        // If the score is greater than 0, start a new turn
        if (contador > 0) {
            new_turn(&a, &b);
            printf("Current score: %d.\n", contador);

            // Print details of persons A and B for the new turn
            printf("Compare A: %s, %s, %s\n", a.name, a.description, a.country);
            printf(" _    __    \n");
            printf("| |  / /____\n");
            printf("| | / / ___/\n");
            printf("| |/ (__  ) \n");
            printf("|___/____(_)\n");
            printf("Compare B: %s, %s, %s\n", b.name, b.description, b.country);
        }
    }

    return 0;
}
