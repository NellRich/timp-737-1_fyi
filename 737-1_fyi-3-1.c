 #include<stdio.h>
 #include<stdlib.h>

 typedef struct node{
       int value;
       struct node *next;
 } node;

 typedef struct list{
       struct node *head;
       struct node *tail;
 } list;

 void init(list* l){
    l->head = NULL;
    l->tail = NULL;
 }

 void clear(list* l){
    node* tmp = l->head;

      while(tmp != NULL){
       tmp = tmp ->next;
       free(tmp);
    }
       l->head = NULL;
       l->tail = NULL;
 }

 int isEmpty(list* l){
    
     if(l->head == NULL && l->tail == NULL)
           return 0;
     return 1;
 }

 int find(list* l, int value){
     node* tmp = l->head;

     while(tmp != NULL){
         if(tmp->value == value)
           return 1;
         tmp = tmp->next;
     }
         return 0;
 }

 int push_back(list*l,int value){
     node* tmp = malloc(sizeof(node));
     tmp->value = value;
     tmp->next = NULL;

        if(l->head == NULL){
              l->head = tmp;
              l->tail = tmp;
              return 0;
        }
        else {
              l->tail->next = tmp;
              l->tail = tmp;
              return 0;
        }
        return 1;
 }

 int push_front(list* l, int value){
     node* tmp = malloc(sizeof(node));
     tmp->value = value;

        if(l->tail == NULL){
              l->head = tmp;
              l->tail = tmp;
              return 0;
        }
        else {
              tmp->next = l->head;
              l->head = tmp;
              return 0;
        }
        return 1;
 }             

 int insertAfter(list* l, int num, int value){
     node* tmp = l->head;
     
     for(int i=0; i<num; ++i){
             tmp = tmp->next;
          if(tmp == NULL)
               return 1;
     }
     node* tmp1 = malloc(sizeof(node));
     tmp1->value = value;
     tmp1->next = tmp->next;
     tmp->next = tmp1;
       return 0;
     }

 int delete(list* l, int value){
     node* tmp;
     node* p;
     tmp = l->head;
     
     while(tmp->value != value){
             p = tmp;
             tmp = tmp->next;
     }
     if(tmp == NULL)
        return 1;

     p->next = tmp->next;
     free(tmp);
      return 0;
}

 void print(list* l){
      node* tmp;
      tmp = l->head;

    while(tmp != NULL){
         printf("%d",tmp->value);
         tmp = tmp->next;
    if(tmp != NULL)
      printf(" ");
    }
    printf("\n");
 }

 int main(){
     int N, x, y;
     list* ls;

     init(ls);
     scanf("%d", &N);


    for(int i=0; i<N; ++i){
        scanf("%d", &x);
        push_back(ls, x);
    }
    print(ls);
     
    for(int i=1; i<=3; ++i){
        scanf("%d", &y);
        printf("%d", find(ls, y));
    }
    printf("\n");

    scanf("%d", &x);
    push_back(ls, x);
    print(ls);

    scanf("%d", &x);
    push_front(ls, x);
    print(ls);

    scanf("%d %d", &x, &y);
    insertAfter(ls, x-1, y);
    print(ls);

    scanf("%d",&x);
    delete(ls, x);
    print(ls);

    clear(ls);
    return 0;
 }
