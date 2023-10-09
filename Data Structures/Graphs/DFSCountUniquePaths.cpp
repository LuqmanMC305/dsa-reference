#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int r, int c)
{
   int rowSize = grid.size();
   int colSize = grid[0].size();

   if(r < 0 || c < 0 || r >= rowSize || c >= colSize || grid[r][c] == 1 || visited[r][c] == 1)
   {
     return 0;
   }

   if(r == rowSize - 1 && c == colSize -1)
   {
     return 1;
   }

   visited[r][c] = 1;

   int count = 0;

   count += dfs(grid, visited, r + 1, c);
   count += dfs(grid, visited, r - 1, c);
   count += dfs(grid, visited, r, c + 1);
   count += dfs(grid, visited, r, c - 1);

   visited[r][c] = 0;

   return count;
}

int main()
{
    vector<vector<int>> grid = 
    {
        {0,0,0,0},
        {1,1,0,0},
        {0,0,0,1},
        {0,1,0,0}
    };

    int rowSize = grid.size();
    int colSize = grid[0].size();

    vector<vector<int>> visited(rowSize, vector<int>(colSize, 0));
    int r = 0, c = 0;

   

    cout << dfs(grid, visited, r, c);



    return 0;
}
