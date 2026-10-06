class Solution {
public:
    int longestSubstring(string s, int k) {

        int ans = 0;

        for (int target = 1; target <= 26; target++) {

            int l = 0, r = 0;
            int frequency[26] = {0};

            int unique = 0;
            int atLeastK = 0;

            while (r < s.length()) {
                int index = s[r] - 'a';
                if (frequency[index] == 0)
                    unique++;
                frequency[index]++;
                if (frequency[index] == k)
                    atLeastK++;
                while (unique > target) {
                    int leftIndex = s[l] - 'a';
                    if (frequency[leftIndex] == k)
                        atLeastK--;
                    frequency[leftIndex]--;
                    if (frequency[leftIndex] == 0)
                        unique--;
                    l++;
                }
                if (unique == target && atLeastK == target) {
                    ans = max(ans, r - l + 1);
                }
                r++;
            }
        }
        return ans;
    }
};