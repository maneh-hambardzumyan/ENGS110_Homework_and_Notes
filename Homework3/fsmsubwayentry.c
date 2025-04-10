#include <stdio.h>

// Defining states of the subway entry system
typedef enum {
    WAITING_FOR_CARD,
    CARD_INSERTED,
    VALIDATING_CARD,
    ACCESS_GRANTED,
    ACCESS_DENIED,
    ENTERING_PLATFORM
} State;

// Defining events that trigger state transitions
typedef enum {
    INSERT_CARD,
    VALIDATE_CARD,
    GRANT_ACCESS,
    DENY_ACCESS,
    ENTER_PLATFORM
} Event;

State currentState = WAITING_FOR_CARD;

// Handles events and transitions between states
void handleEvent(Event event) {
    switch (currentState) {
        case WAITING_FOR_CARD:
            if (event == INSERT_CARD) {
                currentState = CARD_INSERTED;
                printf("Card inserted.\n");
            }
            break;

        case CARD_INSERTED:
            if (event == VALIDATE_CARD) {
                currentState = VALIDATING_CARD;
                printf("Validating card...\n");
            }
            break;

        case VALIDATING_CARD:
            if (event == GRANT_ACCESS) {
                currentState = ACCESS_GRANTED;
                printf("Access granted. You may enter the platform.\n");
            } else if (event == DENY_ACCESS) {
                currentState = ACCESS_DENIED;
                printf("Access denied.\n");
            }
            break;

        case ACCESS_GRANTED:
            if (event == ENTER_PLATFORM) {
                currentState = ENTERING_PLATFORM;
                printf("Entering platform...\n");
            }
            break;

        case ACCESS_DENIED:
            if (event == INSERT_CARD) {
                currentState = CARD_INSERTED;
                printf("Card inserted. Trying again...\n");
            }
            break;

        case ENTERING_PLATFORM:
            printf("Already in the platform.\n");
            break;
    }
}

// Function to guide the user step-by-step
void runInteractiveFlow() {
    int choice;

    while (currentState != ENTERING_PLATFORM) {
        switch (currentState) {
            case WAITING_FOR_CARD:
                printf("\nPlease insert your card (enter 1): ");
                scanf("%d", &choice);
                if (choice == 1) {
                    handleEvent(INSERT_CARD);
                } else {
                    printf("Invalid input. Please insert your card.\n");
                }
                break;

            case CARD_INSERTED:
                printf("\nValidate your card (enter 1): ");
                scanf("%d", &choice);
                if (choice == 1) {
                    handleEvent(VALIDATE_CARD);
                } else {
                    printf("Invalid input. Please validate your card.\n");
                }
                break;

            case VALIDATING_CARD:
                printf("\nValidation result — enter 1 to grant access or 2 to deny: ");
                scanf("%d", &choice);
                if (choice == 1) {
                    handleEvent(GRANT_ACCESS);
                } else if (choice == 2) {
                    handleEvent(DENY_ACCESS);
                } else {
                    printf("Invalid input. Please choose 1 (grant) or 2 (deny).\n");
                }
                break;

            case ACCESS_GRANTED:
                printf("\nEnter the platform (enter 1): ");
                scanf("%d", &choice);
                if (choice == 1) {
                    handleEvent(ENTER_PLATFORM);
                } else {
                    printf("Invalid input. Please enter the platform.\n");
                }
                break;

            case ACCESS_DENIED:
                printf("\nAccess denied. Insert card to try again (enter 1): ");
                scanf("%d", &choice);
                if (choice == 1) {
                    handleEvent(INSERT_CARD);
                } else {
                    printf("Invalid input. Please insert your card to try again.\n");
                }
                break;

            default:
                break;
        }
    }

    printf("\nThank you for using the subway entry system!\n");
}

int main() {
    printf("Welcome to the Subway Entry System!\n");
    runInteractiveFlow();
    return 0;
}
