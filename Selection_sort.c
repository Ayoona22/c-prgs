#include<stdio.h>
void selectionsort(int a[100],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                int t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }for(int i=0;i<n;i++){
        printf("%d",a[i]);
    }
}
void main(){
    int n;
    printf("Enter the size : ");
    scanf("%d",&n);
    printf("Enter the elements : ");
    int a[100];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }printf("After sorting : ");
    selectionsort(a,n);
}
