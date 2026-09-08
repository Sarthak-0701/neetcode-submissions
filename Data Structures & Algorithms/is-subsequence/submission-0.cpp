class Solution {
public:

    int solve(string& word1, int n, string& word2 , int m , vector<vector<int>>& dp){
        if (n < 0) return m + 1;
        if (m < 0) return n + 1;

        if(dp[n][m] != -1){
            return dp[n][m];
        }

        int op3 = 1e8;
        int op1 = 1e8;
        int op2 = 1e8;
        if(word1[n] == word2[m]){
            op3 = 0 + solve(word1 , n-1 , word2 , m-1 , dp);
        }
        else{
            op1 = 1 + solve(word1 , n-1 , word2 , m , dp);
            op2 = 1 + solve(word1 , n , word2 , m-1 , dp);
        }
        
        return dp[n][m] = min({op1 , op2 , op3});
    }

    int lcs(const string& word1 , const string& word2){
        int n = word1.length();
        int m = word2.length();

        vector<vector<int>> dp(n+1 , vector<int> (m+1 , 0));
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(word1[i-1] == word2[j-1]){    
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{    
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); 
                }
            }
        }
        return dp[n][m];
    }

    bool isSubsequence(string s, string t) {

        // int n = s.length();
        // int m = t.length();

        // vector<vector<int>> dp(n , vector<int> (m , -1));

        // return solve(word1 , n-1 , word2 , m-1 , dp);

        return lcs(s, t) == s.length();

    }
};