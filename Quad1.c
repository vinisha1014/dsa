#include<stdio.h>
#include<stdlib.h>

#define TABLE_SIZE 10
int hashTable[TABLE_SIZE];

void initalize(){
    int i;
    for(i=0;i<TABLE_SIZE;i++){
        hashTable[i] = -1;
    }
}
int hash(int key){
    return key % TABLE_SIZE;
}
void display(){
    int i;
    for(i=0;i<TABLE_SIZE;i++){
     
            printf("%d ",hashTable[i]);
        }
    
}

void insert(int key){
    int index=hash(key);
    int i=0;
    while(hashTable[(index+i*i)%TABLE_SIZE]!=-1 && hashTable[(index+i*i)%TABLE_SIZE]!=-2 ){
        i++;
        if(i==TABLE_SIZE){
            printf("Hash table is full\n");
            return;
        }
    }
    hashTable[(index +i * i)%TABLE_SIZE]=key;
    
}

int search(int key){
    int index=hash(key);
    int i=0;
    while(hashTable[(index + i* i)%TABLE_SIZE]!=-1){
        if(hashTable[(index+i*i)%TABLE_SIZE]==key){
            return (index+i*i)%TABLE_SIZE;  
        }
        i++;
        if(i==TABLE_SIZE){
            break;
        }
    }
    return -1;

}

void delete(int key)
{
    int index=search(key);
    int orginalIndex=index;
    if(index!=-1 && hashTable[index]==key){
        hashTable[index]=-2;
        printf("Element deleted succesfully\n");
    }else{
        printf("Element not found\n");
    }
}

int main(){
    initalize();

    // Insert elements
    insert(10);
    insert(20);
    insert(34);
    insert(41);
    insert(51);
    insert(61);
    insert(71);

    // Display hash table
    display();

    // Search for a key
    int searchKey = 34;
    int result = search(searchKey);
    if(result != -1){
        printf("Key %d found at index %d.\n", searchKey, result);
    } else {
        printf("Key %d not found.\n", searchKey);
    }

    // Delete a key
    delete(34);
    printf("After deleting element 34:\n");
    display();

    return 0;
}
