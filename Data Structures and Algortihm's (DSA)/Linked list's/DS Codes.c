// Online C compiler to run C program online at any position
#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *cn();
void iaa();
void display();
void deletes();

int main() {
 struct node *head=NULL;
 iaa(&head,10,1);
 iaa(&head,20,2);
 iaa(&head,30,1);
 iaa(&head,40,4);
  display(head);
 deletes(&head,2);
 display(head);

}
void iaa(struct node **temp,int data,int pos){
    struct node *nnp=cn(data);
    if(pos==1){
        nnp->next=*temp;
        *temp=nnp;
    }
    else{
        struct node *ntemp=*temp;
        for(int i=1;i<pos-1;i++){
            ntemp=ntemp->next;
        }
        nnp->next=ntemp->next;
        ntemp->next=nnp;
    }
}
struct node *cn(int data){
    struct node *cr=(struct node *)malloc(sizeof(struct node));
    cr->data=data;
    cr->next=NULL;
    return cr;
}
void display(struct node *temp){
    while(temp!=NULL){
        printf("The data inserted is %d\n",temp->data);
        temp=temp->next;
    }
}
void deletes(struct node **temp,int pos){
    struct node *temp1;
    if(pos==1){
      (*temp)=(*temp)->next;
    }
    else{
        struct node *link=*temp;
        struct node *ntemp=NULL;
        for(int i=0;i<pos-1;i++){
          link=link->next;
        }
         printf("the node deleted is %d\n",link->next->data);
       link->next=link->next->next;
       
    }
} // ************************************************** //
// Online C compiler to run C program online at beginning
#include <stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
void display();
struct node *cn();
void iab();
void deletionatB();
int main() {
    struct node *head=NULL;
    iab(&head,10);
    iab(&head,20);
    iab(&head,30);
    display(head);
    deletionatB(&head);
    display(head);
    return 0;
}
void iab(struct node **temp,int data){
    struct node *nn=cn(data);
    if(*temp==NULL){
        *temp=nn;
    }
    else{
        nn->next=*temp;
        *temp=nn;
        
    }
}
struct node *cn(int data){
    struct node *nnp=(struct node*)malloc(sizeof(struct node));
    nnp->data=data;
    nnp->next=NULL;
    return nnp;
}
void display(struct node *temp){
    while(temp!=NULL){
        printf("The data is %d\n",temp->data);
        temp=temp->next;
    }
}
void deletionatB(struct node **temp){
    struct node *fre=*temp;
    (*temp)=(*temp)->next;
    printf("The deletion is %d\n",fre->data);
    free(fre);
} //******************************************************//
// Online C compiler to run C program online at end
#include <stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
void display();
struct node *cn();
void iab();
void deletionatD();
int main() {
    struct node *head=NULL;
    iab(&head,10);
    iab(&head,20);
    iab(&head,30);
    display(head);
    deletionatD(&head);
    display(head);
    return 0;
}
void iab(struct node **temp,int data){
    struct node *nn=cn(data);
    if(*temp==NULL){
        *temp=nn;
    }
    else{
        nn->next=*temp;
        *temp=nn;
        
    }
}
struct node *cn(int data){
    struct node *nnp=(struct node*)malloc(sizeof(struct node));
    nnp->data=data;
    nnp->next=NULL;
    return nnp;
}
void display(struct node *temp){
    while(temp!=NULL){
        printf("The data is %d\n",temp->data);
        temp=temp->next;
    }
}
void deletionatD(struct node **head){
    struct node *temp=*head;
    struct node *ptr;
   while(temp->next!=NULL){
       ptr=temp;
       temp=temp->next;
   }
   printf("The deleted node is %d\n",temp->data);
   ptr->next=NULL;
   free(temp);
   
}
// ***********************************************************  //
// Online C compiler to run C program online doubly at any insert
#include <stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *cn();
void iaa();
void display();

int main() {
 struct node *head=NULL;
 iaa(&head,10,1);
 iaa(&head,20,2);
 iaa(&head,30,3);
 iaa(&head,40,4);
 display(head);

}
void iaa(struct node **temp,int data,int pos){
    struct node *nnp=cn(data);
    if(pos==1){
        if(*temp==NULL){
           *temp=nnp;
        }
        else{
        nnp->next=*temp;
        (*temp)->prev=nnp;
        *temp=nnp;}
    }
    else{
        struct node *ntemp=*temp;
        for(int i=1;i<pos-1;i++){
            ntemp=ntemp->next;
        }
        if(ntemp->next==NULL){
            ntemp->next=nnp;
            nnp->prev=ntemp;
        }
        else{
            nnp->next=ntemp->next;
            ntemp->next=nnp;
            ntemp->next->prev=nnp;
            nnp->prev=ntemp;
            
        }
    }
}
struct node *cn(int data){
    struct node *cr=(struct node *)malloc(sizeof(struct node));
    cr->prev=NULL;
    cr->data=data;
    cr->next=NULL;
    return cr;
}
void display(struct node *temp){
    while(temp!=NULL){
        printf("The data inserted is %d\n",temp->data);
        temp=temp->next;
    }
} //*************************************************************//
// Online C compiler to run C program online insert at any
#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *cn();
void iaa();
void display();

int main() {
 struct node *head=NULL;
 iaa(&head,10,1);
 iaa(&head,20,2);
 iaa(&head,30,1);
 iaa(&head,40,4);
 display(head);

}
void iaa(struct node **temp,int data,int pos){
    struct node *nnp=cn(data);
    if(pos==1){
        nnp->next=*temp;
        *temp=nnp;
    }
    else{
        struct node *ntemp=*temp;
        for(int i=1;i<pos-1;i++){
            ntemp=ntemp->next;
        }
        nnp->next=ntemp->next;
        ntemp->next=nnp;
    }
}
struct node *cn(int data){
    struct node *cr=(struct node *)malloc(sizeof(struct node));
    cr->data=data;
    cr->next=NULL;
    return cr;
}
void display(struct node *temp){
    while(temp!=NULL){
        printf("The data inserted is %d\n",temp->data);
        temp=temp->next;
    }
} //8************************************************************************//
#include<stdio.h> // insert at beginning
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *cn();
void iab();
void display();
int main(){
    struct node *header = NULL;
    iab(&header,10);
    iab(&header,20);
    display(header);
}
void iab(struct node **ptr,int data){
    struct node *new1 = cn(data);
    if(*ptr==NULL){
        *ptr=new1;
    }
    else{
        
        new1->next=*ptr;
        *ptr=new1;
    }
}
struct node *cn(int data){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=NULL;
    return ptr;
}
void display(struct node *temp){
    while(temp!=NULL){
        printf("The insertes data is %d\n",temp->data);
        temp=temp->next;
    }
} // ********************************************************//
// Online C compiler to run C program online insert at end
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
 //******************************************************//
 #include<stdio.h>// insert doubly at beginning
#include<stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *cn();
void iab();
void display();
int main(){
    struct node *header = NULL;
    iab(&header,10);
    iab(&header,20);
    iab(&header,30);
    iab(&header,40);
    display(header);
}
void iab(struct node **ptr,int data){
    struct node *new1 = cn(data);
    if(*ptr==NULL){
        *ptr=new1;
    }
    else{
        
        new1->next=*ptr;
        (*ptr)->prev=new1;
        *ptr=new1;
    }
}
struct node *cn(int data){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->prev=NULL;
    ptr->data=data;
    ptr->next=NULL;
    return ptr;
}
void display(struct node *temp){
    while(temp!=NULL){
        printf("The insertes data is %d\n",temp->data);
        temp=temp->next;
    }
}//***************************************************?//
// Online C compiler to run C program online doubly at end insert
#include <stdio.h>
#include<stdlib.h>

struct node
{
  struct node *prev;
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
        nnp1->prev=temp;
    }
    printf("%d inserted\n",nnp1->data);
}
struct node *cn(int d)
{
    struct node *nnp=(struct node *)malloc(sizeof(struct node));
    nnp->prev=NULL;
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
 // ******************************************************************* //
