class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        vector<int> suf(n);
        if(n == 0)  return 0; 
        pre[0] = nums[0];
        suf[n-1] = nums[n-1];
        int mul = 0;
        for(int i = 1 ; i < n ; i++){
            if(pre[i-1] == 0){
                mul = 1; 
            }
            else{
                mul = pre[i-1];
            }
            pre[i] = mul*nums[i];

            if(suf[n-i] == 0){
                mul = 1; 
            }
            else{
                mul = suf[n-i];
            }
            suf[n-i-1] = mul*nums[n-i-1];
        }
        int ans = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            ans = max(ans , max(pre[i] , suf[i]));
        }
        return ans;
    }
};
