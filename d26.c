#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

int main(){
    int n,x;
    scanf("%d",&n);
    struct Node *head=NULL,*temp=NULL,*newnode;
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        newnode=malloc(sizeof(struct Node));
        newnode->data=x;
        newnode->prev=NULL;
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
            temp=head;
        }else{
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
    }
    temp=head;
    while(temp){
        printf("%d",temp->data);
        if(temp->next) printf(" ");
        temp=temp->next;
    }
    return 0;
}