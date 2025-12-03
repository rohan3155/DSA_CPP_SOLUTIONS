class Solution {
public:
    bool isFreqSame(vector<int> freq1, vector<int> freq2) {
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) {
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26, 0);
        for (int i = 0; i < s1.length(); i++) {
            freq[s1[i] - 'a']++;
        }
        int window_size = s1.length();
        for (int i = 0; i < s2.length(); i++) {
            int window_idx = 0, idx = i;
            vector<int> window_freq(26, 0);

            while (window_idx < window_size && idx < s2.length()) {
                window_freq[s2[idx] - 'a']++;
                window_idx++;
                idx++;
            }
            if (isFreqSame(freq, window_freq)) {
                return true;
            }
        }
        return false;
    }
};