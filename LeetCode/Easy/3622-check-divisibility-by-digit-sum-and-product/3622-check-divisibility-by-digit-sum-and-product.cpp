class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
        int digitsum = 0;
        int digitproduct = 1;


        while(temp > 0){
            int ld = temp%10;
            digitsum += ld;
            digitproduct *= ld;
            temp /=10;
        }
        int num = digitsum+digitproduct ;
        if(n%num == 0){
            return true;
        }else{
            return false;
        }

        return false;
    }
};