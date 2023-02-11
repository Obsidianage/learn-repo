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
    if (*head == NULL) {
        newnode->next = newnode;
    } else {
        newnode->next = *head;
        struct node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    *head = newnode;
}

void insertLast(int data,struct node** head){
    struct node* newnode = createNode(data);
    if (*head == NULL) {
        newnode->next = newnode;
        *head = newnode;
    } else {
        struct node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = *head;
    }
}

void insertPos(int data,struct node** head,int index){
    if(index == 1){
        insertFirst(data,head);
        return;
    }
    struct node* newnode = createNode(data);
    struct node* temp = *head;
    int pos = 1;
    while(temp->next != *head && pos != index -1){
        temp = temp->next;
        pos++;
    }
    if (pos == index - 1) {
        newnode->next = temp->next;
        temp->next = newnode;
    } else {
        printf("Invalid position\n");
    }
}

void deleteFirst(struct node** head){
    if (*head == NULL) {
        return;
    }
    struct node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    *head = (*head)->next;
    temp->next = *head;
    free(temp);
}

void deleteLast(struct node** head){
    if (*head == NULL) {
        return;
    }
    struct node* temp = *head;
    if (temp->next == *head) {
        *head = NULL;
        free(temp);
        return;
    }
    while (temp->next->next != *head) {
        temp = temp->next;
    }
    struct node* last = temp->next;
    temp->next = *head;
    free(last);
}

void display(struct node* head){
    if (head == NULL) {
        return;
    }
    struct node* temp = head;
    do {
        printf("%d ",temp->data);
        temp = temp->next;
    } while (temp != head);
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
