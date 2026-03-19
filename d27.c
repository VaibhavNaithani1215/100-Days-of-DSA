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

    int len1=length(l1),len2=length(l2);
    struct Node *p1=l1,*p2=l2;

    if(len1>len2){
        for(int i=0;i<len1-len2;i++) p1=p1->next;
    }else{
        for(int i=0;i<len2-len1;i++) p2=p2->next;
    }

    while(p1 && p2){
        if(p1->data==p2->data){
            printf("%d",p1->data);
            return 0;
        }
        p1=p1->next;
        p2=p2->next;
    }

    printf("No Intersection");
    return 0;
}