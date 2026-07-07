class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n == 0) return 0;
        string s = to_string(n);
        long long sum = 0;
        string ans = "";
        for(char &ch : s){
            if(ch != '0'){
                ans += ch;
                sum += ch-'0';
            }
        }

        int newnum = stoi(ans);

        return newnum * sum;
    }
};