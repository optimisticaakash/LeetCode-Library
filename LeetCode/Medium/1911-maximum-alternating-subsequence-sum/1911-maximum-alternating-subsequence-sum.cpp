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

//Approach3: bottom up 
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<long>> t(n, vector<long>(2, 0));

        t[0][0] = max(-nums[0], 0);
        t[0][1] = max(nums[0], 0);
            
        for(int i = 1; i < n; i++) {
            
            t[i][0] = max(t[i-1][1] - nums[i], t[i-1][0]);
            
            t[i][1] = max(t[i-1][0] + nums[i], t[i-1][1]);
            
            
        }
        
        return max(t[n-1][0], t[n-1][1]);
    }
};

//Approach- (Same as Approach-3 - Only difference is that I have used 1 based indexing to make it general to other Botto Up)
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<long>> t(n+1, vector<long>(2, 0));
            
        for(int i = 1; i < n+1; i++) {
            
            t[i][0] = max(t[i-1][1] - nums[i-1], t[i-1][0]);
            
            t[i][1] = max(t[i-1][0] + nums[i-1], t[i-1][1]);
            
            
        }
        
        return max(t[n][0], t[n][1]);
    }
};
//T.C : O(n)
//S.C : O(n)
