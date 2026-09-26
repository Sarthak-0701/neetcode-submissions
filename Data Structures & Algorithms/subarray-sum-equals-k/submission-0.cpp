class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefixSum = 0;
        int cnt = 0;
        unordered_map<int , int> freq;
        freq[0] = 1;

        for(int i = 0 ; i < nums.size() ; i++){
            prefixSum += nums[i];
            int remove = prefixSum - k;
            cnt += freq[remove];
            freq[prefixSum] += 1;
        }
        return cnt;
    }
};