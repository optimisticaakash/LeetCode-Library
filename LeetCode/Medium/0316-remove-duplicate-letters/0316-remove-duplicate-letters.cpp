//Approach1: using string as stack
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();

        vector<int>LastIndex(26,0);
        for(int i = 0; i < n; i++){
            char ch = s[i];

            LastIndex[ch-'a'] = i;
        }

        vector<bool>taken(26,false);

        string result = "";

        for(int i = 0; i < n; i++){
            char ch = s[i];
            
            int idx = ch-'a';

            if(taken[idx] == true) continue;

            while(result.length() > 0 && result.back() > ch && LastIndex[result.back()-'a'] > i){
                taken[result.back()-'a'] = false;
                result.pop_back();
            }

            result.push_back(ch);
            taken[idx] = true;
        }

        return result;
    }
};
//T.C : O(N)
//S.C : O(1)

//Approach2: using stack
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();

        vector<int>LastIndex(26,0);
        for(int i = 0; i < n; i++){
            char ch = s[i];

            LastIndex[ch-'a'] = i;
        }

        vector<bool>taken(26,false);

        stack<char> st;

        for(int i = 0; i < n; i++){
            char ch = s[i];
            
            int idx = ch-'a';

            if(taken[idx] == true) continue;

            while(!st.empty() && st.top() > ch && LastIndex[st.top()-'a'] > i){
                taken[st.top()-'a'] = false;
                st.pop();
            }

            st.push(ch);
            taken[idx] = true;
        }

        string result;

        while(!st.empty()){
            result += st.top();
            st.pop();
        }

        reverse(result.begin() , result.end());

        return result;
    }
};

//T.C : O(N)
//S.C : O(1)
