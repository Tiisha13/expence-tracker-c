#include <stdio.h>

#define MAX_EXPENSES 100

typedef struct {
    char description[50];
    float amount;
} Expense;

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;
    char choice;

    while (1) {
        printf("Expense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        if (choice == '1') {
            if (count >= MAX_EXPENSES) {
                printf("Expense limit reached.\n");
                continue;
            }

            printf("Enter description: ");
            scanf(" %49[^\n]", expenses[count].description);
            printf("Enter amount: ");
            scanf("%f", &expenses[count].amount);
            count++;
        } else if (choice == '2') {
            float total = 0;
            printf("Expenses:\n");
            for (int i = 0; i < count; i++) {
                printf("%d. %s - $%.2f\n", i + 1, expenses[i].description, expenses[i].amount);
                total += expenses[i].amount;
            }
            printf("Total expenses: $%.2f\n", total);
        } else if (choice == '3') {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}