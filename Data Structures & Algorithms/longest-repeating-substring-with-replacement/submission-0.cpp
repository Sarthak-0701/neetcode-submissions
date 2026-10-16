class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int maxLen = 0;
        int maxFreq = 0;
        vector<int> freq(26 , 0);

        while(r < s.length()){
            char ch = s[r];
            freq[ch-'A']++;
            maxFreq = max(maxFreq , freq[ch-'A']);

            while((r - l + 1) - maxFreq > k){
                freq[s[l] - 'A']--;
                l++;
            }
            maxLen = max(maxLen , r - l + 1);
            r++;
        }
        return maxLen;
    }
};
