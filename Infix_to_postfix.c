#include<stdio.h>
#include<string.h>
#include<ctype.h>
char stack[100],postfix[100];
int top=-1,len=-1;
int opr(int x,int y,char ch){
    if(ch=='+'){
        return(y+x);
    }else if(ch=='-'){
        return(y-x);
    }else if(ch=='*'){
        return(y*x);
    }else if(ch=='/'){
        return(y/x);
    }else if(ch=='^'){
        int e=1;
        for(int i=1;i<=x;i++){
            e*=y;
        }return e;
    }
}
void evaluate(char exp[100]){
    int l=strlen(exp);
    int q[100],f=-1;
    for(int i=0;i<l;i++){
        if(isalnum(exp[i])){
            printf("%c = ",exp[i]);
            int val;
            scanf("%d",&val);
            f++;
            q[f]=val;
        }else{
            int x,y;
            x=q[f];
            f--;
            y=q[f];
            f--;
            int v=opr(x,y,exp[i]);
            f++;
            q[f]=v;
        }
    }printf("\nSolution = %d",q[f]);
}
int check(char ch){
    if(ch=='('){
        return -1;
    }else if(ch==')'){
        return 0;
    }else if(ch=='+'||ch=='-'){
        return 1;
    }else if(ch=='*'||ch=="/"){
        return 2;
    }else if(ch=='^'){
        return 3;
    }
}
void main(){
    char infix[100];
    printf("Enter the infix expression : ");
    gets(infix);
    int l=strlen(infix);
    infix[l]=')';
    top++;
    stack[top]='(';
    for(int i=0;i<=l;i++){
        if(isalnum(infix[i])){
            len++;
            postfix[len]=infix[i];
        }else{
            int p=check(infix[i]);
            if(p==-1){
                top++;
                stack[top]=infix[i];
            }else if(p==0){
                int p1=check(stack[top]);
                while(p1!=-1){
                    len++;
                    postfix[len]=stack[top];
                    top--;
                    p1=check(stack[top]);
                }top--;
            }else if(p<=check(stack[top])){
                int p1=check(stack[top]);
                while(p1>=p){
                    len++;
                    postfix[len]=stack[top];
                    top--;
                    p1=check(stack[top]);
                }top++;
                stack[top]=infix[i];
            }else{
                top++;
                stack[top]=infix[i];
            }
        }
    }printf("\nPostfix Expression : ");
    puts(postfix);
    evaluate(postfix);
}
