class Solution {
public:
    int bin_search(vector<int>& arr, int tar, int st, int end) {
        if (st <= end) {
            int mid = st + (end - st) / 2;

            if (arr[mid] == tar){
                return mid;
            }
            else if (arr[mid] <= tar) {
                return bin_search(arr, tar, mid + 1, end);
            } else {
                return bin_search(arr, tar, st, mid - 1);
            }
        }
        return -1;
    }
    int search(vector<int>& arr, int tar) {
        int n = arr.size();
        return bin_search(arr, tar, 0, n - 1);
    }
};