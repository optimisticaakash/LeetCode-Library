class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();

        sort(begin(nums) , end(nums));

        int curr = nums[0];
        vector<int> result;

        for(int i = 0; i < n;){
            if(curr < nums[i]){
                //missing curr
                result.push_back(curr);
            }else{
                i++;
            }
            curr++;
        }

        return result;
    }
};