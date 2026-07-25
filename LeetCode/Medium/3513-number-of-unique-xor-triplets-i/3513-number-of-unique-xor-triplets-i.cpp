//Approach1: observation
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if(n <= 2) return n;

        int ans = 1;
        while(ans <= n){
            ans *= 2;
        }

        return ans;
    }
};

//T.C : O(log2n)
//S.C : O(1)
