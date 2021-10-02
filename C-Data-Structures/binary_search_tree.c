#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newrec, *root, *a, *b;

void insert(int x){
    newrec = (struct node *)malloc(sizeof(struct node));
    newrec -> data = x;
    newrec -> left = NULL;
    newrec -> right = NULL;
    
    if(root == NULL){
        root = newrec;
    }
    else{
        a = b = root;
        while(a!=NULL){
            b = a;
            if(x <= a->data){
                a = a->left;
            }else{
                a = a->right;
            }
        }
        if(x<=b->data){
            b->left = newrec;
        }else{
            b->right = newrec;
        }
    }
}

void delete(int x){
    a = b = root;
    while(a!=NULL || a->data != x){
        b = a;
        if(x <= a->data){
            a = a->left;
        }else{
            a = a->right;
        }
    }
    if(a==NULL){
        printf("\n Element not found!");
    }
    // element to be delete is pointed by a
    // parent of element to be delete is pointed by b
    else if(a->left != NULL && a->right == NULL){
        // if it is root node
        if(x == root->data){
            root = a->left;
        }else{
            if(b->left == a){
                b->left = a->left;
            }else{
                b->right = a->left;
            }
        }
    }
    else if(a->left == NULL && a->right != NULL){
       if(root->data == x){
           root = a->right;
       }else{
           if(b->left == a){
               b -> left = a->right;
           }else{
               b -> right = a->right;
           }
       }
    }
    else if(a->left == NULL && a->right == NULL){
        if(root->data == x){
            root = NULL;
        }else{
            if(b->left == a){
                b->left = NULL;
            }else{
                b->right = NULL;
            }
        }
    }
    else if(a->left !=NULL && a->right != NULL){
        struct node *c;
        c = a->right;
        while(c->left != NULL){
            c = c -> left;
        }
        c->left = a->left;
        if(root == a){
            root = root-> right;
        }else{
            if(b->left == a){
                b->left = a->right;
            }else{
                b->right = a->right;
            }
        }
    }
}

void inorder(struct node *p){
    if(p!=NULL){
        inorder(p->left);
        printf("%d, ", p->data);
        inorder(p->right);
    }
}

void preorder(struct node *p){
    if(p!=NULL){
        printf("%d, ", p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

void postorder(struct node *p){
    if(p!=NULL){
        postorder(p->left);
        postorder(p->right);
        printf("%d, ", p->data);
    }
}

void distroy(){
    root = NULL;
    printf("\n Tree is destroyed!");
}

void main(void) {
    insert(100);
    insert(50);
    insert(150);
    insert(25);
    insert(75);
    insert(125);
    insert(175);
    printf("\n Inorder traversal: ");
    inorder(root);
    printf("\n Preorder traversal: ");
    preorder(root);
    delete(75);
    printf("\n Postorder traversal: ");
    postorder(root);
    distroy();
}
