//Approach1: dfs for traversal of whole grid
class Solution {
public:
    int n , m;
    vector<vector<int>> best;//store krega maximum health kisi cell tk pahuchne ki 

    vector<vector<int>> dir = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};
    bool dfs(vector<vector<int>>& grid ,int i , int j , int health){
        //outside
        if(i < 0 || j < 0 || i >= n || j >= m) 
            return false;

        //unsafe hoga to health kam hojyegi wrna same rhegi
        health -= grid[i][j];

        if(health <= 0)
            return false;
        
        if(i == n-1 && j == m-1) return true;

        if(best[i][j] != -1 && best[i][j] >= health){
            return false;
        }

        best[i][j] = health;

        //explore all 4 dir
        for(vector<int> &vec: dir){
            int new_i = i + vec[0];
            int new_j = j + vec[1];

            if(dfs(grid , new_i , new_j , health)){
                return true;
            }
        }
        return false;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        n = grid.size();
        m = grid[0].size();


        best.assign(n , vector<int>(m , -1));

        bool ans = dfs(grid ,0 , 0 , health);   

        return ans;
    }
};
//T.C : O(n*m*H)
//S.C : O(n*m)

//Approach2: Dijsktra algorithm
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
//T.C : O(E+Vlog(v)) = O(n*m * log(nm))
//S.C : O(nm)

//Approach3: 0/1 bfs
class Solution {
public:
    vector<vector<int>> directions = {{-1 , 0} , {1 , 0} , {0 , -1} , {0 , 1}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> result(n , vector<int> (m , INT_MAX));
        //result[i][j] = min health to reach from (0 , 0) to (n-1 , m-1)

        deque<pair<int,int>> dq;

        result[0][0] = grid[0][0];
        dq.push_front({0,0});

        while(!dq.empty()){
            auto [r,c] = dq.front();
            dq.pop_front();

            for(auto &dir: directions){
                int nr = r + dir[0];
                int nc = c + dir[1];

                if(nr < 0 || nc < 0 || nr > n-1 || nc > m-1)
                    continue;
                
                if(result[r][c] + grid[nr][nc] < result[nr][nc]){
                    result[nr][nc] = result[r][c] + grid[nr][nc];

                    if(grid[nr][nc] == 0){
                        dq.push_front({nr , nc});
                    }else{
                        dq.push_back({nr , nc});
                    }
                }
            }
        }

        int x = result[n-1][m-1];

        return health-x >= 1;

    }
};
//T.C : O(nm)
//S.C  : O(nm)
