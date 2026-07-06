//Approach1: recursion
class Solution {
public:
    typedef long long ll;
    ll solve(int idx , vector<int>& nums , bool isEven){

        if(idx >= nums.size()) return 0;

        ll skip = solve(idx+1 , nums , isEven);

        ll val = nums[idx];

        if(isEven == false){
            val = -val;
        }

        ll take = solve(idx+1 , nums , !isEven) + val;

        return max(skip , take);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        return solve(0 ,nums ,  true);// 0 : even index , true : + 
    }
};
//T.C : O(2^n)
//S.C : O(n)

//Approach: recursion+memoization
class Solution {
public:
    typedef long long ll;
    ll t[1000001][2];
    ll solve(int idx , vector<int>& nums , bool isEven){

        if(idx >= nums.size()) return 0;

        if(t[idx][isEven] != -1){
            return t[idx][isEven];
        }

        ll skip = solve(idx+1 , nums , isEven);

        ll val = nums[idx];

        if(isEven == false){
            val = -val;
        }

        ll take = solve(idx+1 , nums , !isEven) + val;

        return t[idx][isEven]= max(skip , take);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        memset(t,-1,sizeof(t));
        return solve(0 ,nums ,  true);// 0 : even index , true : + 
    }
};
//T.C : O(2n)
//s.C : O(n)
