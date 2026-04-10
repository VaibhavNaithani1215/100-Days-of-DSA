#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left,*right;
};

struct Node* newNode(int x){
    struct Node* n=malloc(sizeof(struct Node));
    n->data=x;
    n->left=n->right=NULL;
    return n;
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    if(n==0 || arr[0]==-1) return 0;

    struct Node* nodes[n];
    for(int i=0;i<n;i++){
        if(arr[i]==-1) nodes[i]=NULL;
        else nodes[i]=newNode(arr[i]);
    }

    for(int i=0;i<n;i++){
        if(nodes[i]){
            int l=2*i+1,r=2*i+2;
            if(l<n) nodes[i]->left=nodes[l];
            if(r<n) nodes[i]->right=nodes[r];
        }
    }

    struct Node* queue[1000];
    int front=0,rear=0;
    queue[rear++]=nodes[0];

    while(front<rear){
        int size=rear-front;
        for(int i=0;i<size;i++){
            struct Node* curr=queue[front++];
            printf("%d",curr->data);
            if(i<size-1) printf(" ");
            if(curr->left) queue[rear++]=curr->left;
            if(curr->right) queue[rear++]=curr->right;
        }
        if(front<rear) printf("\n");
    }
    return 0;
}