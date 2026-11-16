class Solution {
public:
    string digitSum(string s, int k) {

        while(s.length() > k){
            string nextString  = "";

            int n = s.length();

            for(int i = 0; i < n; i += k){
                int sum = 0;

                for(int j = i; j < min(i + k , n) ; j++){
                    sum += s[j]-'0';
                }

                nextString += to_string(sum);
            }

            s = move(nextString);
        }

        return s;
    }
};