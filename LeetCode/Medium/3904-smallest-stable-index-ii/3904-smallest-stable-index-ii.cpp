class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>prefixMax(n);
        vector<int>suffixMin(n);

        int maxi = INT_MIN;
        int mini = INT_MAX;

        //1.make the prefixMax
        for(int i = 0; i < n; i++){
            maxi = max(maxi , nums[i]);
            prefixMax[i] = maxi;
        }


        //2.make the suffixMin
        for(int i = n-1; i >= 0; i--){
            mini = min(mini , nums[i]);
            suffixMin[i] = mini;
        }

        //check instability score
        int score = 0;
        for(int i = 0; i < n; i++){
            score = prefixMax[i] - suffixMin[i];

            if(score <= k) return i;
        }


        return -1;
    }
};