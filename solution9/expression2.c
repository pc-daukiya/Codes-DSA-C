//Write a program to convert infix expression in  prefix expression using stack
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 50

char stack[MAX];
int top = -1 ;

void push(char item) {
    if (top == MAX - 1) {
        printf("Stack is full\n");
        return;
    }
    stack[++top] = item;
}

char pop() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top--];
}

char peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX - 1;
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

void infixToPrefix(char infix[], char prefix[]) {
    int i, j = 0;
    char temp;

    strrev(infix);

    for (i = 0; infix[i] != '\0'; i++) {
        temp = infix[i];

        if (isalnum(temp)) {
            prefix[j++] = temp;
        } else if (temp == ')') {
            push(temp);
        } else if (temp == '(') {
            while ((x = pop()) != ')') {
                prefix[j++] = x;
            }
        } else {
            while (!isEmpty() && precedence(stack[top]) >= precedence(temp)) {
                prefix[j++] = pop();
            }
            push(temp);
        }
    }

    while (!isEmpty()) {
        prefix[j++] = pop();
    }

    prefix[j] = '\0';

    strrev(prefix);
}

void strrev(char str[]) {
    int i, j, temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter the infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strlen(infix) - 1] = '\0'; // remove the newline character

    infixToPrefix(infix, prefix);

    printf("The prefix expression is: %s\n", prefix);

    return 0;
}