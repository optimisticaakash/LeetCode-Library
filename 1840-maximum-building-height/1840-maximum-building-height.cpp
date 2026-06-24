class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1,0});//for LtoR
        restrictions.push_back({n,n-1});//for RtoL

        sort(restrictions.begin() , restrictions.end());//sorting important for correction

        int N = restrictions.size();

        //left to right
        for(int i = 1; i < N; i++){
            int diffDist = restrictions[i][0] - restrictions[i-1][0];
            restrictions[i][1] = min(restrictions[i][1] , restrictions[i-1][1] + diffDist);
        }

        //right to left correcting
        for(int i = N-2; i >= 0; i--){
            int diffDist = restrictions[i+1][0] - restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1] , restrictions[i+1][1] + diffDist);
        }

        int result = 0;
        //calculating result
        for(int i = 1; i < N; i++){
            int ID1 = restrictions[i-1][0];
            int H1 = restrictions[i-1][1];

            int ID2 = restrictions[i][0];
            int H2 = restrictions[i][1];

            int diff = ID2 - ID1;
            int htDiff = abs(H1 - H2);

            //max(H1 , H2) + ((ID1 - ID2) - abs(H1 - H2))/2;
            int peak = max(H1 , H2) + (diff - htDiff)/2;

            result = max(result , peak);
        }

        return result;
    }
};