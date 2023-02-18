#include<stdio.h>
#include<stdlib.h>
void quickSort(int arr[],int low, int high){
    int start = low;
    int end = high;
    int mid = start+(end - start)/2;
    int p = arr[mid];
    while(start<=end){
        while(arr[start]<p){
            start++;
        }
        while(arr[end]>p){
            end--;
        }
        while(start<=end){
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
        quickSort(arr,low,end);
        quickSort(arr,start,high);
    }
}
void main(){
    int arr[10] = {5,4,3,2,1};
    int n = 5;
    quickSort(arr,0,n-1);
    for(int i =0;i<n;i++){
        printf("%d ",arr[i]);
    }
}