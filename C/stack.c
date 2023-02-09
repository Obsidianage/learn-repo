#include<stdio.h>
#include<stdlib.h>
#define max 5
int s[max],top = -1;
void push(){
    int x;
    printf("\n enter the element to insert\n");
    scanf("%d",&x);
    if(top == max-1){
        printf("overflow");
    }
    else{
        top++;
        s[top] = x;
    }
}
void pop(){
    int x;
    if(top == -1){
        printf("underflow\n");
    }
    else{
        x = s[top];
        top--;
    }
    printf("\nthe deleted number is %d\n",x);
}
void display(){
    for(int i =top;i>=0;i--){
        printf("%d ",s[i]);
    }
}
void main(){
    int ch;
    printf("\nenter the choice\n");
    while(1){
        
        printf("\n1.push 2.pop 3.display 4.exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1 : push();break;
            case 2 : pop();break;
            case 3 : display();break;
            case 4 : exit(0);
        }
    }    
}