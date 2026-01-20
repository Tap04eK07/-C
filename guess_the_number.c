#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
int generate_random_number(int min, int max);
int get_user_guess();
int check_guess(int guess, int target);
void play_game(int range_min, int range_max, int max_attempts);
void display_score(int wins, int losses);

int main() {
    int wins = 0, losses = 0;
    char play_again = 'y';

    srand(time(NULL)); // Seed random number generator

    printf("Welcome to Number Guesser!\n\n");

    while (play_again == 'y' || play_again == 'Y') {
        int difficulty, range_min = 1, range_max, max_attempts;

        printf("Select difficulty:\n");
        printf("1. Easy (1–50, 10 attempts)\n");
        printf("2. Medium (1–100, 7 attempts)\n");
        printf("3. Hard (1–200, 5 attempts)\n");
        printf("> ");

        scanf("%d", &difficulty);

        switch (difficulty) {
            case 1:
                range_max = 50;
                max_attempts = 10;
                break;
            case 2:
                range_max = 100;
                max_attempts = 7;
                break;
            case 3:
                range_max = 200;
                max_attempts = 5;
                break;
            default:
                printf("Invalid choice. Defaulting to Medium.\n");
                range_max = 100;
                max_attempts = 7;
        }

        play_game(range_min, range_max, max_attempts);

        printf("Play again? (y/n) > ");
        scanf(" %c", &play_again);
    }

    display_score(wins, losses);
    return 0;
}

int generate_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int get_user_guess() {
    int guess;
    printf("> ");
    scanf("%d", &guess);
    return guess;
}

int check_guess(int guess, int target) {
    if (guess < target) {
        printf("Too low!\n");
        return -1;
    } else if (guess > target) {
        printf("Too high!\n");
        return 1;
    } else {
        printf("Correct#\n");
        return 0;
    }
}

void play_game(int range_min, int range_max, int max_attempts) {
    int target = generate_random_number(range_min, range_max);
    int attempts = 0;
    int guessed = 0;

    printf("\nGuess the number (%d–%d). You have %d attempts left.\n", 
           range_min, range_max, max_attempts);

    while (attempts < max_attempts && !guessed) {
        int guess = get_user_guess();
        attempts++;

        int result = check_guess(guess, target);
        if (result == 0) {
            guessed = 1;
            printf("You won in %d attempts!\n", attempts);
        } else {
            int remaining = max_attempts - attempts;
            if (remaining > 0) {
                printf("You have %d attempts left.\n", remaining);
            } else {
                printf("No attempts left! The number was %d.\n", target);
            }
        }
    }
}

void display_score(int wins, int losses) {
    printf("\n--- Final Score ---\n");
    printf("Wins: %d\n", wins);
    printf("Losses: %d\n", losses);
}

