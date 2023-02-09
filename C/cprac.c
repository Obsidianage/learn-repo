#include<stdio.h>
#include<stdlib.h>
struct node {
    struct node* next;
    int data;
};
struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode-> data = data;
    newNode->next = NULL;
    return newNode;
}
void insertFirst(struct node** head, int data){
    struct node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}
void insertLast(struct node** head, int data){
    if(*head  == NULL){
        insertFirst(head,data);
        return;
    }
    struct node* newNode = createNode(data);
    struct node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
void insertPos(struct node** head,int data,int pos){
    struct node* newNode = createNode(data);
    struct node* temp = *head;
    int counter = 1;
    if(pos ==1){
        insertFirst(head,data);
        return;
    }
    while(temp->next != NULL && counter != pos-1){
        temp = temp->next;
        counter++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void delete(struct node** head , int key ){
    struct node* temp = *head, *prev;
    if(temp== NULL) return;
    if(temp!=NULL && temp->data == key){
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp!= NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
}
void display(struct node* head){
    struct node*  temp = head;
    while(temp != NULL){
        printf("%d",temp->data);
        temp = temp->next;
    }

}
int main(){
    struct node* head = NULL;
    insertFirst(&head,1);
    insertLast(&head,3);
    insertPos(&head,2,2);
    display(head);
}
