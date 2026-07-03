//Approach: binary Search + dijkstra
class Solution {
public:
    typedef pair<long long,int> P;
    bool check(int mid , int n , long long k , unordered_map<int,vector<pair<int,int>>>& adj){
        //result[i] = minimum cost path from source to i node

        vector<long long > result (n , LLONG_MAX);

        //minheap for dijkstra
        priority_queue<P, vector<P>  , greater<P>> pq;

        result[0] = 0;
        pq.push({0 , 0});

        while(!pq.empty()){
            long long d = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            //total cost from source to node = d
            if(d > result[node])
                continue;

            if(d > k) return false;

            if(node == n-1) return true;

            for(auto &vec: adj[node]){
                int ngbr = vec.first;
                int cost = vec.second;

                if(cost < mid) continue;

                if(d+ cost < result[ngbr]){
                    result[ngbr] = d + cost;

                    pq.push({d+cost , ngbr});
                }
            }
        }

        return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();// no of nodes

        //adjacency list // u -> {( v , cost) , (v' , cost)}
        unordered_map<int , vector<pair<int,int>>> adj;

        int low = INT_MAX;
        int high = 0;
     
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];

            if(!online[u] || !online[v])
                continue;
            
            adj[u].push_back({v,cost});

            low = min(low , cost);
            high = max(high , cost);
        }
        int answer = -1;
        
        while(low <= high){//log(high- low)
            int mid = low + (high-low)/2;


            if(check(mid , n , k , adj)){ // o(ElogV)
                answer = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }

        return answer;

    }
};

//T.C : O(log(high - low) * O(ElogV))
//s.C : O(N + edges)
