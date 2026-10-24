#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char in[30];
int k=1;
void main()
{
    printf("enter the expression\n");
    scanf("%s",in);
    printf("%s\n",in);
for(int i=0;in[i]!='\0';i++)
    {
        if (in[i]=='/')
        {
            printf("t%d=%c%c%c\n",k,in[i-1],in[i],in[i+1]);
            in[i-1] = '0' + k;
            for (int j=i;in[j]!='\0';j++)
                {
                    in[j]=in[j+2];
                }
            k=k+1;
        }
    }
for(int i=0;in[i]!='\0';i++)
    {
        if (in[i]=='*')
        {
            printf("t%d=%c%c%c\n",k,in[i-1],in[i],in[i+1]);
            in[i-1] = '0' + k;
            for (int j=i;in[j]!='\0';j++)
                {
                    in[j]=in[j+2];
                }
            k=k+1;
        }
    }
for(int i=0;in[i]!='\0';i++)
    {
        if (in[i]=='+')
        {
            printf("t%d=%c%c%c\n",k,in[i-1],in[i],in[i+1]);
            in[i-1] = '0' + k;
            for (int j=i;in[j]!='\0';j++)
                {
                    in[j]=in[j+2];
                }
            k=k+1;
        }
    }
for(int i=0;in[i]!='\0';i++)
    {
        if (in[i]=='-')
        {
            printf("t%d=%c%c%c\n",k,in[i-1],in[i],in[i+1]);
            in[i-1] = '0' + k;
            for (int j=i;in[j]!='\0';j++)
                {
                    in[j]=in[j+2];
                }
            k=k+1;
        }
    }
printf("%c=t%d",in[0],k-1);
}
