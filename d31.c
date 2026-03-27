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

struct Node* reverse(struct Node* head){
    struct Node *prev=NULL,*curr=head,*next=NULL;
    while(curr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

struct Node* add(struct Node* l1, struct Node* l2){
    l1=reverse(l1);
    l2=reverse(l2);
    struct Node dummy;
    struct Node* tail=&dummy;
    dummy.next=NULL;
    int carry=0;
    while(l1 || l2 || carry){
        int sum=carry;
        if(l1){ sum+=l1->data; l1=l1->next; }
        if(l2){ sum+=l2->data; l2=l2->next; }
        struct Node* newnode=malloc(sizeof(struct Node));
        newnode->data=sum%10;
        newnode->next=NULL;
        tail->next=newnode;
        tail=newnode;
        carry=sum/10;
    }
    return reverse(dummy.next);
}

int main(){
    int n,m,x;
    scanf("%d",&n);
    struct Node* l1=NULL;
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        l1=insert(l1,x);
    }
    scanf("%d",&m);
    struct Node* l2=NULL;
    for(int i=0;i<m;i++){
        scanf("%d",&x);
        l2=insert(l2,x);
    }
    struct Node* res=add(l1,l2);
    while(res){
        printf("%d",res->data);
        if(res->next) printf(" ");
        res=res->next;
    }
    return 0;
}