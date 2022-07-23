#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


//define an user define datatype name Node
typedef struct Node {
    int data;
    struct Node *next_node;
}Node;
//this function use to print out every value in linked list
void PrintLinkedList(Node* headnode){
    Node *temp = headnode;
    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->next_node;
    }
    
}
//this function use to insert Node at the specific position
void Insert(int position, int data, Node** pointerToHead){
    Node *temp1 = (Node*)malloc(sizeof(Node));
    temp1->data = data;
    temp1->next_node = NULL;
    if (position == 1){
        temp1->next_node = (*pointerToHead);
        (*pointerToHead) = temp1;
    }
    else
    {
        Node *temp2 = (*pointerToHead);
        for(int i = 0; i < position -2; i++)
        {
            temp2 = temp2->next_node;
        }
        temp1->next_node = temp2->next_node;
        temp2->next_node = temp1;
    }

}
//this function use to delete Node at the specific position
void Delete(int position, Node** pointerToHead){
    Node *temp1 = (*pointerToHead);
    for(int i = 0; i < position -2; i++)
    {
        temp1 = temp1->next_node;
    }
    Node *temp2 = temp1->next_node;
    temp1->next_node = temp2->next_node;
    free(temp2);
}

int main(){
    //create a dummy linked list
    Node *nodehead = NULL;
    Node *node_1 = (Node*)malloc(sizeof(Node));
    Node *node_2 = (Node*)malloc(sizeof(Node));
    Node *node_3 = (Node*)malloc(sizeof(Node));
    Node *node_4 = (Node*)malloc(sizeof(Node));
    node_1->data = 1;
    node_1->next_node = node_2;
    node_2->data = 2;
    node_2->next_node = node_3;
    node_3->data = 3;
    node_3->next_node = node_4;
    node_4->data = 4;
    node_4->next_node = NULL;
    nodehead = node_1;
    //test if those function work well
    printf("\nthe original linked list:");
    PrintLinkedList(nodehead);
    Insert(2, 3, &nodehead);
    printf("\nlinked list after insert:");
    PrintLinkedList(nodehead);
    Delete(2, &nodehead);
    printf("\nlinked list after delete:");
    PrintLinkedList(nodehead);
    return 0;
}