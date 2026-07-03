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