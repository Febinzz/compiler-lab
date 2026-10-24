
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct expr {
    char op1[20], op[2], op2[20], res[20];
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
    char line[100], value[20];
    char *eq, *p;

    printf("Enter number of expressions: ");
    scanf("%d", &n);

    getchar();

    for (i = 0; i < n; i++) {
        printf("Enter expression: ");
        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = '\0';

        eq = strchr(line, '=');
        *eq = '\0';

        strcpy(e[i].res, line);
        strcpy(e[i].op1, eq + 1);

        p = strpbrk(e[i].op1, "+-*/");

        if (p != NULL) {
            e[i].op[0] = *p;
            e[i].op[1] = '\0';
            *p = '\0';
            strcpy(e[i].op2, p + 1);
        } else {
            strcpy(e[i].op, "=");
            strcpy(e[i].op2, "-");
        }
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
            default: continue;
        }

        sprintf(value, "%d", result);

        strcpy(e[i].op1, value);
        strcpy(e[i].op, "=");
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
