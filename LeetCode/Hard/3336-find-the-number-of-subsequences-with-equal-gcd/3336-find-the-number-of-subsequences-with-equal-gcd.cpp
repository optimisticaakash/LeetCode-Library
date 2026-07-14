class Solution {
public:
    int MOD = 1e9+7;
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();

        int maxEl = *max_element(nums.begin() , nums.end());
        int t[n+1][maxEl+1][maxEl+1];

        for(int first = 0; first <= maxEl; first++){
            for(int second = 0; second <= maxEl ; second++){
                bool bothNotEmpty = (first != 0 && second != 0);
                bool gcdEqual = (first  == second);

                t[n][first][second] =  (bothNotEmpty && gcdEqual) ? 1 : 0;
            }
        }

        for(int i = n-1; i >= 0; i--){
            for(int first  = maxEl; first >= 0; first--){
                for(int second = maxEl ; second >= 0; second--){

                    int skip = t[i+1][first][second];

                    int take1 = t[i+1][__gcd(first , nums[i])][second];
                    int take2 = t[i+1][first][__gcd(second , nums[i])];

                    t[i][first][second] = (0LL + skip + take1 + take2)%MOD;
                }
            }
        } 
        return t[0][0][0];
    }
};