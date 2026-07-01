class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        set<int> st;

        for(int i = 0; i < n; i++){
            st.insert(nums[i]);
        }

        int idx = 0;
        for(int s:st){
            nums[idx++] = s;
        }

        return idx;
    }
};