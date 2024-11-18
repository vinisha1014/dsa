#include<stdio.h>
#include<stdlib.h>

//heaps
#define MAX 10

int heap[MAX];
int heapSize=0;

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(int arr[],int n,int i){
    int largest = i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[largest]){
        largest = left;

    }
    if(left< n && arr[right]>arr[largest]){
        largest = right;
    }
    if(largest!=i){
       swap(&arr[i],&arr[largest]);
       heapify(arr,n,largest);
    }

}

void insert(int value){
    int i;
    if(heapSize==MAX){
        printf("Heap is full\n");
    }
    heap[heapSize]=value;
    i=heapSize;
    heapSize++;

    //max element kin position
    while(i!=0 && heap[(i-1)/2]<heap[i]){
        swap(&heap[(i-1)/2],&heap[i]);
        i=(i-1)/2;
    }

}
int extractMax(){
    int max;
    if(heapSize<=0){
        printf("Heap is empty\n");
        return -1;
    }
    if(heapSize==1){
        heapSize--;
        return heap[0];
    }
    max=heap[0];
    heap[0]=heap[heapSize-1];
    heapSize--;
    heapify(heap,heapSize,0);
    return max;
}
void heapSort(int arr[],int n){
    int i;
    for(i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    for(i=n-1;i>=0;i--){
        swap(&arr[0],&arr[i]);
  heapify(arr,n,0);
    }
}

void display(){
    int i;
    for(i=0;i<heapSize;i++){
        printf("%d ",heap[i]);
    }
    printf("\n");
}
int main(){
    int i;
    insert(10);
    insert(20);
    insert(40);
    printf("Intial heap\n");
    display();
    printf("Extract maximum element\n");
    printf("%d\n",extractMax());

display();
printf("Sorted elements using heapsort \n");
for(i=0;i<heapSize;i++){
    printf("%d",heap[i]);
}
printf("\n");
return 0;
}

