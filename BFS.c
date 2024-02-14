#include<stdio.h>

void bfs(int a[100][100],int visited[100],int n,int start){
    int q[100],f=-1,r=-1;
    f=r=0;
    q[r]=start;
    while(r>=f){
        start=q[f];
        f++;
        printf("%c ",start+65);
        visited[start]=1;
        for(int i=0;i<n;i++){
            if(a[start][i]==1&&visited[i]==0){
                q[++r]=i;
                visited[i]=1;
            }
        }
    }
}
void main(){
    int n;
    printf("Enter the no.of nodes : ");
    scanf("%d",&n);
    int a[100][100];
    printf("Enter 1 if the nodes are ajdacent otherwise 0\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%c to %c : ",i+65,j+65);
            scanf("%d",&a[i][j]);
        }
    }int visited[100];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }printf("BFS : ");
    bfs(a,visited,n,0);
}
