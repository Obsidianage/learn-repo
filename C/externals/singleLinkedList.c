#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* next;
    int data;
};
struct node* createNode(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->data = data;
    return newnode;
}
void insertFirst(int data, struct node** head){
    struct node* newnode = createNode(data);
    newnode->next = *head;
    *head = newnode;
}
void insertLast(int data,struct node** head){
    if(*head  == NULL){
        insertFirst(data,head);
        return;
    }
    struct node* newnode = createNode(data);
    struct node* temp = *head;
    while(temp->next !=NULL){
        temp = temp->next;
    }
    temp->next = newnode;
}
void insertPos(int data,struct node** head,int index){
    if(*head  != NULL){
        insertFirst(data,head);
        return;
    }
    struct node* newnode = createNode(data);
    struct node* temp = *head;
    int pos = 1;
    while(temp->next != NULL && pos != index -1){
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
void deleteFirst(struct node** head){
    if(*head == NULL){
        return;
    }
    struct node* temp = *head;
    *head = temp->next;
    free(temp);
}

void deleteLast(struct node** head){
    if(*head == NULL){
        return;
    }
    struct node* temp = *head;
    if(temp->next == NULL){
        *head = NULL;
        free(temp);
        return;
    }
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    struct node* last = temp->next;
    temp->next = NULL;
    free(last);
}

void display(struct node* head){
    struct node* temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp =temp->next;
    }
}
void main(){
    struct node* head = NULL;
    insertFirst(4,&head);
    insertFirst(1,&head);
    insertLast(2,&head);
    insertLast(3,&head);
    display(head);
    deleteLast(&head);
    printf("\n");
    display(head);
}
