#include<stdio.h>
#include<stdlib.h>

struct node
{
  struct node* prev ;
  int data ; 
  struct node *next;
};
struct node* addToEmpty(int data){
  struct node* temp = malloc(sizeof (struct node));
  temp->prev = temp;
  temp->data = data ;
  temp->next = temp;
}
struct node* addAtBeg(struct node* tail , int data)
{
   struct node* newp = addToEmpty(data);
     if (tail == NULL)
     {
      return newp ;
     }
    else {
      struct node * temp = tail->next ;
      newp->prev = tail;
      newp->next = temp;
      temp->prev = newp;
      tail->next = newp ;
      return tail;
    }
}
void print(struct node* tail){
  if (tail == NULL)
  {
    printf("no element in the fucking list ");
  }
//      temp = tail->next ;
//    }while(temp != tail->next);
   }
//printf("\n");


int main()
{
  struct node * tail = NULL ;
  tail = addToEmpty(45);
  tail = addAtBeg(tail , 34);
  print(tail);
  return 0;
}
