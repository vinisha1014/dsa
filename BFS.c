#include <stdio.h>  
#include <stdbool.h>  
#define NUM_VERTICES 7  

void printGraph(int graph[NUM_VERTICES][NUM_VERTICES], char *names[]) {  
    printf("Adjacency Matrix\n");  
    for (int i = 0; i < NUM_VERTICES; i++) {  
        printf("%s -> ", names[i]);  
        for (int j = 0; j < NUM_VERTICES; j++) {  
            if (graph[i][j] == 1) {  
                printf("%s ", names[j]);  
            }  
        }  
        printf("\n");  
    }  
}  
void printQueue(int queue[],int distances[],int front,int rear,char *names[]){
    printf("Queue: ");
    for(int i=front;i<rear;i++){
             printf("%s (distance: %d)", names[queue[i]],distances[queue[i]]);
             if(i<rear-1) printf(", ");

    }
    printf("\n");   
}
void printDistances(int distances[],char *names[]){
    printf("Vertex\tDistance\n");
    for(int i=0;i<NUM_VERTICES;i++){
        printf("%s\t%d\n",names[i],distances[i]);
    }
    printf("\n");
}


void bfs(  int graph[NUM_VERTICES][NUM_VERTICES],int startVertex,char *names[]){
    bool visted[NUM_VERTICES]={false};
    int queue[NUM_VERTICES];
    int distances[NUM_VERTICES];
    int front=0;
    int rear=0;
    for(int i=0;i<NUM_VERTICES;i++){
        distances[i]=-1; //initially saare distnaces minus 1 hai
    }
    visted[startVertex]=true;
    distances[startVertex]=0;
    queue[rear++]=startVertex;
    printf("BFS starting from %s\n",names[startVertex]);
    while(front<rear){
        int currentVertex=queue[front++];
        printf("%s ",names[currentVertex]);
        printQueue(queue,distances,front,rear,names);
        printDistances(distances,names);
        for(int i=0;i<NUM_VERTICES;i++){
            if(graph[currentVertex][i]==1 &&!visted[i]){
visted[i]=true;
distances[i]=distances[currentVertex]+1;
queue[rear++]=i;
printf("Added %s to the queue with distance %d.\n", names[i], distances[i]);
                printQueue(queue, distances, front, rear, names);
                printDistances(distances, names);

            }
        }
    }
    
    printf("\nFinal Distances:\n");
    printDistances(distances, names);

    }

int main() {  
    char *names[NUM_VERTICES] = {  
        "Everett", "Seattle", "Olympia", "Centralia",  
        "Portland", "North Bend", "Spokane"  
    };  
    
    int graph[NUM_VERTICES][NUM_VERTICES] = {0};  
    
    // Define edges in the graph  
    graph[0][1] = 1; // Everett -> Seattle  
    graph[0][5] = 1; // Everett -> North Bend  
    graph[0][6] = 1; // Everett -> Spokane  
    graph[1][2] = 1; // Seattle -> Olympia  
    graph[1][0] = 1; // Seattle -> Everett  
    graph[1][5] = 1; // Seattle -> North Bend  
    graph[2][3] = 1; // Olympia -> Centralia  
    graph[2][4] = 1; // Olympia -> Portland  
    graph[3][6] = 1; // Centralia -> Spokane  
    graph[3][4] = 1; // Centralia -> Portland  

    printGraph(graph, names);  
     int pos;
    printf("Enter a position (0 to %d) to start BFS from -> ", NUM_VERTICES - 1);
    scanf("%d", &pos);

    if (pos >= 0 && pos < NUM_VERTICES) {
        bfs(graph, pos, names);
    } else {
        printf("Invalid starting position.\n");
    }


    return 0;  
}