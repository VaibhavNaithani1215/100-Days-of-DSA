#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n;
    scanf("%d",&n);
    int *pq=malloc(n*sizeof(int));
    int size=0;
    char op[10];
    for(int i=0;i<n;i++){
        scanf("%s",op);
        if(strcmp(op,"insert")==0){
            int x;
            scanf("%d",&x);
            pq[size++]=x;
        }else if(strcmp(op,"delete")==0){
            if(size==0){
                printf("-1\n");
            }else{
                int minIdx=0;
                for(int j=1;j<size;j++){
                    if(pq[j]<pq[minIdx]) minIdx=j;
                }
                printf("%d\n",pq[minIdx]);
                for(int j=minIdx;j<size-1;j++){
                    pq[j]=pq[j+1];
                }
                size--;
            }
        }else if(strcmp(op,"peek")==0){
            if(size==0){
                printf("-1\n");
            }else{
                int minIdx=0;
                for(int j=1;j<size;j++){
                    if(pq[j]<pq[minIdx]) minIdx=j;
                }
                printf("%d\n",pq[minIdx]);
            }
        }
    }
    return 0;
}