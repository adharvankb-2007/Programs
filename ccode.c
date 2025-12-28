// Online C compiler to run C program online
#include <stdio.h>

int main(void) {
    int n=0;
    scanf("%d",&n);
    int a[n]={0};
    for(int i=0;i<n;i++){
        scanf("%d ",&a[i]);
        
    }
    int total=0;
    for(int j=0;j<n;j++){
        if(j>0){
            total=total+a[j];
            a[j]=total;
        }else{
            total=a[j];
        }
        
    }
    for(int i=0;i<n;i++){
    printf("%d\t",a[i]);
    }
    return 0;
}