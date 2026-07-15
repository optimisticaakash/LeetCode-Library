//Approach1: derive krke formula for odd , even
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumofNodd = n*n;
        int sumofNeven = n*(n+1);

        return __gcd(sumofNodd ,sumofNeven );
    }
};

//Approach2: observational 
//__gcd(n*n , n*(n+1)); -> n * __gcd(n , n+1) --> n* 1
