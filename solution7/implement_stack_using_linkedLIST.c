#include <stdio.h>
#include <stdlib.h>

// Define the structure for a stack node
typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

// Define the structure for a stack
typedef struct Stack {
    StackNode* top;
    int size;
} Stack;

// Function to create a new stack node
StackNode* createStackNode(int data) {
    StackNode* node = (StackNode*) malloc(sizeof(StackNode));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to create a new stack
Stack* createStack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    StackNode* node = createStackNode(data);
    node->next = stack->top;
    stack->top = node;
    stack->size++;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    int data = stack->top->data;
    StackNode* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return data;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Function to get the size of the stack
int size(Stack* stack) {
    return stack->size;
}

// Function to print the stack
void printStack(Stack* stack) {
    StackNode* temp = stack->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack* stack = createStack();

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    printf("Stack: ");
    printStack(stack);

    printf("Popped: %d\n", pop(stack));
    printf("Stack: ");
    printStack(stack);

    printf("Size: %d\n", size(stack));

    return 0;
}