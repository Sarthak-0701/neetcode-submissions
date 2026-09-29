class Solution {
public:

    int maxi(vector<int>& arr){
        int n = arr.size();
        int ans = -1e9;
        for(int i = 0 ; i < n ; i++){
            ans = max(ans , arr[i]);
        }
        return ans;
    }

    bool canFinish(vector<int>& arr , int h , int k){
        long long hours = 0;
        for(int a : arr){
            hours += a / k;
            if(a % k != 0) hours++;
            if(hours > h) return false;
        }
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = maxi(piles);
        int ans = e;

        while(s <= e){
            int mid = s + (e - s) / 2;

            if(canFinish(piles, h, mid)){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return ans;
    }
};
