#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node*next;
	struct Node*prev;
};
typedef struct Node Node;
Node *start=NULL,*tail=NULL;
void createlist()
{
	Node *q;
	int n,i;
	printf("\nkitne node bnayein:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		q=malloc(sizeof(struct Node));
		printf("Enter data:");
		scanf("%d",&q->data);
		q->next=NULL;
		q->prev=NULL;
		if(start==NULL)
		{
			start=tail=q;
		}
		else
		{
			tail->next=q;
			q->prev=tail;
			tail=q;
		}
	}
}
void displaystart()
{
	Node *q;
	if(start==NULL)
	{
		printf("\nList empty");
	}
	else
	{
		q=start;
		printf("\nList is(from start)");
		while(q!=NULL)
		{
			printf("%d ",q->data);
			q=q->next;
		}
	}
}
void displaytail()
{
	Node *q;
	if(start==NULL)
	printf("\nList empty");
	else
	{
		printf("\nList is(from tail)");
		q=tail;
		while(q!=NULL)
		{
			printf("%d ",q->data);
			q=q->prev;
		}		
	}
}
void insertatbegining()
{
	Node *q;
	q=malloc(sizeof(Node));
	printf("\nEnter data of the node to add at beginig:");
	scanf("%d",&q->data);
	q->next=q->prev=NULL;
	if(start==NULL)
	{
		start=tail=q;
	}
	else
	{
		q->next=start;
		start->prev=q;
		start=q;
	}
}
void insertatmiddle()
{
    Node *q,*p;
    int pos,i;
    printf("\nEnter position to add node:");
    scanf("%d",&pos);
    q=malloc(sizeof(Node));
    printf("\nEnter data of the node to add at middle:");
    scanf("%d",&q->data);
    q->next=q->prev=NULL;
    if(pos==1)
    {
        q->next=start;
        start->prev=q;
        start=q;
    }
    else
    {
        p=start;
        for(i=1;i<pos-1;i++)
        {
            p=p->next;
        }
        q->next=p->next;
        p->next->prev=q;
        p->next=q;
        q->prev=p;
    }
}
void insertatend()
{
	Node *q;
	q=malloc(sizeof(Node));
	printf("\nEnter data of the node to add at the end:");
	scanf("%d",&q->data);
	q->next=q->prev=NULL;
	if(start==NULL)
	{
		start=tail=q;
	}
	else
	{
		tail->next=q;
		q->prev=tail;
		tail=q;
	}
}
void deleteatbegining()
{
	Node *q ;
	if (start==NULL){
		printf("\nList is empty");
	}
	else if(start->next==NULL) {
		printf("\n%d delete kar rahe hai start se ",start->data);
		free(start);
		start=tail=NULL;
	}
	else {
		printf("\n%d delete kar rahe hai start se ",start->data);
		q=start ;
		start=start->next ;
		start->prev=NULL;
		free(q);
	}
}
void deleteatmiddle()
{
    Node *q,*p;
    int pos,i;
    printf("\nEnter position to delete node:");
    scanf("%d",&pos);
    if(pos==1)
    {
        deleteatbegining();
    }
    else
    {
        p=start;
        for(i=1;i<pos-1;i++)
        {
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        q->next->prev=p;
        free(q);
    }
}
void deleteatlast()
{
	Node *q;
	if (start==NULL) {
		printf("\nList is empty");
	}
	else if(start->next=NULL)
	{
		printf("\n%d delete kar rahe hai last se ",start->data);
		free(start);
		start=tail=NULL;
	}
	else {
		printf("\n%d delete kar rahe hai last se ",tail->data);
		q=tail ;
		tail=tail->prev ;
		tail->next=NULL;
		free(q) ;
	}
}
void count()
{
	int count=0 ; 
	struct Node *q = start ;

	while (q!=NULL)
	{
		count++ ;
		q=q->next ;
	}
	printf("\n list mai %d nodes rakhe hai " , count );	
}
void search() {
	struct Node *q=start;
	int data ;
	printf("\nEnter search data ");
	scanf ("%d",&data);

	while (q!=NULL)
	{
		if (q->data==data)
		{
			printf("\n%d data found ", data);
			break ;
			q=q->next ;
		}
		else if (q==NULL)
		{
			printf("\nData Not found");
			break;
		}
		else {
			printf("\nData Not found ");
			break ;
		}
	}
}
int main()
{
	createlist();
	displaystart();
	displaytail();
	
	insertatbegining();
	displaystart();
	displaytail();

	insertatmiddle();
	displaystart();
	displaytail();
	
	insertatend();
	displaystart();
	displaytail();
	count();
	
	deleteatbegining();
	displaystart();
	displaytail();
	
	deleteatmiddle();
	displaystart();
	displaytail();

	deleteatlast();
	displaystart();
	displaytail();
	count();
	search();
	displaystart();
	displaytail();

	return 0 ;
}   