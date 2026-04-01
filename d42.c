#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d",&n);
    int *queue=malloc(n*sizeof(int));
    int *stack=malloc(n*sizeof(int));
    for(int i=0;i<n;i++) scanf("%d",&queue[i]);
    int top=-1;
    for(int i=0;i<n;i++) stack[++top]=queue[i];
    int idx=0;
    while(top!=-1) queue[idx++]=stack[top--];
    for(int i=0;i<n;i++){
        printf("%d",queue[i]);
        if(i<n-1) printf(" ");
    }
    return 0;
}