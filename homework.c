#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

typedef struct node *plist ;
typedef struct node {
    char data ; 
    plist next ;
}word;
int  main () {
   int i , n ; 
   plist H , P , P1 , P2 ; 
   printf("input the number of steos n : ") ;
   do
   {
    scanf("%d" , &n ) ;

   } while (n <= 0 );
   H = malloc(sizeof(word)) ;
 H->data = 'A' ;
 H ->next = H ; 
 printf("evolution of the word : \n");
 i = 0 ; 
 printf("steps %d : %c" , i , H->data ) ; 
 for (int i = 0; i < n; i++)
 {
    P = H ; 
     do
     {
        switch (P ->data)
        {
        case  'A' : P1 = malloc(sizeof(word)) ; 
              P1 ->data = 'B' ; 
              P2 = malloc(sizeof(word));
            //   P2 -> data = 'C' ; 
              P1 ->next = P2 ; 
              P2 ->next = P ->next ;
              P ->next = P1 ; 
              P = P2 ;
            break;
     case 'B' : P ->data = 'C' ; break;
     case 'C' : P ->data = 'A' ; break;
     P = P -> next ; 
        }
     } while ( P!= H);
     printf("step %d : " , i ) ;
  do
  {
    printf("%c" , P->data ) ;
    P = P -> next ; 
  } while (P != H);
  printf("\n");
 }
return 0 ;
}