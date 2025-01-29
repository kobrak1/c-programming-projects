#include <stdlib.h>

int getUserInput(int *addr) {
    printf("Enter Celcius: ");
    scanf("%d", addr);
    return *addr;
}

int main() {
    int userInput;
    int celcius = getUserInput(&userInput);
    printf("Fahrenheit: %d \n", (celcius * 9/5) + 32);

    printf("Press enter to exit the program...");
    getchar();
    getchar();

    return 0;
}
