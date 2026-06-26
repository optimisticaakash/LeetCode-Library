class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> t(n+1 , 0);
        //t[i] = max stolen money till i house

        t[0] = 0; //no house
        t[1] = nums[0];//only 1 house

        for(int i = 2; i<= n; i++){
            int steal = nums[i-1] + t[i-2];
            int skip = t[i-1];

            t[i] = max(steal , skip);
        }

        return t[n];
    }
};