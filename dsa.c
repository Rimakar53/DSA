#include<stdio.h>
void search(int a[],int n){
 int sum;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                sum=a[i]+a[j]+a[k];
                if(sum==0)
                {
                    printf("%d %d %d",a[i],a[j],a[k]);
                    printf("\n");
                    
                    
                }
                sum=0;
            }
           
        }
       
    }
    
}



int main(){
    int a[6]={-1,0,1,2,-1,-4};
    search(a,6);
    return 0;
}