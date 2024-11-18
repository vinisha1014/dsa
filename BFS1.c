    #include<stdio.h>
    #include<stdbool.h>

    #define NUM_VERTICES 7

    void printGraph(int garph[NUM_VERTICES][NUM_VERTICES],char* names[]){
        for(int i=0;i<NUM_VERTICES;i++){
            for(int j=0;j<NUM_VERTICES;j++){
                if(garph[i][j]==1){
                    printf("%s -> %s\n",names[i],names[j]);
                }
            }
            printf("\n");
        }
    }
    void printQueue(int queue[],int distances[],int front,int rear, char* names[]){
        printf("Queue: ");
        for(int i=front;i<rear;i++){
            printf("%s(distance %d)",names[queue[i]],distances[queue[i]]);
            if(i<rear-1) printf(",");

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
    void bfs(int graph[NUM_VERTICES][NUM_VERTICES],int startVertex,char *names[]){
        bool visted[NUM_VERTICES]={false};
        int distances[NUM_VERTICES];
        int queue[NUM_VERTICES];
        int front=0;
        int rear=0;
        for(int i=0;i<NUM_VERTICES;i++){
            distances[i]=-1;

        }
        visted[startVertex]=true;
        distances[startVertex]=0;
        queue[rear++]=startVertex;

        while(front<rear){
            int currentVertex=queue[front++];
            printf("Processing %s\n", names[currentVertex]);

            
            printQueue(queue,distances,front,rear,names);
            for(int i=0;i<NUM_VERTICES;i++){
                if(graph[currentVertex][i]==1 && !visted[i]){
                    visted[i]=true;
                    distances[i]=distances[currentVertex]+1;
                    queue[rear++]=i;
                    printf("Added %s to queue with distance %d",names[i],distances[i]);
                    printQueue(queue,distances,front,rear,names);
                    printDistances(distances,names);


                }
            }
        }
        printf("Final Distances\n");
        printDistances(distances,names);
    }

    int main(){
        char* names[NUM_VERTICES] = {
            "Everett", "Seattle", "Olympia", "Centralia",
            "Portland", "North Bend", "Spokane"
        };

        // Adjacency matrix for the graph
        int graph[NUM_VERTICES][NUM_VERTICES] = {0};

        // Adding edges
        graph[0][1] = 1; graph[0][5] = 1; graph[0][6] = 1;
        graph[1][2] = 1; graph[1][0] = 1; graph[1][5] = 1;
        graph[2][3] = 1; graph[2][4] = 1;
        graph[3][6] = 1; graph[3][4] = 1;
        printGraph(graph,names);
        int pos;
        printf("Enter position where you need to start with BFS\n");
        scanf("%d",&pos);
        if(pos>=0 && pos<NUM_VERTICES){
            bfs(graph,pos,names);


        }	else{
            printf("Invalid position\n");
        }


        return 0;

    }