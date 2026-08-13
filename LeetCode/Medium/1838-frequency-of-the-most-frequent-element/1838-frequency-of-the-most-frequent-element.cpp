//Approach1 : using Binary. Seach + prefixSum
typedef long long ll;
class Solution {
public:
    int bSearch(int target_idx , int k ,vector<int>& nums , vector<ll>& prefixSum){
        int target = nums[target_idx];
        int l = 0;
        int r = target_idx;

        int best_idx = target_idx;

        while(l <= r){
            int mid = l + (r-l)/2;
            ll count = target_idx - mid + 1;

            ll windowSum = count * target;
            ll currSum = prefixSum[target_idx] - prefixSum[mid] + nums[mid];

            int ops = windowSum - currSum;

            if(ops > k){
                l = mid + 1 ;
            }else{
                best_idx = mid;
                r = mid- 1;
            }
        }

        return target_idx - best_idx + 1;
    }
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        vector<ll> prefixSum(n);
        prefixSum[0] = nums[0];

        for(int i = 1; i < n; i++){
            prefixSum[i] = prefixSum[i-1]+ nums[i];
        }

        int result = 0;
        for(int i = 0; i < n; i++){
            result = max(result , bSearch(i , k , nums , prefixSum));
        }

        return result;
    }
};

//T.C : O(nlogn)
//S.C : O(N)