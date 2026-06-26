//Approach1: recursion
class Solution {
public:
    int solve(vector<int>& nums , int i , int n){

        //base case
        if(i >= n) return 0;

        //we have only two option
        int steal = nums[i] + solve(nums , i + 2 , n);

        int skip = solve(nums , i+1 , n);

        return max(steal , skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        return solve(nums , 0 , n);
    }
};
//T.C : O(2^n)
//S.C : O(n)

//Approach2: recursion + memoization
class Solution {
public:
    int t[101];
    int solve(vector<int>& nums , int i , int n){

        //base case
        if(i >= n) return 0;

        if(t[i] != -1) return t[i];

        //we have only two option
        int steal = nums[i] + solve(nums , i + 2 , n);

        int skip = solve(nums , i+1 , n);

        return t[i] = max(steal , skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(t,-1,sizeof(t));
        return solve(nums , 0 , n);
    }
};
//T.C : O(N)
//S.C : O(N)
//Approach3 : bottom up - approach
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
//T.C : O(N)
//S.C : O(N)
