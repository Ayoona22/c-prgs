#include<stdio.h>
int n,a[100];
int partition(int low,int high){
    int pivot=low,i=low,j=high;
    while(i<j){
        while(a[i]<=a[pivot]){
            i++;
        }while(a[j]>a[pivot]){
            j--;
        }if(i<j){
            int t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }int t=a[j];
    a[j]=a[pivot];
    a[pivot]=t;
    return j;
}
void quick(int low,int high){
    if(low<high){
        int j=partition(low,high);
        quick(low,j-1);
        quick(j+1,high);
    }
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
    quick(0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
