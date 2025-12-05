class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> m;

        for(int i = 0;i<n;i++){

            int second = target - nums[i];
            if(m.find(second) != m.end()){
                return {i,m[second]};
            }
            else{
                m[nums[i]] = i;
            }
        }
        return {};
    }
};