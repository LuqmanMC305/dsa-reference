//Shortest path from top left to bottom right
#include <iostream>
#include <queue>
#include <vector>

const int NUM_DIRECTIONS = 4;
const int ROW_COL = 2;

using namespace std;

int bfs(vector<vector<int>> &matrix)
{
   int rows = matrix.size(), cols = matrix[0].size();
    
    //Initial values of 0
    vector<vector<int>> visited(rows, vector<int> (cols, 0)); 
    
    //Queue pair represents rows, cols
    queue<pair<int, int>> queue;

    //Add the starting cell (0,0) to queue
    queue.push(pair<int, int>(0,0)); 
    
    //Mark visited cell
    visited[0][0] = 1;

    int pathLength = 0;

    //BFS traversal loop

    while(queue.size())
    {  
        // Number of cells of current level
        int queueLength = queue.size(); 

        for(int i = 0; i < queueLength; i++)
        {  
            pair<int, int> currCell = queue.front();
            queue.pop();

            int currRow = currCell.first, currCol = currCell.second;
             
            // If reaches destination
            if(currRow == rows - 1 && currCol == cols - 1)
            {
                return pathLength;
            }

            //Define traversal movements (left, right, up, down)
            int neighbours[NUM_DIRECTIONS][ROW_COL] = {
                {currRow, currCol + 1},
                {currRow, currCol -1},
                {currRow + 1, currCol},
                {currRow - 1, currCol},
            };

            //Iterate over each movements
            for(int i = 0; i < NUM_DIRECTIONS; i++)
            {
                int newRow = neighbours[i][0], newCol = neighbours[i][1];

              //Check constraints
              if(min(newRow, newCol) < 0 || newRow == rows || newCol == cols || visited[newRow][newCol] || matrix[newRow][newCol])
              {
                continue; //Skip out of range, visited, obstracle cells
              }

              queue.push(pair<int, int>(newRow, newCol));

              visited[newRow][newCol] = 1;
            }

        }
        pathLength++;
    }

    return -1;
}   



int main()
{
    vector<vector<int>> matrix = 
    {
      {0,0,0,0},
      {1,1,0,0},
      {0,0,0,1},
      {0,1,0,0}
    };

    int result = bfs(matrix);
    cout << result << endl;


    return 0;
}