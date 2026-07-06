class Solution {
public:
    int t[2501][2501];
    int solve(int i , vector<int>& nums , int P){
        if(i >= nums.size()) return 0;

        //take ith element
        int take = 0;

        if( P != -1 && t[i][P] != -1) return t[i][P];


        if(P == -1 || nums[P] < nums[i]){
            take = 1 + solve(i+1 , nums , i);
        }

        //skip ith element
        int skip = solve(i+1,nums,P);

        if(P != -1){
            return t[i][P] =  max(take , skip);
        }

        return max(take , skip);
    }
        
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        memset(t,-1,sizeof(t));
        return solve(0 , nums , -1);
    }
};