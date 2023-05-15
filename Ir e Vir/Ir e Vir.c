#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 2010

char visited[MAXSIZE];
char graph[MAXSIZE][MAXSIZE];

int num_vertices;
void dfs(int);

int main(int argc, char **argv)
{

    int num_edges, u, v, weight, i, j;

    while (scanf("%d %d", &num_vertices, &num_edges), num_edges && num_vertices)
    {

        memset(graph, 0, sizeof(graph));
        for (i = 0; i < num_edges; ++i)
        {

            scanf("%d %d %d", &u, &v, &weight);

            if (weight == 1)
                graph[u][v] = true;
            else
                graph[u][v] = graph[v][u] = true;

        }   

        _Bool flag = false;
        for (i = 1; i <= num_vertices; ++i)
        {
            
            memset(visited, 0, sizeof(visited));
            dfs(i);
            flag = false;
            for (j = 1; j < num_vertices && !flag; ++j)
                if (!visited[j])
                    flag = true;

            if (flag)
                break;

        }

        printf("%d\n", flag ? 0 : 1);

    }

    return 0;

}

void dfs(int vertex)
{

    int i;
    visited[vertex] = true;

    for (i = 1; i <= num_vertices; ++i)
        if (graph[vertex][i])
            if (!visited[i])
                dfs(i);

}
