class Solution {
public:
    bool check(vector<vector<int>>& distNearestThief , int sf){
        int n =distNearestThief.size();
        queue<pair<int,int>> que;

        vector<vector<bool>> visited(n , vector<bool>(n,false));
        //(0,0) -> (n-1 , n-1);
        que.push({0,0});
        visited[0][0] = true;

        if(distNearestThief[0][0] < sf)
            return false;

        while(!que.empty()){
            int curr_i = que.front().first;
            int curr_j = que.front().second;
            que.pop();

            if(curr_i == n-1 && curr_j == n-1) return true;

            int dr[] = {-1 , +1 , 0 , 0};//uplr
            int dc[] = {0 , 0 , -1 , +1};

            for(int k = 0; k < 4; k++){
                int new_r = curr_i + dr[k];
                int new_c = curr_j + dc[k];

                //check new_r and new_c validity
                if(new_r >= 0 && new_c >= 0 && new_r < n && new_c < n && visited[new_r][new_c] != true){
                    if(distNearestThief[new_r][new_c] < sf){
                        continue;//reject this cell
                    }else{
                        que.push({new_r , new_c});
                        visited[new_r][new_c] = true;
                    }
                }
            }
        }

        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        //step1 . pre-calculation of distNearestthief for each cell
        vector<vector<int>> distNearestThief(n,vector<int>(n , -1));

        queue<pair<int,int>> que;

        //visited array for marking visited cell
        vector<vector<bool>> visited( n , vector<bool>(n,false));

        //push all theives in the queue
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    que.push({i , j});
                    visited[i][j] = true;
                }
            }
        }

        int level = 0;
        while(!que.empty()){
            int size = que.size(); //current level me kitne node hai 

            while(size--){
                int curr_i = que.front().first;
                int curr_j = que.front().second;
                que.pop();
                distNearestThief[curr_i][curr_j] = level;

                int dr[] = {-1 , +1 , 0 , 0};//uplr
                int dc[] = {0 , 0 , -1 , +1};

                for(int k = 0; k < 4; k++){
                    int new_r = curr_i + dr[k];
                    int new_c = curr_j + dc[k];

                    //check new_r and new_c validity
                    if(new_r >= 0 && new_c >= 0 && new_r < n && new_c < n && visited[new_r][new_c] == false){
                        que.push({new_r , new_c});
                        visited[new_r][new_c] = true;
                    }
                }
            }
            level++;
        }

        //step2. apply binary search on S.F
        int low = 0;
        int high = 400;
        int result = 0;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(check(distNearestThief , mid)){
                result = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }

        return result;
    }
};