#include <stdio.h>

int main() {
    int A = 0, B = 0, no_results = 0, total_vote, choice;

    printf("How many votes do you want to cast?\n");
    scanf("%d", &total_vote);

    for (int i = 1; i <= total_vote; i++) {
        printf("Welcome to the voting system:\n");
        printf("Enter 1 to vote for A\n");
        printf("Enter 2 to vote for B\n");
        printf("Enter 3 to vote for none\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                A++;
                break;
            case 2:
                B++;
                break;
            case 3:
                no_results++;
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    printf("A got %d votes\n", A);
    printf("B got %d votes\n", B);
    printf("No results got %d votes\n", no_results);

    if (A > B && A > no_results) {
        printf("**A is the winner\n");
    } else if (B > A && B > no_results) {
        printf("**B is the winner\n");
    } else {
        printf("A and B are tied\n");
    }

    return 0;
}
