// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};
struct node *cn();
void display();
void iae();

int main() {
    struct node *head=NULL;
    iae(&head,1);
    iae(&head,2);
     iae(&head,3);
      iae(&head,4);
    display(head);
  
}
void iae(struct node **head1,int d)
{
   struct node *nnp1=cn(d);
   if(*head1==NULL)
        *head1=nnp1;
    else
    {
        struct node *temp=*head1;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=nnp1;
    }
    printf("%d inserted\n",nnp1->data);
}
struct node *cn(int d)
{
    struct node *nnp=(struct node *)malloc(sizeof(struct node));
    nnp->data=d;
    nnp->next=NULL;
    return nnp;
}
void display(struct node *temp)
{
    while(temp!=NULL)
    {
        printf("%d iserted in order\n",temp->data);
        temp=temp->next;
    }
}
