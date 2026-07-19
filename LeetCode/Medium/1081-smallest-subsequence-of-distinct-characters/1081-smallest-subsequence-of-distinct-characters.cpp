class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<int>LastIndex(26,0);
        vector<bool>taken(26,false);

        string result;

        //filling LastIndex
        for(int i = 0; i < n; i++){
            char ch = s[i];

            LastIndex[ch-'a'] = i;
        }

        for(int i = 0; i < n; i++){
            char ch = s[i];

            int idx = ch-'a';

            if(taken[idx] == true) continue;

            while(result.length() > 0 && result.back() > ch && LastIndex[result.back() -'a'] > i){
                taken[result.back() -'a'] = false;
                result.pop_back();
            }

            result.push_back(ch);
            taken[idx] = true;
        }

        return result;
    }
};