#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int data;
    struct Node* next;
};

int main(){
    int n,x;
    scanf("%d",&n);
    char op[20];
    struct Node *front=NULL,*rear=NULL;
    while(n--){
        scanf("%s",op);
        if(strcmp(op,"enqueue")==0){
            scanf("%d",&x);
            struct Node* newnode=malloc(sizeof(struct Node));
            newnode->data=x;
            newnode->next=NULL;
            if(rear==NULL){
                front=rear=newnode;
            }else{
                rear->next=newnode;
                rear=newnode;
            }
        }else if(strcmp(op,"dequeue")==0){
            if(front==NULL){
                printf("-1\n");
            }else{
                struct Node* temp=front;
                printf("%d\n",temp->data);
                front=front->next;
                if(front==NULL) rear=NULL;
                free(temp);
            }
        }
    }
    return 0;
}