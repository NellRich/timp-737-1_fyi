 #include<stdio.h> 
 #include<stdlib.h>

 typedef struct node{
      int value;
      struct node *next;
      struct node *prev;
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
    node* p;

    while(tmp != NULL){
          p = tmp->next;
          free(tmp);
          tmp = p;
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
       node* tmp;
       tmp = l->head;

       while(tmp != NULL){

             if(tmp->value == value)
                      return 1;
             tmp = tmp->next;
       }
       return 0;
 }
 
 int push_back(list* l, int value){
     node* tmp = malloc(sizeof(node));    
           tmp->value = value;
           tmp->next = NULL;
           tmp->prev = NULL;

     if(!isEmpty(l)){
        l->head = tmp;
        l->tail = tmp;
        return 0;
     }
     else {
          tmp->prev = l->tail;
          l->tail->next = tmp;
          l->tail = tmp;
          return 0;
     }
     return 1;
 }

 int push_front(list* l, int value){
     node* tmp = malloc(sizeof(node));
     tmp->value = value;
     tmp->next = NULL;
     tmp->prev = NULL;
   
     if(!isEmpty(l)){
        l->head = tmp;
        l->tail = tmp;
        return 0;
     }
     else {
          tmp->next = l->head;
          l->head->prev = tmp;
          l->head = tmp; 
             return 0;
     }
     return 1;
 } 
     
 int insertAfter(list* l,int num, int value){
     node* tmp = l->head;
      
     for(int i=0; i<num; ++i){
         tmp = tmp->next;
            if(tmp == NULL)
                 return 1;
     }
     node* tmp1 = malloc(sizeof(node));
     tmp1->value = value;

          if(tmp == l->tail){
             tmp->next = tmp1;
             tmp1->prev = tmp;
             tmp1->next = NULL;
          }
          else {
             tmp1->next = tmp->next;
             tmp1->prev = tmp;

             tmp->next = tmp1;
             tmp = tmp->next;
             tmp = tmp->next;
             tmp->prev = tmp1;
                  return 0;
          }
 } 

 int insertBefore(list* l, int num, int value){
     node* tmp = l->head;

     for(int i=0; i<num; ++i){
         tmp = tmp->next;
         if(tmp == NULL)
            return 1;
     }
     node* tmp1 = malloc(sizeof(node));
     tmp1->value = value;
        if(tmp == l->head){
           tmp->prev = tmp1;
           tmp1->next = tmp;
           tmp1->prev = NULL;
           l->head = tmp1;
        }
        else {
           tmp1->prev = tmp->prev;
           tmp1->next = tmp;

           tmp->prev = tmp1;
           tmp = tmp->prev;
           tmp = tmp->prev;
           tmp->next = tmp1;
                return 0;
        }
 }
    
 int deleteFirst(list* l, int value){
     node* tmp = l->head;
     node* p;

     while(tmp != NULL){
           p = tmp;
            if(tmp->value == value){
               if(tmp == l->head){
                  tmp = tmp->next;
                  tmp->prev = NULL;
                  free(p);
               }
               else if(tmp == l->tail){
                    tmp = tmp->prev;
                    tmp->next = NULL;
                    free(p);
                    l->tail = tmp;
               }
               else {
                    tmp = p->next;
                    tmp->prev = p->prev;
                    tmp = p->prev;
                    tmp->next = p->next;
                    free(p);
               }
               return 0;
             }
             tmp = tmp->next;
       }
       return 1;     
 }

 int deleteLast(list* l, int value){
     node* tmp = l->tail;
     node* p;

     while(tmp != NULL){
           p = tmp;
           if(tmp->value == value){

              if(tmp == l->tail){
                 tmp = tmp->prev;
                 tmp->next = NULL;
                 free(p);
              }
              else if(tmp == l->head){
                      tmp = tmp->next;
                      tmp-> prev = NULL;
                      free(p);
                      l->head = tmp;
              }
              else {
                    tmp = p->next;
                    tmp->prev = p->prev;
                    tmp = p->prev;
                    tmp->next = p->next;
                    free(p);
               }
               return 0;
             }
             tmp = tmp->prev;
        }
        return 1;
 } 
                      
 void print(list* l){
     node* tmp;
     tmp = l->head;

     while(tmp != NULL){
           printf("%d", tmp->value);
           tmp = tmp->next;
     if(tmp != NULL)
        printf(" ");
     }
     printf("\n");
 }

 void print_invers(list* l){
     node* tmp;
     tmp = l->tail;

     while(tmp != NULL){
           printf("%d", tmp->value);
           tmp = tmp->prev;
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
    // print(ls);

     print_invers(ls);

     scanf("%d", &x);
     push_front(ls, x);
     print(ls);

     scanf("%d %d", &x, &y);
     insertAfter(ls, x-1, y);

     print_invers(ls);

     scanf("%d %d", &x, &y);
     insertBefore(ls, x-1, y);

     print(ls);

     scanf("%d", &x);
     deleteFirst(ls, x);

     print_invers(ls);

     scanf("%d", &x);
     deleteLast(ls, x);

     print(ls);
 
     clear(ls);

     return 0;
 }
