class Solution {
public:
    void getAllSubsets(vector<int>& nums, vector<int>& ans, int i,
        vector<vector<int>>& allSubsets) 
    {
        if (i == nums.size()) {
            allSubsets.push_back({ans});
            return;
        }

        // include in subset
        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i + 1, allSubsets);
        // step during backtracking
        ans.pop_back();

        // exclude in subset
        getAllSubsets(nums, ans, i + 1, allSubsets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int> ans;

        getAllSubsets(nums, ans, 0, allSubsets);
        return allSubsets;
    }
};