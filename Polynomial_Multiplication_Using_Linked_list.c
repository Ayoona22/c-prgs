#include<stdio.h>
#include<stdlib.h>
struct node{
    int c,e;
    struct node*link;
};
struct node*phead,*qhead,*rhead;
void multiply(){
    struct node*p=phead,*q=qhead;
    struct node*r=rhead;
    while(p!=NULL){
        q=qhead;
        while(q!=NULL){
            struct node*new=(struct node*)malloc(sizeof(struct node));
            new->c=p->c*q->c;
            new->e=p->e+q->e;
            new->link=NULL;
            if(rhead==NULL){
                rhead=r=new;
            }else{
                r->link=new;
                r=new;
            }q=q->link;
        }p=p->link;
    }p=rhead;
    struct node*prev;
    while(p!=NULL){
        prev=p,r=prev->link;
        while(r!=NULL){
            if(r->e==p->e){
                p->c=p->c+r->c;
                prev->link=r->link;
                free(r);
                r=prev->link;
            }else{
                prev=r;
                r=r->link;
            }
        }p=p->link;
    }printf("\npolynomial R : ");
    r=rhead;
    while(r!=NULL){
        printf("%dx^%d",r->c,r->e);
        r=r->link;
        if(r!=NULL&&r->c>=0){
            printf("+");
        }
    }
}
void main(){
    int d1,d2;
    printf("Enter the degree of polynomial 1 : ");
    scanf("%d",&d1);
    printf("Enter polynomial 1\n");
    for(int i=0;i<=d1;i++){
        struct node*new=(struct node*)malloc(sizeof(struct node));
        int coe;
        printf("Enter the coefficient of %d : ",i);
        scanf("%d",&coe);
        new->c=coe;
        new->e=i;
        new->link=phead;
        phead=new;
    }printf("Enter the degree of polynomial 2 : ");
    scanf("%d",&d2);
    printf("Enter polynomial 2\n");
    for(int i=0;i<=d2;i++){
        int coe;
        struct node*new=(struct node*)malloc(sizeof(struct node));
        printf("Enter the coefficient of %d : ",i);
        scanf("%d",&coe);
        new->c=coe;
        new->e=i;
        new->link=qhead;
        qhead=new;
    }printf("polynomial P : ");
    struct node*p=phead;
    while(p!=NULL){
        printf("%dx^%d",p->c,p->e);
        p=p->link;
        if(p!=NULL&&p->c>=0){
            printf("+");
        }
    }printf("\npolynomial Q : ");
    struct node*q=qhead;
    while(q!=NULL){
        printf("%dx^%d",q->c,q->e);
        q=q->link;
        if(q!=NULL&&q->c>=0){
            printf("+");
        }
    }multiply(d1,d2);
}
