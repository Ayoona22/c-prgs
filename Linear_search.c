#include<stdio.h>
void linear_search(int a[100],int n,int e){
    int f=0;
    for(int i=0;i<n;i++){
        if(a[i]==e){
            f=1;
            printf("%d found on %d\n",e,i);
        }
    }if(f==0){
        printf("Not found");
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
    }printf("Enter the element to be searched : ");
    int e;
    scanf("%d",&e);
    linear_search(a,n,e);
}
