#include<stdio.h>
void insertionsort(int a[100],int n){
    for(int i=1;i<n;i++){
        int temp=a[i];
        int j=i-1;
        while(j>=0&&a[j]>temp){
            a[j+1]=a[j];
            j--;
        }a[j+1]=temp;
    }for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
void main(){
    int n;
    printf("Enter the size : ");
    int a[100];
    scanf("%d",&n);
    printf("Enter the elements :");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }printf("After Sorting : ");
    insertionsort(a,n);
}
