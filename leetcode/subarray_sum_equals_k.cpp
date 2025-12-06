class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        int count = 0;
        vector<int> prefix_sum(n, 0);
        prefix_sum[0] = arr[0];

        for (int i = 1; i < n; i++) {
            prefix_sum[i] = prefix_sum[i - 1] + arr[i];
        }

        unordered_map<int, int> m;
        for (int j = 0; j < n; j++) {
            if (prefix_sum[j] == k)
                count++;

            int val = prefix_sum[j] - k;
            if (m.find(val) != m.end()) {
                count += m[val];
            }

            if (m.find(prefix_sum[j]) == m.end()) {
                m[prefix_sum[j]] = 0;
            }
            m[prefix_sum[j]]++;
        }

        return count;
    }
};