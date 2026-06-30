//Approach1. bruteforce
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        //generate all substring and check count

        int cnt = 0;
        for(int i = 0; i < n; i++){
            unordered_set<char> st;
            for(int j = i; j < n; j++){
                st.insert(s[j]);

                if(st.size() == 3) cnt++;
            }

            
        }

        return cnt;
    }
};

//T.C : O(N^2)
//S.C : O(1)

//Approach2 : using sliding window
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        vector<int> mp(3,0);
        int i = 0;
        int j = 0;

        int result = 0;

        while(j < n){
            char ch = s[j];
            mp[ch-'a']++;

            while(mp[0] > 0 && mp[1] > 0 && mp[2] > 0){
                result += n-j;

                mp[s[i]-'a']--; 
                i++;
            }
            j++;
        }
        return result;
    }
};

//T.C : O(2n)
//S.C : O(1)
