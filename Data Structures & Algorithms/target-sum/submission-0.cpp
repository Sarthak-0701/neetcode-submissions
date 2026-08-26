class Solution {
public:

    int solve(vector<int>& nums , int idx , int sum , int target , int totalSum , vector<vector<int>>& dp){
        if (idx == nums.size()) {
            return sum == target ? 1 : 0;
        }

        int shiftedSum = sum + totalSum;
        if(dp[idx][shiftedSum] != -1){
            return dp[idx][shiftedSum];
        }

        int op1 = solve(nums , idx+1 , sum+nums[idx], target , totalSum , dp);
        int op2 = solve(nums , idx+1 , sum-nums[idx], target , totalSum , dp);

        return dp[idx][shiftedSum] = op1+op2;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int totalSum = accumulate(nums.begin() , nums.end() , 0);
        if(abs(target) > totalSum){
            return 0;
        }

        vector<vector<int>> dp(n , vector<int>((2 * totalSum) + 1 , -1));
        return solve(nums , 0 , 0 , target , totalSum , dp);
    }
};
