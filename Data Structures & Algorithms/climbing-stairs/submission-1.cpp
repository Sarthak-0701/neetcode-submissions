class Solution {
public:

    int solve(int n , int idx){
        if(idx > n) return 0;
        if(idx == n)    return 1;

        int jump1 = solve(n , idx+1);
        int jump2 = solve(n , idx+2);

        int ans = jump1 + jump2;
        return ans; 
    }

    int solve(int n , int idx  ,vector<int>& dp){
        if(idx > n) return 0;
        dp[n] = 1;

        if(dp[idx] != -1){
            return dp[idx];
        }

        int jump1 = solve(n , idx+1 , dp);
        int jump2 = solve(n , idx+2 , dp);

        return dp[idx] = jump1 + jump2;
    
    }

    int climbStairs(int n) {
        vector<int> dp(n+1 , -1);
        return solve(n , 0 , dp);
    }
};
