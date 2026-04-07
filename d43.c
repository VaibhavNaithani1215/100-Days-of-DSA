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
        if(nodes[i]!=NULL){
            int l=2*i+1,r=2*i+2;
            if(l<n) nodes[i]->left=nodes[l];
            if(r<n) nodes[i]->right=nodes[r];
        }
    }

    struct Node* stack[1000];
    int top=-1;
    struct Node* curr=nodes[0];

    while(curr || top!=-1){
        while(curr){
            stack[++top]=curr;
            curr=curr->left;
        }
        curr=stack[top--];
        printf("%d",curr->data);
        if(top!=-1 || curr->right) printf(" ");
        curr=curr->right;
    }
    return 0;
}