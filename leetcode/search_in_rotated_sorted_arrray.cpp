class Solution {
public:
    int search(vector<int>& nums, int tar) {
     /*
        Identify which half is sorted
        Check if the target lives in that half
        If yes, shrink to that half
        If no, search the other half
     */   
        int st = 0, end = nums.size() - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] == tar) return mid;

            if (nums[st] <= nums[mid]) {
                if (nums[st] <= tar && tar <= nums[mid]) end = mid - 1;
                else st = mid + 1;
            } else {
                if (nums[mid] <= tar && tar <= nums[end]) st = mid + 1;
                else end = mid - 1;
            }
        }
        return -1;
    }
};
