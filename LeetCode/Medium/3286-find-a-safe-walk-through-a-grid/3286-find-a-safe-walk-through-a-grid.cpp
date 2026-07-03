class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<P , vector<P> , greater<P>> pq;//cost , row , col

        vector<vector<int>> dist(n , vector<int>(m , INT_MAX));
        
        //starting cell me bhi health kam ho skti hai 
        dist[0][0] = grid[0][0];
        pq.push({dist[0][0] , {0 , 0 }});

        //4 directions
        int drow[] = {-1 , 1 , 0 , 0};
        int dcol[] = {0 , 0 , -1 , 1};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int cost = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(cost > dist[row][col])
                continue;
            
            for(int i = 0; i < 4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow < 0 || ncol < 0 || nrow > n-1 || ncol > m-1)
                    continue;
                
                //destination cell ka weight
                int newcost = cost + grid[nrow][ncol];

                if(newcost < dist[nrow][ncol]){
                    dist[nrow][ncol] = newcost;

                    pq.push({newcost , {nrow , ncol}});
                }
            }
        }

        return dist[n-1][m-1] < health;
    }
};