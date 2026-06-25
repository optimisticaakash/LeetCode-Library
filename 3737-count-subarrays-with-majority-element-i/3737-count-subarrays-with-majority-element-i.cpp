//Approach1 : bruteforce 
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int cnt = 0;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int freq = 0;
                for(int k = i; k <= j; k++){
                    if(nums[k] == target) freq++;
                }

                if(freq > (j-i+1)/2) cnt++;
            }
        }

        return cnt;
    }
};
//T.C : O(N^3)
//S.C : O(1) -> it will give tle


//Approach2 : better brute -> calculate on the fly 
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int cnt = 0;

        for(int i = 0; i < n; i++){
            int freq = 0;
            for(int j = i; j < n; j++){
                if(nums[j] == target) freq++;

                if(freq > (j-i+1)/2){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
//T.C : O(N^2)
//S.C : O(N)

//Approach3:simplified bruteforce : since division is costly we are avoid doing it
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int cnt = 0;

        for(int i = 0; i < n; i++){
            int freq = 0;
            for(int j = i; j < n; j++){
                if(nums[j] == target){
                    freq++;
                }else{
                    freq--;
                }

                if(freq > 0){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
//T.C : O(N^2)
//S.C : O(N)

