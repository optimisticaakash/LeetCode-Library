//Approach1: Recursion
class Solution {
public:
    int solve(int n){
        if(n < 0) return 0;

        if(n == 0) return 1;//we have only 1 way

        int one_step = solve(n-1);
        int two_step = solve(n-2);
        
        return one_step + two_step;
    }
    int climbStairs(int n) {
        return solve(n);
    }
};
//T.C : O(2^N)
//S.C : O(1)


//Approach2: Recursion + memoization
class Solution {
public:
    int t[46];
    int solve(int n){
        if(n < 0) return 0;

        if(t[n] != -1) return t[n];

        if(n == 0) return 1;//we have got 1 way to cover all stairs

        int one_step = solve(n-1);
        int two_step = solve(n-2);
        
        return t[n] =  one_step + two_step;
    }
    int climbStairs(int n) {
        memset(t,-1,sizeof(t));
        return solve(n);
    }
};
//T.C : O(N)
//S.C: O(N)


//Approach3: Bottom- up
class Solution {
public:
    int climbStairs(int n) {
        if(n ==1 || n == 2 || n ==3) return n;

        vector<int> arr(n+1);
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 2;

        for(int i = 3; i <= n; i++){
            arr[i] = arr[i-1] + arr[i-2];
        }

        return arr[n];
    }
};
//T.C : O(N)
//S.C : O(N)

//Approach4: similar to fibonacci series
class Solution {
public:
    int climbStairs(int n) {

        if(n == 1 || n == 2) return n;
        
        int a = 1;
        int b = 2;
        int c = 3;

        for(int i = 3; i<= n; i++){
            c = a + b;

            int temp = b;
            b = c;
            a = temp;
        }

        return c;
    }
};
//T.C : O(N)
//S.C : O(1)
