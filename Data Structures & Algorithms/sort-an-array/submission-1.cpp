class Solution {
public:

    void countingSort(vector<int>& nums){
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());

        int range = maxi - mini + 1;
        vector<int> count(range, 0);

        for (int num : nums) {
            count[num - mini]++;
        }

        int idx = 0;
        for(int i = 0 ; i < range ; i++){
            while(count[i] > 0){
                nums[idx] = i+mini;
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