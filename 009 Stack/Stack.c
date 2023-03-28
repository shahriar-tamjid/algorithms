#include <stdio.h>

#define MAXSIZE 8
int stack[MAXSIZE];
int top = -1;

// function to check if stack is empty
int isEmpty() {
    if(top == -1)
        return 1;
    else
        return 0;
}

// function to check if stack is full
int isFull() {
    if(top == MAXSIZE)
        return 1;
    else
        return 0;
}

// function to get the element at the top of stack
int peek() {
    return stack[top];
}

// function to remove an element from the top of stack
int pop() {
    int data;
    if(!isEmpty()) {
        data = stack[top];
        top = top - 1;
        return data;
    } else {
        printf("Could not retrieve data, Stack is empty.\n");
    }
}

// function to add an element to the top of stack
int push(int data) {
    if(!isFull()) {
        top = top + 1;
        stack[top] = data;
    } else {
        printf("Could not insert data, Stack is full.\n");
    }
}

// function to create the stack based on user input
void createStack() {
    int n, data;
    printf("Enter the number of elements to be pushed into the stack (max size: %d): ", MAXSIZE);
    scanf("%d", &n);
    if(n > MAXSIZE) {
        printf("Error: Number of elements exceeds stack size.\n");
        return;
    }
    for(int i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &data);
        push(data);
    }
}

// function to print the elements in the stack
void printStack() {
    if(isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Elements in the stack: ");
    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, data;
    printf("\nWelcome to the Stack Program!\n");
    do {
        printf("\nMenu:\n");
        printf("1. Create stack\n");
        printf("2. Print stack\n");
        printf("3. Push element into stack\n");
        printf("4. Pop element from stack\n");
        printf("5. Exit program\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createStack();
                break;
            case 2:
                printStack();
                break;
            case 3:
                printf("Enter element to be pushed: ");
                scanf("%d", &data);
                push(data);
                break;
            case 4:
                data = pop();
                printf("Popped element: %d\n", data);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 5);
    return 0;
}
