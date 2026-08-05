class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        queue<pair<int, int>> q;

        // Step 1: Collect ALL treasure chests first (Multi-Source Initialization)
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, -1, 0, 1};

        // Step 2: Single BFS traversal outward from all chests at once
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                // If neighbor is within bounds and is an unvisited empty land (2147483647 / INF)
                if (nx >= 0 && nx < r && ny >= 0 && ny < c && grid[nx][ny] == 2147483647) {
                    grid[nx][ny] = grid[x][y] + 1; // Direct distance update
                    q.push({nx, ny});
                }
            }
        }
    }
};