// Online C compiler to run C program online
#include <stdio.h>
#include<string.h>


int main() {
    char str[10];
  gets(str);
  int i=0;
  int stack[30];
  int top=-1;
  while(str[i]!='\0'){
      if(str[i]==ALPHABET)
            stack[++top]=str[i];
        else{
            if(str[i]=='-'){
                stack[top-1]=stack[top-1]-stack[top];
                top--;
            }
            if(str[i]=='*')
            {    stack[top-1]=stack[top-1]*stack[top];
                 top--;
            }
            if(str[i]=='+')
            {    stack[top-1]=stack[top-1]+stack[top];
                 top--;
            }
            if(str[i]=='/')
            {    stack[top-1]=stack[top-1]/stack[top];
                 top--;
            }
            if(str[i]=='%')
            {    stack[top-1]=stack[top-1]%stack[top];
                 top--;
            }
            
        }
        i++;
  }
  printf("%d",stack[top]);
  

    return 0;
}