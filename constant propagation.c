
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100
#define SIZE 32

struct expr {
    char op[2];
    char op1[SIZE];
    char op2[SIZE];
    char res[SIZE];
};

struct expr arr[MAX];
int n;

void input(void);
void constant(void);
void change(int p, const char *value);
void output(void);

int main(void)
{
    input();
    constant();
    output();
    return 0;
}

void input(void)
{
    int i;
    char line[200];
    char *eq, *rhs, *p, *oper;

    printf("Enter the number of expressions: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid number of expressions.\n");
        exit(1);
    }

    getchar();
    printf("Enter expressions (example: a=b+c):\n");

    for (i = 0; i < n; i++) {
        if (fgets(line, sizeof(line), stdin) == NULL) {
            printf("Input ended unexpectedly.\n");
            exit(1);
        }

        line[strcspn(line, "\r\n")] = '\0';

        p = line;
        oper = line;
        while (*p) {
            if (!isspace((unsigned char)*p))
                *oper++ = *p;
            p++;
        }
        *oper = '\0';

        eq = strchr(line, '=');
        if (eq == NULL || eq == line || eq[1] == '\0') {
            printf("Invalid expression: %s\n", line);
            exit(1);
        }

        *eq = '\0';

        if (strlen(line) >= SIZE || strlen(eq + 1) >= SIZE) {
            printf("Variable or expression too long.\n");
            exit(1);
        }

        strcpy(arr[i].res, line);
        rhs = eq + 1;
        oper = NULL;

        for (p = rhs + 1; *p; p++) {
            if (*p == '+' || *p == '-' ||
                *p == '*' || *p == '/') {
                oper = p;
                break;
            }
        }

        if (oper != NULL) {
            char operator_char = *oper;
            *oper = '\0';

            strcpy(arr[i].op1, rhs);
            arr[i].op[0] = operator_char;
            arr[i].op[1] = '\0';
            strcpy(arr[i].op2, oper + 1);

            if (arr[i].op1[0] == '\0' ||
                arr[i].op2[0] == '\0') {
                printf("Invalid expression.\n");
                exit(1);
            }
        } else {
            strcpy(arr[i].op1, rhs);
            strcpy(arr[i].op, "=");
            strcpy(arr[i].op2, "-");
        }
    }
}

void change(int p, const char *value)
{
    int i;
    char *oldname = arr[p].res;

    for (i = p + 1; i < n; i++) {
        if (strcmp(arr[i].op1, oldname) == 0)
            strcpy(arr[i].op1, value);

        if (strcmp(arr[i].op2, oldname) == 0)
            strcpy(arr[i].op2, value);

        if (strcmp(arr[i].res, oldname) == 0)
            break;
    }
}

void constant(void)
{
    int i, a, b, result;
    char *end1, *end2;
    char value[SIZE];

    for (i = 0; i < n; i++) {
        a = (int)strtol(arr[i].op1, &end1, 10);

        if (arr[i].op1[0] == '\0' || *end1 != '\0')
            continue;

        if (strcmp(arr[i].op, "=") == 0) {
            change(i, arr[i].op1);
            continue;
        }

        b = (int)strtol(arr[i].op2, &end2, 10);

        if (arr[i].op2[0] == '\0' || *end2 != '\0')
            continue;

        switch (arr[i].op[0]) {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                if (b == 0) {
                    printf("Error: division by zero in expression %s.\n",
                           arr[i].res);
                    continue;
                }
                result = a / b;
                break;
            default:
                continue;
        }

        snprintf(value, sizeof(value), "%d", result);

        strcpy(arr[i].op1, value);
        strcpy(arr[i].op, "=");
        strcpy(arr[i].op2, "-");

        change(i, value);
    }
}

void output(void)
{
    int i;

    printf("\nOptimized code is:\n");

    for (i = 0; i < n; i++) {
        if (strcmp(arr[i].op, "=") == 0)
            printf("%s = %s\n", arr[i].res, arr[i].op1);
        else
            printf("%s = %s %s %s\n",
                   arr[i].res, arr[i].op1,
                   arr[i].op, arr[i].op2);
    }
}
