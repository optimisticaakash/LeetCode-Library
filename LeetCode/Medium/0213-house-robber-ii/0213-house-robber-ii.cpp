class Solution {
public:
    int t[101];
    int solve(vector<int>& nums , int i , int n){

        //base case
        if(i > n){
            return 0;
        }

        if(t[i] != -1){
            return t[i];
        }

        //we have only two ways
        //steal
        int steal = nums[i] + solve(nums , i+2 , n);
        int skip = solve(nums , i+1 , n);

        return t[i] = max(steal , skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        if(n == 2){
            return max(nums[0] , nums[1]);
        }

        memset(t , -1 , sizeof(t));
        //case1. take 0th index house (1st house);
        int take_0th_house = solve(nums , 0 , n-2);

        memset(t , -1 , sizeof(t));
        //case2. take 1st index house (2nd house);
        int take_1st_house = solve(nums , 1 , n-1);

        return max(take_0th_house , take_1st_house);
    }
};