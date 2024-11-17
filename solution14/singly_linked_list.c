#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data ;
    struct Node *next ;
};
struct Node *start=NULL;
struct Node *lastnode=NULL;

void display()
{
    struct Node *temp=start ;
    printf("\nList is : ");
    while (temp!=NULL) {
        printf("%d ",temp->data);
        temp=temp->next ;
    }
}
void create()
{
    struct Node *node;
    int n , i ;
    printf("\nKitne node ki list banani hai bata de : ");
    scanf("%d",&n);
    printf("\n");
    for(i=0 ; i<n ; i++) {
        node = malloc (sizeof(struct Node ));
        printf("Enter data to node %d : " , i);
        scanf("%d",&node->data);
        node ->next = NULL;

        if(start==NULL) {
            lastnode = start = node ;
        }
        else {
            lastnode->next = node ;
            lastnode = node  ;
        }
    }
}
void insertatbegin()
{
    struct Node *node = malloc(sizeof(struct Node));
    printf("\nEnter data of the node which added at begining : ");
    scanf("%d",&node->data);
    node->next=NULL;

    if(start==NULL) {
        lastnode = start = node ;
    }
    else {
        node->next=start ;
        start=node ;
    }
}
void insertatend()
{
    printf("\n");
    struct Node *node = malloc(sizeof(struct Node));
    printf("\nEnter data of the node which added at end : ");
    scanf("%d",&node->data);
    node->next=NULL;

    if(start==NULL) {
        lastnode = start = node ;
    }
    else {
        lastnode->next=node ;
        lastnode=node ;
    }
}
void deleteatbegin()
{
    if(start==NULL) {
        printf("\nList is empty...");
    }
    else if(start->next==NULL) {
        printf("\n%d ko list ke shuru se delete kar rahe hai " , start->data) ;
        free(start);
        start==NULL;
    }
    else {
        struct Node *temp=start ;
        start = start->next ;

        printf("\n%d ko list ke shuru se mita rahe hain " ,temp->data);

        free(temp);
    }
}
void deleteatend(){
     if(start==NULL) {
        printf("\nList is empty...");
    }
    else if(start->next==NULL) {
        printf("\n%d Deleted from end " , start->data) ;
        free(start);
        start=lastnode=NULL;
    }
    else {
        struct Node *temp=start ;
        while(temp->next!=lastnode) {
            temp=temp->next;
        }
        printf("\n%d Deleted from end " ,temp->data);
        temp->next=NULL;
        free(lastnode);
        lastnode = temp ;
    }
}
int main()
{
    create();
    display();
    insertatbegin();
    display();
    insertatend();
    display();
    deleteatbegin();
    display();
    deleteatend();
    display();
    return 0 ;
}