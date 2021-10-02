#include <stdio.h>

int n = 7;
int stack[10];
int top = -1;

void push(int x){
    if(top==n){
        printf("\n Stak is overflow!");
    }
    else{
        top++;
        stack[top] = x;
    }
}

void pop(){
    if(top==-1){
        printf("\n Stack is underflow");
    }else{
        printf("\n Element to be delete:%d", stack[top]);
        top--;
    }
}

void distroy(){
    top= -1;
    printf("\n Stack is destroyed!");
}

void display(){
    if(top==-1){
        printf("\n Stack is underflow");
    }else{
        printf("\n stack elements:");
        for(int i=0; i<=top; i++){
            printf("%d ", stack[i]);
        }
    }
}
void main(void) {
    display();
    push(1);
    push(2);
    push(3);
    push(4);
    display();
    pop();
    display();
    distroy();
}


// ===== OUTPUT =====
//  Stack is underflow
//  stack elements:1 2 3 4 
//  Element to be delete:4
//  stack elements:1 2 3 
//  Stack is destroyed!
