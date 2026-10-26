#include <stdio.h>

/* i + * $ */
char table[4][4] = {
    {'=', '>', '>', '>'},
    {'<', '>', '<', '>'},
    {'<', '>', '>', '>'},
    {'<', '<', '<', '='}
};

char op[4] = {'i', '+', '*', '$'};
char stack[50], s[50];
int top = -1, i;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

int findpos(char ch)
{
    int k;

    for (k = 0; k < 4; k++)
    {
        if (ch == op[k])
            return k;
    }

    return k;
}

void displaystack()
{
    int j = 0;

    while (j <= top)
    {
        printf("%c", stack[j]);
        j++;
    }

    printf("\t\t");
}

void displaystring()
{
    int j = i;

    while (s[j] != '\0')
    {
        printf("%c", s[j]);
        j++;
    }

    printf("\t\t");
}

void parse()
{
    char ch, ch1, opr;
    int pos1, pos2;

    printf("Enter the expression (end with $): ");
    scanf("%49s", s);

    push('$');
    i = 0;

    while (1)
    {
        displaystack();
        displaystring();

        if (stack[top] == '$' && s[i] == '$')
        {
            printf("\nValid Expression\n");
            return;
        }

        ch = s[i];

        /* Check for adjacent operators */
        if ((ch == '+' || ch == '-' || ch == '*' || ch == '/') &&
            (s[i+1] == '+' || s[i+1] == '-' ||
             s[i+1] == '*' || s[i+1] == '/'))
        {
            printf("\nInvalid expression\n");
            return;
        }

        pos2 = findpos(ch);
        pos1 = findpos(stack[top]);

        if (pos1 == 4 || pos2 == 4)
        {
            printf("\nInvalid expression\n");
            return;
        }

        opr = table[pos1][pos2];

        if (opr == '<' || opr == '=')
        {
            push(ch);
            i++;
            printf("Shift\n");
        }
        else if (opr == '>')
        {
            ch1 = pop();

            pos2 = findpos(ch1);
            pos1 = findpos(stack[top]);

            while (pos1 != 4 && pos2 != 4 &&
                   table[pos1][pos2] != '<')
            {
                printf("%c ", ch1);

                ch1 = pop();
                pos2 = findpos(ch1);
                pos1 = findpos(stack[top]);
            }

            printf("%c ", ch1);
            printf("Reduce\n");
        }
        else
        {
            printf("\nInvalid expression\n");
            return;
        }
    }
}

int main()
{
    parse();
    return 0;
}
