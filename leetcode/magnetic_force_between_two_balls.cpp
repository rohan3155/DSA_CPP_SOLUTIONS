class Solution {
public:
    bool canPlace(vector<int>& pos, int balls, int minDist) {
        int placed = 1;
        int last = pos[0];

        for (int i = 1; i < pos.size(); i++) {
            if (pos[i] - last >= minDist) {
                placed++;
                last = pos[i];
            }
            if (placed == balls) return true;
        }
        return false;
    }

    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(), pos.end());
        int low = 1;
        int high = pos.back() - pos.front();
        int best = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canPlace(pos, m, mid)) {
                best = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return best;
    }
};
