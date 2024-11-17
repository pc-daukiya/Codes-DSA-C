#include <stdio.h>
#define SIZE 5

int stack[SIZE];
int top=-1 ;

void push(int data) {
    if (top==SIZE-1) {
        printf("\nStack overflow , %d cannot be pushed ",data);
    }
    else 
    {
        top++;
        stack[top]=data ;
        printf("\n%d pushed into stack ", data);
    }
}
void pop()
    {
        if(top==-1) {
            printf("\nStack underflow , nothing to pop from stack ");
        }
        else {
            int d = stack[top];
            stack[top]=0;
            top--;
            printf("\n%d popped from stack " , d);
        }
    }
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);

    pop();
    pop();
    pop();
    pop();
    pop();
    pop();

    return 0 ;
}