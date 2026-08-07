class Solution {
public:
    int findDigitProd(int num){
        int prod = 1;
        while(num > 0){
            prod *= num%10;
            num/=10;
        }

        return prod;
    }
    int smallestNumber(int n, int t) {
        for(int i = n; i <= n+10; i++){
            if(findDigitProd(i)%t == 0){
                return i;
            }
        }

        return -1;
    }
};