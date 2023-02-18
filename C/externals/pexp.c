#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* next;
    struct node* right;
    int data;
};
struct node* newNode(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->next = newnode->right = NULL;
    newnode->data = data;
    return newnode; 
}
struct node* insert(struct node* node, int data){
    if(node == NULL){
        return newNode(data);
    }
    if(data<node->data){
        node->next = insert(node->next,data);
    }
    if(data>node->data){
        node->right = insert(node->right,data);
    }
    return node;
}
void inOrder(struct node* node){
    if(node !=NULL){
        inOrder(node->next);
        printf("%d ",node->data);
        inOrder(node->right);
    }
}
int main (){
    struct node* root = NULL;
    root = insert(root,50);
    insert(root,40);
    insert(root,60);
    insert(root,30);
    insert(root,80);
    insert(root,20);
    insert(root,90);
    inOrder(root);
    return 0;
}