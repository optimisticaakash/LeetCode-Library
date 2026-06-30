class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin() , arr.end());

        int maxi = 0;
        for(int i = 0; i < arr.size(); i++){
            if(i == 0){
                arr[0] = 1;
            }else if(abs(arr[i] - arr[i-1]) >= 1){
                arr[i] = arr[i-1] + 1;
            }
            maxi = max(maxi , arr[i]);
        }


        return maxi;
    }
};

//T.C : O(n)
//S.C : :O(1)
