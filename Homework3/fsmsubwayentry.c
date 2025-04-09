#include <stdio.h>

// Defineing states of the subway entry system using an enum to clearly define and group related states and events, making the code, type-safe, and easier to maintain.
typedef enum {
    WAITING_FOR_CARD,  
    CARD_INSERTED,     
    VALIDATING_CARD,   
    ACCESS_GRANTED,   
    ACCESS_DENIED,     
    ENTERING_PLATFORM  
} State;

// Defining events that trigger state transitions using an enum
typedef enum {
    INSERT_CARD,    
    VALIDATE_CARD,  
    GRANT_ACCESS,   
    DENY_ACCESS,    
    ENTER_PLATFORM  
} Event;

// The current state of the system 
State currentState = WAITING_FOR_CARD;

// Function defined to handle events and transition between states
void handleEvent(Event event) {
    // Checking the current state and deciding what to do based on the event
    switch (currentState) {
        case WAITING_FOR_CARD:
            // If the system is waiting for a card and the INSERT_CARD event happens
            if (event == INSERT_CARD) {
                currentState = CARD_INSERTED;  // Transition to the CARD_INSERTED state
                printf("Card inserted.\n");    // Output the action
            }
            break;

        case CARD_INSERTED:
            // If the card has been inserted, the next step is to validate it
            if (event == VALIDATE_CARD) {
                currentState = VALIDATING_CARD;  // Transition to the VALIDATING_CARD state
                printf("Validating card...\n");  // Output the action
            }
            break;

        case VALIDATING_CARD:
            // Once card validation is happening, check the result
            if (event == GRANT_ACCESS) {
                currentState = ACCESS_GRANTED;  // If the card is valid, grant access
                printf("Access granted. You may enter the platform.\n");  // Output the action
            } else if (event == DENY_ACCESS) {
                currentState = ACCESS_DENIED;   // If the card is invalid, deny access
                printf("Access denied.\n");      // Output the action
            }
            break;

        case ACCESS_GRANTED:
            // Once access is granted, the next event is entering the platform
            if (event == ENTER_PLATFORM) {
                currentState = ENTERING_PLATFORM;  // Transition to the ENTERING_PLATFORM state
                printf("Entering platform...\n");  // Output the action
            }
            break;

        case ACCESS_DENIED:
            // If access was denied, the user can try again by inserting a card
            if (event == INSERT_CARD) {
                currentState = CARD_INSERTED;  // Go back to the CARD_INSERTED state
                printf("Card inserted. Trying again...\n");  // Output the action
            }
            break;

        case ENTERING_PLATFORM:
            // Once the user is entering the platform, no more state transitions occur
            printf("Already in the platform.\n");  // Inform that the user is already on the platform
            break;
    }
}

int main() {
    // Simulate a sequence of inputs and print the transitions
    printf("Simulation begins:\n");

    // Simulate inserting a card and granting access
    handleEvent(INSERT_CARD);        
    handleEvent(VALIDATE_CARD);      
    handleEvent(GRANT_ACCESS);       
    handleEvent(ENTER_PLATFORM);     

    // Simulateing access denied scenario
    printf("\nSimulation for access denied begins:\n");
    currentState = WAITING_FOR_CARD; 
    handleEvent(INSERT_CARD);        
    handleEvent(VALIDATE_CARD);      
    handleEvent(DENY_ACCESS);        
    handleEvent(INSERT_CARD);        

    return 0;
}
