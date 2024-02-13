#include<stdio.h>
void binarysearch(int a[100],int n,int e){
    int low=0,high=n-1,f=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(e>a[mid]){
            low=mid+1;
        }else if(e<a[mid]){
            high=mid-1;
        }else if(e==a[mid]){
            f=1;
            printf("%d found on %d\n",e,mid);
            break;
        }
    }if(f==0){
        printf("Not Found");
    }
}
void main(){
    int n;
    printf("Enter the size : ");
    int a[100];
    scanf("%d",&n);
    printf("Enter the elements in a sorted order :");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }int e;
    printf("Enter the element to searched : ");
    scanf("%d",&e);
    binarysearch(a,n,e);
}
