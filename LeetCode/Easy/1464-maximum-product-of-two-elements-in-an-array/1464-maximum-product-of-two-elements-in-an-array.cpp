class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int currmax = nums[0];
        int result = 0;

        for(int i = 1; i < n; i++){
            result = max(result , (currmax-1)*(nums[i]-1));

            currmax = max(currmax , nums[i]);
        }

        return result;
    }
};