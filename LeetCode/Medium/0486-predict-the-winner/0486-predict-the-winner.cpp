//Approach1: recursion1 +memoization
class Solution {
public:
    int t[22][22];
    int solve(int i , int j , vector<int>& nums){
        //base caase: koi element nhi bacha
        if(i > j){
            return 0;
        }

        if(i == j) return nums[i]; //sirf ek hi element;

        if(t[i][j] != -1){
            return t[i][j];
        }

        int take_i = nums[i] + min(solve(i+2 , j , nums) , solve(i+1, j-1 , nums));

        int take_j = nums[j] + min(solve(i+1 , j-1 , nums) , solve(i, j-2 , nums));

        return t[i][j] =  max(take_i , take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        int n = nums.size();

        int total_score = accumulate(begin(nums) , end(nums) , 0);

        int player1_score = solve(0 , n-1 , nums);
        int player2_score = total_score - player1_score;

        return player1_score >= player2_score;
    }
};
//T.C : O(n^2)
//S.C : O(n^2)



//Approach2: recursion type 2 : aise function banaye jo direct player1_score - player2_score >= 0 dede 
class Solution {
public:
    int t[22][22];
    int solve(int i , int j , vector<int>& nums){
        if(i > j) return 0;

        if(i == j) return nums[i];

        if(t[i][j] != -1){
            return t[i][j];
        }

        int take_i = nums[i] - solve(i+1 , j , nums);
        int take_j = nums[j] - solve(i , j-1 , nums);

        return t[i][j] =  max(take_i , take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        memset(t,-1,sizeof(t));
        return solve(0 , n-1 , nums) >= 0;
    }
};
//T.C : O(n^2)
//S.C : O(n^2)
