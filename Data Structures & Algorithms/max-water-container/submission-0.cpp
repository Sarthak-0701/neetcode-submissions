class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0 ;
        int right = heights.size()-1;
        int maxi = INT_MIN;
        int area = 1;
        while(left < right){
            area = (right - left) * (min(heights[left] , heights[right]));
            maxi = max(area , maxi);
            if(heights[left] < heights[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxi;
    }
};
