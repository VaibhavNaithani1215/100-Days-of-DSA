#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int heap[1000];
int size=0;

void heapifyUp(int i){
    while(i>0){
        int p=(i-1)/2;
        if(heap[p]<=heap[i]) break;
        int t=heap[p];
        heap[p]=heap[i];
        heap[i]=t;
        i=p;
    }
}

void heapifyDown(int i){
    while(1){
        int l=2*i+1,r=2*i+2,small=i;
        if(l<size && heap[l]<heap[small]) small=l;
        if(r<size && heap[r]<heap[small]) small=r;
        if(small==i) break;
        int t=heap[i];
        heap[i]=heap[small];
        heap[small]=t;
        i=small;
    }
}

void insert(int x){
    heap[size]=x;
    heapifyUp(size);
    size++;
}

int extractMin(){
    if(size==0) return -1;
    int x=heap[0];
    heap[0]=heap[size-1];
    size--;
    heapifyDown(0);
    return x;
}

int peek(){
    if(size==0) return -1;
    return heap[0];
}

int main(){
    int n,x;
    scanf("%d",&n);
    char op[20];
    while(n--){
        scanf("%s",op);
        if(strcmp(op,"insert")==0){
            scanf("%d",&x);
            insert(x);
        }else if(strcmp(op,"extractMin")==0){
            printf("%d\n",extractMin());
        }else if(strcmp(op,"peek")==0){
            printf("%d\n",peek());
        }
    }
    return 0;
}