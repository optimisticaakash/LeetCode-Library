class Solution {
public:
    int candy(vector<int>& ratings) {
        //Approach 1 : bruteforce 
        int n = ratings.size();
        int candies = n;

        int i = 1;
        while(i < n){
            //if same rating
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }

            //increasing slope
            int peak = 0;
            while(ratings[i] > ratings[i-1]){
                peak++;
                candies += peak;
                i++;

                if(i == n) return candies;
            }

            //decreasing slope
            int dip = 0;
            while(i < n && ratings[i] < ratings[i-1]){
                dip++;
                candies += dip;
                i++;
            }

            //after completing mountain
            candies -= min(peak , dip);
        }

        return candies;
    }
};