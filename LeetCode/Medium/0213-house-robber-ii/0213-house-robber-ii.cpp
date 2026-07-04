class Solution {
public:
    int solve(vector<int>& nums ,int l , int r){
        int prev = 0 , prevprev = 0;

        for(int i = l; i <= r; i++){
            int skip = prev;
            int steal = nums[i] + prevprev;

            int temp = max(steal,skip);

            prevprev = prev;
            prev = temp;
        }

        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        if(n == 2) return max(nums[0] , nums[1]);

        int take_first = solve(nums,0 , n-2);
        int not_takefirst = solve(nums ,1 , n-1);

        return max(take_first,not_takefirst);
    }
};