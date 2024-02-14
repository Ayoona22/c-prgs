#include<stdio.h>
struct queue{
    int e;
    int p;
}pq[5];
int f=-1,r=-1;
void display(){
    if(f==-1&&r==-1){
        printf("EMPTY\n");
    }else{
        printf("ELEMENT\tPRIORITY\n");
        for(int i=f;i<=r;i++){
            printf("%d\t%d\n",pq[i].e,pq[i].p);
        }
    }
}
void enqueue(int pr,int ele,int s){
    if(f==0&&r==s-1){
        printf("QUEUE FULL\n");
    }else if((f==-1)&&(r==-1)){
        f=r=0;
        pq[r].p=pr;
        pq[r].e=ele;
    }else if(r==s-1){
        for(int i=f;i<=r;i++){
            pq[i-1]=pq[i];
        }f--;
        r--;
        int loc,i;
        for(i=r;i>=f;i--){
            if(pq[i].p<=pr){
                break;
            }
        }loc=i+1;
        for(i=r;i>=loc;i--){
            pq[i+1]=pq[i];
        }pq[loc].p=pr;
        pq[loc].e=ele;
        r++;
    }else{
        int loc,i;
        for(i=r;i>=f;i--){
            if(pq[i].p<=pr){
                break;
            }
        }loc=i+1;
        for(i=r;i>=loc;i--){
            pq[i+1]=pq[i];
        }pq[loc].p=pr;
        pq[loc].e=ele;
        r++;
    }display();
}void dequeue(){
    if(r==-1&&f==-1){
        printf("EMPTY\n");
    }else if(r==f){
        printf("%d with priority %d deleted\n",pq[f].e,pq[f].p);
        r==f==-1;
    }else{
        printf("%d with priority %d deleted\n",pq[f].e,pq[f].p);
        f++;
    }display();
}
void main(){
    int c;
    while(1){
        printf("\n1 : ENQUEUE\n2 : DEQUEUE\n3 : DISPLAY\n4 : EXIT\n");
        printf("Enter the choice : ");
        scanf("%d",&c);
        if(c==1){
            printf("Enter the priority : ");
            int pr;
            scanf("%d",&pr);
            int ele;
            printf("Enter the element : ");
            scanf("%d",&ele);
            enqueue(pr,ele,5);
        }else if(c==2){
            dequeue();
        }else if(c==3){
            display();
        }else if(c==4){
            printf("EXITING\n");
            break;
        }else{
            printf("Enter the correct choice\n");
        }
    }
}
