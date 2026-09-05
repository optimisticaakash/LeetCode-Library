class Solution {
public:
    int recursiveBS(vector<int>& nums , int low , int high , int target){
        if(low > high) return -1;

        int mid = low + (high - low)/2;

        if(nums[mid] == target) return mid;
        else if(target > nums[mid]) return recursiveBS(nums , mid+1 , high , target);
        else return  recursiveBS(nums , low , mid-1 , target);
    }
    int search(vector<int>& nums, int target) {
        return recursiveBS(nums , 0 , nums.size() -1 , target);
    }
};