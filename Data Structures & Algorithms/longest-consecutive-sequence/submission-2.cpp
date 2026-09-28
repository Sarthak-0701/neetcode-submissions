class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int> freq(nums.begin() , nums.end());

        int maxLen = 0;

        for(int num : freq){
            if(!freq.count(num - 1)){
                int currNum = num;
                int currentStreak = 1;

                while(freq.count(currNum + 1)){
                    currNum++;
                    currentStreak++;
                }

                maxLen = max(maxLen, currentStreak);
            }
        }
        return maxLen;
    }
};
