class Solution {
public:
    using ll = long long;
    const ll MOD = 1e9 + 7;

    vector<vector<ll>> multiply(vector<vector<ll>>& A,
                                vector<vector<ll>>& B) {

        int n = A.size();

        vector<vector<ll>> C(n, vector<ll>(n, 0));

        for(int i = 0; i < n; i++) {
            for(int k = 0; k < n; k++) {

                if(A[i][k] == 0) continue;

                for(int j = 0; j < n; j++) {
                    if(B[k][j] == 0) continue;

                    C[i][j] =
                        (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    vector<vector<ll>> matrixPower(vector<vector<ll>> base,
                                   long long exp) {

        int n = base.size();

        vector<vector<ll>> result(
            n,
            vector<ll>(n, 0)
        );

        for(int i = 0; i < n; i++) {
            result[i][i] = 1;
        }

        while(exp) {

            if(exp & 1)
                result = multiply(result, base);

            base = multiply(base, base);

            exp >>= 1;
        }

        return result;
    }

    vector<ll> multiplyMatrixVector(
        vector<vector<ll>>& A,
        vector<ll>& v
    ) {

        int n = A.size();

        vector<ll> ans(n, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                ans[i] =
                    (ans[i] + A[i][j] * v[j]) % MOD;
            }
        }

        return ans;
    }

    int zigZagArrays(int n, int l, int r) {

        int M = r - l + 1;

        if(n == 1)
            return M;

        int S = 2 * M;

        vector<vector<ll>> T(
            S,
            vector<ll>(S, 0)
        );

        // Increasing states
        for(int x = 1; x <= M; x++) {

            int from = x - 1;

            for(int y = x + 1; y <= M; y++) {

                int to = M + (y - 1);

                T[from][to] = 1;
            }
        }

        // Decreasing states
        for(int x = 1; x <= M; x++) {

            int from = M + (x - 1);

            for(int y = 1; y < x; y++) {

                int to = y - 1;

                T[from][to] = 1;
            }
        }

        vector<ll> base(S, 1);

        vector<vector<ll>> P =
            matrixPower(T, n - 1);

        vector<ll> finalState =
            multiplyMatrixVector(P, base);

        ll ans = 0;

        for(ll x : finalState) {
            ans = (ans + x) % MOD;
        }

        return (int)ans;
    }
};