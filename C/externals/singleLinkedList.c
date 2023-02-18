#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* next;
    int data;
};
struct node* createnode(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
void insertFirst(struct node** head,int data){
    struct node* newnode = createnode(data);    
    newnode->next = *head;
    *head = newnode;
}
void insertLast(struct node** head, int data){
    struct node* newnode = createnode(data);
    struct node* temp = *head;
    if(temp ==NULL){
        insertFirst(head,data);
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
}
void display(struct node* head){
    struct node* temp = head;
    while(temp!= NULL){
        printf("%d ",temp->data);
        temp= temp->next;
    }
}
void main(){
    struct node* head = NULL;
    insertFirst(&head,1);
    display(head);
}