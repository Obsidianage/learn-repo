#include<stdio.h>
void swap(int,int,int[]);
void bubbleSort(int n , int arr[]){
    for(int i =0;i<n;i++){
        for(int j =1;j<n;j++){
            if(arr[j-1]>arr[j]){
                swap(j,j-1,arr);
            }
        }
    }

}
void swap(int a, int b, int arr[]){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
void main(){
    int n,arr[5]={5,4,3,2,1};
    n = 5;
    bubbleSort(n,arr);
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
}