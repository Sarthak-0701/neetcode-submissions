class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int el = 0;

        for(int num : nums){
            if(count == 0){
                el = num;
                count++;
            }
            else{
                if(num == el){
                    count++;
                }
                else{
                    count--;
                }
            }
        }
        return el;
    }
};