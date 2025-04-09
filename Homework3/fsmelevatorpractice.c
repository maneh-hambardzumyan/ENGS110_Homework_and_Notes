#include <stdio.h>

// Define states of the elevator door system
typedef enum {
    DOOR_CLOSED,
    DOOR_OPEN,      
    DOOR_OPENING,   
    DOOR_CLOSING    
} State;

// Define events that trigger state transitions
typedef enum {
    PRESS_OPEN_BUTTON,  
    PRESS_CLOSE_BUTTON, 
    DOOR_OPENED,        
    DOOR_CLOSED_EVENT   
} Event;

// Current state of the elevator door system
State currentState = DOOR_CLOSED;

// Function to handle events and transition between states
void handleEvent(Event event) {
    switch (currentState) {
        case DOOR_CLOSED:
            if (event == PRESS_OPEN_BUTTON) {
                currentState = DOOR_OPENING;  // Transition to opening state
                printf("Door is opening...\n");
            }
            break;

        case DOOR_OPEN:
            if (event == PRESS_CLOSE_BUTTON) {
                currentState = DOOR_CLOSING;  // Transition to closing state
                printf("Door is closing...\n");
            }
            break;

        case DOOR_OPENING:
            if (event == DOOR_OPENED) {
                currentState = DOOR_OPEN;  // Transition for opening the state
                printf("Door is fully open.\n");
            }
            break;

        case DOOR_CLOSING:
            if (event == DOOR_CLOSED_EVENT) {
                currentState = DOOR_CLOSED;  // Transition for closing the state
                printf("Door is fully closed.\n");
            }
            break;
    }
}

int main() {
    // Simulating a sequence of inputs and printing results
    printf("Elevator Door Simulation begins:\n");

    // Door is initially closed
    handleEvent(PRESS_OPEN_BUTTON);   
    handleEvent(DOOR_OPENED);         
    handleEvent(PRESS_CLOSE_BUTTON);  
    handleEvent(DOOR_CLOSED_EVENT);   
    

    return 0;
}
