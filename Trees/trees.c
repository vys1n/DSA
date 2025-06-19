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

struct btnode * Insert(struct btnode *first, int data){
	if(first == NULL){
		return getNode(data);
	}
	if(data <= first->data){
		first->lc = Insert(first->lc, data);
	}
	else{
		first->rc = Insert(first->rc, data);
	}

	return first;
}

int count_leaf(struct btnode *root){
	if(root == NULL){
		return 0;
	}
	else{
		if(root->lc == NULL && root->rc == NULL){
			return 1;
		}
		else{
			return(count_leaf(root->lc) + count_leaf(root->rc));
		}
	}
}

void InOrder(struct btnode *p){
	if(p != NULL){
		InOrder(p->lc);
		printf("%d | ", p->data);
		InOrder(p->rc);
	}
}

void PreOrder(struct btnode *p){
	if(p == NULL){
		return;
	}
	else{
		printf("%d | ", p->data);
		PreOrder(p->lc);
		PreOrder(p->rc);
	}
}

void PostOrder(struct btnode *p){
	if(p != NULL){
		PostOrder(p->lc);
		PostOrder(p->rc);
		printf("%d | ", p->data);
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

		printf("Preorder Traversal:\n");
		PreOrder(root);
		printf("\n");

		printf("Postorder Traversal:\n");
		PostOrder(root);
		printf("\n");
	}
}

int main(){
	struct btnode *first;
	
	first = getNode(5);
	first->lc = getNode(6);
	first->rc = getNode(9);

	first->lc->lc = getNode(10);
	first->lc->rc = getNode(12);

	Display(first);

	free(first);

	return 0;
}
