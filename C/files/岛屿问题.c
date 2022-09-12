#include <stdio.h>
void dfs(char **grid, int m, int n, int row, int column)
{
    if (grid[row][column] == '1') //如果是岛屿，先变成0
    {
        grid[row][column] = '0';
    }
    else //不是岛屿，返回
    {
        return;
    }

    if (row)
    {
        dfs(grid, m, n, row - 1, column);
    }
    if ((row + 1) != m)
    {
        dfs(grid, m, n, row + 1, column);
    }
    if (column)
    {
        dfs(grid, m, n, row, column - 1);
    }
    if ((column + 1) != n)
    {
        dfs(grid, m, n, row, column + 1);
    }
}

int solve(char **grid, int m, int n)
{
    int row, column;
    int totalLand = 0;
    for (row = 0; row < m; row++)
    {
        for (column = 0; column < n; column++)
        {
            if (grid[row][column] == '1')
            {
                dfs(grid, m, n, row, column);
                totalLand++;
            }
        }
    }
    return totalLand;
}

int main()
{
    char *grid[4] = {"11110", "11010", "11000", "00000"};
    int m = 4;
    int n = 5;
    int result = solve(grid, m, n);
    printf("%d", result);
}