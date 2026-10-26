#include <stdio.h>

int main()
{
    int nostate, notrans;
    int trans[30][3], eclos[10][20];
    int visited[10], queue[100];
    int i, j, d, state;
    int front, rear, count;
    char c;

    printf("Enter the number of states:\n");
    scanf("%d", &nostate);

    printf("Enter the number of transitions:\n");
    scanf("%d", &notrans);

    printf("Enter transitions (source symbol destination):\n");

    for (i = 0; i < notrans; i++)
    {
        scanf("%d %c %d",
              &trans[i][0], &c, &trans[i][2]);
        trans[i][1] = c;
    }

    printf("\nEpsilon closure of states:\n");

    for (i = 1; i <= nostate; i++)
    {
        for (j = 0; j < 10; j++)
            visited[j] = 0;

        front = 0;
        rear = 0;
        count = 0;

        queue[rear++] = i;
        visited[i] = 1;

        while (front < rear)
        {
            state = queue[front++];

            eclos[i][count++] = state;

            for (j = 0; j < notrans; j++)
            {
                if (trans[j][0] == state &&
                    trans[j][1] == 'e')
                {
                    d = trans[j][2];

                    if (visited[d] == 0)
                    {
                        visited[d] = 1;
                        queue[rear++] = d;
                    }
                }
            }
        }

        eclos[i][count] = 0;
    }

    for (i = 1; i <= nostate; i++)
    {
        printf("E-closure(q%d) = {", i);

        for (j = 0; eclos[i][j] != 0; j++)
        {
            printf("q%d", eclos[i][j]);

            if (eclos[i][j + 1] != 0)
                printf(", ");
        }

        printf("}\n");
    }

    return 0;
}
