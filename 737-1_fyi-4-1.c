#include <stdio.h>
#include <stdlib.h>

 typedef struct node {
	int value; 
	struct node *left; 
	struct node *right; 
	struct node *parent;  
 } node;

 typedef struct tree {
	struct node *root; 
	int Tnum; 
 } tree;

 typedef struct node_turn {
	 struct node *limb;  
	 struct node_turn* next; 
 } node_turn;

 typedef struct turn {
	// int tnum; 
	 struct node_turn* head; 
	 struct node_turn* tail; 
 } turn;

 void init_turn(turn *t) {
	//t->tnum = 0;
	t->head = NULL;
	t->tail = NULL;
 }

 int isEmpty_turn(turn *t) {
	return (t->tail == NULL);
 }

 void print_turn(turn *t) {
	node_turn* tmp = t->head;

	while(tmp != NULL) {
		if(tmp->limb == NULL) 
			printf("_");
		else
			printf("%d", tmp->limb->value);

		if(tmp->next != NULL)
			printf(" ");

		tmp = tmp->next;
	}
	printf("\n");
 }

 void push_in_turn(turn *t, node *value) {
	node_turn *tmp;
	tmp = malloc(sizeof(node_turn));

	tmp->limb = value;
	tmp->next = NULL;

	// if(value != NULL)
	// 	t->tnum++;

	if(!isEmpty_turn(t)) {
		t->tail->next = tmp;
		t->tail = tmp;
	}
	else {
		t->head = t->tail = tmp;
	}
 }

 node* pop_out_turn(turn *t) {
	node_turn *tmp = t->head;
	node* n = t->head->limb;

	t->head = t->head->next;

	if(t->head == NULL)
		t->tail = NULL;

	free(tmp);

	return(n);
 }

 int control(turn *t) {
	node_turn* tmp = t->head;

	while(tmp != NULL) {
		if(tmp->limb != NULL)
			return 0;

		tmp = tmp->next;
	}
	return 1;
 }

 void init(tree* T) {
           T->root = NULL;
	   T->Tnum = 0;
 }

 void clear(tree* T, turn* t) {
	node* tmp = T->root;
	node* del;

	push_in_turn(t, tmp);

	while(!isEmpty_turn(t)) {
		del = tmp;
		tmp = pop_out_turn(t);

	//	free(del);

		if(tmp->left != NULL)
			push_in_turn(t, tmp->left);
		if(tmp->right != NULL)
			push_in_turn(t, tmp->right);
	}
	        T->root = NULL;
 }

 int find(tree* T, int value, node* n, turn* t) {
	node* tmp = T->root;

	while(tmp != NULL) {
		if(tmp->value == value)
				break;

		if(value > tmp->value) {
			if(tmp->right == NULL) {
				printf("-\n");
				return 0;
			}
			tmp = tmp->right;
		}
		else {
			if(tmp->left == NULL) {
				printf("-\n");
				return 0;
			}
			tmp = tmp->left;
		}
	}

	printf("%d ", tmp->parent->value);
	        if(tmp->left == NULL)
		   printf("_ ");
	        else
		   printf("%d ", tmp->left->value);
	        if(tmp->right == NULL)
		   printf("_");
	        else
		   printf("%d", tmp->right->value);
	printf("\n");
 }

 int insert(tree* T, int value) {
	node* tmp = malloc(sizeof(node));

	if(tmp == NULL) {
	   return 2;
	}

	tmp->value = value;
	tmp->left = NULL;
	tmp->right = NULL;

	if(T->root == NULL) {
	   T->root = tmp;
	}
	else {
              node* curr = T->root;
	      node* prev = NULL;

                    int check;

		while(curr != NULL){
		      prev = curr;
		      if(value < curr->value) {
			 curr = curr->left;
		         check = 1;
		}
		       else if(value == curr->value) {
			       return 1;
			}
			else {
			       curr = curr->right;
			       check = 0;
			}
		}
		if(check) {
			   prev->left = tmp;
			   tmp->parent = prev;
		}
		else {
		      prev->right = tmp;
	              tmp->parent = prev;
		}
	}
        T->Tnum++;
        return 0;
 }
 
 int delete(tree* T, int value, turn* t) {
	node* tmp = T->root;
	node* parad;
	node* q;

	while(tmp != NULL) {
		if(tmp->value == value)
			break;

		if(value > tmp->value) {
			if(tmp->right == NULL) {
				return 1;
			}
			tmp = tmp->right;
		}
		else  {
			if(tmp->left == NULL) {
				return 1;
			}
			tmp = tmp->left;
		}
	}
	if(tmp->value == T->root->value) {
		parad = tmp;
		if(tmp->right != NULL) {
			parad = tmp->right;

			while(parad->left != NULL) {
				parad = parad->left;
			}
		}
		parad->parent = NULL;
		parad->left = tmp->left;
		q = tmp;
		q = q->left;
		q->parent = parad;
		
		T->root = parad;
		free(tmp);
		T->Tnum--;
		return 1;
	}
	return 0;
}

 //int deleteMin(node* n, turn* t)
 
 int deletMin(tree* T, int value, turn* t){
	///.
 }
 
 int rotateRight(tree* T) {
	node* tmp = T->root;
	node* q;

	while(tmp->left != NULL) {
		tmp = tmp->left;
	}
	
	T->root = tmp;
	while(q->parent != NULL) {
		q = tmp->parent;
		// printf("%d\n", q->value);
		q->left = NULL;
		tmp->right = q;
		tmp = tmp->right;
	}

	tmp = T->root;
	tmp->parent = NULL;
	while(tmp->right != NULL) {
		q = tmp;
		tmp = tmp->right;
		tmp->parent = q;
	}
 }

 int rotateLeft(tree* T) {
	node* tmp = T->root;
	node* q;

	while(tmp->right != NULL) {
		tmp = tmp->right;
	}
	
	T->root = tmp;

	while(q->parent != NULL) {
		q = tmp->parent;
		q->right = NULL;
		tmp->left = q;
		tmp = tmp->left;
	}

	tmp = T->root;
	tmp->parent = NULL;
	while(tmp->left != NULL) {
		q = tmp;
		tmp = tmp->left;
		tmp->parent = q;
	}
 }

 // void print(node* n)

 void print(tree* T, int value, turn* t) {
	node* tmp = T->root;
	turn* q;
	q = malloc(sizeof(turn));

	while(tmp != NULL) {
		if(value > tmp->value) {
			if(tmp->value == value)
				break;

			if(tmp->right == NULL) {
				printf("-\n");
				return;
			}
			tmp = tmp->right;
		}
		else {
			if(tmp->left == NULL) {
				printf("-\n");
				return;
			}
			tmp = tmp->left;
		}
	}
	push_in_turn(t, tmp);
	print_turn(t);

	for(;;) {
		while(!isEmpty_turn(t)) {
			tmp = pop_out_turn(t);
			push_in_turn(q, tmp);
		}
		while(!isEmpty_turn(q)) {
			tmp = pop_out_turn(q);
			if(tmp == NULL) {
				push_in_turn(t, NULL);
				push_in_turn(t, NULL);
			}
			else {
				push_in_turn(t, tmp->left);
				push_in_turn(t, tmp->right);
			}
		}
		if(control(t)) {
			while(!isEmpty_turn(t))
				pop_out_turn(t);
			break;
		}
		print_turn(t);
	}
 }

 void printTree(tree* T, turn* t) {
	node* tmp = T->root;
	turn* q;
	q = malloc(sizeof(turn));

	if(tmp == NULL) {
		printf("-\n");
		return;
	}
	push_in_turn(t, tmp);
	print_turn(t);

	for(;;) {
		while(!isEmpty_turn(t)) {
			tmp = pop_out_turn(t);
			push_in_turn(q, tmp);
		}
		while(!isEmpty_turn(q)) {
			tmp = pop_out_turn(q);
			if(tmp == NULL) {
				push_in_turn(t, NULL);
				push_in_turn(t, NULL);
			}
			else {
				push_in_turn(t, tmp->left);
				push_in_turn(t, tmp->right);
			}
		}
		if(control(t)) {
			while(!isEmpty_turn(t))
				pop_out_turn(t);
			break;
		}
		print_turn(t);
	}
 }

 int main() {
	int n;
	turn *t;
	tree *T;

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	T = malloc(sizeof(tree));
	init(T);
	t = malloc(sizeof(turn));
	init_turn(t);

	for (int i = 0; i < 4; ++i) {
		scanf("%d", &n);
		insert(T, n);
	}

	printTree(T, t);

	for (int i = 0; i < 3; ++i) {
		scanf("%d", &n);
		insert(T, n);
	}

	printTree(T, t);

	scanf("%d", &n);
	find(T, n, NULL, t);

	scanf("%d", &n);
	find(T, n, NULL, t);

	scanf("%d", &n);
	delete(T, n, t);
	printTree(T, t);

	rotateLeft(T);
	printTree(T, t);

	rotateRight(T);
	printTree(T, t);

	printf("%d\n", T->Tnum);
	clear(T, t);

	printTree(T, t);

	return 0;
}
