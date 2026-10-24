
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct expr {
    char res[20], op1[20], op[2], op2[20];
};

struct expr e[20];
int n;

void change(int p, char value[])
{
    int i;

    for (i = p + 1; i < n; i++) {
        if (strcmp(e[i].op1, e[p].res) == 0)
            strcpy(e[i].op1, value);

        if (strcmp(e[i].op2, e[p].res) == 0)
            strcpy(e[i].op2, value);

        if (strcmp(e[i].res, e[p].res) == 0)
            break;
    }
}

int main()
{
    int i, a, b, result;
    char value[20];

    printf("Enter number of expressions: ");
    scanf("%d", &n);

    printf("Enter each expression as: result operand1 operator operand2\n");
    printf("For assignment, enter: result = value\n");

    for (i = 0; i < n; i++) {
        scanf("%s %s %s %s",
              e[i].res, e[i].op, e[i].op1, e[i].op2);
    }

    for (i = 0; i < n; i++) {
        if (strcmp(e[i].op, "=") == 0) {
            change(i, e[i].op1);
            continue;
        }

        if (sscanf(e[i].op1, "%d", &a) != 1 ||
            sscanf(e[i].op2, "%d", &b) != 1)
            continue;

        switch (e[i].op[0]) {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;

            case '/':
                if (b == 0) {
                    printf("Division by zero!\n");
                    continue;
                }
                result = a / b;
                break;

            default:
                continue;
        }

        sprintf(value, "%d", result);

        strcpy(e[i].op, "=");
        strcpy(e[i].op1, value);
        strcpy(e[i].op2, "-");

        change(i, value);
    }

    printf("\nOptimized code:\n");

    for (i = 0; i < n; i++) {
        if (strcmp(e[i].op, "=") == 0)
            printf("%s = %s\n", e[i].res, e[i].op1);
        else
            printf("%s = %s %s %s\n",
                   e[i].res, e[i].op1,
                   e[i].op, e[i].op2);
    }

    return 0;
}
