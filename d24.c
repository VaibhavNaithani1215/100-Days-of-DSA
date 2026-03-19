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

struct Node* deleteKey(struct Node* head,int key){
    if(head==NULL) return head;
    if(head->data==key){
        struct Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    struct Node* curr=head;
    while(curr->next && curr->next->data!=key){
        curr=curr->next;
    }
    if(curr->next){
        struct Node* temp=curr->next;
        curr->next=temp->next;
        free(temp);
    }
    return head;
}

int main(){
    int n,x,key;
    scanf("%d",&n);
    struct Node* head=NULL;
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        head=insert(head,x);
    }
    scanf("%d",&key);
    head=deleteKey(head,key);
    struct Node* temp=head;
    while(temp){
        printf("%d",temp->data);
        if(temp->next) printf(" ");
        temp=temp->next;
    }
    return 0;
}