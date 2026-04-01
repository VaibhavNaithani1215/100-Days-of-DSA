#include <stdio.h>

void heapify(int arr[], int n, int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && arr[l]>arr[largest]) largest=l;
    if(r<n && arr[r]>arr[largest]) largest=r;
    if(largest!=i){
        int t=arr[i];
        arr[i]=arr[largest];
        arr[largest]=t;
        heapify(arr,n,largest);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    for(int i=n/2-1;i>=0;i--) heapify(arr,n,i);

    for(int i=n-1;i>0;i--){
        int t=arr[0];
        arr[0]=arr[i];
        arr[i]=t;
        heapify(arr,i,0);
    }

    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
        if(i<n-1) printf(" ");
    }
    return 0;
}


