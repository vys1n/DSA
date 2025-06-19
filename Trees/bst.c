#include <stdio.h>
#include <stdlib.h>

typedef struct btnode{
    int data;
    struct btnode *lc;
    struct btnode *rc;
}bstnode;

bstnode* createNode(int x){
    bstnode *p;
    p = (bstnode *)malloc(sizeof(bstnode));

    if(p == NULL){
        exit (1);
    }

    p->data = x;
    p->lc = NULL;
    p->rc = NULL;

    return p;
}

void InOrder(bstnode *root){
    if(root != NULL){
        InOrder(root->lc);
        printf("%d | ", root->data);
        InOrder(root->rc);
    }
}

bstnode * Insert(bstnode *first, int data){
    if(first == NULL){
        return createNode(data);
    }

    if(data <= first->data){
        first -> lc = Insert(first->lc, data);
    }

    else{
        first->rc = Insert(first->rc, data);
    }

    return first;
}

void FreeTree(bstnode *root){
    if(root != NULL){
        FreeTree(root->lc);
        FreeTree(root->rc);
        free(root);
    }
}

int InternalNodes(bstnode *root){
    if(root == NULL){
        return 0;
    }
    
    if(root->lc == NULL && root->rc == NULL){
        return 0;   // iss program mei 0 ko 1 kardoge toh yeh total no. of nodes dedega
    }

    else{
        return (1 + InternalNodes(root->lc) + InternalNodes(root->rc));
    }
}

int max(int x, int y){
    if(x >= y){
        return x;
    }

    else{
        return y;
    }
}

int Depth(bstnode *root){
    if(root != NULL){
        if(root->lc == NULL && root->rc == NULL){
            return 0;
        }

        else{
            int x_left = Depth(root->lc);
            int x_right = Depth(root->rc);

            return 1+max(x_left, x_right);
        }
    }
}

int main(){
    bstnode *root;
    root = NULL;

    int array[] = {5,7,9,-1,3,2};
    int n = sizeof(array)/sizeof(array[3]);

    for(int i = 0; i<n; i++){
        root = Insert(root, array[i]);
    }

    InOrder(root);

    int num = InternalNodes(root);
    printf("\nNo. of Internal Nodes: %d", num);

    printf("\nDepth of the tree: %d", Depth(root));

    FreeTree(root);

    return 0;
}
