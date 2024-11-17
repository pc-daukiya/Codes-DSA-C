#include <stdio.h>
// #include <stdlib.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int data)
{
    if (front==0 && rear == SIZE-1 || rear+1==front)
    {
        printf("\nQueue is full...");
    }
    else
    {
        if (front == -1)
        {
            front = rear = 0;
            queue[rear] = data;
        }
        else if(rear==SIZE-1) {
            rear = 0 ;
            queue[rear] = data ;
        }
        else
        {
            rear++;
            queue[rear] = data;
        }
        printf("\n%d added to queue", data);
    }
}
void dequeue()
{
    if (front == -1){
        printf("\nQueue is Empty...");
    }
    else
    {
        int data = queue[front];
        queue[front] = 0;

        if(front == rear) {
            front = -1 ;
            rear = -1 ;
        }
        else {
            front++ ;
            if(front==SIZE) 
            front = 0 ;
        }
        
        printf("\n%d removed from queue ",data);

        // if(front>rear) {
        //     front = rear = -1 ;
        // }
    }   
}

int main()
{
    dequeue();
    enqueue(100);
    enqueue(200);
    enqueue(300);
    enqueue(400);
    enqueue(500);
    enqueue(600);

    dequeue();
    dequeue();dequeue();dequeue();dequeue();dequeue();dequeue();
    
}