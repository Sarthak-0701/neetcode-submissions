class Solution {
public:

    int solve(vector<int>& nums , int n , vector<int>& dp){
        if(n < 0)    return 0;
        if(dp[n] != -1) return dp[n];
        int take = nums[n] + solve(nums , n-2 , dp);
        int notTake = 0 + solve(nums , n-1 , dp);

        return dp[n] = max(take, notTake);
    }

    int solveTab(vector<int>& arr){
        int n = arr.size();
        if(n == 0)  return 0;
        if(n == 1)  return arr[0];

        // vector<int> dp(n , 0);

        int curr = 0;
        int prev2 = arr[0];
        int prev1 = max(arr[0] , arr[1]);

        for(int i = 2 ; i < n ; i++){
            curr = max(arr[i] + prev2 , prev1);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n , -1);
        // return solve(nums , n-1 , dp);
        return solveTab(nums);
    }
};
