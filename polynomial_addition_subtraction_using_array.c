#include<stdio.h>
void polyopr(int p1[100],int p2[100],int d1,int d2){
    int p3[100],p4[100];
    if(d1>=d2){
        for(int i=0;i<=d2;i++){
            p3[i]=p1[i]+p2[i];
            p4[i]=p2[i]-p1[i];
        }for(int i=d2+1;i<=d1;i++){
            p3[i]=p1[i];
            p4[i]=-p1[i];
        }printf("\nP2 + P1 = ");
        for(int i=d1;i>0;i--){
            printf("%d^%d",p3[i],i);
            if(p3[i-1]>=0){
                printf("+");
            }
        }printf("%d",p3[0]);
        printf("\nP2 - P1 = ");
        for(int i=d1;i>0;i--){
            printf("%d^%d",p4[i],i);
            if(p4[i-1]>=0){
                printf("+");
            }
        }printf("%d",p4[0]);
    }else{
        for(int i=0;i<=d1;i++){
            p3[i]=p1[i]+p2[i];
            p4[i]=p2[i]-p1[i];
        }for(int i=d1+1;i<=d2;i++){
            p3[i]=p2[i];
            p4[i]=p2[i];
        }printf("\nP2 + P1 = ");
        for(int i=d2;i>0;i--){
            printf("%d^%d",p3[i],i);
            if(p3[i-1]>=0){
                printf("+");
            }
        }printf("%d",p3[0]);
        printf("\nP2 - P1 = ");
        for(int i=d2;i>0;i--){
            printf("%d^%d",p4[i],i);
            if(p4[i-1]>=0){
                printf("+");
            }
        }printf("%d",p4[0]);
    }
}
void main(){
    int d1,d2;
    printf("Degree of polynomial 1 : ");
    scanf("%d",&d1);
    printf("Degree of polynomial 2 : ");
    scanf("%d",&d2);
    printf("Enter coefficients of polynomial 1 \n");
    int p1[100],p2[100];
    for(int i=0;i<=d1;i++){
        printf("Coefficient of %d : ",i);
        scanf("%d",&p1[i]);
    }printf("Enter coefficients of polynomial 2 \n");
    for(int i=0;i<=d2;i++){
        printf("Coefficient of %d : ",i);
        scanf("%d",&p2[i]);
    }printf("Polynomial 1 : ");
    for(int i=d1;i>0;i--){
        printf("%d^%d+",p1[i],i);
    }printf("%d",p1[0]);
    printf("\nPolynomial 2 : ");
    for(int i=d2;i>0;i--){
        printf("%d^%d+",p2[i],i);
    }printf("%d",p2[0]);
    polyopr(p1,p2,d1,d2);
}
