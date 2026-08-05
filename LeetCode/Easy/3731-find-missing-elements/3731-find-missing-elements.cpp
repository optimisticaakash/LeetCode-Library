//Approach1:
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
//T.C : O(nlogn + T) T : no of element between minEl and maxEl
//S.C : O(K) k : no of missing elements

//Approach2:
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

//T.C : O(nlogn + T) T : no of element between minEl and maxEl
//S.C : O(K) k : no of missing elements

//Approach3:
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
//T.C : O(n + T) T : no of element between minEl and maxEl
//S.C : O(1) k : no of missing elements
