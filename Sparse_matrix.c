#include<stdio.h>
void add(int s1[100][100],int s2[100][100]){
    if(s1[0][0]==s2[0][0]&&s1[0][1]==s2[0][1]){
        int m=1,n=1,f=1,r[100][100],count=0;
        r[0][0]=s1[0][0],r[0][1]=s1[0][1];
        for(int i=0;i<s1[0][0];i++){
            for(int j=0;j<s1[0][1];j++){
                if(s1[m][0]==i&&s1[m][1]==j&&s2[n][0]==i&&s2[n][1]==j){
                    r[f][2]=s1[m][2]+s2[n][2];
                    r[f][1]=j;
                    r[f][0]=i;
                    m++;
                    n++;
                    f++;
                    count++;
                }else if(s1[m][0]==i&&s1[m][1]==j){
                    r[f][2]=s1[m][2];
                    r[f][1]=j;
                    r[f][0]=i;
                    m++;
                    f++;
                    count++;
                }else if(s2[n][0]==i&&s2[n][1]==j){
                    r[f][2]=s2[n][2];
                    r[f][1]=j;
                    r[f][0]=i;
                    n++;
                    f++;
                    count++;
                }
            }
        }r[0][2]=count;
        printf("\nResultant Matrix\n");
        for(int i=0;i<=r[0][2];i++){
            for(int j=0;j<3;j++){
                printf("%d ",r[i][j]);
            }printf("\n");
        }
    }else{
        printf("\nCannot multiply");
    }
}
void transpose(int s1[100][100],int s2[100][100]){
    int t1[100][100],t2[100][100];
    t1[0][0]=s1[0][1],t1[0][1]=s1[0][0],t1[0][2]=s1[0][2];
    int k=1,h=0;
    while(h<s1[0][1]){
        for(int i=1;i<=t1[0][2];i++){
            if(s1[i][1]==h){
                t1[k][0]=s1[i][1];
                t1[k][1]=s1[i][0];
                t1[k][2]=s1[i][2];
                k++;
            }
        }h++;
    }printf("\nTranspose of Matrix 1\n");
    for(int i=0;i<=t1[0][2];i++){
        for(int j=0;j<3;j++){
            printf("%d ",t1[i][j]);
        }printf("\n");
    }t2[0][0]=s2[0][1],t2[0][1]=s2[0][0],t2[0][2]=s2[0][2];
    k=1,h=0;
    while(h<s2[0][1]){
        for(int i=1;i<=t2[0][2];i++){
            if(s2[i][1]==h){
                t2[k][0]=s2[i][1];
                t2[k][1]=s2[i][0];
                t2[k][2]=s2[i][2];
                k++;
            }
        }h++;
    }printf("\nTranspose of Matrix 2\n");
    for(int i=0;i<=t2[0][2];i++){
        for(int j=0;j<3;j++){
            printf("%d ",t2[i][j]);
        }printf("\n");
    }
}
void sparse(int m1[100][100],int m2[100][100],int r1,int r2,int c1,int c2){
    int s1[100][100],s2[100][100];
    s1[0][0]=r1,s1[0][1]=c1;
    int count=0,k=1;
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            if(m1[i][j]!=0){
                s1[k][0]=i;
                s1[k][1]=j;
                s1[k][2]=m1[i][j];
                count++;
                k++;
            }
        }
    }s1[0][2]=count;
    printf("Tuple form of Matrix 1\n");
    for(int i=0;i<k;i++){
        for(int j=0;j<3;j++){
            printf("%d ",s1[i][j]);
        }printf("\n");
    }
    s2[0][0]=r2,s2[0][1]=c2;
    count=0,k=1;
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            if(m2[i][j]!=0){
                s2[k][0]=i;
                s2[k][1]=j;
                s2[k][2]=m2[i][j];
                count++;
                k++;
            }
        }
    }s2[0][2]=count;
    printf("Tuple form of Matrix 2\n");
    for(int i=0;i<k;i++){
        for(int j=0;j<3;j++){
            printf("%d ",s2[i][j]);
        }printf("\n");
    }transpose(s1,s2);
    add(s1,s2);
}
void main(){
    int r1,c1;
    printf("No.of rows of matrix 1: ");
    scanf("%d",&r1);
    printf("No.of columns matrix 1: ");
    scanf("%d",&c1);
    printf("Enter the sparse matrix elements\n");
    int m1[100][100];
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            scanf("%d",&m1[i][j]);
        }
    }int r2,c2;
    printf("No.of rows of matrix 2: ");
    scanf("%d",&r2);
    printf("No.of columns matrix 2: ");
    scanf("%d",&c2);
    printf("Enter the sparse matrix elements\n");
    int m2[100][100];
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            scanf("%d",&m2[i][j]);
        }
    }sparse(m1,m2,r1,r2,c1,c2);
}
