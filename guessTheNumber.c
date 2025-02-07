#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int total_score = 0, lives = 0, user_input = 0;

    srand(time(0));

    while (lives != 3) {
        int random_number = rand() % 10 + 1;
        printf("\n%d%s Guess (Enter a number between 1 and 10): ", lives + 1, (lives == 0) ? "st" : (lives == 1) ? "nd" : "rd");
        scanf("%d", &user_input);

        // Input validation
        if (user_input < 1 || user_input > 10) {
            printf("Invalid input! Please enter a number between 1 and 10.\nYou lost 1 point.\n");
            total_score -= 1;
        }
        // Correct guess
        else if (user_input == random_number) {
            printf("That's correct!\nYou got 15 points!\n");
            total_score += 15;
        }
        // Incorrect guess
        else {
            printf("Unfortunately, the correct number was %d.\n", random_number);
            int penalty = abs(user_input - random_number);  // Positive penalty based on distance
            total_score += (10 - penalty);  // Closer guesses get more points
        }

        lives++;
    }

    printf("\nTotal Score: %d\n", total_score);

    return 0;
}
