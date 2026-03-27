#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int data;
    struct Node* next;
};

void push(struct Node** top,int x){
    struct Node* newnode=malloc(sizeof(struct Node));
    newnode->data=x;
    newnode->next=*top;
    *top=newnode;
}

int pop(struct Node** top){
    struct Node* temp=*top;
    int x=temp->data;
    *top=temp->next;
    free(temp);
    return x;
}

int main(){
    char s[1000];
    fgets(s,1000,stdin);
    struct Node* top=NULL;
    char *token=strtok(s," \n");
    while(token){
        if(strlen(token)==1 && (token[0]=='+'||token[0]=='-'||token[0]=='*'||token[0]=='/')){
            int b=pop(&top);
            int a=pop(&top);
            int res;
            if(token[0]=='+') res=a+b;
            else if(token[0]=='-') res=a-b;
            else if(token[0]=='*') res=a*b;
            else res=a/b;
            push(&top,res);
        }else{
            int num=atoi(token);
            push(&top,num);
        }
        token=strtok(NULL," \n");
    }
    printf("%d",pop(&top));
    return 0;
}