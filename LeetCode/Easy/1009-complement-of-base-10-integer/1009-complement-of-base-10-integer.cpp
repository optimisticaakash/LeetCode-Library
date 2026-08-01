class Solution {
public:
    int bitwiseComplement(int n) {

        if(n==0) return 1;

        
        int bits = floor(log2(n)) + 1; //number of bits
        int mask = (1 << bits)-1;// 2^bits -1 



        return n ^ mask;
    }
};