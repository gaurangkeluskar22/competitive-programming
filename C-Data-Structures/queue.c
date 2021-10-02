#include <stdio.h>

int n = 7;
int queue[10];
int front = -1;
int rear = -1;

void insert(int x){
    if(front==-1){
        front = rear = 0;
        queue[rear] = x;
    }else{
        rear++;
        queue[rear] = x;
    }
}

void delete(){
    if(front == -1){
        printf("\n Queue is underflow");
    }else{
        printf("\n element to be delete: %d", queue[front]);
        front++;
    }
}

void display(){
     if(rear == -1){
        printf("\n Queue is underflow");
    }else{
        printf("\n element of queue are:");
        for(int i=front; i<=rear; i++){
            printf("%d ", queue[i]);
        }
    }
}

void destroy(){
    front = -1;
    rear = -1;
    printf("\n Queue is destroyed");
}
void main(void) {
    display();
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    display();
    delete();
    display();
    destroy();
}

// ====OUTPUT====
//  Queue is underflow
//  element of queue are:1 2 3 4 
//  element to be delete: 1
//  element of queue are:2 3 4 
//  Queue is destroyed
