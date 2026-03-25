#include <stdio.h>
#include <stdlib.h>

struct Node{
    int coeff, exp;
    struct Node* next;
};

int main(){
    int n,c,e;
    scanf("%d",&n);
    struct Node *head=NULL,*temp=NULL,*newnode;
    for(int i=0;i<n;i++){
        scanf("%d %d",&c,&e);
        newnode=malloc(sizeof(struct Node));
        newnode->coeff=c;
        newnode->exp=e;
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
            temp=head;
        }else{
            temp->next=newnode;
            temp=newnode;
        }
    }
    temp=head;
    while(temp){
        if(temp->exp==0) printf("%d",temp->coeff);
        else if(temp->exp==1) printf("%dx",temp->coeff);
        else printf("%dx^%d",temp->coeff,temp->exp);
        if(temp->next) printf(" + ");
        temp=temp->next;
    }
    return 0;
}