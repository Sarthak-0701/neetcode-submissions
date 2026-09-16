class Solution {
public:

    int solve(const string& s1 , const string& s2 , int i , int j , vector<vector<int>>& dp){
        if(i < 0 || j < 0)  return 0;
        if(dp[i][j] != -1)  return dp[i][j];

        int op1 = -1e8;
        int op2 = -1e8;
        if(s1[i] == s2[j]){
            op1 = 1 + solve(s1 , s2 , i-1 , j-1 , dp);
        }
        else{
            op2 = 0 + max({
                solve(s1 , s2 , i-1 , j , dp),
                solve(s1 , s2 , i , j-1 , dp)
            });
        }
        return dp[i][j] = max(op1 , op2);
    }

    int solveTab(const string& s1 , const string& s2){
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , 0));

        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                int op1 = -1e8;
                int op2 = -1e8;
                if(s1[i-1] == s2[j-1]){    
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{    
                    dp[i][j] = 0 + max({ dp[i-1][j] , dp[i][j-1]});
                }
            }
        }
        return dp[n][m];
    }

    int longestCommonSubsequence(string text1, string text2) {
        // int n = text1.length();
        // int m = text2.length();
        // vector<vector<int>> dp(n , vector<int>(m , -1));
        // return solve(text1 , text2 , n-1 , m-1 , dp);
        return solveTab(text1 , text2);
    }
};
