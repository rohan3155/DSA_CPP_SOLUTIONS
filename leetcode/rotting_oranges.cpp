class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = true;
                }
            }
        }

        int ans = 0;
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [pos, time] = q.front();
            q.pop();

            int x = pos.first;
            int y = pos.second;
            ans = max(ans, time);

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                    !vis[nx][ny] && grid[nx][ny] == 1) {
                    vis[nx][ny] = true;
                    q.push({{nx, ny}, time + 1});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) return -1;
            }
        }

        return ans;
    }
};
