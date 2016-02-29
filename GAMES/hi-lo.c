#include <stdlib.h>
#include <time.h>

int main() {
    int LOWEST_NUMBER   = 0;    // We will generate between 0 and 500
    int HIGHEST_NUMBER  = 500;
    int MAX_ATTEMPTS    = 9;    // The max tries a user gets before they lose
    // Also note, the log2 of 500 is ~=8.9 - which is the worse case for finding
    // the random number using binary search.  So, if you don't mess up - you 
    // will win every time.  Lower this number to make the game harder (impossible?)
    // and raise it to make the game easier.
    int currentAttempts = 0;
    // Generate a pseudorandom number
    srand(time(NULL)); 
    int r = rand() % HIGHEST_NUMBER + LOWEST_NUMBER;
    // Game loop - when we finish we will "break" out
    printf("Hi-lo - from %d to %d\n\n", LOWEST_NUMBER, HIGHEST_NUMBER);
    while (1) {
        printf("Guess my number: ");
        int s;
        scanf("%d", &s);    // Store a user-entered integer value into s
        if ( s == r ) {
            printf("Correct!\n");
            break;
        }
        currentAttempts++;
        if (currentAttempts >= MAX_ATTEMPTS) {
            printf("You lose, too many tries!  The number was %d\n", r);
            break;
        }
        printf("Incorrect -- ");
        if ( s > r ) {
            printf("Too high!\n");
        }
        else if ( s < r ) {
            printf("Too low!\n");
        }
        printf("Attempts left: %d\n", MAX_ATTEMPTS - currentAttempts);
    }
    printf("Thanks for playing!\n");
    return 0;
}
