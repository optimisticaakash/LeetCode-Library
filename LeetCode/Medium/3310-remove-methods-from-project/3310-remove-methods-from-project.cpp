//Approach: using bfs
class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);

        vector<int> inDegree(n , 0);
        vector<int> Suspicious(n ,false);

        for(auto &edge : invocations){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            inDegree[v]++;
        }

        queue<int> que;
        que.push(k);
        Suspicious[k] = true;

        while(!que.empty()){
            int curr = que.front();
            que.pop();

            for(int &ngbr : adj[curr]){
                inDegree[ngbr]--;

                if(!Suspicious[ngbr]){
                    que.push(ngbr);
                    Suspicious[ngbr] = true;
                }
            }
        }

        vector<int> result;
        bool cannotRemove = false;

        for(int i = 0; i < n; i++){
            if(Suspicious[i] && inDegree[i] > 0){
                cannotRemove = true;
            }
            
            if(!Suspicious[i]){
                result.push_back(i);
            }
        }

        if(cannotRemove){
            vector<int> vec(n);
            for(int i = 0; i < n; i++){
                vec[i] = i;
            }
            return vec;
        }

        return result;
    }
};
//T.C : O(V+E)
//S.C : O(V+E)