//Approach1: recursion+memoization
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
//T.C : O(2n)
//S.C : O(n)

//Approach2: bottomup 
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
//T.C : O(2n)
//S.C : O(n)
