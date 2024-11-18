#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int hashTable[MAX];

void initialize(){
    for(int i=0;i<MAX;i++){
        hashTable[i]=-1;
        
    }
}
int hash(int key){
    return key% MAX;
}
void insert(int key){
    int i=0;
    int index=hash(key);
      printf("%d\n",index);
    while(hashTable[(index+i*i)%MAX]!=-1){
       i++;
    }
    if(i==MAX){
        printf("Full\n");
        return ;
    }
  
    hashTable[(index+i*i)%MAX]=key;

}
void display(){
    for(int i = 0; i < MAX; i++){
        printf("%d ", hashTable[i]);

    }
}
int search(int key){
    int index=hash(key);
    int orginalIndex=index; 
   
    while(hashTable[index]!=-1){
        if(hashTable[index]==key){
        return index;
        }
        index=(index+1)%MAX;
        if(orginalIndex==index){
            break;
        }
            

    }
    return -1;
    
    

}
void searchAndPrint(int key){
    int index=search(key);
    if(index!=-1){
        printf("key found at index %d",index);
    }
    else{
        printf("Key not found\n");
    }
}
int main(){
    initialize();
    insert(10);
    insert(20);
    insert(30);
    display();
    printf("Seraching for element 30\n");
    searchAndPrint(30);
    display();

    return 0;
}