class Solution {
public:
    set<vector<int>> s;

    void getAllCombinations(vector<int>& arr, int idx, int tar,
                            vector<vector<int>>& ans,
                            vector<int>& combinations) {

        if (tar == 0) {
            if (s.find(combinations) == s.end()) {
                ans.push_back(combinations);
                s.insert(combinations);
            }
            return;
        }

        if (idx == arr.size() || tar < 0) {
            return;
        }

        combinations.push_back(arr[idx]);
        getAllCombinations(arr, idx + 1, tar - arr[idx], ans, combinations);
        getAllCombinations(arr, idx, tar - arr[idx], ans, combinations);
        combinations.pop_back();

        getAllCombinations(arr, idx + 1, tar, ans, combinations);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> combinations;
        sort(arr.begin(), arr.end());
        getAllCombinations(arr, 0, target, ans, combinations);
        return ans;
    }
};
