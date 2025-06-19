#include <stdio.h>
#include <stdlib.h>

struct btnode{
    int data;
    struct btnode *lc;
    struct btnode *rc;
};

struct btnode * getNode(int x){
	struct btnode *p;
	p = (struct btnode *)malloc(sizeof(struct btnode));

	p->data = x;
	p->lc = NULL;
	p->rc = NULL;

	return p;
}

void InOrder(struct btnode *p){
	if(p != NULL){
		InOrder(p->lc);
		printf("%d | ", p->data);
		InOrder(p->rc);
	}
}

int InternalNodes(struct btnode *root){
    if(root == NULL){
        return 0;
    }

    if(root -> lc == NULL && root -> rc == NULL){
        return 0;
    }

    else{
        int left_count = InternalNodes(root -> lc);
        int right_count = InternalNodes(root -> rc);

        return 1 + left_count + right_count;
    }
}

void Display(struct btnode *root){
	if(root == NULL){
		return;
	}
	else{
		printf("Inorder Traversal:\n");
		InOrder(root);
		printf("\n");
    }
}

int main(){
	struct btnode *first;
	
	first = getNode(5);
	first->lc = getNode(6);
	first->rc = getNode(9);

	first->rc->lc = getNode(8);
	first->rc->rc = getNode(12);

	Display(first);

    int num = InternalNodes(first);
    printf("\nNodes: %d\n", num);

	free(first);

	return 0;
}
