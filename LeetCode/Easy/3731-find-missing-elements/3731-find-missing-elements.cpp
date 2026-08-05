class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();

        vector<bool> present(101,false);

        int mini = nums[0];
        int maxi = nums[0];
        for(int i = 0; i < n; i++){
            maxi = max(nums[i] , maxi);
            mini = min(nums[i] , mini);

            present[nums[i]] = true;
        }

        vector<int>result;

        for(int curr = mini; curr < maxi; curr++){
            if(present[curr] != true){
                result.push_back(curr);
            }
        }

        return result;
    }
};