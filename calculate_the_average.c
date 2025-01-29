#include <stdio.h>
#include <stdlib.h>

int* getTheArray(int *size) {
    printf("Enter the number of elements (max 20): ");
    scanf("%d", size);

    if (*size > 20 || *size <= 0) {
        printf("Invalid size. Must be between 1 and 20.\n");
        return NULL;
    }

    int *arr = (int*)malloc(*size * sizeof(int)); // Allocates a dynamic memory for the user input according to indicated size entered by user
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    printf("Enter %d elements: ", *size);
    for (int i = 0; i < *size; i++) {
        scanf("%d", &arr[i]);
    }

    return arr;
}

int main() {
    int total = 0;
    int size;
    int *input = getTheArray(&size);

    if (input == NULL) {
        printf("No valid input has been entered.\n");
        return 1;
    }

    printf("Input entered: ");

    // Prints each item in the list and adds their values to the total variable
    for (int i = 0; i < size; i++) {
        total += input[i];
        printf("%d ", input[i]);
    }
    printf("\n");
    printf("Average: %d", total / size); // Prints the average of total

    free(input); // Frees allocated memory
    return 0;
}
