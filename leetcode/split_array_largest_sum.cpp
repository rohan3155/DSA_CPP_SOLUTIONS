class Solution {
public:
    bool isValid(vector<int>& nums, int k ,int allowed_pages) {
        int std = 1, pages = 0;
        for (int val : nums) {
            if (val > allowed_pages) {
                return false;
            }
            if (pages + val <= allowed_pages) {
                pages += val;
            } else {
                std++;
                pages = val;
            }
        }

        return std <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        int s = 0, e = sum;
        int ans = INT_MAX;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (isValid(nums, k,mid)) {
                ans = min(ans,mid);
                e = mid - 1;
            } else {
                s = mid + 1;
            }

        }
        return ans;
    }
};