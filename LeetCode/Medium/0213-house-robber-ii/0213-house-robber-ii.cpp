class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        vector<int> t(n+1);
        //t[i] = money when have i houses

        int result1;
        t[0] = 0;
        //case1 : take 1st house -> skip the last house
        for(int i = 1; i <= n-1; i++){
            int skip = t[i-1];
            int steal = nums[i-1] + (i-2 >= 0 ?t[i-2]: 0);

            t[i] = max(steal , skip);
        }
        result1 = t[n-1];

        t.clear();

        int result2;
        t[0] = 0;
        t[1] = 0;//skip first house
        //case2: skip first house -> take the last house
        for(int i = 2; i <= n; i++){
            int skip = t[i-1];
            int steal = nums[i-1] + (i-2 >= 0 ? t[i-2]: 0);

            t[i] = max(steal , skip);
        }
        result2 = t[n];


        return max(result1 , result2);

    }
};