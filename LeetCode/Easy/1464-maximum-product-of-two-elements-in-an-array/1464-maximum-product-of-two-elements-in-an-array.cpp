class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi1 = 0 , maxi2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] > maxi1){
                maxi2 = maxi1;
                maxi1 = nums[i];
            }else{
                maxi2 = max(maxi2 , nums[i]);
            }
        }


        return (maxi1 - 1)*(maxi2-1);
    }
};