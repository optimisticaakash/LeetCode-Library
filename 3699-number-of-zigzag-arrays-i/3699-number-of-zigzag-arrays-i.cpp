//Approach1: recursion
class Solution {
public: 
    int Mod = 1e9+7;
    typedef long long ll;
    int N , M;
    int solve(int i , int prevVal , bool increasing){

        if(i == N){
            //we reached the end of zig zag array
            return 1;
        }

        ll result = 0;

        if(increasing == true){
            for(int nextVal = prevVal + 1; nextVal <=  M; nextVal++){
                result = (result + solve(i + 1 , nextVal , false)) % Mod;
            }
        }else{//decreasing
            for(int nextVal = 1; nextVal <  prevVal; nextVal++){
                result = (result + solve(i + 1 , nextVal , true)) % Mod;
            }
        }

        return result;
    }
    int zigZagArrays(int n, int l, int r) {
        N = n;
        M = r - l +1;
        l = 1;
        r = M;

        ll result = 0;

        for(int startVal = 1; startVal <= M; startVal++){
            //i = 0 pr startVal dal diya hai

            //increasing
            result = (result + solve(1 , startVal  , true)) % Mod;

            //decreasing
            result = (result + solve(1 , startVal  , false)) % Mod;

        }
        return result;
    }
};

//Approach2: recursion+ memoization
class Solution {
public: 
    int Mod = 1e9+7;
    typedef long long ll;
    int N , M;

    int t[2001][2001][2];
    int solve(int i , int prevVal , bool increasing){

        if(i == N){
            //we reached the end of zig zag array
            return 1;
        }

        if(t[i][prevVal][increasing] != -1){
            return t[i][prevVal][increasing];
        }

        ll result = 0;

        if(increasing == true){
            for(int nextVal = prevVal + 1; nextVal <=  M; nextVal++){
                result = (result + solve(i + 1 , nextVal , false)) % Mod;
            }
        }else{//decreasing
            for(int nextVal = 1; nextVal <  prevVal; nextVal++){
                result = (result + solve(i + 1 , nextVal , true)) % Mod;
            }
        }

        return t[i][prevVal][increasing] = result;
    }
    int zigZagArrays(int n, int l, int r) {
        memset(t , -1 , sizeof(t));
        N = n;
        M = r - l +1;
        l = 1;
        r = M;

        ll result = 0;

        for(int startVal = 1; startVal <= M; startVal++){
            //i = 0 pr startVal dal diya hai

            //increasing
            result = (result + solve(1 , startVal  , true)) % Mod;

            //decreasing
            result = (result + solve(1 , startVal  , false)) % Mod;

        }
        return result;
    }
};

//Approach3: dp + prefixSum
class Solution {
public:
    int MOD = 1e9 + 7;
    typedef long long ll;
    int zigZagArrays(int n, int l, int r) {
        int N = n;
        int M = r-l+1;

        ll t[2001][2001][2];//DP array

        //base case
        for(int prevVal = 1; prevVal <= M; prevVal++){
            t[N][prevVal][0] = 1;
            t[N][prevVal][1] = 1;
        }

        for(int i = N-1; i >= 0; i--){

            vector<ll>cumsum1(M+1 , 0);
            vector<ll> cumsum0(M+1 , 0);

            for(int Val = 1; Val <= M; Val++){
                cumsum0[Val] = (cumsum0[Val-1]+ t[i+1][Val][0]) % MOD;
                cumsum1[Val] = (cumsum1[Val-1]+ t[i+1][Val][1]) % MOD;
            }
            for(int prevVal = 1; prevVal <= M; prevVal++){
                t[i][prevVal][1] = (cumsum0[M] - cumsum0[prevVal] + MOD)% MOD; 

                t[i][prevVal][0] = cumsum1[prevVal-1];
            }  
        }
        ll result = 0;

        for(int startVal = 1;startVal <= M; startVal++){
            result = (result + t[1][startVal][1])%MOD;

            result = (result + t[1][startVal][0])%MOD;
        }

        return result;
    }
};
