#include<stdio.h>
int n,a[100],b[100];
void mergesort(int low,int mid,int high){
    int x,y,i=low;
    x=low;
    y=mid+1;
    while(x<=mid&&y<=high){
        if(a[x]>a[y]){
            b[i]=a[y];
            y++;
        }else{
            b[i]=a[x];
            x++;
        }i++;
    }if(x<=mid){
        for(int k=x;k<=mid;k++){
            b[i]=a[k];
            i++;
        }
    }else{
        for(int k=y;k<=high;k++){
            b[i]=a[k];
            i++;
        }
    }for(int j=low;j<=high;j++){
        a[j]=b[j];
    }
}
void merge(int low,int high){
    int mid;
    if(low<high){
    mid=(low+high)/2;
    merge(low,mid);
    merge(mid+1,high);
    mergesort(low,mid,high);}
}
void main(){
    printf("Enter the size : ");
    scanf("%d",&n);
    printf("Enter the elements : ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }printf("Before sorting : ");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }printf("\nAfter sorting : ");
    merge(0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
