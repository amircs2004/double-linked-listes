#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    struct node * next ; 
    struct node * prev ; 
    int data ;

}node;
// node * createFIFO(int n) {
//      struct tail * node ;
//       for (int i = 0; i < n; i++)
//       {
//          tail -> next = node ; 
//          tail = node ;
//       }
       
// }
struct node * createFIfo (int n){

    // n -> data
    struct node * head = NULL;
    struct node * tail = NULL ;
    for (int i = 0; i < n; i++)
    {
           struct node * newnode = (struct node *) malloc(sizeof(struct node));
           newnode -> data = i ;
           newnode -> next = NULL ;
           if (head ==  NULL)
           {
            head = newnode ; 
            tail = newnode ;
           }else {
            tail -> next = newnode ; 
            tail = newnode ;
           }
    }
    return head ; 
}
void removeDuplicate(struct node ** headA){
    struct node * current = * headA ;
    while (current != NULL && current->next != NULL){
        struct node * runner = current ;
    while (runner->next != NULL)
    {
      if (current-> data == runner->next->data) {
        struct node * temp = runner->next;
        runner->next = temp ->next ;
      free(temp);
      }else
      {
        runner = runner->next ;
      }
    }
    current = current->next;
    }
}


int main (){
    struct node * head = createFIfo(15);
    struct node * current = head ; 
    while (current != NULL)
    {
       printf("%d" , current -> data);
       current = current -> next ; 
    }
    current = head ; 
    while (current != NULL)
    {
       struct node * temp = current ; 
       current = current -> next;
       free(temp) ;
    }
    return 0 ;
}
//
typedef struct node {
  int data ; 
  struct node * next ; 
  struct node * prev ; 
}node;

node * createFIFO ( int n){
  node * head = NULL ; 
  node * tail = NULL ; 
  // struct node * newnode = (struct node *) malloc(sizeof(struct node));
   for (int i = 0; i < n; i++)
   {
    node * newnode = (struct node *) malloc(sizeof(struct node));
    newnode-> next = NULL ; 
    newnode-> prev = tail ; 
   
   
    newnode ->next = NULL ;
    newnode ->prev = tail ; 
  if (tail != NULL)
  {
    tail -> next = newnode ;
  }
   }
   return head  ; 

}  
// 
void delete (node **head , int v){
  node * temp = * head ;
  node * next ; 
  while (temp != NULL)
  {
   next = temp->next ; 
   if (temp->data == v)
   {
     if (temp->prev != NULL)
     {
        temp->prev->next = temp->next ; 

     }
     else {(* head = temp->next)}
   }
    if (temp->next = NULL )
     {
   temp ->next -> prev = temp -> prev ; 
     }
     free(temp);
   temp =  temp -> next;
  }
  
}
void rightRotation (node ** head) {
 node * tail = *head ; 
 while (tail ->next != NULL)
 {
 tail = tail -> next
 }
 tail ->prev-> next = NULL ;  //detach tail
 tail -> prev = NULL ;
  // attach back tail 
  (*head)->prev = tail ; 
  tail -> next = *head ;
  *head = tail ;
}
