#include <stdlib.h>

int shortestPathLength(int** graph, int graphSize, int* graphColSize) {

    int finalMask = (1 << graphSize) - 1;

    // queue large enough for all states
    int queue[50000][2];
    int front = 0, rear = 0;

    // visited[node][mask]
    int visited[12][1 << 12] = {0};

    // start BFS from every node
    for (int i = 0; i < graphSize; i++) {
        queue[rear][0] = i;
        queue[rear][1] = 1 << i;
        rear++;

        visited[i][1 << i] = 1;
    }

    int steps = 0;

    while (front < rear) {

        int size = rear - front;

        for (int s = 0; s < size; s++) {

            int node = queue[front][0];
            int mask = queue[front][1];
            front++;

            if (mask == finalMask)
                return steps;

            for (int i = 0; i < graphColSize[node]; i++) {

                int next = graph[node][i];
                int nextMask = mask | (1 << next);

                if (!visited[next][nextMask]) {

                    visited[next][nextMask] = 1;

                    queue[rear][0] = next;
                    queue[rear][1] = nextMask;
                    rear++;
                }
            }
        }

        steps++;
    }

    return -1;
}