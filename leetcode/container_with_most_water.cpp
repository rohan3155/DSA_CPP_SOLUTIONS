class Solution {
public:
    int maxArea(vector<int>& height) {
        int n =height.size();
        int lp=0, rp = n-1,max_wt=0;

        while(lp<rp){
            int w = rp-lp;
            int ht = min(height[lp],height[rp]);
            int curr_wt = w * ht; 
            max_wt = max(curr_wt,max_wt);
            height[lp] < height[rp] ? lp++ : rp--;
        }
        return max_wt;
    }
};