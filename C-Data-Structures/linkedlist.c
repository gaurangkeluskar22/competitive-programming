#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}; 

struct node *newrec, *first, *last, *temp; 

void insert_beg(int x){
    newrec = (struct node*)malloc(sizeof(struct node));
    newrec->data = x;
    if(first == NULL){
        first = last = newrec;
        newrec->next = NULL;
    }
    else{
        newrec->next = first;
        first = newrec;
    }
}

void insert_end(int x){
    newrec = (struct node*)malloc(sizeof(struct node));
    newrec -> data = x;
    if(first == NULL){
        first = last = newrec;
        newrec -> next = NULL;
    }else{
        last -> next = newrec;
        newrec ->next = NULL;
        last = newrec;
    }
}

void insert_pos(int x, int p){
    newrec = (struct node *)malloc(sizeof(struct node));
    newrec -> data = x;
    if(first==NULL){
        first = last = newrec;
        newrec -> next = NULL;
    }else{
        temp = first;
        for(int i=1; i<p-1; i++){
            temp = temp->next;
        }
        newrec->next = temp->next;
        temp->next = newrec;
    }
}

void del_beg(){
    if(first == NULL){
        printf("linkedlist is underflow");
    }else{
        printf("Element to be delete: %d \n", first->data);
        if(first == last){
            first = last = NULL;
        }else{
            first = first->next;
        }
    }
}

void del_end(){
    if(first == NULL){
        printf("linkedlist is underflow");
    }else{
        printf("Element to be delete: %d \n", last->data);
        if(first == last){
            first = last = NULL; 
        }else{
            temp = first;
            while(temp->next!=last){
                temp = temp->next;
            }
            last = temp;
            last -> next = NULL;
            
        }
    }
}

void del_pos(int p){
    if(first == NULL){
        printf("linkedlist is underflow");
    }else{
        if(first==last){
            printf("Element to be delete: %d \n", first->data);
            first = last = NULL;
        }else{
            temp = first;
            for(int i=1; i<p-1; i++){
                temp=temp->next;
            }
            printf("Element to be delete: %d \n", temp->next->data);
            temp->next = temp->next->next;
        }
    }
}

void display(){
    if(first==NULL){
        printf("Linked list is underflow");
    }else{
        temp = first;
        printf("Content of linkedlist:");
        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp -> next;
        }
    }
    printf("\n");
}

void destroy(){
    first = last = NULL;
    printf("linkedlist is destroyed! \n");
}

void main(void) {
    display();
    insert_beg(3);
    display();
    insert_beg(2);
    display();
    insert_beg(1);
    display();
    insert_end(4);
    display();
    insert_end(5);
    display();
    insert_beg(0);
    display();
    insert_pos(8,3);
    display();
    insert_pos(10,2);
    display();
    del_beg();
    display();
    del_end();
    display();
    del_pos(4);
    display();
    destroy();
    display();
}

// ===========OUTPUT=============
// Linked list is underflow
// Content of linkedlist:3 
// Content of linkedlist:2 3 
// Content of linkedlist:1 2 3 
// Content of linkedlist:1 2 3 4 
// Content of linkedlist:1 2 3 4 5 
// Content of linkedlist:0 1 2 3 4 5 
// Content of linkedlist:0 1 8 2 3 4 5 
// Content of linkedlist:0 10 1 8 2 3 4 5 
// Element to be delete: 0 
// Content of linkedlist:10 1 8 2 3 4 5 
// Element to be delete: 5 
// Content of linkedlist:10 1 8 2 3 4 
// Element to be delete: 2 
// Content of linkedlist:10 1 8 3 4 
// linkedlist is destroyed! 
// Linked list is underflow
