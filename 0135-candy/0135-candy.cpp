class Solution {
public:
    //Approach1 : using left and right array
    //T.C : O(3n)
    //S.C :O(2n)
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> left(n , 0);
        vector<int> right(n , 0);

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
        right[n-1] = 1;
        for(int i = n-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]){
                right[i] = right[i+1]+1;
            }else{
                right[i] = 1;
            }
        }

        int total = 0;

        for(int i = 0; i < n; i++){
            total += max(left[i] , right[i]);
        }

        return total;
    }
};