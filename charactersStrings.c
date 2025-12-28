#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void){
        char s1[50];
        scanf("%c",&s1[0]);
        for(int i=1;s1[i-1] != '?';i++){
                scanf("%c",&s1[i]);
                if(s1[i] == '?'){
                        s1[i+1]='\0';
                }
        }
        char * leng[]={"inches","centimetres","feet"};
        char s2[]="1234567890";
        char *sPtr = strpbrk(s1,s2);
        double n = strtod(sPtr,NULL);
        for(int i=0;i<3;i++){
             if(strstr(s1,leng[i]) != NULL){
                if(i==0){
                        
                     double k=1;
                     k=(double)n * (double)(0.0254);
                     printf("it is %lf metres sir/madam.\n",k);
                }
                if(i==1){
                double k=0;
                k=(double)n * (double)(0.01);
                printf("it is %lf metres sir/madam.\n",k);
                }
                if(i==2){
                      double k=0;
                k=(double)n * (double)(0.3048);
                printf("it is %lf metres sir/madam.\n",k);  
                }
        }
        }
        return 0;        
}