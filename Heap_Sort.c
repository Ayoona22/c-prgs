#include<stdio.h>
int a[100],n;
void Heapify(int m,int i){
    int l=2*i+1;
    int r=2*i+2;
    int largest=i;
    if(l<m&&a[l]>a[largest]){
        largest=l;
    }if(r<m&&a[r]>a[largest]){
        largest=r;
    }if(largest!=i){
        int t=a[i];
        a[i]=a[largest];
        a[largest]=t;
        Heapify(m,largest);
    }
}
void BuildMaxHeap(){
    int m=n;
    for(int i=(n/2)-1;i>=0;i--){
        Heapify(m,i);
    }
}
void HeapSort(){
    BuildMaxHeap();
    for(int i=n-1;i>=0;i--){
        int t=a[0];
        a[0]=a[i];
        a[i]=t;
        Heapify(i,0);
    }
    
}
void main(){
    printf("Enter the size : ");
    scanf("%d",&n);
    printf("Enter the elements : ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }HeapSort();
    printf("After Sorting : ");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
