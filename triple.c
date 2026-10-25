#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char exxp[20];
int count=0;
int val=65;
int i,j;
void main()
{
    printf("enter the expression\n");
    scanf("%s",exxp);
            printf("index OP ARG1 ARG2 \n");
    for(int i=0;i<strlen(exxp);i++){
        if (exxp[i]=='/')
            {
             printf("(%d) %c %c %c \n",count,exxp[i],exxp[i-1],exxp[i+1],val);
                exxp[i-1]=count + '0';
             for( j=i;exxp[j+2]!='\0';j++)
                 {
                 exxp[j]=exxp[j+2];
                 }
            exxp[j]='\0';
                count=count+1;
            }
    }
        for(int i=0;i<strlen(exxp);i++){
        if (exxp[i]=='*')
            {
              printf("(%d) %c %c %c \n",count,exxp[i],exxp[i-1],exxp[i+1],val);
                exxp[i-1]=count + '0';
             for( j=i;exxp[j+2]!='\0';j++)
                 {
                 exxp[j]=exxp[j+2];
                 }
            exxp[j]='\0';
                count=count+1;
        val=val+1;
            }
  
    }
        for(int i=0;i<strlen(exxp);i++){
        if (exxp[i]=='+')
            {
             printf("(%d) %c %c %c \n",count,exxp[i],exxp[i-1],exxp[i+1],val);
                exxp[i-1]=count + '0';
             for( j=i;exxp[j+2]!='\0';j++)
                 {
                 exxp[j]=exxp[j+2];
                 }
            exxp[j]='\0';
                count=count+1;
        val=val+1;
            }
        }
        for(int i=0;i<strlen(exxp);i++){
        if (exxp[i]=='-')
            {
              printf("(%d) %c %c %c \n",count,exxp[i],exxp[i-1],exxp[i+1],val);
                exxp[i-1]=count + '0';
             for( j=i;exxp[j+2]!='\0';j++)
                 {
                 exxp[j]=exxp[j+2];
                 }
            exxp[j]='\0';
                count=count+1;
        val=val+1;
            }
    }
  printf("(%d) = %c  %c \n",count,exxp[0],exxp[2]);  
}
