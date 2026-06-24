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

//Approach2:using vector
class Solution {
public:
    int fib(int n) {
        if(n== 0) return 0;
        vector<int>fibo(n+1);
        fibo[0] = 0;
        fibo[1] = 1;

        for(int i = 2; i <=n; i++){
            fibo[i] = fibo[i-1]+fibo[i-2];
        }

        return fibo[n];
    }
};
//T.C : O(N)
//S.C :O(N)

//Approach3 : using recursion
class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;

        int last = fib(n-1);
        int slast = fib(n-2);

        return last+ slast;
    }
};
