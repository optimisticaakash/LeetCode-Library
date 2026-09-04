class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>PrefixMax(n);
        vector<int>SuffixMin(n);

        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int i = 0; i < n; i++){
            maxi = max(maxi , nums[i]);
            PrefixMax[i] = maxi;
        }

        for(int i = n-1; i >= 0; i--){
            mini = min(mini , nums[i]);
            SuffixMin[i] = mini;
        }


        int instablity_Score = 0 ;
        for(int i = 0; i < n; i++){
            instablity_Score = PrefixMax[i] - SuffixMin[i];
            if(instablity_Score <= k )return i;
        }


        return -1;
    }
};