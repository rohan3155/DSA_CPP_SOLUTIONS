class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_set<int> s;
        int repeating = -1;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int v = grid[i][j];
                sum += v;
                if (s.find(v) != s.end()) {
                    repeating = v;
                } else {
                    s.insert(v);
                }
            }
        }

        long long total = 1LL * n * n * (n * n + 1) / 2;
        int missing = total - (sum - repeating);

        return {repeating, missing};
    }
};
