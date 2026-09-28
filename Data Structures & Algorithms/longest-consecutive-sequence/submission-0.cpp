class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> freq;
        for(int num : nums){
            freq[num]++;
        }
        int len = 1;
        int maxLen = 0;
        for(auto [key , val] : freq){
            if(freq.count(key+1)){
                len++;
            }
            else{
                len = 1;
            }
            maxLen = max(maxLen , len);
        }
        return maxLen;
    }
};
