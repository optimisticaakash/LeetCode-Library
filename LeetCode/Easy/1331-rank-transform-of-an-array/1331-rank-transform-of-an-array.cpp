//Approach1: my approach 
//1. ek temp array me arr ko dal kr sort krenge
//2. sorted array ke hisab se har no , rank ko map me store krenge
//3. arr pr iterate krke mp se number ke corresponding rank ko dal denge
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
       sort(temp.begin() , temp.end()); //nlogn

       unordered_map<int,int> rankmp;//n

       for(int i = 0; i < arr.size(); i++){//O(n
            if(rankmp.find(temp[i]) == rankmp.end()){
                int size = rankmp.size();
                rankmp[temp[i]] = size+1;
            }
       }

       vector<int> ans;
       for(int i = 0; i < arr.size() ; i++){//O(n)
            ans.push_back(rankmp[arr[i]]);
       }

       return ans;
    }
};

//T.C : O(2n) + O(nlogn)
//S.C : O(2n)
