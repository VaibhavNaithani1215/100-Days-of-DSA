#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int dq[MAX];
int front=0,rear=-1,size=0;

void push_front(int x){
    front=(front-1+MAX)%MAX;
    dq[front]=x;
    if(size==0) rear=front;
    size++;
}

void push_back(int x){
    rear=(rear+1)%MAX;
    dq[rear]=x;
    if(size==0) front=rear;
    size++;
}

void pop_front(){
    if(size==0) return;
    front=(front+1)%MAX;
    size--;
}

void pop_back(){
    if(size==0) return;
    rear=(rear-1+MAX)%MAX;
    size--;
}

int main(){
    int n,x;
    scanf("%d",&n);
    char op[20];
    while(n--){
        scanf("%s",op);
        if(strcmp(op,"push_front")==0){
            scanf("%d",&x);
            push_front(x);
        }else if(strcmp(op,"push_back")==0){
            scanf("%d",&x);
            push_back(x);
        }else if(strcmp(op,"pop_front")==0){
            pop_front();
        }else if(strcmp(op,"pop_back")==0){
            pop_back();
        }else if(strcmp(op,"front")==0){
            if(size==0) printf("-1\n");
            else printf("%d\n",dq[front]);
        }else if(strcmp(op,"back")==0){
            if(size==0) printf("-1\n");
            else printf("%d\n",dq[rear]);
        }else if(strcmp(op,"empty")==0){
            printf("%d\n",size==0);
        }else if(strcmp(op,"size")==0){
            printf("%d\n",size);
        }
    }
    for(int i=0;i<size;i++){
        printf("%d",dq[(front+i)%MAX]);
        if(i<size-1) printf(" ");
    }
    return 0;
}