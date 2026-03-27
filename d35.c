#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,x;
    scanf("%d",&n);
    int *q=malloc(n*sizeof(int));
    int front=0,rear=-1;
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        q[++rear]=x;
    }
    for(int i=front;i<=rear;i++){
        printf("%d",q[i]);
        if(i<rear) printf(" ");
    }
    return 0;
}