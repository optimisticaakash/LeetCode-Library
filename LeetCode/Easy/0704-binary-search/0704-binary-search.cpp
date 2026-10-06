class Solution {
public:
    int BS(vector<int>& nums , int low , int high , int target){
        //base case
        if(low > high) return -1;

        int mid = low + (high - low)/2;

        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] < target){
            return BS(nums , mid+1 , high , target);
        }else{
            return BS(nums , low , mid-1 , target);
        }
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0;
        int high = n-1;

        return BS(nums , low , high , target);
    }
};