class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<int>preMax(n,0);
        preMax[0] = nums[0];

        for(int i = 1; i < n; i++){
            preMax[i] = max(nums[i] , preMax[i-1]);
        }
        
        vector<int>prefixGcd(n , 0);
        prefixGcd[0] = preMax[0];
        for(int i = 1; i < n; i++){
            prefixGcd[i] = __gcd(nums[i] ,preMax[i]);
        }

        sort(prefixGcd.begin() , prefixGcd.end());

        int l = 0;
        int r = n-1;
        long long gcdsum = 0;
        while(l < r){
            gcdsum += __gcd(prefixGcd[l] , prefixGcd[r]);
            l++;
            r--;
        }

        return gcdsum;
    }
};