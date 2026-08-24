class Solution {
public:

    void countingSort(vector<int>& nums){
        unordered_map<int ,int> count;
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int num : nums){
            count[num]++;
            mini = min(mini , num);
            maxi = max(maxi , num);
        }

        int idx = 0;
        for(int i = mini ; i <= maxi ; i++){
            while(count[i] > 0){
                nums[idx] = i;
                idx++;
                count[i]--;
            }
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        countingSort(nums);
        return nums;
    }
};