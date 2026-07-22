class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> checkstring(26,false);

        for(char c : sentence){
            checkstring[c-'a'] = true;
        }

        for(bool it : checkstring){
            if(it != true) return false;
        }

        return true;
    }
};