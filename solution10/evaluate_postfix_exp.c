// Write a program to evaluate postfix expression using stack in c 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int isOperator(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 1;
    return 0;
}

int evaluatePostfix(char postfix[]) {
    int i;
    for (i = 0; i < strlen(postfix); i++) {
        if (isOperator(postfix[i])) {
            int op2 = pop() - '0';
            int op1 = pop() - '0';
            int result;
            switch (postfix[i]) {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    result = op1 / op2;
                    break;
            }
            push(result + '0');
        } else {
            push(postfix[i]);
        }
    }
    return pop() - '0';
}

int main() {
    char postfix[100];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);
    printf("Result: %d\n", evaluatePostfix(postfix));
    return 0;
}