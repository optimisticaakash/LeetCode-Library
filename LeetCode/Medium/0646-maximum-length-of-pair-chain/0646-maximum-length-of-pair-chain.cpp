class Solution {
public:
    int t[1001][1001];
    int solve(int i ,vector<vector<int>>& pairs , int P){
        if(i >= pairs.size()){
            return 0;
        }

        if(P != -1 && t[i][P] != -1) return t[i][P];

        int take = 0;
        //take ith element
        if(P == -1 || pairs[P][1] < pairs[i][0]){
            take = 1 + solve(i+1 , pairs , i);
        }

        //skip the ith element
        int skip = solve(i+1 , pairs , P);

        if(P != -1){
            return t[i][P]  = max(skip , take);
        }

        return max(skip , take);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin() , pairs.end());

        memset(t , -1 , sizeof(t));

        return solve(0 , pairs , -1);
    }
};