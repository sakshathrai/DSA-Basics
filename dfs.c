#include <stdio.h>
#include <stdlib.h>
int i, j, source, a[5][5], visited[5], n;

void dfs(int j)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[j][i] & !visited[i])
        {
            visited[i] = 1;
            dfs(i);
        }
    }
}

int main()
{
    printf("Enter the number of vertices\n");
    scanf("%d", &n);
    printf("Enter the Adjecent Matrix\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }
    printf("Enter the Source\n");
    scanf("%d", &source);
    visited[source] = 1;
    dfs(source);
    printf("Nodes reachable from %d are\n", source);
    for (i = 0; i < n; i++)
    {
        if (visited[i])
            printf("%d\t", i);
    }
    return 0;
}