class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        sort(pairs.begin() , pairs.end());
        vector<int>t(n+1,1);
        int maxPairchain = 1;

        for(int i = 0; i < n; i++){
            for(int j = 0;j < n; j++){
                if(pairs[j][1] < pairs[i][0]){
                    t[i] = max(t[i] , t[j]+1);
                    maxPairchain = max(maxPairchain , t[i]);
                }
            }
        }

        return maxPairchain;
    }
};