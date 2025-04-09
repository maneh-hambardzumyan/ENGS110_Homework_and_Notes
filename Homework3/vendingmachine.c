#include <stdio.h>

// Define the states of the vending machine
typedef enum {
    WAITING_FOR_COINS,    // The machine is waiting for coins
    COINS_INSERTED,       // Coins are inserted, awaiting product selection
    DISPENSE_PRODUCT,     // Product is being dispensed
    OUT_OF_STOCK          // The product is out of stock
} State;

// Define events that trigger state transitions
typedef enum {
    INSERT_COIN,          // Event when a coin is inserted
    SELECT_PRODUCT,       // Event when a product is selected
    DISPENSED_PRODUCT,    // Event when a product is dispensed
    OUT_OF_STOCK_EVENT    // Event when the selected product is out of stock
} Event;

// Current state of the vending machine
State currentState = WAITING_FOR_COINS;
int insertedCoins = 0;
int productPrice = 2; // Assume the product price is 2 units

// Function to handle events and transition between states
void handleEvent(Event event) {
    switch (currentState) {
        case WAITING_FOR_COINS:
            if (event == INSERT_COIN) {
                insertedCoins++;
                printf("Coin inserted. Total coins: %d\n", insertedCoins);
                currentState = COINS_INSERTED;  // Transition to coin inserted state
            }
            break;

        case COINS_INSERTED:
            if (event == SELECT_PRODUCT) {
                if (insertedCoins >= productPrice) {
                    currentState = DISPENSE_PRODUCT;  // Transition to dispensing product state
                    insertedCoins -= productPrice;   // Deduct the product price from inserted coins
                    printf("Product selected. Dispensing product...\n");
                } else {
                    printf("Not enough coins. Please insert more coins.\n");
                }
            }
            break;

        case DISPENSE_PRODUCT:
            if (event == DISPENSED_PRODUCT) {
                currentState = WAITING_FOR_COINS;  // Transition back to waiting for coins state
                printf("Product dispensed. Please take your product.\n");
            }
            break;

        case OUT_OF_STOCK:
            if (event == OUT_OF_STOCK_EVENT) {
                printf("Selected product is out of stock.\n");
                currentState = WAITING_FOR_COINS;  // Transition back to waiting for coins state
            }
            break;
    }
}

int main() {
    int choice;
    int isRunning = 1;

    // Simulate the vending machine operation interactively
    printf("Welcome to the Interactive Vending Machine!\n");

    while (isRunning) {
        // Display current state information
        printf("\nCurrent state: ");
        switch (currentState) {
            case WAITING_FOR_COINS:
                printf("Waiting for coins.\n");
                break;
            case COINS_INSERTED:
                printf("Coins inserted, awaiting product selection.\n");
                break;
            case DISPENSE_PRODUCT:
                printf("Dispensing product.\n");
                break;
            case OUT_OF_STOCK:
                printf("Out of stock.\n");
                break;
        }

        // Provide options to the user
        printf("\nChoose an action:\n");
        if (currentState == WAITING_FOR_COINS || currentState == COINS_INSERTED) {
            printf("1. Insert Coin\n");
        }
        if (currentState == COINS_INSERTED) {
            printf("2. Select Product\n");
        }
        if (currentState == DISPENSE_PRODUCT) {
            printf("3. Dispense Product\n");
        }
        if (currentState != OUT_OF_STOCK) {
            printf("4. Quit\n");
        } else {
            printf("5. Reset and start over\n");
        }
        
        // Get user input
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handle user's choice
        switch (choice) {
            case 1:
                if (currentState == WAITING_FOR_COINS || currentState == COINS_INSERTED) {
                    handleEvent(INSERT_COIN);  // Insert coin event
                } else {
                    printf("Invalid option for the current state.\n");
                }
                break;
            case 2:
                if (currentState == COINS_INSERTED) {
                    handleEvent(SELECT_PRODUCT);  // Select product event
                } else {
                    printf("Please insert enough coins first.\n");
                }
                break;
            case 3:
                if (currentState == DISPENSE_PRODUCT) {
                    handleEvent(DISPENSED_PRODUCT);  // Dispense product event
                } else {
                    printf("No product selected yet.\n");
                }
                break;
            case 4:
                if (currentState != OUT_OF_STOCK) {
                    isRunning = 0;  // Quit the program
                    printf("Thank you for using the Vending Machine! Goodbye!\n");
                }
                break;
            case 5:
                if (currentState == OUT_OF_STOCK) {
                    currentState = WAITING_FOR_COINS;
                    insertedCoins = 0;
                    printf("Vending machine reset. Start over.\n");
                }
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}
