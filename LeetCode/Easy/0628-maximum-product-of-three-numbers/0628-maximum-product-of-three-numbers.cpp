class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;
        int mini1 = INT_MAX;
        int mini2 = INT_MAX;

        for(int& num : nums){
            if(num > max1){
                max3 = max2;
                max2 = max1;
                max1 = num; 
            }else if(num > max2){
                max3 = max2;
                max2 = num;
            }else if(num > max3){
                max3 = num;
            }

            if(num < mini1){
                mini2 = mini1;
                mini1 = num;
            }else if(num < mini2){
                mini2 = num;
            }
        } 


        return max(max1*max2*max3 , mini1*mini2*max1);
    }
};