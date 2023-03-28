## Stack
This is a simple implementation of a stack in C language. A stack is a linear data structure that follows the Last-In-First-Out (LIFO) principle, i.e., the element that is inserted last will be the first one to be removed. This implementation provides various functionalities like creating a stack, pushing an element into the stack, popping an element from the stack, and printing the elements in the stack.

### Use cases of Stack
Stacks have various applications in computer science, such as:

- Expression evaluation and syntax parsing
- Implementing function calls and recursion in programming languages
- Memory management in compilers and operating systems
- Undo/redo functionality in text editors and image processing software
- Implementing backtracking algorithms, such as depth-first search

### Working Principle of this Code
This implementation defines a stack of maximum size `MAXSIZE` and initializes the top index `top` to `-1`. The code provides five functions to operate on the stack:

- `isEmpty()`: checks if the stack is empty
- `isFull()`: checks if the stack is full
- `peek()`: gets the element at the top of the stack
- `pop()`: removes an element from the top of the stack
- `push()`: adds an element to the top of the stack

The `createStack()` function allows the user to create a stack based on their input. It prompts the user to enter the number of elements they want to push into the stack and then prompts them to enter each element. If the number of elements entered by the user exceeds the maximum stack size, an error message is displayed.

The `printStack()` function prints all the elements in the stack, starting from the top.

In the `main()` function, a menu-driven approach is used to allow the user to perform the following operations:

1. Create stack
2. Print stack
3. Push element into stack
4. Pop element from stack
5. Exit program

The program will keep running until the user chooses to exit.

### Code Explanation

Let's go through each function and understand its purpose and implementation:

```c
#include <stdio.h>

#define MAXSIZE 8
int stack[MAXSIZE];
int top = -1;
```
Initializing the stack


```c
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
```
This function creates a stack based on the user's input. It asks the user to enter the number of elements they want to add to the stack and reads their input. If the number of elements is greater than the maximum size of the stack, it prints an error message and returns. Otherwise, it uses a loop to ask the user for each element they want to add to the stack and reads their input. It then calls the push function to add each element to the stack.


```c
// function to check if stack is empty
int isEmpty() {
    if(top == -1)
        return 1;
    else
        return 0;
}
```
This code defines a function named "isEmpty" that checks whether the stack is empty or not. It does this by checking the value of a variable named "top". If "top" is equal to -1, then the stack is empty, so the function returns 1 (which means true). If "top" is not equal to -1, then the stack is not empty, so the function returns 0 (which means false). The code basically just checks whether the top of the stack has a value or not, and returns true or false accordingly.


```c
// function to check if stack is full
int isFull() {
    if(top == MAXSIZE)
        return 1;
    else
        return 0;
}
```
This is a function named isFull that checks whether the stack is full or not. It does this by comparing the current value of top (which represents the index of the last element in the stack) with the maximum size of the stack (MAXSIZE). If the value of top is equal to MAXSIZE, then the stack is considered full and the function returns 1. Otherwise, the stack is not full and the function returns 0.


```c
// function to print the elements in the stack
void printStack() {
    if(isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Elements in the stack: ");
    for(int i = top; i >= 0; i--) {
        printf("=> %d ", stack[i]);
    }
}
```
This code defines a function named printStack() which prints all the elements present in the stack. First, it checks if the stack is empty or not by calling the isEmpty() function. If the stack is empty, it prints a message saying "Stack is empty" and exits the function using the return statement.

If the stack is not empty, the function prints a message saying "Elements in the stack:" and then starts a loop to print all the elements present in the stack. The loop starts from the top of the stack (which is stored in the variable top) and goes down to the bottom of the stack (which is at index 0).

For each element in the stack, the function prints its value using the printf() function. In this code, the elements are printed with an arrow symbol (=>) before the element value. Finally, the function ends when all elements in the stack have been printed.


```c
// function to add an element to the top of stack
int push(int data) {
    if(!isFull()) {
        top = top + 1;
        stack[top] = data;
    } else {
        printf("Could not insert data, Stack is full.\n");
    }
}
```
This function adds an element to the top of a stack data structure. It first checks if the stack is not full by calling the isFull() function. If the stack is not full, the function increments the top variable to point to the next empty location in the stack, and inserts the data value into the stack at that location. If the stack is full, the function prints an error message indicating that the data could not be inserted, since the stack is already full.


```c
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
```
This function is used to remove an element from the top of the stack. It first checks whether the stack is empty or not using the isEmpty() function. If the stack is not empty, it removes the element from the top of the stack and updates the value of top to point to the new top element. Then, it returns the removed element. If the stack is empty, it prints an error message saying that the stack is empty and returns nothing.


```c
int main() {
    int choice, data;
    printf("\n========== Stack Operations ==========\n");
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
                printf("\n");
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
```
The program uses a do-while loop to keep displaying the menu and asking the user for their choice until they choose to exit the program. When the user selects an operation from the menu, the program uses a switch-case statement to execute the appropriate function based on the user's choice.

For example, if the user chooses to create a stack, the program calls the createStack() function which asks the user to enter the number of elements they want to add to the stack and then prompts them to enter those elements one by one. The program then adds those elements to the stack using the push() function.

If the user chooses to print the stack, the program calls the printStack() function which displays all the elements in the stack from top to bottom.

If the user chooses to push an element into the stack, the program prompts the user to enter the element they want to push, and then calls the push() function to add that element to the top of the stack.

If the user chooses to pop an element from the stack, the program calls the pop() function which removes the top element from the stack and returns it.

If the user chooses to exit the program, the program simply displays a message and exits. If the user enters an invalid choice, the program displays an error message and asks the user to try again.


### Sample Output
```bash
/tmp/YH771lupc6.o
========== Stack Operations ==========

Menu:
1. Create stack
2. Print stack
3. Push element into stack
4. Pop element from stack
5. Exit program

Enter your choice: 1
Enter the number of elements to be pushed into the stack (max size: 8): 4
Enter element 1: 1
Enter element 2: 2
Enter element 3: 3
Enter element 4: 4
Menu:
1. Create stack
2. Print stack
3. Push element into stack
4. Pop element from stack
5. Exit program

Enter your choice: 2
Elements in the stack: => 4 => 3 => 2 => 1 
Menu:
1. Create stack
2. Print stack
3. Push element into stack
4. Pop element from stack
5. Exit program

Enter your choice: 3
Enter element to be pushed: 76
Menu:
1. Create stack
2. Print stack
3. Push element into stack
4. Pop element from stack
5. Exit program

Enter your choice: 2
Elements in the stack: => 76 => 4 => 3 => 2 => 1 
Menu:
1. Create stack
2. Print stack
3. Push element into stack
4. Pop element from stack
5. Exit program

Enter your choice: 4
Popped element: 76

Menu:
1. Create stack
2. Print stack
3. Push element into stack
4. Pop element from stack
5. Exit program

Enter your choice: 2
Elements in the stack: => 4 => 3 => 2 => 1 
Menu:
1. Create stack
2. Print stack
3. Push element into stack
4. Pop element from stack
5. Exit program

Enter your choice: 5
Exiting program...

```

Thanks for reading!