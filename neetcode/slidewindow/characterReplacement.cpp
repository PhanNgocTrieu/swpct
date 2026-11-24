class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int left = 0;
        int maxFreq = 0;
        int best = 0;

        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            int idx = s[right] - 'A';
            ++freq[idx];
            maxFreq = max(maxFreq, freq[idx]);

            while ((right - left + 1) - maxFreq > k) {
                --freq[s[left] - 'A'];
                ++left;
            }

            best = max(best, right - left + 1);
        }

        return best;
    }
};
