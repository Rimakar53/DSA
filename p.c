// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int push(char stack[],int n,int top,int x){
   
    if(top==n-1)
        printf("overflow\n");
    else
    {   
        stack[++top]=x;
        return top;
    }
}

void display(int stack[],int top){
    for(int i=top;i>=0;i--){
        printf("%d",stack[i]);
        printf(" ");
    }
}

int pop(char stack[],int top){
    if(top==-1){
        printf("underflow");
    }
    else{
        top--;
        return top;
    }
}
int main(){
    char stack[10];
    int top = -1;
    char post[20];
    int n1,n2,res=0,i=0,t;
    printf("enter the string:");
    scanf("%s",post);
    while(post[i]!='\0'){
        t=post[i];
        if(isdigit(t))
           top= push(stack,10,top,t-'0');
        else
        { n2=pop(stack,top);
            n1=pop(stack,top);
            switch(t){
                case '+': res =n1+n2;
                           break;
                 case '-': res =n1-n2;
                           break;
                 case '*': res =n1*n2;
                           break;
                 case '/': res =n1/n2;
                           break;
                default: printf("invalid\n");
            }
               top= push(stack,10,top,res);
            }
            i++;
    }
    printf("the value is %d",stack[top]);
    return 0;
            
    }