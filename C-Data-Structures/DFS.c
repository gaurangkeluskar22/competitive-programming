#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

struct vertex{
    char lable;
    bool visited;
};

// graph variables
struct vertex *vertices[MAX];
int adjencencymatrix[MAX][MAX];
int vertexcount = 0;

// stack variables
int stack[MAX];
int top = -1;

// stack functions
void push(int x){
    stack[++top] = x;
}

int pop(){
    return stack[top--];
}

int peek(){
    return stack[top];
}

bool isstackempty(){
    return(top==-1);    
}

// graph functions
void addVertex(char x){
    struct vertex *v = (struct vertex *)malloc(sizeof(struct vertex));
    v -> lable = x;
    v -> visited = false;
    vertices[vertexcount++] = v;
}

void addEdge(int start, int end){
    adjencencymatrix[start][end] = 1;
    adjencencymatrix[end][start] = 1;
}

void displayvertex(int vertexindex){
    printf("%c ", vertices[vertexindex]->lable);
}

int getadjecentvertex(int vertexindex){
    int i;
    for(i = 0; i<vertexcount; i++){
        if(adjencencymatrix[vertexindex][i]==1 && vertices[i]->visited == false){
            return i;
        }
    }
    return -1;
}

void depthFirstSearch(){
    int i;
    vertices[0] -> visited = true;
    displayvertex(0);
    push(0);
    
    while(!isstackempty()){
        //get the unvisited vertex of vertex which is at top of the stack
        int unvisited = getadjecentvertex(peek());
        
        //no adjacent vertex found
        if(unvisited == -1){
            pop();
        }
        else{
            vertices[unvisited]->visited = true;
            displayvertex(unvisited);
            push(unvisited);
        }
    }
    
    //stack is empty, search is complete, reset the visited flag
    for(i=0; i< vertexcount; i++){
        vertices[i]->visited = false;
    }
}


int main(void) {
	// your code goes here
	int i, j;
	for(i=0; i<MAX; i++){
	    for(j=0; j<MAX; j++){
	        adjencencymatrix[i][j] = 0;
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
    
    printf("Depth First Search: ");
    depthFirstSearch(); 
    
	return 0;
}
