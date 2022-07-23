#include <stdio.h>

//implement stack by using array
#define MAX_SIZE 100

int A[MAX_SIZE];
int top_arr = -1;
void Push_arr(int val)
{
    if(top_arr == MAX_SIZE - 1)
    {
        printf("ERROR: Stack overflow\n");
    }
    A[++top_arr] = val;
}

void Pop_arr()
{
    if(top_arr == -1)
    {
        printf("ERROR: No element to pop\n");
        return;
    }
    top_arr--;
}

int Top_arr()
{
    return A[top_arr];
}

int IsEmpty_arr()
{
    if(top_arr == -1)
    {
        return 1;
    }
    return 0;
}

void PrintStack_arr() {
	printf("Stack: ");
	for(int i = 0;i<=top_arr;i++)
		printf("%d ",A[i]);
	printf("\n");
}

//implement stack using linked list, assume head of linked list is top of stack
typedef struct Node 
{
    int data;
    struct Node *next_node;
}Node;
Node *top_linkedlist = NULL;

void Push_linkedlist(int val)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->next_node = top_linkedlist;
    top_linkedlist = temp;
}

void Pop_linkedlist()
{
    Node *temp;
    if(top_linkedlist == NULL)
    {
        printf("ERROR: No element to pop\n");
        return;
    }
    temp = top_linkedlist;
    top_linkedlist = top_linkedlist->next_node;
    free(temp);
}

int Top_linkedList()
{
    if(top_linkedlist == NULL)
    {
        printf("ERROR: No element to print\n");
        return;
    }
    return top_linkedlist->data;
}

int IsEmpty_linkedlist()
{
    if(top_linkedlist == NULL)
    {
        return 1;
    }
    return 0;
}