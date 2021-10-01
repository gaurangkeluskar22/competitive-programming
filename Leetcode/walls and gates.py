'''

Suppose we have one m x n 2D grid, and that is initialized with these three possible values.

-1 for a wall or an obstacle.

0 for a gate.

INF This is infinity means an empty room.

Here 2^31 - 1 = 2147483647 is INF as we may assume that the distance to a gate is less than 2147483647. Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

So, if the input is like

INF	-1	0	INF
INF	INF	INF	-1
INF	-1	INF	-1
0	-1	INF	INF

then the output will be

3	-1	0	1
2	2	1	-1
1	-1	2	-1
0	-1	3	4
'''

import math


def walls_and_gates(matrix):

    for row in range(len(matrix)):
        for col in range(len(matrix[0])):

            if matrix[row][col] == 0:
                dfs(matrix, row, col, 0)

    for row in matrix:
        print(row)


def dfs(matrix, row, col, steps):

    if row >= len(matrix) or row < 0 or col >= len(matrix[0]) or col < 0:
        return

    if matrix[row][col] == -1:
        return

    if steps > 0 and matrix[row][col] == 0:
        return

    if steps > matrix[row][col]:
        return

    matrix[row][col] = steps

    dfs(matrix, row-1, col, steps+1)
    dfs(matrix, row, col+1, steps+1)
    dfs(matrix, row+1, col, steps+1)
    dfs(matrix, row, col-1, steps+1)


matrix = [
    [math.inf, -1, 0, math.inf],
    [math.inf, math.inf, math.inf, -1],
    [math.inf, -1, math.inf, -1],
    [0, -1, math.inf, math.inf]
]

print(walls_and_gates(matrix))
