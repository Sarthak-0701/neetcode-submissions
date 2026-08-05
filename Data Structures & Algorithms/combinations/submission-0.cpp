class Solution {
public:

    void backtrack(int start , int n , int k , vector<vector<int>>& result , vector<int>& current){
        if(current.size() == k){
            result.push_back(current);
            return;
        }
        int remaining = k - current.size();
        for(int i = start ; i <= n - remaining + 1 ; i++){
            current.push_back(i);
            backtrack(i+1 , n , k , result , current);
            current.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;

        backtrack(1 , n , k , result , current);

        return result;
    }
};