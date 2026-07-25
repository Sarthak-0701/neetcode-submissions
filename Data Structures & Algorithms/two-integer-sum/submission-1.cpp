class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> ans;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            ans.push_back({nums[i] , i});
        }
        sort(ans.begin() , ans.end());

        int i = 0; 
        int j = n-1;
        while(i < j){
            if(ans[i].first + ans[j].first > target){
                j--;
            }
            else if(ans[i].first + ans[j].first < target){
                i++;
            }
            else{
                if(ans[i].second < ans[j].second){
                    return {ans[i].second , ans[j].second};
                }
                return {ans[j].second , ans[i].second};
            }
        }
        return {-1};
    }
};
