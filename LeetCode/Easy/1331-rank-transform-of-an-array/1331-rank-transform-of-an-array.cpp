class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
       sort(temp.begin() , temp.end());

       unordered_map<int,int> rankmp;

       for(int i = 0; i < arr.size(); i++){
            if(rankmp.find(temp[i]) == rankmp.end()){
                int size = rankmp.size();
                rankmp[temp[i]] = size+1;
            }
       }

       vector<int> ans;
       for(int i = 0; i < arr.size() ; i++){
            ans.push_back(rankmp[arr[i]]);
       }

       return ans;
    }
};