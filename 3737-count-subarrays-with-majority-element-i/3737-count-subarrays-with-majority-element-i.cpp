//Approach4:Cummulative Sum/ prefix Sum
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int cnt = 0;

        vector<int> cumSum(n,0);

        for(int i = 0; i < n; i++){
            if(i == 0){
                cumSum[0] = (nums[0] == target ? 1 : -1);
            }else{
                cumSum[i] = cumSum[i-1] + (nums[i] == target ? 1 : -1);
            }
        }

        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                if(i == 0)
                    sum = cumSum[j];
                else
                    sum = cumSum[j] - cumSum[i-1];

                if(sum > 0 ) cnt++;
            }
        }

        return cnt;
    }
};
//T.C : O(N^2)
//S.C : O(1)
