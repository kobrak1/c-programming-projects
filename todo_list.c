#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100
#define TASK_LENGTH 100

// Structure to represent a task
typedef struct {
    char description[TASK_LENGTH];
    int completed;
} Task;

// Array to store tasks
Task tasks[MAX_TASKS];
int task_count = 0;

// Function to add a task
void add_task() {
    if (task_count >= MAX_TASKS) {
        printf("To-do list is full!\n");
        return;
    }

    printf("Enter the task description: ");
    getchar(); // Clear the input buffer
    fgets(tasks[task_count].description, TASK_LENGTH, stdin);
    tasks[task_count].description[strcspn(tasks[task_count].description, "\n")] = '\0'; // Remove newline character
    tasks[task_count].completed = 0; // Mark task as incomplete
    task_count++;
    printf("Task added successfully!\n");
}

// Function to view all tasks
void view_tasks() {
    if (task_count == 0) {
        printf("No tasks available.\n");
        return;
    }

    printf("To-Do List:\n");
    for (int i = 0; i < task_count; i++) {
        printf("%d. %s [%s]\n", i + 1, tasks[i].description, tasks[i].completed ? "Completed" : "Pending");
    }
}

// Function to mark a task as completed
void complete_task() {
    int task_number;
    view_tasks();
    printf("Enter the task number to mark as completed: ");
    scanf("%d", &task_number);

    if (task_number < 1 || task_number > task_count) {
        printf("Invalid task number!\n");
        return;
    }

    tasks[task_number - 1].completed = 1;
    printf("Task marked as completed!\n");
}

// Function to delete a task
void delete_task() {
    int task_number;
    view_tasks();
    printf("Enter the task number to delete: ");
    scanf("%d", &task_number);

    if (task_number < 1 || task_number > task_count) {
        printf("Invalid task number!\n");
        return;
    }

    for (int i = task_number - 1; i < task_count - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    task_count--;
    printf("Task deleted successfully!\n");
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n--- To-Do List Menu ---\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Mark Task as Completed\n");
        printf("4. Delete Task\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_task();
                break;
            case 2:
                view_tasks();
                break;
            case 3:
                complete_task();
                break;
            case 4:
                delete_task();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
