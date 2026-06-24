class Solution {
public:
    //Approach1 : using loop
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