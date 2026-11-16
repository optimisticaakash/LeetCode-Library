class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int result = INT_MAX;

        for(int i = 0; i < n; i++){
            int currsum = 0;

            for(int j = i; j < n && (j-i+1) <= r; j++){
                currsum += nums[j];

                if((j-i+1) >= l && currsum > 0){
                    result = min(result , currsum);
                }
            }
        }

        return result ==INT_MAX ? -1 : result;
    }
};