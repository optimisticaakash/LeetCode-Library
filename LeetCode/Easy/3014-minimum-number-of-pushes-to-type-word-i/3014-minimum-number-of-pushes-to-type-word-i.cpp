class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();

        vector<int> mp(26,0);

        for(char &ch : word){
            mp[ch-'a']++;
        }

        sort(mp.begin() , mp.end() , greater<int>()); //descending

        int result = 0;
        for(int i = 0; i < n; i++){
            int freq = mp[i];

            int press = i/8+1;

            result += (press *freq);
        }

        return result;
    }
};