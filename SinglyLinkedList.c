#include <stdio.h>
#include<stdlib.h>
struct node{
    int n;
    struct node *link;
};
int main() {
   struct node *head=NULL;
   head=malloc(sizeof(struct node));
   struct node *first=NULL;
   first=malloc(sizeof(struct node));
   struct node *second=NULL;
   second=malloc(sizeof(struct node));
   struct node *p=head;
   head->link=first;
    first->link=second;
    second->link=NULL;
   while(p!=NULL){
       scanf("%d",&(p->n));
       p=p->link;
   }
   p=head;
   while(p!=NULL){
       printf("%d\n",p->n);
       p=p->link;
   }
   
    return 0;
}
