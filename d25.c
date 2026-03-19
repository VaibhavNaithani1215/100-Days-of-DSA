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

int main(){
    int n,x,key,count=0;
    scanf("%d",&n);
    struct Node* head=NULL;
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        head=insert(head,x);
    }
    scanf("%d",&key);
    struct Node* temp=head;
    while(temp){
        if(temp->data==key) count++;
        temp=temp->next;
    }
    printf("%d",count);
    return 0;
}