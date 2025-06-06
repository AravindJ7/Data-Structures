#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *cn();
void display();
void iaa();
int main(){
    struct node *head=NULL;
    iaa(&head,11,1);
    iaa(&head,12,2);
    iaa(&head,13,3);
    iaa(&head,14,4);
    iaa(&head,15,1);
    iaa(&head,16,2);
    display(head);
    
}
void iaa(struct node **head,int data,int position){
    struct node *nnp=cn(data);
    if(position==1){
        nnp->next=*head;
        *head=nnp;
    }
    else{
        struct node *temp=*head;
        for(int i=1;i<position-1;i++){
            temp=temp->next;
        }
        nnp->next=temp->next;
        temp->next=nnp;
        
    }
}
struct node *cn(int data){
    struct node *nnp1=(struct node *)malloc(sizeof(struct node));
    nnp1->data=data;
    nnp1->next=NULL;
    return nnp1;
    
}
void display(struct node *temp){
    while(temp!=NULL){
        printf("The node is %d\n",temp->data);
        temp=temp->next;
    }
}