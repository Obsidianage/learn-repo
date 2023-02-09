#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* next;
    struct node* prev;
    int data;
};
struct node* createNode(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}
void insertFirst(struct node** head, int data){
    struct node* newnode = createNode(data);
    newnode->next = *head;
    if(*head != NULL){
        (*head)->prev = newnode;
    }
    *head = newnode;
}
void insertLast(struct node** head, int data){
    if(*head == NULL){
        insertFirst(head,data);
        return;
    }
    struct node* newnode = createNode(data);
    struct node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}
void display(struct node* head){
    struct node* temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
void deletion(struct node** head, int data,int key){
    if(head == NULL){
        return;
    }
    struct node* temp = *head;
    while(temp!= NULL && temp->data != key){
         temp = temp->next;
    }
    if(temp->prev != NULL){
        temp->prev->next  = temp ->next; 
    }
    if(temp->next != NULL){
        temp->next->prev = temp->prev;
    }
    if(temp ==*head){
        *head = temp->next;
    }
    free(temp);
}
int main(){
    struct node* head = NULL;
    insertFirst(&head, 1);
    insertLast(&head,2 );
    display(head);
    return 0;
}

