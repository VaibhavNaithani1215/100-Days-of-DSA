#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,m,x;
    scanf("%d",&n);
    int *q=malloc(n*sizeof(int));
    int front=0,rear=0;
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        q[rear]=x;
        rear=(rear+1)%n;
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        front=(front+1)%n;
    }
    int size=n-m;
    for(int i=0;i<size;i++){
        printf("%d",q[(front+i)%n]);
        if(i<size-1) printf(" ");
    }
    return 0;
}