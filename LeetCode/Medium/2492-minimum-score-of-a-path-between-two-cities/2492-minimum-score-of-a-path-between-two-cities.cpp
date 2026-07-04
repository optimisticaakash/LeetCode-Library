//Approach1 : dfs
class Solution {
public:
    typedef pair<int,int> P;
    void solvebydfs(unordered_map<int,vector<P>> &adj , int node , vector<bool>& visited , int &result){

        visited[node] = true;

        for(auto& vec: adj[node]){
            int v = vec.first;
            int cost = vec.second;

            result = min(result , cost);

            if(!visited[v]){
                solvebydfs(adj , v , visited , result);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        
        unordered_map<int,vector<P>> adj;

        //making the adjacency list
        for(auto& road:roads){
            int u = road[0];
            int v = road[1];
            int dist = road[2];

            adj[u].push_back({v , dist});
            adj[v].push_back({u, dist});
        } 

        vector<bool>visited(n+1 ,false);

        int result = INT_MAX;
        solvebydfs(adj , 1 , visited ,  result);

        return result;
    }
};
//T.C : O(V+E)
//S.C : O(V+E)
