class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int l = 0, r = n - 1;
        int lmax = 0, rmax = 0;

        while (l < r) {
            int lheight = height[l];
            int rheight = height[r];
            lmax = max(lmax, lheight);
            rmax = max(rmax, rheight);
            if (lmax < rmax) {
                ans += lmax - lheight;
                l++;
            } else {
                ans += rmax - rheight;
                r--;
            }
        }
        return ans;
    }
};