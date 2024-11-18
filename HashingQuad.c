#include<stdio.h>
#include<stdlib.h>

#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];

void intialize(){
    for(int i = 0; i < TABLE_SIZE; i++){
        hashTable[i] = -1;
    }
}
int hash(int key){
    return key % TABLE_SIZE;
}
void insert(int key){
    int i=0;
    int index=hash(key);
   while(hashTable[(index+i*i)%TABLE_SIZE]!=-1){
        i++;
    }
   if(i==TABLE_SIZE){
    printf("Hash table is full\n");
    return ;
   }
   hashTable[(index+i*i)%TABLE_SIZE]=key;
}

int search(int key){
    int i=0;
    int index=hash(key);
    while(hashTable[(index+i*i)%TABLE_SIZE]!=-1){
        if(hashTable[(index+i*i)%TABLE_SIZE]==key){
            return (index+i*i)%TABLE_SIZE;
        }
        else{
            i++;
        }
        if(i==TABLE_SIZE){
            break;
        }
    }
    return -1;
}

void searchAndPrint(int key){
  
    int result=search(key);
    
    if(result!=-1){
        printf("Key %d is found at index %d\n",key,result);
    }
    else{
        printf("Key %d is not found\n",key);
    }
}
void display(){
    for(int i = 0; i < TABLE_SIZE; i++){
        printf("%d\n",hashTable[i]);
    }
}

void main(){
    intialize();
    insert(10);
    insert(20);
    insert(30);
   
    display();
     searchAndPrint(30);
}


