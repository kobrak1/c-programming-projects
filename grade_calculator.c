#include <stdio.h>

int main() {
    int final = 0, midterm = 0, quiz = 0;

    printf("Final Grade(60%%):");
    scanf("%d", &final);

    printf("Midterm Grade(30%%):");
    scanf("%d", &midterm);

    printf("Quiz Grade(10%%):");
    scanf("%d", &quiz);

    float final_weight = final * 0.6;
    float midterm_weight = midterm * 0.3;
    float quiz_weight = quiz * 0.1;

    // Final result
    float sum_of_all_grades = final_weight + midterm_weight + quiz_weight;
    printf("Total Grade: %f", sum_of_all_grades);

    return 0;
}
