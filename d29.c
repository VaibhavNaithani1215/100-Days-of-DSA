#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* insert(struct Node* head,int x){
    struct Node* newnode=malloc(sizeof(struct Node));
    newnode->data=x;
    newnode->next=NULL;
    if(head==NULL) return newnode;
    struct Node* temp=head;
    while(temp->next) temp=temp->next;
    temp->next=newnode;
    return head;
}

int length(struct Node* head){
    int c=0;
    while(head){
        c++;
        head=head->next;
    }
    return c;
}

int main(){
    int n,x,k;
    scanf("%d",&n);
    struct Node* head=NULL;
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        head=insert(head,x);
    }
    scanf("%d",&k);
    if(head==NULL || head->next==NULL){
        struct Node* t=head;
        while(t){
            printf("%d",t->data);
            if(t->next) printf(" ");
            t=t->next;
        }
        return 0;
    }
    int len=length(head);
    k=k%len;
    if(k==0){
        struct Node* t=head;
        while(t){
            printf("%d",t->data);
            if(t->next) printf(" ");
            t=t->next;
        }
        return 0;
    }
    struct Node* tail=head;
    while(tail->next) tail=tail->next;
    tail->next=head;
    int steps=len-k;
    struct Node* newtail=head;
    for(int i=1;i<steps;i++) newtail=newtail->next;
    head=newtail->next;
    newtail->next=NULL;
    struct Node* t=head;
    while(t){
        printf("%d",t->data);
        if(t->next) printf(" ");
        t=t->next;
    }
    return 0;
}