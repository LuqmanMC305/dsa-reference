#include <bits/stdc++.h>
using namespace std;

int main() {
    // --- Declaration ---
    vector<vector<int>> a;                        // empty
    vector<vector<int>> b(3, vector<int>(4));      // 3x4, zero-initialised
    vector<vector<int>> c(3, vector<int>(4, -1));  // 3x4, filled with -1
    vector<vector<int>> d = {{1,2},{3,4}};         // literal init

    int n = b.size();
    int m = b[0].size();

    // --- Access ---
    b[0][0] = 5;
    int x = b.at(0).at(0);

    // --- Iterate ---
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cout << b[i][j] << " ";
    cout << "\n";

    for (auto& row : b)
        for (auto& val : row)
            cout << val << " ";
    cout << "\n";

    // --- Modify structure ---
    b.push_back(vector<int>(m, 0));   // add row
    b[0].push_back(7);                // add element to row 0
    b.pop_back();                     // remove last row
    if (!b[0].empty())
        b[0].erase(b[0].begin());     // remove first element of row 0

    // --- Resize ---
    b.resize(5, vector<int>(m, 0));
    b[0].resize(6, 0);

    // --- Fill ---
    for (auto& row : b) fill(row.begin(), row.end(), 0);

    // --- Copy (deep copy) ---
    vector<vector<int>> e = b;

    // --- Applications ---

    // 1. Grid traversal (4-directional)
    int rows = 3, cols = 4;
    vector<vector<int>> grid(rows, vector<int>(cols, 0));
    int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
    int i = 1, j = 1;
    for (int k = 0; k < 4; k++) {
        int ni = i + dx[k], nj = j + dy[k];
        if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
            // process grid[ni][nj]
        }
    }

    // 2. Transpose
    vector<vector<int>> t(cols, vector<int>(rows));
    for (int r = 0; r < rows; r++)
        for (int col = 0; col < cols; col++)
            t[col][r] = grid[r][col];

    // 3. Adjacency list (graph)
    int numNodes = 5;
    vector<vector<int>> adj(numNodes);
    int u = 0, v = 1;
    adj[u].push_back(v);
    adj[v].push_back(u); // if undirected

    // 4. DP table
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // 5. Sort rows by first column
    sort(b.begin(), b.end(), [](const vector<int>& p, const vector<int>& q) {
        return p[0] < q[0];
    });

    // 6. Flatten
    vector<int> flat;
    for (auto& row : b)
        flat.insert(flat.end(), row.begin(), row.end());

    return 0;
}