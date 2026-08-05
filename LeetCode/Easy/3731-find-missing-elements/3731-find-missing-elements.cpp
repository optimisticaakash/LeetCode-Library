class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin() , nums.end());

        int n = nums.size();

        vector<int> ans;

        for(int i = 1; i < n; i++){
            int prev = nums[i-1];
            int curr = nums[i];

            //add all number between prev and curr jo bhi missing hai 
            for(int j = prev+1; j < curr ; j++){
                ans.push_back(j);
            }
        }

        return ans;
    }
};