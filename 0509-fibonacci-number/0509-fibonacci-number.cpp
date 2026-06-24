//Approach1 : using loop
class Solution {
public:
    
    int fib(int n) {
        int a = 0 , b = 1 , c;
        int count = 2;
        if(n<=1) return n;
        while(count <= n){
            c = a+b;
            a = b;
            b = c;
            count++;
        }
        return c;
    }
};
//T.C : O(N)
//S.C : O(1)

//Approach2 : using recursion
class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;

        int last = fib(n-1);
        int slast = fib(n-2);

        return last+ slast;
    }
};
//T.C : O(2^N)
//S.C : O(N)

///Approach3: using memoization
class Solution {
public:
    int solve(int n , vector<int>& dp){
        if(n <= 1) return n;

        if(dp[n] != -1){
            return dp[n];
        }

        return dp[n] = solve(n-1 , dp) + solve(n-2 , dp);
    }
    int fib(int n) {
        if(n <= 1) return n;

        vector<int> dp(n+1 , -1);

        return solve(n , dp);
    }
};
//T.C : O(N)
//S.C : O(N)

//Approach4: bottom up 
class Solution {
public:
    
    int fib(int n) {
        if(n <= 1) return n;

        vector<int> dp(n+1 , -1);
        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1]+ dp[i-2];
        }

        return dp[n];
    }
};
//T.C : O(N)
//S.C :O(N)
