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

struct Node* merge(struct Node* l1,struct Node* l2){
    struct Node dummy;
    struct Node* tail=&dummy;
    dummy.next=NULL;
    while(l1 && l2){
        if(l1->data < l2->data){
            tail->next=l1;
            l1=l1->next;
        }else{
            tail->next=l2;
            l2=l2->next;
        }
        tail=tail->next;
    }
    if(l1) tail->next=l1;
    else tail->next=l2;
    return dummy.next;
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
    struct Node* res=merge(l1,l2);
    while(res){
        printf("%d",res->data);
        if(res->next) printf(" ");
        res=res->next;
    }
    return 0;
}