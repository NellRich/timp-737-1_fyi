#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value; 
	struct node *left; 
	struct node *right; 
	struct node *parent;  
 } node;

 typedef struct tree {
	node *root; 
	unsigned int size;
 } tree;

 void init(tree* t) {
           t->root = NULL;
	   t->size = 0;
 }

 node* clear_impl(node *n) {  
    if (n != NULL) {
        clear_impl(n->left);
        clear_impl(n->right);
        n = NULL;
        return n;
    }

    return NULL;
}

void clear(tree *t) {
    clear_impl(t->root);
}

 int insert(tree* t, int value) {
	node* tmp = malloc(sizeof(node));
  	tmp->value = value;
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->parent = NULL;

	node* curr = t->root;
	node* prev = NULL;
	
	if(t->root == NULL) {
	   t->root = tmp;
	}
	else {
		while(curr != NULL){
		      prev = curr;
		      if(value < curr->value) {
			 curr = curr->left;
		      }
		       else if(value > curr->value) {
			       curr = curr->right;
			}
			else if (value == curr->value) {
			       return 1;
			}
		}
                tmp->parent = prev;

		if(value < prev->value) {
			   prev->left = tmp;	   
		}
		else if (value > prev->value) {
		      prev->right = tmp;
		}
	}
        t->size++;
        return 0;																																																
 }
 
 void iterPostorder(node* n) {
     if (n == NULL) {
        return;
    }

    iterPostorder(n->left);
  
    iterPostorder(n->right);
    printf("%d", n->value);
    if (n->parent != NULL) {
        printf(" ");
    }
 }

 int main() {
        tree *t = malloc(sizeof(tree));
        init(t);
	int n = 7;
        int a;

	for (int i = 0; i < n; ++i) {
		scanf("%d", &a);
		insert(t, a);
	}

	iterPostorder(t->root);
        printf("%c", '\n');
        clear(t);

	return 0;
 }
