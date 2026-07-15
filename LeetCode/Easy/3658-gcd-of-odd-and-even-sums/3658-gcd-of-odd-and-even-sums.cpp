class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumofNodd = n*n;
        int sumofNeven = n*(n+1);

        return __gcd(sumofNodd ,sumofNeven );
    }
};