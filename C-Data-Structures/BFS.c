#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

struct vertex{
    char lable;
    int visited;
};

int queue[MAX];
int front = 0;
int rear = -1;

struct vertex * vertices[MAX];
int adjmatrix[MAX][MAX];
int vertexcount = 0;

void insert(int data){
    queue[++rear] = data;
}

int delete(){
    return queue[front++];
}

bool isQueueEmpty(){
    return front == -1;
}

void addVertex(char data){
    struct vertex * v = (struct vertex *) malloc(sizeof(struct vertex));
    v->lable = data;
    v->visited = false;
    vertices[vertexcount++] = v;
}

void addEdge(int start, int end){
    adjmatrix[start][end] = 1;
    adjmatrix[end][start] = 1;
}

void displayVertex(int vertexIndex) {
   printf("%c ",vertices[vertexIndex]->lable);
}

int getadjecentVertex(int vertexIndex){
    for(int i = 0; i<vertexcount; i++) {
      if(adjmatrix[vertexIndex][i] == 1 && vertices[i]->visited == false)
         return i;
    }
    return -1;
}

void breadthFirstSearch() {
   int i;

   vertices[0]->visited = true;

   displayVertex(0);   

   //insert vertex index in queue
   insert(0);
   int unvisitedVertex;

   while(!isQueueEmpty()) {
      int tempVertex = delete();   
      while((unvisitedVertex = getadjecentVertex(tempVertex)) != -1) {    
         vertices[unvisitedVertex]->visited = true;
         displayVertex(unvisitedVertex);
         insert(unvisitedVertex);               
      }
   }   

   //queue is empty, search is complete, reset the visited flag        
   for(i = 0;i<vertexcount;i++) {
      vertices[i]->visited = false;
   }    
}

int main() {
   int i, j;

   for(i = 0; i<MAX; i++){
        for(j = 0; j<MAX; j++){
           adjmatrix[i][j] = 0;
        }
   }

   addVertex('S');   // 0
   addVertex('A');   // 1
   addVertex('B');   // 2
   addVertex('C');   // 3
   addVertex('D');   // 4
 
   addEdge(0, 1);    // S - A
   addEdge(0, 2);    // S - B
   addEdge(0, 3);    // S - C
   addEdge(1, 4);    // A - D
   addEdge(2, 4);    // B - D
   addEdge(3, 4);    // C - D
	
   printf("\nBreadth First Search: ");
   
   breadthFirstSearch();

   return 0;
}
