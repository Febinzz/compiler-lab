#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
    FILE *input;
    int l=1;
    int t=0;
    int j=0;
    int i,flag,k;
    char ch,ch1,str[20],dig[20];

    input = fopen("input.c","r");

    if(input == NULL)
    {
        printf("File not found\n");
        return 1;
    }

    char keyword[30][30] = {"int","void","if","else","do","while"};

    printf("Line no. \t Token no.\t\t Token \t\t Lexeme\n");

    while((ch=fgetc(input))!=EOF)
    {
        i=0,k=0;
        flag=0;

        if(ch=='/')
        {
            ch=fgetc(input);

            if(ch=='/')
            {
                while((ch=fgetc(input))!=EOF && ch!='\n');

                if(ch=='\n')
                    l++;

                continue;
            }
            else if(ch=='*')
            {
                ch=fgetc(input);
                ch1=fgetc(input);

                while(ch!=EOF && ch1!=EOF && !(ch=='*' && ch1=='/'))
                {
                    if(ch=='\n')
                        l++;

                    ch=ch1;
                    ch1=fgetc(input);
                }

                continue;
            }
            else
            {
                ungetc(ch,input);
                ch='/';
            }
        }

        if(ch=='+' || ch=='-' || ch=='*' || ch=='/' ||
           ch=='>' || ch=='<' || ch=='=' || ch=='%' ||
           ch=='&' || ch=='|')
        {
            printf("%7d\t\t %7d\t\t Operator\t %7c\n",l,t,ch);
            t++;
        }
        else if(ch==';' || ch=='{' || ch=='}' || ch=='(' ||
                ch==')' || ch=='?' || ch=='@' || ch=='!' ||
                ch=='#' || ch==',' || ch=='.' || ch=='"')
        {
            printf("%7d\t\t %7d\t\t Special symbol\t %7c\n",l,t,ch);
            t++;
        }
        else if(isdigit(ch))
        {
            dig[k]=ch;
            k++;

            ch=fgetc(input);

            while(ch!=EOF && isdigit(ch))
            {
                dig[k]=ch;
                k++;
                ch=fgetc(input);
            }

            if(ch!=EOF)
                ungetc(ch,input);

            dig[k]='\0';

            printf("%7d\t\t %7d\t\t Number\t\t %7s\n",l,t,dig);
            t++;
        }
        else if(isalpha(ch))
        {
            str[i]=ch;
            i++;

            ch=fgetc(input);

            while(ch!=EOF && isalnum(ch) && ch!=' ')
            {
                str[i]=ch;
                i++;
                ch=fgetc(input);
            }

            if(ch!=EOF)
                ungetc(ch,input);

            str[i]='\0';

            for(j=0;j<6;j++)
            {
                if(strcmp(str,keyword[j])==0)
                {
                    flag=1;
                    break;
                }
            }

            if(flag==1)
            {
                printf("%7d\t\t %7d\t\t Keyword\t %7s\n",l,t,str);
                t++;
            }
            else
            {
                printf("%7d\t\t %7d\t\t Identifier\t %7s\n",l,t,str);
                t++;
            }
        }
        else if(ch=='\n')
        {
            l++;
        }
    }

    fclose(input);
    return 0;
}
