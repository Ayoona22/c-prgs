#include<stdio.h>
void dfs(int a[100][100],int n,int visited[100],int start){
    int stack[100],top=-1;
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    top++;
    stack[top]=start;
    visited[start]=1;
    while(top!=-1){
        start=stack[top--];
        printf("%c ",start+65);
        for(int i=0;i<n;i++){
            if(a[start][i]&&visited[i]==0){
                stack[++top]=i;
                visited[i]=1;
                break;
            }
        }
    }
}
void main(){
    printf("Enter the no.of nodes : ");
    int n;
    scanf("%d",&n);
    printf("Enter the Adjacency matrix\nEnter 1 if the nodes are connencted otherwise zero\n ");
    int a[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%c to %c : ",i+65,j+65);
            scanf("%d",&a[i][j]);
        }
    }int visited[100];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }dfs(a,n,visited,0);
}
