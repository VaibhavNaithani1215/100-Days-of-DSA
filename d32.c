#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,m;
    scanf("%d",&n);
    int *stack=malloc(n*sizeof(int));
    int top=-1,x;
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        stack[++top]=x;
    }
    scanf("%d",&m);
    while(m-- && top!=-1) top--;
    while(top!=-1){
        printf("%d",stack[top]);
        if(top>0) printf(" ");
        top--;
    }
    return 0;
}