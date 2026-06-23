class Solution {
public:
    //Approach2: using single array
    //T.C :O(2n)
    //S.C :O(N) 
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> left(n , 0);

        //left neighbours
        left[0] = 1;
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1]){
                left[i] = left[i-1]+1;
            }else{
                left[i] = 1;
            }
        }

        //right neighbours
        int curr = 1; int right = 1;
        int total = max(1 , left[n-1]);
        for(int i = n-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]){
                curr = right+1;
                right = curr;
            }else{
                curr = 1;
                right = 1;
            }

            total = total + max(curr , left[i]);
        }

        

        return total;
    }
};