#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
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
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
            temp=head;
        }else{
            temp->next=newnode;
            temp=newnode;
        }
    }
    if(temp) temp->next=head;
    if(head){
        struct Node* curr=head;
        do{
            printf("%d",curr->data);
            curr=curr->next;
            if(curr!=head) printf(" ");
        }while(curr!=head);
    }
    return 0;
}