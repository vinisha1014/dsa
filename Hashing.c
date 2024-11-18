#include<stdio.h>
#include<stdlib.h>

#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];

void intialize(){
    for(int i = 0; i < TABLE_SIZE; i++){
        hashTable[i] = -1;
    }
}

void display(){
    for(int i = 0; i < TABLE_SIZE; i++){
        printf("%d ", hashTable[i]);

    }
}
int hash(int key){
    return key % TABLE_SIZE;
}
void insert(int key){
    int index = hash(key);
    while(hashTable[index]!=-1 && hashTable[index]!=-2){
        index =(index +1)%TABLE_SIZE;
    }
    hashTable[index]=key;

}



int search(int key){
    int index = hash(key);
    if(index!=-1){
        if(hashTable[index]==key){
            return index;
        }
        else{
            printf("Key not found\n");
        }
    }
    return -1;

}

void searchAndPrint(int key){
    int index = search(key);
    if(index!=-1){
        printf("Key found at index %d\n", index);
    }
    else{
        printf("Key not found\n");
    }
}
void delete(int key){
    int index = search(key);
    
        if(index!=-1){
            hashTable[index]=-2;
            printf("key %d deleted succesfully\n",key);
        }
        else{
            printf("key doesnt exists\n");
        }
     
}




void main(){
    intialize();
    insert(10);
    insert(20);
    insert(30);
    display();
  searchAndPrint(30);
    delete(30);
    display();
    
}