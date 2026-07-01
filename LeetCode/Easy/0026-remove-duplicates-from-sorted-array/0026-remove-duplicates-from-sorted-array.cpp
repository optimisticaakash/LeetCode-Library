//Approach1: bruteforce using set
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
//T.C : O(nlogn + n) //set insertion takes logn
//S.C  :O(N)


//Approach2: using two pointer - 
//code1: using while loop
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        int j = 1;

        while( j < n && i < n ){
            if(nums[i] != nums[j]){
                nums[i+1] = nums[j];
                i++;
            }
            j++;
        }

        return i+1;
    }
};
//T.C : O(n)
//S.C : O(1)

//code2: using for loop
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        for(int j=1; j < n; j++){
            if(nums[i] != nums[j]){
                nums[i+1] = nums[j];
                i++;
            }
        }

        return i+1;
    }
};

//T.C : O(n)
//S.C : O(1)

