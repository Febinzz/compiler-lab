
#include <stdio.h>
#include <string.h>

#define MAX 100

char prod[MAX][MAX];
char first[26][MAX], follow[26][MAX];
char nt[26];
int n, count = 0;

int isNT(char c)
{
    return c >= 'A' && c <= 'Z';
}

int add(char set[], char c)
{
    if (strchr(set, c))
        return 0;

    int len = strlen(set);
    set[len] = c;
    set[len + 1] = '\0';
    return 1;
}

int main()
{
    int i, j, k, changed;
    char lhs, x;

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (use # for epsilon):\n");

    for (i = 0; i < n; i++) {
        scanf("%99s", prod[i]);

        lhs = prod[i][0];

        if (!strchr(nt, lhs))
            nt[count++] = lhs;
    }

    /* Calculate FIRST sets */
    do {
        changed = 0;

        for (i = 0; i < n; i++) {
            lhs = prod[i][0];
            int nullable = 1;

            for (j = 2; prod[i][j] != '\0'; j++) {
                x = prod[i][j];

                if (x == '#') {
                    changed |= add(first[lhs - 'A'], '#');
                    nullable = 0;
                    break;
                }

                if (!isNT(x)) {
                    changed |= add(first[lhs - 'A'], x);
                    nullable = 0;
                    break;
                }

                for (k = 0; first[x - 'A'][k]; k++) {
                    if (first[x - 'A'][k] != '#')
                        changed |= add(first[lhs - 'A'],
                                       first[x - 'A'][k]);
                }

                if (!strchr(first[x - 'A'], '#')) {
                    nullable = 0;
                    break;
                }
            }

            if (nullable)
                changed |= add(first[lhs - 'A'], '#');
        }
    } while (changed);

    /* Start symbol */
    add(follow[prod[0][0] - 'A'], '$');

    /* Calculate FOLLOW sets */
    do {
        changed = 0;

        for (i = 0; i < n; i++) {
            lhs = prod[i][0];

            for (j = 2; prod[i][j] != '\0'; j++) {
                x = prod[i][j];

                if (!isNT(x))
                    continue;

                int nullable = 1;

                for (k = j + 1; prod[i][k] != '\0'; k++) {
                    char y = prod[i][k];

                    if (!isNT(y)) {
                        changed |= add(follow[x - 'A'], y);
                        nullable = 0;
                        break;
                    }

                    int t;
                    for (t = 0; first[y - 'A'][t]; t++) {
                        if (first[y - 'A'][t] != '#')
                            changed |= add(follow[x - 'A'],
                                           first[y - 'A'][t]);
                    }

                    if (!strchr(first[y - 'A'], '#')) {
                        nullable = 0;
                        break;
                    }
                }

                if (nullable) {
                    for (k = 0; follow[lhs - 'A'][k]; k++)
                        changed |= add(follow[x - 'A'],
                                       follow[lhs - 'A'][k]);
                }
            }
        }
    } while (changed);

    printf("\nFIRST sets:\n");
    for (i = 0; i < count; i++) {
        x = nt[i];
        printf("FIRST(%c) = { ", x);

        for (j = 0; first[x - 'A'][j]; j++)
            printf("%c ", first[x - 'A'][j]);

        printf("}\n");
    }

    printf("\nFOLLOW sets:\n");
    for (i = 0; i < count; i++) {
        x = nt[i];
        printf("FOLLOW(%c) = { ", x);

        for (j = 0; follow[x - 'A'][j]; j++)
            printf("%c ", follow[x - 'A'][j]);

        printf("}\n");
    }

    return 0;
}
