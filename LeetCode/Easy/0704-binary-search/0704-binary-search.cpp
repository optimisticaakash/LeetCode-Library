class Solution {
public:
    int BinarySearch(vector<int>& nums , int low , int high , int target){
        int n = nums.size();

        

        while(low <= high){
            int mid = low + (high-low)/2;

            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }

        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0;
        int high = n-1;
        return BinarySearch(nums, low , high , target);
    }
};