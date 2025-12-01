class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }
        int s = 0, e = n - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (mid == 0 && nums[0] != nums[1]) {
                return nums[mid];
            }
            if (mid == n - 1 && nums[n - 1] != nums[n - 2]) {
                return nums[mid];
            }
            if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }
            if (n % 2 == 0) {
                if (nums[mid - 1] == nums[mid]) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            } else {
                if (nums[mid - 1] == nums[mid]) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
        }
        return -1;
    }
};