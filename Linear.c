#include<stdio.h>
#include<stdlib.h>

#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];

void intialize(){
    int i;
    for(i=0;i<TABLE_SIZE;i++){
        hashTable[i]=-1;
    }
}

int hash(int key){
    return key%TABLE_SIZE;
}
void display(){
    int i;
    for(i=0;i<TABLE_SIZE;i++){
        printf("%d\n",hashTable[i]);
    } 
}
void insert(int key){
    int index = hash(key);
    while(hashTable[index]!=-1 && hashTable[index]!=-2){
        index=(index+1)%TABLE_SIZE;
    }
    hashTable[index]=key;
}
int  search(int key){
    int index = hash(key);
    int orginalIndex=index;
    while(hashTable[index]!=-1){
        if(hashTable[index]==key){
            return index;
        }
        index=(index+1)%TABLE_SIZE;
        if(index==orginalIndex){
            break;
        }
    }
    return -1;
}

void delete(int key){
    int index = search(key);
    
        if(hashTable[index]==key){
            hashTable[index]=-2;
            printf("key %d deleted succesfully\n",key);
        }
        else{
            printf("key doesnt exists\n");
        }
     
}

int main(){
    intialize();
    insert(10);
    insert(20);
    insert(34);
    insert(41);
    insert(51);
    insert(61);
    insert(71);
    display();
    int searchkey=34;
    int result=search(searchkey);
    if(result!=-1){
        printf("key %d founded at index %d\n",searchkey,result);
    }else{
        printf("key %d not found\n",searchkey);
    }
    delete(34);
    printf("After deleting element 34\n");
    display();

    return 0;
}